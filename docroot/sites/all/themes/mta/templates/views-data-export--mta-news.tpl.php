<?php print "<?xmlns"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<news>
<?php foreach ($themed_rows as $count => $row): ?>
  <story>
<?php foreach ($row as $field => $content): ?>
    <<?php print $xml_tag[$field]; ?>><?php print $content; ?></<?php print $xml_tag[$field]; ?>>
<?php endforeach; ?>
  </story>
<?php endforeach; ?>
</news>