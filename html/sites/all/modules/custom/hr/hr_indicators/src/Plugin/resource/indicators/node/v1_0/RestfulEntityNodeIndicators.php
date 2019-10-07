<?php

/**
 * @file
 * Contains \RestfulEntityNodeIndicators.
 */

namespace Drupal\hr_indicators\Plugin\resource\indicators\node\v1_0;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeIndicators
 * @package Drupal\hr_indicators\Plugin\resource\indicators\node\v1_0
 *
 * @Resource(
 *   name = "indicators:1.0",
 *   resource = "indicators",
 *   label = "Indicators",
 *   description = "Export the indicators.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_indicator"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class RestfulEntityNodeIndicators extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides EntityNode::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['global_clusters'] = array(
      'property' => 'field_sectors',
    );

    $public_fields['code'] = array(
      'property' => 'field_ind_code',
    );

    $public_fields['domain'] = array(
      'property' => 'field_ind_domain',
    );

    $public_fields['description'] = array(
      'property' => 'body',
    );

    $public_fields['unit'] = array(
      'property' => 'field_ind_unit',
    );

    $public_fields['unit_description'] = array(
      'property' => 'field_ind_unit_desc',
    );

    $public_fields['numerator'] = array(
      'property' => 'field_ind_numerator',
    );

    $public_fields['denominator'] = array(
      'property' => 'field_ind_denominator',
    );

    $public_fields['disaggregation'] = array(
      'property' => 'field_ind_disaggregation',
    );

    $public_fields['key'] = array(
      'property' => 'field_ind_key',
    );

    $public_fields['types'] = array(
      'property' => 'field_ind_types',
    );

    $public_fields['response_monitoring'] = array(
      'property' => 'field_ind_response',
    );

    $public_fields['standards'] = array(
      'property' => 'field_ind_standards',
    );

    $public_fields['threshold'] = array(
      'property' => 'field_ind_threshold',
    );

    $public_fields['guidance_phases'] = array(
      'property' => 'field_ind_guidance_phases',
    );

    $public_fields['general_guidance'] = array(
      'property' => 'field_ind_general_guidance',
    );

    $public_fields['guidance_baseline'] = array(
      'property' => 'field_ind_guidance_baseline',
    );

    $public_fields['comments'] = array(
      'property' => 'field_ind_comments',
    );

    $public_fields['data_sources'] = array(
      'property' => 'field_ind_data_sources',
    );

    $public_fields['sector_cross_tagging'] = array(
      'property' => 'field_ind_cross_tagging',
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

}
