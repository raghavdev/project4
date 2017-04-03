<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($teaser) print render($content['field_image']); ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted" style="color:gray; font-style: italic; padding-left:8px;">
      <?php print $user_picture; ?>
      <?php 
      if ($submitted) {
      	echo " " . date( "F dS, Y",$node->created);
      }       ?>
      
    </div>
  <?php endif; ?>
<?php print render($content['links']); ?>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      print $node->field_article_body['und'][0]['value'];
    ?>
  </div>

  

  <?php print render($content['comments']); ?>

</div>
