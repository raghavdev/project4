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

							<div class="container">
							<a name="main-content"></a>

							<div class="span-ad roundCorners">
									<?php print $messages; ?>
			 				 <div id="pageTitleAreaAd">
									<?php print render($title_prefix); ?>
									<?php if ($title): ?><h1 class="title" id="page-title-ad"><?php print $title; ?></h1><?php endif; ?>
									<?php print render($title_suffix); ?>
									<?php print render($page['page_title']);?>

							</div>


									<div id="main-ad-content">


									<?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
									<?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
									<?php if ($page['sidebar_first']): ?>
										<div id="sidebar_first">
											<?php print render($page['sidebar_first']); ?>
											</div>
											<div class="span-side-ad">
										<?php endif; ?>
										<?php if (empty($page['sidebar_first'])): ?>
											<div class="span-no-side-ad">
										<?php endif;?>


									<?php print render($page['content']); ?>

									</div>
								<!-- close span-43 -->


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

                 </div>

								<!-- close span-21 last -->
						</div><!-- close container for grid -->

										<?php if ($page['sidebar_second']): ?>
										<div id="sidebar_second_ad" class="column sidebar"><div class="section roundCorners">
										<?php print render($page['sidebar_second']); ?>
										</div></div> <!-- /.section, /#sidebar_second -->
									<?php endif; ?>
		</div>
		<div id="foot-div">
		<?php print render($page['footer']);?>
		</div>

</div>



