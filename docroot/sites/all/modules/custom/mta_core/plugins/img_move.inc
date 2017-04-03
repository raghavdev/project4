<?php

/**
 * @file
 * Parse files from the body field.
 */

require_once 'mta_core_admin.inc';

$plugin = array(
  'form' => 'mta_core_img_move_form',
  'callback' => 'mta_core_img_move_callback',
  //'validate' => 'mta_core_img_move_validate',
  'name' => 'Image mover',
  'multi' => 'skip',
  'category' => 'MTA',
);

function mta_core_img_move_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
      '#markup' => t("We look for file links and upload their contents to the server and re-write the link to its new home"),
  );
  return $form;
}

function mta_core_img_move_callback($result, $item_key, $element_key, &$field, $settings) {
  $img_start = strpos($field, '<img');
  if($img_start){
    $local_path = '/' . variable_get('file_public_path', conf_path());
    if(strpos($_SERVER["HTTP_HOST"], 'mta.info')){//the files part of the path has to be added for dev thru prod
      $local_path .= '/files';
    }
    $local_path .= '/archive/imgs/';
    $droot = DRUPAL_ROOT;
    $dir = file_default_scheme() . '://' . 'archive/imgs';
    if(!file_prepare_directory($dir, FILE_CREATE_DIRECTORY)){
      $dir = file_default_scheme() . '://';
      $test_dir = file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
      $dir = file_default_scheme() . '://' . 'archive';
      $test_dir = file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
      $dir = file_default_scheme() . '://' . 'archive/imgs';
      $test_dir = file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
    }
    unset($test_dir);
    $src_start = strpos($field, 'src="', $img_start);
    if($src_start){
      $dir_array[] = '/';
      $dir_array[] = '/images/';
       $dir_array[] = '/news/stories/';
      $dir_array[] = '/mta/news/releases/';
    }
    while($src_start){
      $src_start += 5;
      $src_end = strpos($field, '"', $src_start);
      $src = substr($field, $src_start, $src_end - $src_start);
      $src_img_file = pathinfo($src);
      $img_file = fopen($droot . $local_path . str_replace(' ', '_', $src_img_file['basename']),'w');
      $src_enc = str_replace(' ', '%20', $src);
      foreach($dir_array as $temp_dir){
        $test_dir = 'http://mta.info' . $temp_dir . $src_enc;
        if(remoteFileExists($test_dir)){
          $good_url = $test_dir;
        }
      }
      $options = array(
          CURLOPT_FILE => $img_file,
          CURLOPT_FOLLOWLOCATION => true,
          CURLOPT_URL => $good_url,

      );
      $ch = curl_init();
      curl_setopt_array($ch, $options);
      $cresult = curl_exec($ch);
      $img_info = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
      curl_close($ch);
      $dest = $local_path . str_replace(' ', '_', $src_img_file['basename']);
      fclose($img_file);
      $new_file = $droot . $dest;
      if(file_exists($new_file) && filesize($new_file) == 0){
        unlink($new_file);
      }//*/
      $field = str_replace($src, $dest, $field);
      $img_start = strpos($field, '<img', $src_end);
      $img_start ? $src_start = strpos($field, 'src="', $img_start) : $src_start = FALSE;
    }
  }
}



