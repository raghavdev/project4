<?php
/**
 * @file
 * home_page_block.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function home_page_block_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_blocks_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Blocks Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    36 => '36',
    1 => '1',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="[status]">[body]</div>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Queue position (field_queue_position) */
  $handler->display->display_options['sorts']['field_queue_position_value']['id'] = 'field_queue_position_value';
  $handler->display->display_options['sorts']['field_queue_position_value']['table'] = 'field_data_field_queue_position';
  $handler->display->display_options['sorts']['field_queue_position_value']['field'] = 'field_queue_position_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );

  /* Display: hq Block */
  $handler = $view->new_display('block', 'hq Block', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    2616 => '2616',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';

  /* Display: nyct Block */
  $handler = $view->new_display('block', 'nyct Block', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    2611 => '2611',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';

  /* Display: lirr Block */
  $handler = $view->new_display('block', 'lirr Block', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    2626 => '2626',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';

  /* Display: MNR Block */
  $handler = $view->new_display('block', 'MNR Block', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    0 => '2621',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';

  /* Display: B&T Block */
  $handler = $view->new_display('block', 'B&T Block', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    0 => '2606',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';

  /* Display: SIR Block */
  $handler = $view->new_display('block', 'SIR Block', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_block' => 'homepage_block',
  );
  /* Filter criterion: Content: Agency home page categories (field_agency_home_page_categorie) */
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['id'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['table'] = 'field_data_field_agency_home_page_categorie';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['field'] = 'field_agency_home_page_categorie_tid';
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['value'] = array(
    0 => '2631',
  );
  $handler->display->display_options['filters']['field_agency_home_page_categorie_tid']['vocabulary'] = 'agency_home_page_block';
  $export['homepage_blocks_admin'] = $view;

  return $export;
}
