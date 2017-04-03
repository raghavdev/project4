<?php

/**
 * @file
 * Parse mta agencies.
 */

$plugin = array(
  'form' => 'mta_core_mta_agency_form',
  'callback' => 'mta_core_mta_agency_callback',
  'name' => 'MTA Agency re-format',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_mta_agency_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
      '#markup' => t("We look for mta agency codes in the XML and reformat them"),
  );
  return $form;
}

function mta_core_mta_agency_callback($result, $item_key, $element_key, &$field, $settings) {
  if(!empty($field)) {
    if($field == 'hq'){
      $agency = 'MTA HQ';
    }elseif($field == 'nyct'){
      $agency = 'NYCT';
    }elseif($field == 'bandt'){
      $agency = 'B & T';
    }elseif($field == 'lirr'){
      $agency = 'LIRR';
    }elseif($field == 'mnr'){
      $agency = 'MNR';
    }
  }
  $field = $agency;
}
