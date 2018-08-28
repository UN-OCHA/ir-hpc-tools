<?php
/**
 * @file
 * Template overrides, preprocess, and alter hooks for the OCHA Basic theme.
 */


/**
 * Implements hook_form_alter().
 */
function ocha_basic_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['#attributes']['role'] = 'search';
    $form['#attributes']['class'][] = 'cd-search--inline__form';
    $form['#attributes']['aria-labelledby'][] = 'cd-search-btn';
    $form['search_block_form']['#attributes']['placeholder'] = t('What are you looking for?');
    $form['search_block_form']['#attributes']['autocomplete'][] = 'off';
    $form['search_block_form']['#attributes']['class'][] = 'cd-search--inline__input';
    $form['search_block_form']['#attributes']['id'][] = 'cd-search';
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#prefix' => '<button type="submit" id="edit-submit" name="op" class="cd-search--inline__submit form-submit"><svg width="34" height="34" viewBox="0 0 34 34"><title>search</title><path d="M19.427 20.427c-1.39 0.99-3.090 1.573-4.927 1.573-4.694 0-8.5-3.806-8.5-8.5s3.806-8.5 8.5-8.5c4.694 0 8.5 3.806 8.5 8.5 0 2.347-0.951 4.472-2.49 6.010l5.997 5.997c0.275 0.275 0.268 0.716-0.008 0.992-0.278 0.278-0.72 0.28-0.992 0.008l-6.081-6.081zM14.5 21c4.142 0 7.5-3.358 7.5-7.5s-3.358-7.5-7.5-7.5c-4.142 0-7.5 3.358-7.5 7.5s3.358 7.5 7.5 7.5v0z" stroke-width="1"></path></svg><span class="element-invisible">Search</span>',
      '#suffix' => '</button>',
      '#markup' => '',
      '#weight' => 1000,
    );
    $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
  }

  if ($form_id == 'views_exposed_form') {
    $form['#attributes']['role'] = 'search';
    $form['#attributes']['class'][] = 'cd-search--inline__form';
    $form['#attributes']['aria-labelledby'][] = 'cd-search-btn';
  }
}


/**
 * Implements hook_preprocess_search_block_form().
 */
function ocha_basic_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}


/**
 * Implements hook_preprocess_html().
 */
function ocha_basic_preprocess_html(&$vars) {

  // Add some custom classes for panels pages.
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $vars['is_panel'] = TRUE;

    // Get the current panel display and add some classes to body.
    if ($display = panels_get_current_page_display()) {
      $vars['classes_array'][] = 'panel-layout-' . $display->layout;

      // Add a custom class for each region that has content.
      $regions = array_keys($display->panels);
      foreach ($regions as $region) {
        $vars['classes_array'][] = 'panel-region-' . $region;
      }
    }
  }

  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );

  $apple = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/apple-touch-icon.png',
      'rel' => 'apple-touch-icon',
      'sizes' => '180x180',
    ),
  );

  $fav_32 = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/favicon-32x32.png',
      'rel' => 'icon',
      'sizes' => '32x32',
      'type' => 'image/png',
    ),
  );

  $fav_16 = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/favicon-16x16.png',
      'rel' => 'icon',
      'sizes' => '16x16',
      'type' => 'image/png',
    ),
  );

  $safari_pinned_tab = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/safari-pinned-tab.svg',
      'rel' => 'mask-icon',
      'color' => '#5bbad5',
    ),
  );

  drupal_add_html_head($viewport, 'viewport');
  drupal_add_html_head($apple, 'apple-touch-icon');
  drupal_add_html_head($fav_32, 'favicon-32x32');
  drupal_add_html_head($fav_16, 'favicon-16x16');
  drupal_add_html_head($safari_pinned_tab, 'safari_pinned_tab');
}


/**
 * Implements template_preprocess_page().
 */
