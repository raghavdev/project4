<?php
/**
 * @file
 * home_page_block.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function home_page_block_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'create homepage_block content'.
  $permissions['create homepage_block content'] = array(
    'name' => 'create homepage_block content',
    'roles' => array(
      'agency user' => 'agency user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own homepage_block content'.
  $permissions['delete own homepage_block content'] = array(
    'name' => 'delete own homepage_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own homepage_block content'.
  $permissions['edit own homepage_block content'] = array(
    'name' => 'edit own homepage_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'set workbench schedule'.
  $permissions['set workbench schedule'] = array(
    'name' => 'set workbench schedule',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
    ),
    'module' => 'workbench_scheduler',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Survey Master' => 'Survey Master',
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
      'content administrator' => 'content administrator',
      'content creator' => 'content creator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'agency user' => 'agency user',
      'content administrator' => 'content administrator',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
