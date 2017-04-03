<?php
/**
 * @file
 * eotf.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function eotf_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-blank_source_1-default_value';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['eotf-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '2',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['eotf-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_1-exists_regex';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'exists_regex';
  $feeds_tamper->settings = array(
    'exists_regex' => '/\\(.*\\)$/',
    'negate' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Exists Regex';
  $export['eotf-xpathparser_1-exists_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_11-strip_tags';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'strip_tags';
  $feeds_tamper->settings = array(
    'allowed_tags' => '',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Strip tags';
  $export['eotf-xpathparser_11-strip_tags'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_2-find_replace_regex';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\(.*\\)$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['eotf-xpathparser_2-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_3-trim';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '()',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['eotf-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_8-month_parse';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'month_parse';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Month Parse';
  $export['eotf-xpathparser_8-month_parse'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'eotf-xpathparser_8-strip_tags';
  $feeds_tamper->importer = 'eotf';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'strip_tags';
  $feeds_tamper->settings = array(
    'allowed_tags' => '',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Strip tags';
  $export['eotf-xpathparser_8-strip_tags'] = $feeds_tamper;

  return $export;
}
