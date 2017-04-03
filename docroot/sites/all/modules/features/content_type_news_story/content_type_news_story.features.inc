<?php
/**
 * @file
 * content_type_news_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_news_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function content_type_news_story_image_default_styles() {
  $styles = array();

  // Exported image style: rotator_horizontal.
  $styles['rotator_horizontal'] = array(
    'name' => 'rotator_horizontal',
    'label' => 'rotator_horizontal',
    'effects' => array(
      111 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 438,
          'height' => 220,
          'keepproportions' => 1,
          'style_name' => 'rotator_horizontal',
        ),
        'weight' => 0,
      ),
      106 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 438,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotator_vertical.
  $styles['rotator_vertical'] = array(
    'name' => 'rotator_vertical',
    'label' => 'rotator_vertical',
    'effects' => array(
      121 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'keepproportions' => 1,
          'style_name' => 'rotator_vertical',
        ),
        'weight' => 0,
      ),
      116 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function content_type_news_story_node_info() {
  $items = array(
    'news_story' => array(
      'name' => t('News Story'),
      'base' => 'node_content',
      'description' => t('Create a MTA News Article'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('When submitted, your News Article will be reviewed. If there are no problems, it will be published.'),
    ),
  );
  return $items;
}