function ocha_basic_preprocess_page(&$vars) {
  // Bail out if function is not available.
  if (!function_exists('language_negotiation_get_switch_links')) {
    return;
  }
  // Add language links.
  global $language;
  $path = drupal_is_front_page() ? '<front>' : $_GET['q'];
  $links = language_negotiation_get_switch_links('language', $path);
  // Bail out if links is not enumerable
  if (!$links) {
    return;
  }
  $render = array(
    'links' => $links->links,
    'attributes' => array(
      'class' => [
        'cd-global-header__dropdown',
        'cd-dropdown',
        'cd-user-menu__dropdown',
      ],
      'role' => 'menu',
      'id' => 'cd-language',
      'aria-labelledby' => 'cd-language-toggle',
    ),
  );
  $output = '';
  $output .= '<div class="cd-language-switcher">';
  $output .= '<button type="button" class="cd-user-menu__item cd-user-menu__item--small cd-global-header__dropdown-btn" data-toggle="dropdown" id="cd-language-toggle">';
  $output .= $language->language;
  $output .= '<svg width="32" height="32" viewBox="0 0 32 32" class="arrow-down" aria-hidden="true"><path d="M26.2 11.7c0 0.4-0.2 0.6-0.3 0.7l-8.4 8.4c-0.4 0.4-0.9 0.6-1.5 0.6s-1.1-0.2-1.5-0.6l-8.4-8.4c-0.2-0.2-0.3-0.4-0.3-0.7s0.1-0.5 0.3-0.7c0.2-0.2 0.4-0.3 0.7-0.3s0.5 0.1 0.7 0.3l8.4 8.4c0 0 0 0 0 0s0 0 0.1 0 0.1 0 0.2 0l8.3-8.4c0.4-0.4 1-0.4 1.4 0 0.1 0.1 0.3 0.3 0.3 0.7z"></path></svg>';
  $output .= '</button>';
  $output .= theme('links__locale_block', $render);
  $output .= '</div>';
  $vars['page']['language_switcher'] = $output;
}

/**
 * Implements hook_pwa_manifest_alter().
 */
function ocha_basic_pwa_manifest_alter(&$manifest) {
  // Hard-code a theme-color into the manifest.
  $manifest['theme_color'] = '#026CB6';

  // Override the PWA default icons with OCHA defaults.
  //
  // If you are using this theme as a starterkit feel free to manually adjust
  // this code block, otherwise copy this hook into your subtheme and customize
  // to your heart's content.
  $manifest['icons'] = [
    [
      'src' => url(drupal_get_path('theme', 'ocha_basic') . '/img/android-chrome-512x512.png'),
      'sizes' => '512x512',
      'type' => 'image/png',
    ],
    [
      'src' => url(drupal_get_path('theme', 'ocha_basic') . '/img/android-chrome-192x192.png'),
      'sizes' => '192x192',
      'type' => 'image/png',
    ],
  ];
}

/**
 * Implements hook_preprocess_fieldable_panels_pane().
 *
 * Fixes title appearing 2 times in fieldable panels panes.
 */
function ocha_basic_preprocess_fieldable_panels_pane(&$variables) {
  if (isset($variables['content']['title'])) {
    unset($variables['content']['title']);
  }
}

/**
 * Implements template_preprocess_views_view_table().
 */
function ocha_basic_preprocess_views_view_table(&$variables) {
  // Add Bootstrap table classes.
  $variables['classes_array'] = array_merge($variables['classes_array'], array(
    'table',
    'table-striped',
    'table-bordered',
  ));
}

/**
 * Custom function to render a block.
 */
function ocha_basic_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}


/**
 * Returns HTML for a search keys facet item.
 */
function ocha_basic_current_search_keys($variables) {
  $link_text = check_plain($variables['keys']);

  $variables['path'] = current_path();
  $variables['text'] = 'X ' . $link_text;
  $variables['options']['html'] = TRUE;
  $variables['options']['attributes']['title'] = t('Remove keyword: @text', array('@text' => $link_text));

  return theme('link', $variables);
}

/**
 * Returns HTML for an active facet item.
 */
function ocha_basic_facetapi_link_active($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $link_text,
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  $variables['options']['attributes']['title'] = t('Remove filter: @text', array('@text' => $link_text));
  return theme('link', $variables);
}

/**
 * Returns HTML for the deactivation widget.
 */
function ocha_basic_facetapi_deactivate_widget($variables) {
  return '<span class="facet-api--remove-icon">X</span>';
}

/**
 * Returns HTML that adds accessible markup to facet links.
 */
function ocha_basic_facetapi_accessible_markup($variables) {
  $vars = array('@text' => $variables['text']);
  $text = ($variables['active']) ? t('Remove filter', $vars) : t('Apply filter', $vars);
  // Add spaces before and after the text, since other content may be displayed
  // inline with this and we don't want the words to run together. However, the
  // spaces must be inside the <span> so as not to disrupt the layout for
  // sighted users.
  if ($variables['active']) {
    return '<span class="element-invisible"> ' . $text . ' </span>' . $variables['text'];
  }
  else {
    return '<span class="element-invisible"> ' . $text . ' </span>';
  }
}

function ocha_basic_views_data_export_feed_icon($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('html' => TRUE);
  if ($query) {
    $url_options['query'] = $query;
  }
  $image = theme('image', array('path' => $image_path, 'alt' => $text, 'title' => $text));
  return '<li>'.l($text, $url, $url_options).'</li>';
}
