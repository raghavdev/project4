<?php

/**
 * @file
 * Create a boolean where string exists.
 */

$plugin = array(
  'form' => 'mta_core_exists_regex_form',
  'callback' => 'mta_core_exists_regex_callback',
  'validate' => 'mta_core_exists_regex_validate',
  'name' => 'Exists Regex',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_exists_regex_form($importer, $element_key, $settings) {
  $form = array();
  $form['exists_regex'] = array(
      '#type' => 'textfield',
      '#title' => t('Exists Regex'),
      '#default_value' => isset($settings['exists_regex']) ? $settings['exists_regex'] : '',
      '#description' => t("regex to find"),
  );
  $form['negate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Negate'),
    '#default_value' => isset($settings['negate']) ? $settings['negate'] : FALSE,
    '#description' => t('If regex is found, respond with a false value'),
  );
  return $form;
}

function mta_core_exists_regex_validate(&$settings) {
  if (empty($settings['exists_regex'])) {
    form_set_error('settings][exists_regex', t('Regex must not be empty.'));
  }
}

function mta_core_exists_regex_callback($result, $item_key, $element_key, &$field, $settings) {
  ($settings['negate'] == 1) ? $negate = 1 : $negate = 0;
  (preg_match($settings['exists_regex'], $field) > 0) ? $return = 1 : $return = 0;
    if($return && $negate){
      $field = 0;
    }else if(!$return && !$negate){
      $field = 0;
    }else {
      $field = 1;
    }//*/

}
