<?php
/**
 * @file
 * content_type_press_release.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_press_release_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-press_release-body'
  $field_instances['node-press_release-body'] = array(
    'bundle' => 'press_release',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-press_release-field_category'
  $field_instances['node-press_release-field_category'] = array(
    'bundle' => 'press_release',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select one of the terms to categorize this piece of content. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-press_release-field_press_multi_image'
  $field_instances['node-press_release-field_press_multi_image'] = array(
    'bundle' => 'press_release',
    'deleted' => 0,
    'description' => 'Upload Multiple Images for horizontal display under body',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'press_release_multi',
        ),
        'type' => 'image_caption',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'press_release_multi',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_press_multi_image',
    'label' => 'Additional Horizontal Images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'press release images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '800x600',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 1,
        'manualcrop_instant_preview' => 1,
        'manualcrop_require_cropping' => array(
          'horizontal_image' => 0,
          'news_horizontal' => 0,
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 'press_release_multi',
          'press_release_single' => 0,
          'rotator_horizontal' => 0,
          'rotator_vertical' => 0,
          'small_rotator' => 0,
          'vertical_image' => 0,
          'wide_rotator' => 0,
        ),
        'manualcrop_styles_list' => array(
          'horizontal_image' => 0,
          'news_horizontal' => 0,
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 'press_release_multi',
          'press_release_single' => 0,
          'rotator_horizontal' => 0,
          'rotator_vertical' => 0,
          'small_rotator' => 0,
          'vertical_image' => 0,
          'wide_rotator' => 0,
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-press_release-field_press_single_image'
  $field_instances['node-press_release-field_press_single_image'] = array(
    'bundle' => 'press_release',
    'deleted' => 0,
    'description' => 'Upload image for body of Press Release',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'press_release_single',
        ),
        'type' => 'image_caption',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'press_release_single',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_press_single_image',
    'label' => 'Single Vertical Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'press release images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '800x600',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_require_cropping' => array(
          'horizontal_image' => 0,
          'news_horizontal' => 0,
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 0,
          'press_release_single' => 'press_release_single',
          'rotator_horizontal' => 0,
          'rotator_vertical' => 0,
          'small_rotator' => 0,
          'vertical_image' => 0,
          'wide_rotator' => 0,
        ),
        'manualcrop_styles_list' => array(
          'horizontal_image' => 0,
          'news_horizontal' => 0,
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 0,
          'press_release_single' => 'press_release_single',
          'rotator_horizontal' => 0,
          'rotator_vertical' => 0,
          'small_rotator' => 0,
          'vertical_image' => 0,
          'wide_rotator' => 0,
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-press_release-field_sub_title'
  $field_instances['node-press_release-field_sub_title'] = array(
    'bundle' => 'press_release',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sub_title',
    'label' => 'Sub-Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Horizontal Images');
  t('Body');
  t('Category');
  t('Select one of the terms to categorize this piece of content. ');
  t('Single Vertical Image');
  t('Sub-Title');
  t('Upload Multiple Images for horizontal display under body');
  t('Upload image for body of Press Release');

  return $field_instances;
}
