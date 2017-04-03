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
			
			<a name="main-content"></a>
			
			<div id="contentbox" class="clearfix">
							<div class="container">
								<div class="span-94">									
									<div id="messages"> <?php print $messages; ?> </div>
									
      		    																
									<?php if ($page['sidebar_first']): ?>
										<div id="sidebar_first" class="span-23">
											<?php print render($page['sidebar_first']); ?>
																					
									<?php print render($page['sidebar_first_lower']); ?>	
									<div id="sidebar_first_lower" class="sidebar_first_lower">
												</div>
													</div>																										
										<?php endif; ?>

								
								
								<?php 
										print'<div id="main-message" class="span-46">';

								?>

									
									<?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
									<?php print render($page['content']); ?>
																					
										<div id="content_bottom" class="content_bottom">
									<?php print render($page['content_bottom']); ?>
											<div id="contentbl" class="bl">
									<?php print render($page['content_bottom_left']); ?>
											</div>	
										<div id ="contentbr" class="br">
									<?php print render($page['content_bottom_right']); ?>
											</div>
										<div id="postscript" class="postscript">
									 <?php print render($page['postscript']); ?>
									 		</div>
									 <div id="postscript_left" class="pl">
									<?php print render($page['postscript_left']); ?>
											</div>
										<div id ="postscript_right" class="pr">			
									<?php print render($page['postscript_right']); ?>
											</div>
												</div>	
									 				</div>			
								<!-- close span-43 -->

							
									<?php if ($page['sidebar_second']): ?>
										<div id="sidebar_second" class="column sidebar"><div class="section">
										<?php print render($page['sidebar_second']); ?>
										</div> <!-- /.section, /#sidebar_second -->
									
									<?php print render($page['sidebar_second_lower']); ?>
									<div id="sidebar_second_lower" class="column sidebar><div class="section">
										</div>
											</div>
												
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
