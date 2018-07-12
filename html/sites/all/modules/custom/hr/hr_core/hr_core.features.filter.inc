<?php
/**
 * @file
 * hr_core.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function hr_core_filter_default_formats() {
  $formats = array();

  // Exported format: WYSIWYG trusted.
  $formats['hr_wysiwyg_trusted'] = array(
    'format' => 'hr_wysiwyg_trusted',
    'name' => 'WYSIWYG trusted',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(),
  );

  // Exported format: HTML.
  $formats['panopoly_html_text'] = array(
    'format' => 'panopoly_html_text',
    'name' => 'HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(),
  );

  // Exported format: WYSIWYG.
  $formats['panopoly_wysiwyg_text'] = array(
    'format' => 'panopoly_wysiwyg_text',
    'name' => 'WYSIWYG',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(),
  );

  return $formats;
}
