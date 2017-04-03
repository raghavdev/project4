<?php

/**
 * @file
 * Parse files from the body field.
 */

$plugin = array(
  'form' => 'mta_core_subway_icon_form',
  'callback' => 'mta_core_subway_icon_callback',
  'name' => 'Subway Icon Parser',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_subway_icon_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
      '#markup' => t("Will replace subway icon images with the appropriate custom filter tokens"),
  );
  return $form;
}

function mta_core_subway_icon_callback($result, $item_key, $element_key, &$field, $settings) {
  $line = array('1','2','3','4','5','6','7','a','b','c','d','e','f','g','j','l','m','n','q','r','s','w','z');
  for($i = 0; $i <= count($line); $i++) {
    $field = preg_replace('/<img [^>]*\/' . $line[$i] . '\.png"([^"]+)"[^>]*>/', '[' . $line[$i] . ']', $field);
  }
}
