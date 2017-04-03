<?php
/**
 * @file
 * home_page_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function home_page_block_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_block_imahes|node|homepage_block|form';
  $field_group->group_name = 'group_hp_block_imahes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'HP block Images',
    'weight' => '3',
    'children' => array(
      0 => 'field_hp_block_image_left',
      1 => 'field_hp_block_image_center',
      2 => 'field_hp_block_image_right',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'HP block Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-hp-block-imahes field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_hp_block_imahes|node|homepage_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hpb_layout_1|node|homepage_block|form';
  $field_group->group_name = 'group_hpb_layout_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'HPB Layout 1',
    'weight' => '7',
    'children' => array(
      0 => 'field_hpb_header_1',
      1 => 'field_hpb_subhead_1',
      2 => 'field_hpb_link_1',
      3 => 'field_hpb_image_1',
      4 => 'field_hpb_header_2',
      5 => 'field_hpb_subhead_2',
      6 => 'field_hpb_link_2',
      7 => 'field_hpb_link_2b',
      8 => 'group_hpb_layout_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hpb-layout-1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hpb_layout_1|node|homepage_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hpb_layout_3|node|homepage_block|form';
  $field_group->group_name = 'group_hpb_layout_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'HPB Layout 3',
    'weight' => '19',
    'children' => array(
      0 => 'field_hpb_header_3',
      1 => 'field_hpb_subhead_3a',
      2 => 'field_hpb_subhead_3b',
      3 => 'field_hpb_header_3b',
      4 => 'field_hpb_link_3a1',
      5 => 'field_hpb_link_3a2',
      6 => 'field_hpb_link_3b1',
      7 => 'field_hpb_link_3b2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hpb-layout-3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hpb_layout_3|node|homepage_block|form'] = $field_group;

  return $export;
}
