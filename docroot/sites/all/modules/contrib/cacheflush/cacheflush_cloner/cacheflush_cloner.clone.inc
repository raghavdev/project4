<?php

/**
 * @file
 * Cacheflush Cloner include.
 */

/**
 * Callback function after drupal_get_form().
 */
function cacheflush_cloner_presets_clone($form, &$form_state, $preset_id) {

  // Form element for preset name.
  $form['cacheflush_preset_name'] = array(
    '#type' => "textfield",
    '#title' => t('Preset Name'),
    '#weight' => 0,
    '#required' => TRUE,
  );

  // Form element Submit button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create'),
  );

  $form_state['preset_id'] = $preset_id;

  return $form;
}

/**
 * Implements hook_formID_submit().
 */
function cacheflush_cloner_presets_clone_submit($form, $form_state) {

  $cache_presets = variable_get('cacheflush_preset_list', array());
  $new_id = max(array_keys($cache_presets)) + 1;
  $cache_presets[$new_id] = $cache_presets[$form_state['preset_id']];
  $cache_presets[$new_id]['#name'] = $form_state['values']['cacheflush_preset_name'];
  variable_set('cacheflush_preset_list', $cache_presets);
  drupal_set_message(t("@name preset cloned.", array('@name' => $form_state['values']['cacheflush_preset_name'])));
  drupal_goto('admin/config/development/cacheflush');
}
