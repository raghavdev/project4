<?php
/**
 * @file
 * content_type_news_story.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function content_type_news_story_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: content administrator.
  $roles['content administrator'] = array(
    'name' => 'content administrator',
    'weight' => 5,
  );

  // Exported role: content creator.
  $roles['content creator'] = array(
    'name' => 'content creator',
    'weight' => 6,
  );

  // Exported role: content provider.
  $roles['content provider'] = array(
    'name' => 'content provider',
    'weight' => 3,
  );

  return $roles;
}
