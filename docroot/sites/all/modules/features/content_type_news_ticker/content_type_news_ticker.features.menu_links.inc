<?php
/**
 * @file
 * content_type_news_ticker.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function content_type_news_ticker_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_news-ticker:node/add/news-ticker
  $menu_links['navigation_news-ticker:node/add/news-ticker'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/news-ticker',
    'router_path' => 'node/add/news-ticker',
    'link_title' => 'News Ticker',
    'options' => array(
      'identifier' => 'navigation_news-ticker:node/add/news-ticker',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('News Ticker');


  return $menu_links;
}
