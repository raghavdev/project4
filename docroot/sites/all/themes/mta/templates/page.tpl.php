<div id="page">
		<div id="mainbox">

			<div id="topbar">
				<div id="branding">
					<a href="http://www.mta.info"><img src="<?php print $base_path ?>sites/all/themes/mta/images/mta_info.gif" alt="Metropolitan Transportation Authority logo"></a>
				</div>
				<div id="middle-header">
				<?php print render($page['header_middle']); ?>
				</div>
				<div id="search">

			<?php print render($page['header_right']); ?>

				</div>
			 </div>
			<div id="navbar"><?php print render($page['navbar']);?></div>
			<div id="breadcrumb"> <!-- we leave the div and keep spacing -->
								<?php //if ($breadcrumb){print $breadcrumb;}?>
			</div>
			<div id="contentbox" class="roundCorners clearfix">
							<div class="container">
								<div class="span-90">
									<?php print $messages; ?>
			 				 <div id="pageTitleArea">
			 				 		
									<?php print render($title_prefix); ?>
									<?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
									<?php print render($title_suffix); ?>
									<?php print render($page['page_title']);?>
									<?php print $feed_icons; ?>

							</div>
							
							<a name="main-content"></a>
							
									<?php if ($page['sidebar_first']): ?>
										<div id="sidebar_first">
											<?php print render($page['sidebar_first']); ?>
											</div>
										<?php endif; ?>


								<?php if ($page['sidebar_first'] && $page['sidebar_second']) {
										print'<div id="main-message" class="span-43 small-main">';
								} elseif ($page['sidebar_first'] || $page['sidebar_second']){
										print'<div id="main-message" class="span-43 mid-main">';
								} else {
										print'<div id="main-message" class="span-43 full-main">';
								}
								?>

									<?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
									<?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
									<?php print render($page['content']); ?>
								</div><!-- close span-43 -->


									<?php if ($page['sidebar_second']): ?>
										<div id="sidebar_second" class="column sidebar"><div class="section">
										<?php print render($page['sidebar_second']); ?>
										</div></div> <!-- /.section, /#sidebar_second -->
									<?php endif; ?>

										<?php if ($page['help']): ?>
										<div id="help" class="column sidebar"><div class="section">
										<?php print render($page['help']); ?>
										</div></div> <!-- /.section, /#help -->
									<?php endif; ?>

									<?php if ($page['highlighted']): ?>
										<div id="highlighted" class="column sidebar" style="padding-top: 10px; border-top: 1px solid black;"><div class="section">
										<?php print render($page['highlighted']); ?>
										</div></div> <!-- /.section, /#highlighted-->
									<?php endif; ?>



								<!-- close span-21 last -->
						</div><!-- close container for grid -->
			</div>

	</div>
		<?php print render($page['footer']);?>
		
</div>
