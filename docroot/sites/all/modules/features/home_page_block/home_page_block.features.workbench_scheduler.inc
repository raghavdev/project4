<?php
/**
 * @file
 * home_page_block.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function home_page_block_workbench_scheduler_export_schedules() {
  $items = array(
    'home_page_block' => array(
      'sid' => 6,
      'name' => 'home_page_block',
      'label' => 'home page block',
      'start_state' => 'published',
      'end_state' => 'unpublished',
      'types' => array(
        0 => 'homepage_block',
      ),
    ),
  );
  return $items;
}
