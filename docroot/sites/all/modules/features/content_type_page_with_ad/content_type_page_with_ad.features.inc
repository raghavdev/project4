<?php
/**
 * @file
 * content_type_page_with_ad.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_page_with_ad_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_page_with_ad_node_info() {
  $items = array(
    'page_with_ad' => array(
      'name' => t('Page with ad'),
      'base' => 'node_content',
      'description' => t('This a simple page but with Google ads'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
