<?php
/**
 * @file
 * content_type_news_ticker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_news_ticker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function content_type_news_ticker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function content_type_news_ticker_node_info() {
  $items = array(
    'news_ticker' => array(
      'name' => t('News Ticker'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
