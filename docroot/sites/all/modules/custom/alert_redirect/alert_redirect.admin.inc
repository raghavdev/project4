<?php

/**
 * @file
 * Administrative page callbacks for the alert_redirect module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function alert_redirect_admin_settings_form($form_state) {
  $form['mode'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site mode')
  );

  $mode = variable_get('alert_redirect_mode', ALERT_REDIRECT_MODE_JS);

  $form['mode']['alert_redirect_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Set site mode'),
    '#options' => array(
      ALERT_REDIRECT_MODE_JS => t('JS/cookie based redirect') . ' ' . t('(main site mode)'),
      ALERT_REDIRECT_MODE_BEACON => t('JS/cookie beacon') . ' ' . t('(alert site mode)'),
      ALERT_REDIRECT_MODE_HTTP => t('HTTP based redirect') . ' ' . t('(main site mode)'),
    ),
    '#default_value' => $mode,
    '#description' => t("Select the mode depending on this site's role."),
  );

  if ($mode == ALERT_REDIRECT_MODE_JS || $mode == ALERT_REDIRECT_MODE_BEACON) {
    $form['redirect'] = array(
      '#type' => 'fieldset',
      '#title' => t('Redirect settings'),
      '#description' => t('
        <b>Please note that most of these settings are exported and handled in Javascript.</b><br>
        There may be a delay with the settings propagation depending on the caching strategies used.
      '),
    );

    $form['redirect']['alert_redirect_cookie_domain'] = array(
      '#title' => t('Cookie Domain'),
      '#type' => 'textfield',
      '#default_value' => variable_get('alert_redirect_cookie_domain', ''),
      '#size' => 32,
      '#maxlength' => 32,
      '#required' => TRUE,
      '#description' =>
        t('Cookie domain to be used.') . ' ' .
        t('E.g. ".example.com" (notice the leading dot) will make cookie visible for all sub domains (*.example.com)"'),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_HTTP) {
    $form['redirect'] = array(
      '#type' => 'fieldset',
      '#title' => t('Redirect settings'),
      '#description' => t('There may be a delay with the settings propagation depending on the caching strategies used.'),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_JS || $mode == ALERT_REDIRECT_MODE_HTTP) {
    $form['redirect']['alert_redirect_redirect_enabled'] = array(
      '#title' => t('Enable redirect'),
      '#type' => 'checkbox',
      '#default_value' => variable_get('alert_redirect_redirect_enabled', 0),
      '#required' => FALSE,
      '#description' => t('Check to turn the redirect on.'),
    );

    $form['redirect']['alert_redirect_url'] = array(
      '#title' => t('Redirect URL'),
      '#type' => 'textfield',
      '#default_value' => variable_get('alert_redirect_url', ''),
      '#size' => 128,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#description' => t('URL of the alert site.'),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_JS) {
    $form['redirect']['alert_redirect_persistent'] = array(
      '#title' => t('Persistent redirect'),
      '#type' => 'checkbox',
      '#default_value' => variable_get('alert_redirect_persistent', 1),
      '#required' => FALSE,
      '#description' => t('Check to always redirect users. Otherwise redirect will be performed once.'),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_JS || $mode == ALERT_REDIRECT_MODE_HTTP) {
    // Scope settings.
    $form['redirect']['visibility'] = array(
      '#type' => 'fieldset',
      '#title' => t('Redirect scope'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['redirect']['visibility']['alert_redirect_visibility_pages'] = array(
      '#type' => 'radios',
      '#title' => t('Enable redirect on specific pages'),
      '#options' => array(
        ALERT_REDIRECT_SCOPE_NOTLISTED => t('All pages except those listed'),
        ALERT_REDIRECT_SCOPE_LISTED => t('Only the listed pages'),
      ),
      '#default_value' => variable_get('alert_redirect_visibility_pages', ALERT_REDIRECT_SCOPE_NOTLISTED),
    );

    $form['redirect']['visibility']['alert_redirect_pages'] = array(
      '#type' => 'textarea',
      '#title' => t('Pages'),
      '#default_value' => variable_get('alert_redirect_pages', ''),
      '#description' => t("
        Specify pages by using their paths. Enter one path per line.
        The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every
        personal blog. %front is the front page.",
        array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')
      ),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_JS) {
    $form['advanced'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t("It is safe to leave these settings at their default values."),
    );

    $form['advanced']['alert_redirect_cookie_expiry'] = array(
      '#title' => t('Beacon cookie expiry'),
      '#type' => 'textfield',
      '#default_value' => variable_get('alert_redirect_cookie_expiry', 1),
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t('The number of days the beacon cookie will be preserved for (default: 1)'),
    );
  }

  if ($mode == ALERT_REDIRECT_MODE_BEACON) {
    // No settings here for now.
  }

  return system_settings_form($form);
}

/**
 * Implements _form_validate().
 */
function alert_redirect_admin_settings_form_validate($form, &$form_state) {
  // Make sure we have a valid redirect URL.
  if (isset($form_state['values']['alert_redirect_url']) && !valid_url($form_state['values']['alert_redirect_url'], TRUE)) {
    form_set_error('alert_redirect_url', t('Redirect URL must be a valid absolute URL'));
  }

}
