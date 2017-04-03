<?php
/**
 * @file
 * content_type_news_story.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_news_story_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency|node|news_story|form';
  $field_group->group_name = 'group_emergency';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_story';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_news_rotator';
  $field_group->data = array(
    'label' => 'Emergency Notice',
    'weight' => '26',
    'children' => array(
      0 => 'field_emergency_headline',
      1 => 'field_emergency_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Emergency Notice',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-emergency field-group-fieldset',
        'description' => 'Enter Emergency Alert Notice',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_emergency|node|news_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_media|node|news_story|form';
  $field_group->group_name = 'group_news_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_story';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Upload Body Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_news_body_horizontal_image',
      1 => 'field_news_body_vertical_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Upload Body Images',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-news-media field-group-fieldset',
        'description' => 'Upload Body Images',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_news_media|node|news_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_rotator|node|news_story|form';
  $field_group->group_name = 'group_news_rotator';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_story';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Enter News Rotator Image or Emergency Notice',
    'weight' => '2',
    'children' => array(
      0 => 'field_news_rotator_caption',
      1 => 'field_page_link',
      2 => 'field_rotator_horizontal_image',
      3 => 'field_rotator_vertical_image',
      4 => 'group_emergency',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Enter News Rotator Image or Emergency Notice',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-news-rotator field-group-fieldset',
        'description' => 'Upload Image and Caption for the News Rotator<br>
<b>CHOOSE ONLY ONE STYLE BELOW - HORIZONTAL OR VERTICAL</b>',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_news_rotator|node|news_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_story|node|news_story|form';
  $field_group->group_name = 'group_news_story';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_story';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Enter News Story (summary and body)',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_tags',
      2 => 'field_article_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Enter News Story (summary and body)',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-news-story field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_news_story|node|news_story|form'] = $field_group;

  return $export;
}
