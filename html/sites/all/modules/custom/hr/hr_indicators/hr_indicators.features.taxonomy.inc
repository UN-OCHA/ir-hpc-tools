<?php

/**
 * @file
 * hr_indicators.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_indicators_taxonomy_default_vocabularies() {
  return array(
    'hr_indicator_domain' => array(
      'name' => 'Indicator Domain',
      'machine_name' => 'hr_indicator_domain',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_standard' => array(
      'name' => 'Indicator Standard',
      'machine_name' => 'hr_indicator_standard',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_type' => array(
      'name' => 'Indicator Type',
      'machine_name' => 'hr_indicator_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_unit' => array(
      'name' => 'Indicator Unit',
      'machine_name' => 'hr_indicator_unit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'level' => array(
      'name' => 'Level',
      'machine_name' => 'level',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'path' => array(
        'pathauto' => 0,
      ),
    ),
    'sectoral_objective' => array(
      'name' => 'Sectoral objective',
      'machine_name' => 'sectoral_objective',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'path' => array(
        'pathauto' => 0,
      ),
    ),
    'strategic_objective' => array(
      'name' => 'Strategic objective',
      'machine_name' => 'strategic_objective',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'path' => array(
        'pathauto' => 0,
      ),
    ),
  );
}
