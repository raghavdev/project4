<?php
/**
 * @file
 * content_type_news_ticker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function content_type_news_ticker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news_ticker';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_news_ticker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news_ticker';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news_ticker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news_ticker';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'moderation',
    2 => 'revision',
  );
  $export['node_options_news_ticker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news_ticker';
  $strongarm->value = '1';
  $export['node_preview_news_ticker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news_ticker';
  $strongarm->value = 1;
  $export['node_submitted_news_ticker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_ticker_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_ticker_pattern'] = $strongarm;

  return $export;
}
