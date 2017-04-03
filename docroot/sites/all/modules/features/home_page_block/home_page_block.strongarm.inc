<?php
/**
 * @file
 * home_page_block.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function home_page_block_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__homepage_block';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
        'workbench_access' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_homepage_block';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_homepage_block';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_homepage_block';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_homepage_block';
  $strongarm->value = '1';
  $export['node_preview_homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_homepage_block';
  $strongarm->value = 0;
  $export['node_submitted_homepage_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_categories';
  $strongarm->value = array(
    11 => '11',
  );
  $export['tac_lite_categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_config_scheme_1';
  $strongarm->value = array(
    'name' => 'anonymous content for agency',
    'perms' => array(
      'grant_view' => 'grant_view',
    ),
    'unpublished' => 0,
    'term_visibility' => 0,
    'tac_lite_create' => 0,
  );
  $export['tac_lite_config_scheme_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_config_scheme_2';
  $strongarm->value = array(
    'name' => 'auth content tac agency',
    'perms' => array(
      'grant_view' => 'grant_view',
    ),
    'unpublished' => 0,
    'term_visibility' => 0,
    'tac_lite_create' => 0,
  );
  $export['tac_lite_config_scheme_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_config_scheme_3';
  $strongarm->value = array(
    'name' => 'agency user',
    'perms' => array(
      'grant_view' => 'grant_view',
      'grant_update' => 'grant_update',
      'grant_delete' => 'grant_delete',
    ),
    'unpublished' => 1,
    'term_visibility' => 1,
    'tac_lite_create' => 1,
  );
  $export['tac_lite_config_scheme_3'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_grants_scheme_1';
  $strongarm->value = array(
    1 => array(
      11 => array(
        2606 => '2606',
        2626 => '2626',
        2621 => '2621',
        2616 => '2616',
        2611 => '2611',
      ),
    ),
    2 => array(
      11 => array(),
    ),
    3 => array(
      11 => array(),
    ),
    6 => array(
      11 => array(),
    ),
    8 => array(
      11 => array(),
    ),
    21 => array(
      11 => array(),
    ),
    26 => array(
      11 => array(),
    ),
    36 => array(
      11 => array(),
    ),
  );
  $export['tac_lite_grants_scheme_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_grants_scheme_2';
  $strongarm->value = array(
    1 => array(
      11 => array(),
    ),
    2 => array(
      11 => array(),
    ),
    3 => array(
      11 => array(),
    ),
    6 => array(
      11 => array(),
    ),
    8 => array(
      11 => array(),
    ),
    21 => array(
      11 => array(),
    ),
    26 => array(
      11 => array(),
    ),
    36 => array(
      11 => array(),
    ),
  );
  $export['tac_lite_grants_scheme_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_grants_scheme_3';
  $strongarm->value = array(
    1 => array(
      11 => array(),
    ),
    2 => array(
      11 => array(),
    ),
    3 => array(
      11 => array(),
    ),
    6 => array(
      11 => array(),
    ),
    8 => array(
      11 => array(),
    ),
    21 => array(
      11 => array(),
    ),
    26 => array(
      11 => array(),
    ),
    36 => array(
      11 => array(),
    ),
  );
  $export['tac_lite_grants_scheme_3'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tac_lite_schemes';
  $strongarm->value = '4';
  $export['tac_lite_schemes'] = $strongarm;

  return $export;
}
