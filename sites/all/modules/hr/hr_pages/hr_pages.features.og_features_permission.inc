<?php
/**
 * @file
 * hr_pages.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_pages_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_sector:access authoring options of hr_page content'
  $permissions['node:hr_sector:access authoring options of hr_page content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access publishing options of hr_page content'
  $permissions['node:hr_sector:access publishing options of hr_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access revisions options of hr_page content'
  $permissions['node:hr_sector:access revisions options of hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:administer panelizer node hr_page content'
  $permissions['node:hr_sector:administer panelizer node hr_page content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:create hr_page content'
  $permissions['node:hr_sector:create hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete any hr_page content'
  $permissions['node:hr_sector:delete any hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete own hr_page content'
  $permissions['node:hr_sector:delete own hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update any hr_page content'
  $permissions['node:hr_sector:update any hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update own hr_page content'
  $permissions['node:hr_sector:update own hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:view any unpublished hr_page content'
  $permissions['node:hr_sector:view any unpublished hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access authoring options of hr_page content'
  $permissions['node:hr_space:access authoring options of hr_page content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access publishing options of hr_page content'
  $permissions['node:hr_space:access publishing options of hr_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access revisions options of hr_page content'
  $permissions['node:hr_space:access revisions options of hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:administer panelizer node hr_page content'
  $permissions['node:hr_space:administer panelizer node hr_page content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:create hr_page content'
  $permissions['node:hr_space:create hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete any hr_page content'
  $permissions['node:hr_space:delete any hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete own hr_page content'
  $permissions['node:hr_space:delete own hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update any hr_page content'
  $permissions['node:hr_space:update any hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update own hr_page content'
  $permissions['node:hr_space:update own hr_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:view any unpublished hr_page content'
  $permissions['node:hr_space:view any unpublished hr_page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
