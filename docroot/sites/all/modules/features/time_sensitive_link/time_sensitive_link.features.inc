<?php
/**
 * @file
 * time_sensitive_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function time_sensitive_link_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function time_sensitive_link_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function time_sensitive_link_node_info() {
  $items = array(
    'time_sensitive_link' => array(
      'name' => t('time sensitive link'),
      'base' => 'node_content',
      'description' => t('Time sensitive links  are used for displaying HTML links on a schedule.  These links should appear for a Give block. A View will select the links from the database based on the schedule and by the block they will be displayed  in.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
