<?php
/**
 * @file
 * home_page_block.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function home_page_block_user_default_roles() {
  $roles = array();

  // Exported role: agency user.
  $roles['agency user'] = array(
    'name' => 'agency user',
    'weight' => 7,
  );

  return $roles;
}
