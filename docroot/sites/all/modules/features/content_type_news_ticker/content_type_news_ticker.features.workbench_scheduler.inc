<?php
/**
 * @file
 * content_type_news_ticker.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function content_type_news_ticker_workbench_scheduler_export_schedules() {
  $items = array(
    'news_ticker_pub_sched_2' => array(
      'name' => 'news_ticker_pub_sched_2',
      'label' => 'news ticker pub schedule 2',
      'start_state' => 'published',
      'end_state' => 'unpublished',
      'types' => array(
        0 => 'news_ticker',
      ),
    ),
  );
  return $items;
}
