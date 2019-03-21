<?php

/**
 * @file
 * Code for the Indicators feature.
 */

/**
 * Form to import XLSX.
 */
function hr_indicators_import_from_xlsx($form, &$form_state) {
  if (!variable_get('file_private_path')) {
    $form['private_path'] = array(
      '#type' => 'markup',
      '#markup' => t('You must specify a private file system path in the !settings so we can save the created files there.', array('!settings' => l(t('file system settings'), 'admin/config/media/file-system'))),
    );
  }
  else {
    $form['xlsx'] = array(
      '#type' => 'file',
      '#title' => t('Upload xlsx file'),
      '#size' => 48,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import indicators'),
    );
  }

  return $form;
}

/**
 * Validate form to import XLSX.
 */
function hr_indicators_import_from_xlsx_validate($form, &$form_state) {
  $validators['file_validate_extensions'] = array('xlsx');

  $file = file_save_upload('xlsx', $validators, FALSE, FILE_EXISTS_REPLACE);
  if (!$file) {
    form_error($form['xlsx'], t('Something went wrong while uploading the file.'));
    return;
  }
  $form_state['values']['xlsx'] = $file;
}

/**
 * Submit form to import XLSX.
 */
function hr_indicators_import_from_xlsx_submit($form, &$form_state) {
  $file = $form_state['values']['xlsx'];
  hr_indicators_import_from_xlsx_populate_queue($file);
}

/**
 * Populate queue.
 */
function hr_indicators_import_from_xlsx_populate_queue($xlsx_file, $autostart = TRUE, $use_batch = TRUE) {
  $batch = array(
    'operations' => array(),
    'title' => t('Importing'),
    'init_message' => t('Initializing.'),
    'progress_message' => t('Processed @current out of @total.'),
    'file' => drupal_get_path('module', 'hr_indicators') . '/hr_indicators.admin.inc',
    'finished' => 'hr_indicators_import_from_xlsx_finished',
  );

  // Include XLSX parser.
  module_load_include('php', 'hr_indicators', 'SimpleXLSX');

  $xlsx = SimpleXLSX::parse($xlsx_file->uri);

  if (!$xlsx) {
    // Something went wrong.
  }

  // Loop all sheets, sheet name is domain.
  $sheets = $xlsx->sheetNames();
  foreach ($sheets as $index => $sheet) {
    $rows = $xlsx->rows($index);

    // Make sure all data is UTF8.
    $encoding_list[] = "UTF-8";
    $encoding_list[] = "ASCII";
    $encoding_list[] = "ISO-8859-1";

    // Assume 1 header line.
    $header = $rows[0];
    $header_lowercase = array_map('drupal_strtolower', $header);

    // Remove first row.
    unset($rows[0]);
    foreach ($rows as $row) {
      $data = array();
      for ($i = 0; $i < count($row); $i++) {
        $content = $row[$i];
        if (mb_detect_encoding($content, $encoding_list, TRUE) == 'ISO-8859-1') {
          $row[$i] = utf8_encode($content);
        }
        elseif (!mb_check_encoding($content, 'UTF-8') || !($content === mb_convert_encoding(mb_convert_encoding($content, 'UTF-32', 'UTF-8'), 'UTF-8', 'UTF-32'))) {
          $content = mb_convert_encoding($content, 'UTF-8');
          if (mb_check_encoding($content, 'UTF-8')) {
            $row[$i] = $content;
          }
        }
        $data[$header_lowercase[$i]] = $row[$i];
      }

      // Add domain.
      $data['domain'] = $sheet;

      $batch['operations'][] = array(
        'hr_indicators_import_from_xlsx_import_row',
        array($data),
      );
    }
  }

  batch_set($batch);
  batch_process(current_path());
}

/**
 * Import one row of data.
 */
