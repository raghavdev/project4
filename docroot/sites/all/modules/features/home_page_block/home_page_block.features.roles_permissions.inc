<?php
/**
 * @file
 * home_page_block.features.roles_permissions.inc
 */

/**
 * Implements hook_default_roles_permissions().
 */
function home_page_block_default_roles_permissions() {
  $roles = array();

  // Exported role: agency user
  $roles['agency user'] = array(
    'name' => 'agency user',
    'weight' => 7,
    'permissions' => array(
      'access content overview' => TRUE,
      'access toolbar' => TRUE,
      'access workbench' => TRUE,
      'access workbench access by role' => TRUE,
      'batch update workbench access' => TRUE,
      'create homepage_block content' => TRUE,
      'delete revisions' => TRUE,
      'edit any homepage_block content' => TRUE,
      'moderate content from draft to needs_review' => TRUE,
      'set workbench schedule' => TRUE,
      'use text format filtered_html' => TRUE,
      'use text format full_html' => TRUE,
      'use workbench_moderation my drafts tab' => TRUE,
      'use workbench_moderation needs review tab' => TRUE,
      'view all unpublished content' => TRUE,
      'view moderation messages' => TRUE,
      'view own unpublished content' => TRUE,
      'view revisions' => TRUE,
      'view workbench access information' => TRUE,
      'view workbench taxonomy pages' => TRUE,
    ),
  );

  return $roles;
}
