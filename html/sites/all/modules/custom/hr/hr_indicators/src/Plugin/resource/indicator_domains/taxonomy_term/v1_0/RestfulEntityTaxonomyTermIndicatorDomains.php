<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermIndicatorDomains.
 */

namespace Drupal\hr_indicators\Plugin\resource\indicator_domains\taxonomy_term\v1_0;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonomyTermIndicatorDomains
 * @package Drupal\hr_indicators\Plugin\resource\indicator_domains\taxonomy_term\v1_0
 *
 * @Resource(
 *   name = "indicator_domains:1.0",
 *   resource = "indicator_domains",
 *   label = "indicator_domains",
 *   description = "Export the indicator_domains.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_indicator_domain"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class RestfulEntityTaxonomyTermIndicatorDomains extends ResourceEntity implements ResourceInterface {

}