function hr_indicators_import_from_xlsx_import_row($data, &$context) {
  // Make sure we have a indicator code.
  if (!isset($data['indicator code']) || empty($data['indicator code'])) {
    watchdog('hr_indicators', 'indicator code is not set');
    return;
  }

  // Assume it fails.
  $context['results']['failures'][$data['indicator code']] = 'Failed to import ' . $data['indicator code'];

  // Make sure we have a title.
  if (!isset($data['indicator']) || empty($data['indicator'])) {
    watchdog('hr_indicators', 'Missing indicator for @indicator_code', array('@indicator_code' => $data['indicator code']));
    $context['results']['failures'][$data['indicator code']] = 'Missing indicator for ' . $data['indicator code'];
    return;
  }

  // Load existing node by indicator code.
  $node = FALSE;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_ind_code', 'value', $data['indicator code'], '=')
    ->range(0, 1);

  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nid = reset($nids);
    $node = node_load($nid);
  }
  else {
    $node = (object) array('type' => 'hr_indicator');
    node_object_prepare($node);

    $node->title = substr($data['indicator'], 0, 250);
    $node->title_field['en'][0]['value'] = substr($data['indicator'], 0, 250);
    $node->status = NODE_NOT_PUBLISHED;
    $node->uid = 1;
    $node->field_ind_code['und'][0]['value'] = $data['indicator code'];
    $node->language = 'en';
    node_save($node);
  }

  // Sub-Domain.
  if (isset($data['status'])) {
    $node->status = (bool) $data['status'];
  }

  // Sub-Domain.
  if (isset($data['sub-domain']) && !empty($data['sub-domain'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['sub-domain'])));
    $node->field_ind_domain[LANGUAGE_NONE] = array();

    // Get parent term.
    $domain = hr_indicators_get_term($data['domain'], 'hr_indicator_domain');

    foreach ($terms as $term) {
      $sub_domain = hr_indicators_get_term($term, 'hr_indicator_domain', $domain->tid);
      $node->field_ind_domain[LANGUAGE_NONE][]['target_id'] = $sub_domain->tid;
    }
  }

  // Strategic objective.
  if (isset($data['strategic objective']) && !empty($data['strategic objective'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['strategic objective'])));
    $node->field_ind_strategic_objective[LANGUAGE_NONE] = array();

    foreach ($terms as $term) {
      $strategic_objective = hr_indicators_get_term($term, 'strategic_objective');
      $node->field_ind_strategic_objective[LANGUAGE_NONE][]['target_id'] = $strategic_objective->tid;
    }
  }

  // Cluster/AoR.
  if (isset($data['cluster/aor']) && !empty($data['cluster/aor'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['cluster/aor'])));
    $node->field_sectors[LANGUAGE_NONE] = array();

    foreach ($terms as $term) {
      $cluster = hr_indicators_get_node($term, 'hr_sector');
      $node->field_sectors[LANGUAGE_NONE][]['target_id'] = $cluster->nid;
    }
  }

  // Sectoral objective.
  if (isset($data['sectoral objective']) && !empty($data['sectoral objective'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['sectoral objective'])));
    $node->field_ind_sectoral_objective[LANGUAGE_NONE] = array();

    foreach ($terms as $term) {
      $sectoral_objective = hr_indicators_get_term($term, 'sectoral_objective');
      $node->field_ind_sectoral_objective[LANGUAGE_NONE][]['target_id'] = $sectoral_objective->tid;
    }
  }

  // Indicator type.
  if (isset($data['indicator type']) && !empty($data['indicator type'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['indicator type'])));
    $node->field_ind_types[LANGUAGE_NONE] = array();

    foreach ($terms as $term) {
      $hr_indicator_type = hr_indicators_get_term($term, 'hr_indicator_type');
      $node->field_ind_types[LANGUAGE_NONE][]['target_id'] = $hr_indicator_type->tid;
    }
  }

  // Level.
  if (isset($data['level']) && !empty($data['level'])) {
    $separator = '|';
    $terms = array_filter(explode($separator, trim($data['level'])));
    $node->field_ind_level[LANGUAGE_NONE] = array();

    foreach ($terms as $term) {
      $level = hr_indicators_get_term($term, 'level');
      $node->field_ind_level[LANGUAGE_NONE][]['target_id'] = $level->tid;
    }
  }

  node_save($node);
  unset($context['results']['failures'][$data['indicator code']]);
  $context['results']['succes'][$data['indicator code']] = 'Imported row ' . $data['indicator code'];
}

/**
 * Finish callback.
 */
function hr_indicators_import_from_xlsx_finished($success, $results, $operations) {
  if ($success) {
    if (!isset($results['succes'])) {
      $results['succes'] = array();
    }
    $message = t('@count indicators successfully imported', array('@count' => count($results['succes'])));
    drupal_set_message($message);

    if (!empty($results['failures'])) {
      $message = t('Failed to import @count indicators', array('@count' => count($results['failures'])));
      drupal_set_message($message);
    }
  }
}

/**
 * Load a term.
 */
function hr_indicators_get_term($name, $vocabulary, $parent_id = 0) {
  $name = trim($name);
  if (empty($name)) {
    return;
  }

  // Add short name, first 10 words.
  $short_name = hr_indicators_first_n_words($name);
  if ($short_name != $name) {
    $short_name .= ' ...';
  }

  // Query by name.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->entityCondition('bundle', $vocabulary, '=');
  $query->propertyCondition('name', $short_name, '=');
  $result = $query->execute();

  // Make sure term exists.
  if (isset($result['taxonomy_term'])) {
    $term_tid = reset($result['taxonomy_term']);
    $term = taxonomy_term_load($term_tid->tid);
  }
  else {
    // Load vocabulary.
    $voc = taxonomy_vocabulary_machine_name_load($vocabulary);

    // Add new term.
    $term = new stdClass();
    $term->language = 'en';
    $term->name = $short_name;
    $term->name_field[LANGUAGE_NONE][0]['value'] = $short_name;
    $term->description = $name;
    $term->vid = $voc->vid;
    $term->vocabulary_machine_name = $vocabulary;

    if ($parent_id) {
      $term->parent = $parent_id;
    }

    taxonomy_term_save($term);
  }

  return $term;
}

/**
 * Load a node.
 */
function hr_indicators_get_node($name, $type) {
  // Query by name.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', $type, '=');
  $query->propertyCondition('title', $name, '=');
  $result = $query->execute();

  // Make sure node exists.
  if (isset($result['node'])) {
    $node_nid = reset($result['node']);
    $node = node_load($node_nid->nid);
  }
  else {
    $node = (object) array('type' => $type);
    node_object_prepare($node);

    $node->title = $name;
    $node->status = NODE_PUBLISHED;
    $node->uid = 1;
    $node->language = 'en';
    node_save($node);
  }

  return $node;
}

/**
 * Return first N words.
 */
function hr_indicators_first_n_words($s, $limit = 10) {
  return preg_replace('/((\w+\W*){' . ($limit - 1) . '}(\w+))(.*)/', '${1}', $s);
}
