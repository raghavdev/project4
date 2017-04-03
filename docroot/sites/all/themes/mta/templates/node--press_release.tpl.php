<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  
  <?php if ($teaser) print render($content['field_image']); ?>

  
  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $user_picture; ?>
      <?php print $submitted; ?>
      
    </div>
    
  <?php endif; ?>
  
  	<div id="press_title_region">
    						
  			<div id="press-release-date">
  			<?php print "Press Release" ?></div>
  			<div id="press-date">
  			<?php print format_date($node->created, 'custom', 'F j, Y') ?>
  			</div>
  					  						
  			<div id="press-mta-agency">
  			<?php print render($content['field_category'][0]); ?></div>
  			<div id="press-release-urgency">
  			<?php print "IMMEDIATE" ?></div>
  						
  			<div id="press-release-title" class="press-release-title">
  			<?php print $title; ?></div>
   			<div id="press-sub-title">
  			<?php print render($content['field_sub_title'][0]); ?></div>
			<div id="press-sub-title-2">
  			<?php print render($content['field_sub_title_2'][0]); ?></div>
						
			</div>

  
    <div id="press-release-body">
    <div id ="press_single_image" style="float:left"></div>
    <div id ="press_multi_image"></div>
   
    <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
     
  </div>
  
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>

	</div>

