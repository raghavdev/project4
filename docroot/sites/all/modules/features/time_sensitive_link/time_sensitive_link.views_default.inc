<?php
/**
 * @file
 * time_sensitive_link.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function time_sensitive_link_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'train_to_the_game_sports_schedule';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div>
	<h2 class="banner">
		<a href="http://web.mta.info/mta/sports">Take the Train to the Game</a><sup>&reg;</sup></h2>
</div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: End Date */
  $handler->display->display_options['fields']['field_end_date']['id'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['fields']['field_end_date']['field'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_end_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: link caption */
  $handler->display->display_options['fields']['field_link_caption']['id'] = 'field_link_caption';
  $handler->display->display_options['fields']['field_link_caption']['table'] = 'field_data_field_link_caption';
  $handler->display->display_options['fields']['field_link_caption']['field'] = 'field_link_caption';
  $handler->display->display_options['fields']['field_link_caption']['label'] = '';
  $handler->display->display_options['fields']['field_link_caption']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_caption']['alter']['text'] = '<ul class="arrow"><li>[field_link_caption]</li></ul>';
  $handler->display->display_options['fields']['field_link_caption']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_link_caption']['alter']['path'] = 'http://web.mta.info/mta/sports/';
  $handler->display->display_options['fields']['field_link_caption']['element_label_colon'] = FALSE;
  /* Field: Content: link to content */
  $handler->display->display_options['fields']['field_link_to_content']['id'] = 'field_link_to_content';
  $handler->display->display_options['fields']['field_link_to_content']['table'] = 'field_data_field_link_to_content';
  $handler->display->display_options['fields']['field_link_to_content']['field'] = 'field_link_to_content';
  $handler->display->display_options['fields']['field_link_to_content']['label'] = '';
  $handler->display->display_options['fields']['field_link_to_content']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_to_content']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_link_to_content']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_link_to_content']['element_label_colon'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: owner (field_owner) */
  $handler->display->display_options['filters']['field_owner_value']['id'] = 'field_owner_value';
  $handler->display->display_options['filters']['field_owner_value']['table'] = 'field_data_field_owner';
  $handler->display->display_options['filters']['field_owner_value']['field'] = 'field_owner_value';
  $handler->display->display_options['filters']['field_owner_value']['value'] = 'Train to the Game';
  /* Filter criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: End Date (field_end_date) */
  $handler->display->display_options['filters']['field_end_date_value']['id'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['filters']['field_end_date_value']['field'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_end_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_end_date_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['train_to_the_game_sports_schedule'] = $view;

  return $export;
}
