<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>

<div id="eotf">
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
      <?php endif; ?>
 

  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <class="<?php print $classes_array[$id]; ?>"><?php print $row; ?>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
</div>


     