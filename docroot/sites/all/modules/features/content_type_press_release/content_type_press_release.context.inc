<?php
/**
 * @file
 * content_type_press_release.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function content_type_press_release_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mta_main_press_page';
  $context->description = 'Press releases';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'press-releases' => 'press-releases',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-press_release-block_1' => array(
          'module' => 'views',
          'delta' => 'press_release-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'page_title',
          'weight' => '-10',
        ),
        'google_adsense-google_adsense' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => '36',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => '31',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Press releases');
  $export['mta_main_press_page'] = $context;

  return $export;
}
