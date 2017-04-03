<?php

/**
 * @file
 * Parse a month/year for SolicationMonth date.
 */

$plugin = array(
  'form' => 'mta_core_month_parse_form',
  'callback' => 'mta_core_month_parse_callback',
  'name' => 'Month Parse',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_month_parse_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
      '#markup' => t('This will take 2 strings containing Month/Year format and convert it into a single date field.')
  );
  return $form;
}

function mta_core_month_parse_callback($result, $item_key, $element_key, &$field, $settings) {
  $format = 'MY';
  $date = DateTime::createFromFormat($format, $field);
  dsm($field);
  $field = $date->format('m/Y');
}
