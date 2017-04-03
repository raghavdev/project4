<?php

/**
 * @file
 * Cacheflush Cloner include.
 */

/**
 * Callback function after drupal_get_form().
 */
function cacheflush_combine_preset_form($form, &$form_state, $preset_id = NULL) {

  $list = array();
  // Get the preset list.
  $form_state['cacheflush_preset_list'] = $cache_presets = variable_get('cacheflush_preset_list', array());
  ($preset_id) ? ($form_state['preset_id'] = $preset_id) : NULL;
  foreach ($cache_presets as $key => $value) {
    $list[$key] = $value['#name'];
  }

  // Form element for preset name.
  $form['cacheflush_preset_name'] = array(
    '#type' => "textfield",
    '#title' => t('Preset Name'),
    '#weight' => 0,
    '#required' => TRUE,
    '#default_value' => ($preset_id) ? $cache_presets[$preset_id]['#name'] : '',
  );
  // Form element for presets list.
  $form['selected'] = array(
    '#type' => 'select',
    '#title' => t('Presets'),
    '#options' => $list,
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#default_value' => ($preset_id) ? $cache_presets[$preset_id]['#parent_ids'] : array(),
  );
  // Form element for updating presets.
  $form['checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update'),
    '#default_value' => ($preset_id && isset($cache_presets[$preset_id]['#live'])) ? $cache_presets[$preset_id]['#live'] : FALSE,
    '#description' => t('"TRUE" - At cache clear will use the parent(s) current configuration.<br />
      "FALSE" - At cache clear will use the parent(s) configuration from the creation time.'),
  );

  // Form element Submit button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => ($preset_id) ? t('Update') : t('Create'),
  );

  // Form element Cancel button.
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/config/development/cacheflush'),
  );

  return $form;
}

/**
 * Implements hook_formID_submit().
 */
function cacheflush_combine_preset_form_submit($form, &$form_state) {

  if (isset($form_state['preset_id'])) {
    $preset_id = $form_state['preset_id'];
  }
  else {
    $preset_id = max(array_keys($form_state['cacheflush_preset_list'])) + 1;
  }

  $form_state['cacheflush_preset_list'][$preset_id] = array(
    '#name' => $form_state['values']['cacheflush_preset_name'],
    '#cacheflush_preset_values' => array(),
    '#enabled' => $preset_id,
    '#combined' => TRUE,
  );

  foreach ($form_state['values']['selected'] as $key => $value) {

    $form_state['cacheflush_preset_list'][$preset_id]['#combined'] = TRUE;
    $form_state['cacheflush_preset_list'][$preset_id]['#parent_ids'][] = $key;

    if ($form_state['values']['checkbox'] == 1) {
      $form_state['cacheflush_preset_list'][$preset_id]['#cacheflush_preset_values']["cloned_$preset_id"]['functions'][$key] = "_cacheflush_clear_preset";
      $form_state['cacheflush_preset_list'][$preset_id]['#cacheflush_preset_values']["cloned_$preset_id"]['params'][$key] = array($key);
      $form_state['cacheflush_preset_list'][$preset_id]['#cacheflush_preset_values']["cloned_$preset_id"]['is_table'] = FALSE;
      $form_state['cacheflush_preset_list'][$preset_id]['#live'] = TRUE;
    }
    else {
      $form_state['cacheflush_preset_list'][$preset_id]['#cacheflush_preset_values'] += $form_state['cacheflush_preset_list'][$key]['#cacheflush_preset_values'];
    }
  }

  variable_set('cacheflush_preset_list', $form_state['cacheflush_preset_list']);
  drupal_set_message(t("@name preset saved.", array('@name' => $form_state['values']['cacheflush_preset_name'])));

  // Rebuild Menu.
  node_types_rebuild();
  menu_rebuild();
}
