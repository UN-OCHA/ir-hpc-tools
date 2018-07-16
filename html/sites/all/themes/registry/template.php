<?php
/**
 * @file
 * Theme functions
 */

require_once dirname(__FILE__) . '/includes/structure.inc';
require_once dirname(__FILE__) . '/includes/comment.inc';
require_once dirname(__FILE__) . '/includes/form.inc';
require_once dirname(__FILE__) . '/includes/menu.inc';
require_once dirname(__FILE__) . '/includes/node.inc';
require_once dirname(__FILE__) . '/includes/panel.inc';
require_once dirname(__FILE__) . '/includes/user.inc';
require_once dirname(__FILE__) . '/includes/view.inc';

/**
 * Returns HTML for an active facet item.
 */
function registry_facetapi_link_active($variables) {
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
function registry_facetapi_deactivate_widget($variables) {
  return 'X';
}

/**
 * Returns HTML that adds accessible markup to facet links.
 */
function registry_facetapi_accessible_markup($variables) {
  $vars = array('@text' => $variables['text']);
  $text = ($variables['active']) ? t('Remove filter', $vars) : t('Apply filter', $vars);
  // Add spaces before and after the text, since other content may be displayed
  // inline with this and we don't want the words to run together. However, the
  // spaces must be inside the <span> so as not to disrupt the layout for
  // sighted users.
  return '<span class="element-invisible"> ' . $text . ' </span>' . $variables['text'];
}

/**
 * Implements hook_css_alter().
 */
function registry_css_alter(&$css) {
  $radix_path = drupal_get_path('theme', 'radix');

  // Radix now includes compiled stylesheets for demo purposes.
  // We remove these from our subtheme since they are already included
  // in compass_radix.
  unset($css[$radix_path . '/assets/stylesheets/radix-style.css']);
  unset($css[$radix_path . '/assets/stylesheets/radix-print.css']);
}

/**
 * Implements template_preprocess_page().
 */
function registry_preprocess_page(&$variables) {
  global $theme_path;
  $tree = menu_tree_page_data('main-menu', 1);
  $main_menu_dropdown = menu_tree_output($tree);
  $main_menu_dropdown['#theme_wrappers'] = array();
  $variables['main_menu_dropdown'] = $main_menu_dropdown;
  $variables['hr_tabs'] = array();
  $header_img_path = $theme_path.'/assets/images/headers/general.png';

  if (user_is_anonymous()) {
    $variables['follow_us_link_href'] = 'connect/oauthconnector_hid_oauth';
    $variables['follow_us_link_title'] = t('Login to follow us');
    $variables['follow_us_link_status'] = 'flag';
  }
}

/**
 * Custom function to render a block so I can manually position it in the markup
 */
function _registry_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}

/**
 * Implements hook_preprocess_fieldable_panels_pane()
 * Fixes title appearing 2 times in fieldable panels panes
 */
function registry_preprocess_fieldable_panels_pane(&$variables) {
  if (isset($variables['content']['title'])) {
    unset($variables['content']['title']);
  }
}
