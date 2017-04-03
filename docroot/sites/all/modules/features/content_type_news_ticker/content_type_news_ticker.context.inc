<?php
/**
 * @file
 * content_type_news_ticker.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function content_type_news_ticker_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mta_homepage';
  $context->description = 'MTAHQ Homepage';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'mta' => 'mta',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-banner_news-block' => array(
          'module' => 'views',
          'delta' => 'banner_news-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'mta_megamenu-mta_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'mta_megamenu',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_1' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-941' => array(
          'module' => 'block',
          'delta' => 941,
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-956' => array(
          'module' => 'block',
          'delta' => 956,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-156' => array(
          'module' => 'block',
          'delta' => 156,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-441' => array(
          'module' => 'block',
          'delta' => 441,
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => 16,
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-521' => array(
          'module' => 'block',
          'delta' => 521,
          'region' => 'sidebar_first_lower',
          'weight' => '-10',
        ),
        'block-371' => array(
          'module' => 'block',
          'delta' => 371,
          'region' => 'sidebar_first_lower',
          'weight' => '-9',
        ),
        'block-761' => array(
          'module' => 'block',
          'delta' => 761,
          'region' => 'sidebar_first_lower',
          'weight' => '-8',
        ),
        'block-376' => array(
          'module' => 'block',
          'delta' => 376,
          'region' => 'sidebar_first_lower',
          'weight' => '-7',
        ),
        'block-381' => array(
          'module' => 'block',
          'delta' => 381,
          'region' => 'sidebar_first_lower',
          'weight' => '-6',
        ),
        'tripplanner-tripplanner' => array(
          'module' => 'tripplanner',
          'delta' => 'tripplanner',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-961' => array(
          'module' => 'block',
          'delta' => 961,
          'region' => 'sidebar_second_lower',
          'weight' => '-10',
        ),
        'block-936' => array(
          'module' => 'block',
          'delta' => 936,
          'region' => 'sidebar_second_lower',
          'weight' => '-9',
        ),
        'block-546' => array(
          'module' => 'block',
          'delta' => 546,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-456' => array(
          'module' => 'block',
          'delta' => 456,
          'region' => 'sidebar_second_lower',
          'weight' => '-7',
        ),
        'block-396' => array(
          'module' => 'block',
          'delta' => 396,
          'region' => 'sidebar_second_lower',
          'weight' => '-6',
        ),
        'block-796' => array(
          'module' => 'block',
          'delta' => 796,
          'region' => 'sidebar_second_lower',
          'weight' => '-5',
        ),
        'block-721' => array(
          'module' => 'block',
          'delta' => 721,
          'region' => 'sidebar_second_lower',
          'weight' => '-4',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'footer',
          'weight' => '-88',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'footer',
          'weight' => '-87',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => 31,
          'region' => 'footer',
          'weight' => '-86',
        ),
        'google_adsense-google_adsense_horizontal' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense_horizontal',
          'region' => 'footer',
          'weight' => '-85',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('MTAHQ Homepage');
  $export['mta_homepage'] = $context;

  return $export;
}
