<?php

/**
 * @file
 * Parse a date for published date.
 */

$plugin = array(
  'form' => 'mta_core_date_parse_form',
  'callback' => 'mta_core_date_parse_callback',
/*  'validate' => 'mta_core_date_parse_validate',*/
  'name' => 'Date Parse',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_date_parse_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
      '#markup' => t("We look for dates and import them from the ymd format provided in the XML"),
  );
/*  $form['date_format'] = array(
      '#type' => 'textfield',
      '#title' => t('Date Format'),
      '#default_value' => isset($settings['date_format']) ? $settings['date_format'] : '',
      '#description' => t("The formating of the incoming date string, i.e. mdy, as per " . l('Php.net', 'http://us.php.net/manual/en/function.date.php') . ".
          It's especially useful if the incoming date isn't in an English date format."),
  );//*/
  return $form;
}
/*
function mta_core_date_parse_validate(&$settings) {
  if (empty($settings['date_format'])) {
    form_set_error('settings][date_format', t('Date format must not be empty.'));
  }
}//*/

function mta_core_date_parse_callback($result, $item_key, $element_key, &$field, $settings) {
  $format = 'ymd H:i:s';
  if(!empty($field)) {
    $tmp_date = str_split($field, 2);
    if($tmp_date[0] >= 90){
      $date_tmp = $tmp_date[1] . '/' . $tmp_date[2] . '/19' . $tmp_date[0];
    }else {
      $date_tmp = $tmp_date[1] . '/' . $tmp_date[2] . '/20' . $tmp_date[0];
    }
    $date = new DateTime($date_tmp . ' 11:00:00');
  } else {
    $date = new DateTime('02/01/2010 11:00:00');
  }
  $field = $date->format('Y-m-d H:i:s');
}
