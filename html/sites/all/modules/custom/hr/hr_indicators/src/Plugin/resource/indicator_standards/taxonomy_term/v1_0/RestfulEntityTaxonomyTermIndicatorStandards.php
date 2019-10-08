<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermIndicatorStandards.
 */

namespace Drupal\hr_indicators\Plugin\resource\indicator_standards\taxonomy_term\v1_0;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonomyTermIndicatorStandards
 * @package Drupal\hr_indicators\Plugin\resource\indicator_standards\taxonomy_term\v1_0
 *
 * @Resource(
 *   name = "indicator_standards:1.0",
 *   resource = "indicator_standards",
 *   label = "indicator_standards",
 *   description = "Export the indicator_standards.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_indicator_standard"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class RestfulEntityTaxonomyTermIndicatorStandards extends ResourceEntity implements ResourceInterface {

}
