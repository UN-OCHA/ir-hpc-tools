<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermIndicatorTypes.
 */

namespace Drupal\hr_indicators\Plugin\resource\indicator_types\taxonomy_term\v1_0;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonomyTermIndicatorTypes
 * @package Drupal\hr_indicators\Plugin\resource\indicator_types\taxonomy_term\v1_0
 *
 * @Resource(
 *   name = "indicator_types:1.0",
 *   resource = "indicator_types",
 *   label = "indicator_types",
 *   description = "Export the indicator_types.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_indicator_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class RestfulEntityTaxonomyTermIndicatorTypes extends ResourceEntity implements ResourceInterface {

}
