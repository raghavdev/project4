<?php
/**
 * @file
 * home_page_block.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function home_page_block_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bandt';
  $context->description = 'Bridges & Tunnels';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'bandt' => 'bandt',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mta_megamenu-bandt_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'bandt_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'service_notice-service_notice_bandt' => array(
          'module' => 'service_notice',
          'delta' => 'service_notice_bandt',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_3' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_3',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-homepage_blocks_admin-block_5' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_5',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-351' => array(
          'module' => 'block',
          'delta' => 351,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-356' => array(
          'module' => 'block',
          'delta' => 356,
          'region' => 'content_bottom_left',
          'weight' => '-10',
        ),
        'block-361' => array(
          'module' => 'block',
          'delta' => 361,
          'region' => 'content_bottom_right',
          'weight' => '-10',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-336' => array(
          'module' => 'block',
          'delta' => 336,
          'region' => 'sidebar_first_lower',
          'weight' => '-9',
        ),
        'block-341' => array(
          'module' => 'block',
          'delta' => 341,
          'region' => 'sidebar_first_lower',
          'weight' => '-8',
        ),
        'block-346' => array(
          'module' => 'block',
          'delta' => 346,
          'region' => 'sidebar_first_lower',
          'weight' => '-7',
        ),
        'block-331' => array(
          'module' => 'block',
          'delta' => 331,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-636' => array(
          'module' => 'block',
          'delta' => 636,
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-591' => array(
          'module' => 'block',
          'delta' => 591,
          'region' => 'sidebar_second_lower',
          'weight' => '-5',
        ),
        'block-786' => array(
          'module' => 'block',
          'delta' => 786,
          'region' => 'sidebar_second_lower',
          'weight' => '-4',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'footer',
          'weight' => '-10',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => 31,
          'region' => 'footer',
          'weight' => '-8',
        ),
        'google_adsense-google_adsense_horizontal' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense_horizontal',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bridges & Tunnels');
  $export['bandt'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lirr';
  $context->description = 'Long Island Rail Road';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'lirr' => 'lirr',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mta_megamenu-lirr_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'lirr_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'service_notice-service_notice_lirr' => array(
          'module' => 'service_notice',
          'delta' => 'service_notice_lirr',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_2' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_2',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-homepage_blocks_admin-block_3' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_3',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-491' => array(
          'module' => 'block',
          'delta' => 491,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-766' => array(
          'module' => 'block',
          'delta' => 766,
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'block-266' => array(
          'module' => 'block',
          'delta' => 266,
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-251' => array(
          'module' => 'block',
          'delta' => 251,
          'region' => 'sidebar_first_lower',
          'weight' => '-9',
        ),
        'block-646' => array(
          'module' => 'block',
          'delta' => 646,
          'region' => 'sidebar_first_lower',
          'weight' => '-7',
        ),
        'block-591' => array(
          'module' => 'block',
          'delta' => 591,
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-711' => array(
          'module' => 'block',
          'delta' => 711,
          'region' => 'sidebar_second_lower',
          'weight' => '-10',
        ),
        'block-281' => array(
          'module' => 'block',
          'delta' => 281,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-631' => array(
          'module' => 'block',
          'delta' => 631,
          'region' => 'sidebar_second_lower',
          'weight' => '-7',
        ),
        'block-536' => array(
          'module' => 'block',
          'delta' => 536,
          'region' => 'sidebar_second_lower',
          'weight' => '-5',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'footer',
          'weight' => '-10',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => 31,
          'region' => 'footer',
          'weight' => '-8',
        ),
        'google_adsense-google_adsense_horizontal' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense_horizontal',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Long Island Rail Road');
  $export['lirr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mnr';
  $context->description = 'Metro North Rail Road';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'mnr' => 'mnr',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mta_megamenu-mnr_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'mnr_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'service_notice-service_notice_mnr' => array(
          'module' => 'service_notice',
          'delta' => 'service_notice_mnr',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_4' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_4',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-homepage_blocks_admin-block_4' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_4',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-751' => array(
          'module' => 'block',
          'delta' => 751,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-801' => array(
          'module' => 'block',
          'delta' => 801,
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'block-776' => array(
          'module' => 'block',
          'delta' => 776,
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'block-726' => array(
          'module' => 'block',
          'delta' => 726,
          'region' => 'content_bottom',
          'weight' => '-5',
        ),
        'block-771' => array(
          'module' => 'block',
          'delta' => 771,
          'region' => 'content_bottom',
          'weight' => '-4',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-286' => array(
          'module' => 'block',
          'delta' => 286,
          'region' => 'sidebar_first_lower',
          'weight' => '-10',
        ),
        'block-651' => array(
          'module' => 'block',
          'delta' => 651,
          'region' => 'sidebar_first_lower',
          'weight' => '-9',
        ),
        'block-821' => array(
          'module' => 'block',
          'delta' => 821,
          'region' => 'sidebar_first_lower',
          'weight' => '-8',
        ),
        'block-296' => array(
          'module' => 'block',
          'delta' => 296,
          'region' => 'sidebar_first_lower',
          'weight' => '-7',
        ),
        'block-486' => array(
          'module' => 'block',
          'delta' => 486,
          'region' => 'sidebar_first_lower',
          'weight' => '-6',
        ),
        'block-591' => array(
          'module' => 'block',
          'delta' => 591,
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-706' => array(
          'module' => 'block',
          'delta' => 706,
          'region' => 'sidebar_second_lower',
          'weight' => '-10',
        ),
        'block-756' => array(
          'module' => 'block',
          'delta' => 756,
          'region' => 'sidebar_second_lower',
          'weight' => '-9',
        ),
        'block-806' => array(
          'module' => 'block',
          'delta' => 806,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-631' => array(
          'module' => 'block',
          'delta' => 631,
          'region' => 'sidebar_second_lower',
          'weight' => '-7',
        ),
        'block-301' => array(
          'module' => 'block',
          'delta' => 301,
          'region' => 'sidebar_second_lower',
          'weight' => '-6',
        ),
        'block-826' => array(
          'module' => 'block',
          'delta' => 826,
          'region' => 'sidebar_second_lower',
          'weight' => '-5',
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
  t('Metro North Rail Road');
  $export['mnr'] = $context;

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
        'mta_megamenu-mta_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'mta_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-news_rotator-block_1' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-homepage_blocks_admin-block_1' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-811' => array(
          'module' => 'block',
          'delta' => 811,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-156' => array(
          'module' => 'block',
          'delta' => 156,
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'block-441' => array(
          'module' => 'block',
          'delta' => 441,
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => 16,
          'region' => 'content_bottom',
          'weight' => '-5',
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
        'block-546' => array(
          'module' => 'block',
          'delta' => 546,
          'region' => 'sidebar_second_lower',
          'weight' => '-10',
        ),
        'block-456' => array(
          'module' => 'block',
          'delta' => 456,
          'region' => 'sidebar_second_lower',
          'weight' => '-9',
        ),
        'block-396' => array(
          'module' => 'block',
          'delta' => 396,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-796' => array(
          'module' => 'block',
          'delta' => 796,
          'region' => 'sidebar_second_lower',
          'weight' => '-7',
        ),
        'block-721' => array(
          'module' => 'block',
          'delta' => 721,
          'region' => 'sidebar_second_lower',
          'weight' => '-6',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nyct_homepage';
  $context->description = 'New York City Transit Homepage';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'nyct' => 'nyct',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mta_megamenu-nyct_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'nyct_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'service_notice-service_notice_nyct' => array(
          'module' => 'service_notice',
          'delta' => 'service_notice_nyct',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_5' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_5',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-homepage_blocks_admin-block_2' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_2',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'block-811' => array(
          'module' => 'block',
          'delta' => 811,
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'block-231' => array(
          'module' => 'block',
          'delta' => 231,
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'block-556' => array(
          'module' => 'block',
          'delta' => 556,
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'block-461' => array(
          'module' => 'block',
          'delta' => 461,
          'region' => 'content_bottom',
          'weight' => '-5',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-456' => array(
          'module' => 'block',
          'delta' => 456,
          'region' => 'sidebar_first_lower',
          'weight' => '-10',
        ),
        'block-521' => array(
          'module' => 'block',
          'delta' => 521,
          'region' => 'sidebar_first_lower',
          'weight' => '-9',
        ),
        'block-176' => array(
          'module' => 'block',
          'delta' => 176,
          'region' => 'sidebar_first_lower',
          'weight' => '-7',
        ),
        'block-241' => array(
          'module' => 'block',
          'delta' => 241,
          'region' => 'sidebar_first_lower',
          'weight' => '-6',
        ),
        'block-516' => array(
          'module' => 'block',
          'delta' => 516,
          'region' => 'sidebar_first_lower',
          'weight' => '-5',
        ),
        'block-201' => array(
          'module' => 'block',
          'delta' => 201,
          'region' => 'sidebar_first_lower',
          'weight' => '-4',
        ),
        'block-591' => array(
          'module' => 'block',
          'delta' => 591,
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-186' => array(
          'module' => 'block',
          'delta' => 186,
          'region' => 'sidebar_second_lower',
          'weight' => '-9',
        ),
        'block-211' => array(
          'module' => 'block',
          'delta' => 211,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-816' => array(
          'module' => 'block',
          'delta' => 816,
          'region' => 'sidebar_second_lower',
          'weight' => '-7',
        ),
        'block-216' => array(
          'module' => 'block',
          'delta' => 216,
          'region' => 'sidebar_second_lower',
          'weight' => '-6',
        ),
        'block-796' => array(
          'module' => 'block',
          'delta' => 796,
          'region' => 'sidebar_second_lower',
          'weight' => '-5',
        ),
        'block-481' => array(
          'module' => 'block',
          'delta' => 481,
          'region' => 'sidebar_second_lower',
          'weight' => '-4',
        ),
        'block-226' => array(
          'module' => 'block',
          'delta' => 226,
          'region' => 'sidebar_second_lower',
          'weight' => '-3',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'footer',
          'weight' => '-10',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => 31,
          'region' => 'footer',
          'weight' => '-8',
        ),
        'google_adsense-google_adsense_horizontal' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense_horizontal',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('New York City Transit Homepage');
  $export['nyct_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sir_homepage';
  $context->description = 'SIR Homepage';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sir' => 'sir',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mta_megamenu-sir_megamenu' => array(
          'module' => 'mta_megamenu',
          'delta' => 'sir_megamenu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'service_notice-service_notice_sir' => array(
          'module' => 'service_notice',
          'delta' => 'service_notice_sir',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_rotator-block_7' => array(
          'module' => 'views',
          'delta' => 'news_rotator-block_7',
          'region' => 'content',
          'weight' => '-7',
        ),
        'block-616' => array(
          'module' => 'block',
          'delta' => 616,
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-homepage_blocks_admin-block_6' => array(
          'module' => 'views',
          'delta' => 'homepage_blocks_admin-block_6',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'servicestatus-mta-service-status' => array(
          'module' => 'servicestatus',
          'delta' => 'mta-service-status',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-626' => array(
          'module' => 'block',
          'delta' => 626,
          'region' => 'sidebar_first_lower',
          'weight' => '-10',
        ),
        'block-411' => array(
          'module' => 'block',
          'delta' => 411,
          'region' => 'sidebar_first_lower',
          'weight' => '-8',
        ),
        'tripplanner-tripplanner' => array(
          'module' => 'tripplanner',
          'delta' => 'tripplanner',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-416' => array(
          'module' => 'block',
          'delta' => 416,
          'region' => 'sidebar_second_lower',
          'weight' => '-10',
        ),
        'block-186' => array(
          'module' => 'block',
          'delta' => 186,
          'region' => 'sidebar_second_lower',
          'weight' => '-9',
        ),
        'block-641' => array(
          'module' => 'block',
          'delta' => 641,
          'region' => 'sidebar_second_lower',
          'weight' => '-8',
        ),
        'block-406' => array(
          'module' => 'block',
          'delta' => 406,
          'region' => 'sidebar_second_lower',
          'weight' => '-6',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'footer',
          'weight' => '-10',
        ),
        'google_translate-google_translate' => array(
          'module' => 'google_translate',
          'delta' => 'google_translate',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => 31,
          'region' => 'footer',
          'weight' => '-8',
        ),
        'google_adsense-google_adsense_horizontal' => array(
          'module' => 'google_adsense',
          'delta' => 'google_adsense_horizontal',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('SIR Homepage');
  $export['sir_homepage'] = $context;

  return $export;
}
