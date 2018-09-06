<?php
/**
 * @file
 * hr_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function hr_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'standard';
  $item->label = 'Standard';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => ' <p>Filter: <span class="facetapi-active">[facetapi_results:result-count] item</span> displayed</p>',
        'plural' => 1,
        'text_plural' => '<p>Filter: <span class="facetapi-active">[facetapi_results:result-count] items</span> displayed</p>',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'current-search-filter',
        'weight' => '-50',
      ),
      'reset' => array(
        'id' => 'text',
        'label' => 'Reset',
        'text' => '<a href="/[facetapi_results:search-path]"><span>Reset filter</span></a>',
        'plural' => 1,
        'text_plural' => '<a href="/[facetapi_results:search-path]"><span>Reset all filters</span></a>',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'current-reset-filter',
        'weight' => '-49',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 1,
        'classes' => '.current-selected-item',
        'nofollow' => 1,
        'weight' => '-48',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );

  $export['hr_current_search'] = $item;

  return $export;
}
