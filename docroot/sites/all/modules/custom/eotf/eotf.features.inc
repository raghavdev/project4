<?php
/**
 * @file
 * eotf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function eotf_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function eotf_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function eotf_node_info() {
  $items = array(
    'eotf' => array(
      'name' => t('EotF'),
      'base' => 'node_content',
      'description' => t('A Drupal content type to store MTA Eye on the Future (EotF) data'),
      'has_title' => '1',
      'title_label' => t('Contract Description'),
      'help' => '',
    ),
  );
  return $items;
}
