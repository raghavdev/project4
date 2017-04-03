<?php
/**
 * @file
 * content_type_press_release.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_press_release_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_add_pr_images|node|press_release|form';
  $field_group->group_name = 'group_add_pr_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add PR Images',
    'weight' => '3',
    'children' => array(
      0 => 'field_press_multi_image',
      1 => 'field_press_single_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add PR Images',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-add-pr-images field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_add_pr_images|node|press_release|form'] = $field_group;

  return $export;
}
