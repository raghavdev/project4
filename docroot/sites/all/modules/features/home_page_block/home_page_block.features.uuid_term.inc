<?php
/**
 * @file
 * home_page_block.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function home_page_block_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'B&T',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6a0e66b0-958a-4df5-90df-b283d3c4eed6',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  $terms[] = array(
    'name' => 'NYCT',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '75b62944-bb82-47ec-9f2b-b7502523b8c8',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  $terms[] = array(
    'name' => 'MTAHQ',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '89f8490a-b742-445e-b650-0f66cc14cc79',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  $terms[] = array(
    'name' => 'LIRR',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8bc66fd9-87bb-460c-8db5-4e419c539b13',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  $terms[] = array(
    'name' => 'SIR',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e71cd730-d785-4967-9edc-5bf4e3d6818f',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  $terms[] = array(
    'name' => 'MNR',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f0e76013-e268-4576-a551-cbe00ecc9c90',
    'vocabulary_machine_name' => 'agency_home_page_block',
  );
  return $terms;
}
