<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermIndicatorUnits.
 */

namespace Drupal\hr_indicators\Plugin\resource\indicator_units\taxonomy_term\v1_0;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonomyTermIndicatorUnits
 * @package Drupal\hr_indicators\Plugin\resource\indicator_units\taxonomy_term\v1_0
 *
 * @Resource(
 *   name = "indicator_units:1.0",
 *   resource = "indicator_units",
 *   label = "indicator_units",
 *   description = "Export the indicator_units.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_indicator_unit"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class RestfulEntityTaxonomyTermIndicatorUnits extends ResourceEntity implements ResourceInterface {

}
