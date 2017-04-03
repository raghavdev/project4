
(function ($) {

/**
 * Provide summary information for vertical tabs.
 */
Drupal.behaviors.nodequeue_scheduler_settings = {
  attach: function (context) {
  // Provide summary when editting a node.
  $('fieldset#edit-nodequeue-scheduler-settings', context).drupalSetSummary(function(context) {
      var value = '';
      if ($('#edit-nodequeue-scheduler-settings input:checkbox]:checked').val() && $('#edit-nodequeue-publish-on-datepicker-popup-0').val()) {
        value = Drupal.t('Scheduled for publishing');
      }
      if (!value.length) {
        value = Drupal.t('Not scheduled');
      }
      return value;
    });
  }
};

})(jQuery);
