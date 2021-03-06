<?php
/**
 * @file
 * hr_layout.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hr_layout_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_privacy-policy:https://www.un.org/en/sections/about-website/privacy-notice.
  $menu_links['menu-footer-menu_privacy-policy:https://www.un.org/en/sections/about-website/privacy-notice'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://www.un.org/en/sections/about-website/privacy-notice',
    'router_path' => '',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_privacy-policy:https://www.un.org/en/sections/about-website/privacy-notice',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_terms-of-use:http://www.un.org/en/aboutun/terms.
  $menu_links['menu-footer-menu_terms-of-use:http://www.un.org/en/aboutun/terms'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'http://www.un.org/en/aboutun/terms',
    'router_path' => '',
    'link_title' => 'Terms of use',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_terms-of-use:http://www.un.org/en/aboutun/terms',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Log out');
  t('Privacy Policy');
  t('Terms of use');
  t('User account');

  return $menu_links;
}
