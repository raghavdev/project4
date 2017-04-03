<?php
/**
 * @file
 * content_type_news_story.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_news_story_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-news_story-body'
  $field_instances['node-news_story-body'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use Summary to enter an Article Teaser.
Use News Article Body to enter the full story',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'News Story Body',
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
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-news_story-field_article_summary'
  $field_instances['node-news_story-field_article_summary'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter Article summary for teaser<br>
DO NOT ENTER SUBWAY BULLETS IN ARTICLE SUMMARY FIELD',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_article_summary',
    'label' => 'Article Summary',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
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
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-news_story-field_emergency_headline'
  $field_instances['node-news_story-field_emergency_headline'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter an Emergency Headline to display in the News Rotator',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_emergency_headline',
    'label' => 'Emergency Headline',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-news_story-field_emergency_summary'
  $field_instances['node-news_story-field_emergency_summary'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a brief description of the Emergency Details',
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_emergency_summary',
    'label' => 'Emergency Summary',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 700,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-news_story-field_news_body_horizontal_image'
  $field_instances['node-news_story-field_news_body_horizontal_image'] = array(
    'bundle' => 'news_story',
    'deleted' => 0,
    'description' => 'Upload Images to crop for Horizontal display under body',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'news_horizontal',
        ),
        'type' => 'image_caption',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_body_horizontal_image',
    'label' => 'News Body Horizontal Image',
    'required' => 0,
    'rubik_edit_field_display' => 'default',
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'news images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '424x318',
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
          'news_horizontal' => 'news_horizontal',
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 0,
          'press_release_single' => 0,
          'rotator_horizontal' => 0,
          'rotator_vertical' => 0,
          'small_rotator' => 0,
          'vertical_image' => 0,
          'wide_rotator' => 0,
        ),
        'manualcrop_styles_list' => array(
          'horizontal_image' => 0,
          'news_horizontal' => 'news_horizontal',
          'news_vertical' => 0,
          'portrait' => 0,
          'press_release_multi' => 0,
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
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-news_story-field_news_body_vertical_image'
  $field_instances['node-news_story-field_news_body_vertical_image'] = array(
    'bundle' => 'news_story',
    'deleted' => 0,
    'description' => 'Upload Images to crop for Vertical display under body',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'news_vertical',
        ),
        'type' => 'image_caption',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_body_vertical_image',
    'label' => 'News Body Vertical Image',
    'required' => 0,
    'rubik_edit_field_display' => 'default',
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'news images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '424x318',
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
          'news_vertical' => 'news_vertical',
          'portrait' => 0,
          'press_release_multi' => 0,
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
          'news_vertical' => 'news_vertical',
          'portrait' => 0,
          'press_release_multi' => 0,
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
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-news_story-field_news_category'
  $field_instances['node-news_story-field_news_category'] = array(
    'bundle' => 'news_story',
    'default_value' => array(
      0 => array(
        'tid' => 376,
      ),
    ),
    'deleted' => 0,
    'description' => 'Leave the category set to news.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_category',
    'label' => 'News category',
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
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-news_story-field_news_rotator_caption'
  $field_instances['node-news_story-field_news_rotator_caption'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a Caption for the News Rotator Image.<br>
To include a caption in body of story use caption field<i> below uploaded image.</i>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_rotator_caption',
    'label' => 'Enter News Rotator Caption',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-news_story-field_page_link'
  $field_instances['node-news_story-field_page_link'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Leave blank to link to the full story or enter a url for other destinations',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_link',
    'label' => 'Page Link',
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
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-news_story-field_rotator_horizontal_image'
  $field_instances['node-news_story-field_rotator_horizontal_image'] = array(
    'bundle' => 'news_story',
    'deleted' => 0,
    'description' => 'Upload a horizontal image for the News Rotator',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'rotator_horizontal',
        ),
        'type' => 'image_caption',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rotator_horizontal_image',
    'label' => 'News Rotator Horizontal Image',
    'required' => 0,
    'rubik_edit_field_display' => 'default',
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'news images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '424x318',
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
          'press_release_single' => 0,
          'rotator_horizontal' => 'rotator_horizontal',
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
          'press_release_single' => 0,
          'rotator_horizontal' => 'rotator_horizontal',
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
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-news_story-field_rotator_vertical_image'
  $field_instances['node-news_story-field_rotator_vertical_image'] = array(
    'bundle' => 'news_story',
    'deleted' => 0,
    'description' => 'Upload a Vertical image for the News Rotator',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_caption_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'rotator_vertical',
        ),
        'type' => 'image_caption',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rotator_vertical_image',
    'label' => 'News Rotator Vertical Image',
    'required' => 0,
    'rubik_edit_field_display' => 'default',
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'news images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '424x318',
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
          'press_release_single' => 0,
          'rotator_horizontal' => 0,
          'rotator_vertical' => 'rotator_vertical',
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
          'press_release_single' => 0,
          'rotator_horizontal' => 0,
          'rotator_vertical' => 'rotator_vertical',
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
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-news_story-field_tags'
  $field_instances['node-news_story-field_tags'] = array(
    'bundle' => 'news_story',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 15,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Article Summary');
  t('Emergency Headline');
  t('Emergency Summary');
  t('Enter Article summary for teaser<br>
DO NOT ENTER SUBWAY BULLETS IN ARTICLE SUMMARY FIELD');
  t('Enter News Rotator Caption');
  t('Enter a Caption for the News Rotator Image.<br>
To include a caption in body of story use caption field<i> below uploaded image.</i>');
  t('Enter a brief description of the Emergency Details');
  t('Enter an Emergency Headline to display in the News Rotator');
  t('Leave blank to link to the full story or enter a url for other destinations');
  t('Leave the category set to news.');
  t('News Body Horizontal Image');
  t('News Body Vertical Image');
  t('News Rotator Horizontal Image');
  t('News Rotator Vertical Image');
  t('News Story Body');
  t('News category');
  t('Page Link');
  t('Tags');
  t('Upload Images to crop for Horizontal display under body');
  t('Upload Images to crop for Vertical display under body');
  t('Upload a Vertical image for the News Rotator');
  t('Upload a horizontal image for the News Rotator');
  t('Use Summary to enter an Article Teaser.
Use News Article Body to enter the full story');

  return $field_instances;
}
