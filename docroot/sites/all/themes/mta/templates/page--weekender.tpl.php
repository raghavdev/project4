		
		
		<?php 		
drupal_add_js("sites/all/libraries/weekender/weekendstatus.js");
drupal_add_js("sites/all/libraries/weekender/LinesStaticData.js");
drupal_add_js("sites/all/libraries/weekender/neighborhoodScript.js");
drupal_add_js("sites/all/libraries/weekender/date.js");
drupal_add_js("sites/all/libraries/weekender/WeekenderMain.js");
drupal_add_js("sites/all/libraries/weekender/SystemWideMapScriptTiles.js");
drupal_add_js("sites/all/libraries/weekender/lineView.js");
$scripts = drupal_get_js();

?>		
		
<div id="page">

		<div id="mainbox" style="width:960px;">
						
				<div id="weekender_branding">
				<div id="weekender_banner" style="margin-top:10px;"> 
 				<div id="bannerWhiteLine " style="top:9px; height:1px; background-color:white; overflow:hidden;"></div>
			
					<div id = "weekender_topbar_left">
 <img name="status" id="status" src="sites/all/themes/mta/images/weekender/status.png" style="cursor:pointer; position:absolute; top:11px; left:15px; height:17px;" border="0" alt="" onmouseover="menuImageOver('status')" onmouseout="menuImageOut('status')" onclick="window.location.href = 'servicestatus.html';"/>
 <img name="station" id="station" src="sites/all/themes/mta/images/weekender/station.png" style="cursor:pointer; position:absolute; top:28px; left:15px; width:120px; height:17px;" border="0" alt="" onmouseover="menuImageOver('station')" onmouseout="menuImageOut('station')" onclick="window.location.href = 'stationview.html';"/>
 <img name="line" id="line" src="sites/all/themes/mta/images/weekender/line.png" style="cursor:pointer; position:absolute; top:45px; left:15px; width:101px; height:17px;" border="0" alt="" onmouseover="menuImageOver('line')" onmouseout="menuImageOut('line')"  onclick="window.location.href = 'http://mta.info/weekender/lineview.html';"/>
 <img name="borough" id="borough" src="sites/all/themes/mta/images/weekender/borough.png" style="cursor:pointer; position:absolute; top:62px; left:15px; height:17px;" border="0" alt="" onmouseover="menuImageOver('borough')"  onmouseout="menuImageOut('borough')"  onclick="window.location.href = 'boroughview.html';"/>
 <a href="http://tripplanner.mta.info/" target="_blank"><img name="planner" id="planner" src="sites/all/themes/mta/images/weekender/planner.png" style="cursor:pointer; position:absolute; top:11px; left:165px; height:17px;" border="0" alt="" onmouseover="menuImageOver('planner')"  onmouseout="menuImageOut('planner')" /></a>
 <a href="http://mta.info/mnr/" target="_blank"><img name="metronorth" id="metronorth" src="sites/all/themes/mta/images/weekender/metro_north.png" style="cursor:pointer; position:absolute; top:28px; left:210px; height:17px;" border="0" alt=""   onmouseover="menuImageOver('metronorth')" onmouseout="menuImageOut('metronorth')"/></a>
 <a href="http://mta.info/lirr/" target="_blank"><img name="lirr" id="lirr" src="sites/all/themes/mta/images/weekender/lirr.png" style="cursor:pointer; position:absolute; top:28px; left:165px; height:17px;" border="0" alt="" onmouseover="menuImageOver('lirr')" onmouseout="menuImageOut('lirr')" /></a><img src="sites/all/themes/mta/images/weekender/slash.gif" width="10" height="17" alt="" style="cursor:pointer; position:absolute; top:28px; left:200px; height:17px;" />
 <a href="http://mta.info/nyct/" target="_blank"><img name="buses" id="buses" src="sites/all/themes/mta/images/weekender/buses.png" style="cursor:pointer; position:absolute; top:45px; left:165px; height:17px;" border="0" alt="" onmouseover="menuImageOver('buses')" onmouseout="menuImageOut('buses')" /></a>
 <a href="http://mta.info/bandt/" target="_blank"><img name="bridges" id="bridges" src="sites/all/themes/mta/images/weekender/bridges.png" style="cursor:pointer; position:absolute; top:62px; left:165px; height:17px;" border="0" alt="" onmouseover="menuImageOver('bridges')" onmouseout="menuImageOut('bridges')"/></a>
 <img name="diagram" id="diagram" src="sites/all/themes/mta/images/weekender/diagram.png" style="cursor:pointer; position:absolute; top:62px; left:330px;" border="0" alt="" onmouseover="menuImageOver('diagram')" onclick="window.location.href = 'subwaydiagram.html';"/>
 <img name="zoom_out" id="zoom_out" src="sites/all/themes/mta/images/weekender/zoom_out.png" style="display:none;cursor:pointer; position:absolute; top:62px; left:450px;" border="0" alt="" onmouseover="menuImageOver('zoom_out')" onmouseout="menuImageOut('zoom_out')" onclick="zoomOut();"/>
 <img name="zoom_in" id="zoom_in" src="sites/all/themes/mta/images/weekender/zoom_in.png" style="display:none;cursor:pointer; position:absolute; top:62px; left:470px;" border="0" alt="" onmouseover="menuImageOver('zoom_in')" onmouseout="menuImageOut('zoom_in')" onclick="zoomIn();"/>
 <img name="drawer" id="drawer" src="sites/all/themes/mta/images/weekender/drawer.png" style="display:none;cursor:pointer; position:absolute; top:62px; left:490px;" border="0" alt="" onmouseover="menuImageOver('drawer')" onmouseout="menuImageOut('drawer')" onclick="ShowHide('weekenderleftPanel');"/>
 
					
					</div>
					<div id = "weekender_topbar_center"> 
					<a href="http://www.mta.info"><img src="<?php print $base_path ?>sites/all/themes/mta/images/weekender/home.png"></a>
					</div>
					
					<div id = "weekender_topbar_right">
					<a href="/mta" target="_blank"><img  src="sites/all/themes/mta/images/weekender/mta_logo.png" style="cursor:pointer; position:absolute; top:11px; left:910px;" border="0" alt="" onmouseover="menuImageOver('mtainfo')" onmouseout="menuImageOut('mtainfo')"/> </a>
 					<a href="/mta" target="_blank"><img name="mtahome" id="mtahome" src="sites/all/themes/mta/images/weekender/mta_home.png" style="cursor:pointer; position:absolute; top:62px; left:870px;" border="0" alt="" onmouseover="menuImageOver('mtahome')" onmouseout="menuImageOut('mtahome')"/> </a>
					
					</div>
					</div>
					
				
			
			
			<div id="weekender_contentbox">
							<div class="container">
								<div class="span-90">									
									<?php print $messages; ?>
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
								

									<a id="main-content"></a>

									
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
			
	
	
	
    
  <!-- Weekender Footer (start) -->
<div  style="position:absolute; top:714px; width:898px; margin-left:21px; height:20px; background-color:black;">
    <img name="legend" id="legend" style="position:absolute;cursor:pointer;left:15px;top:0px;margin:0px;" src="/sites/all/themes/mta/images/weekender/legend.png" onclick="EnableLegend();" onmouseover="menuImageOver('legend')" onmouseout="menuImageOut('legend')" border="0" alt="" />
	<a href="http://www.youtube.com/watch?v=c30CwkKyTYQ" target="_blank">
<img name="video" id="video" style="position:absolute;cursor:pointer;left:165px;top:0px;margin:0px;" src="/sites/all/themes/mta/images/weekender/tutorial.gif" onmouseover="menuImageOver('video')" onmouseout="menuImageOut('video')"  border="0" alt="" />
</a>

    <div id="FooterCenterSection" style="position:absolute;left:330px;">
        <span id="dateSpan" class="footerDateText"><script language="javascript" type="text/javascript">document.write(getWeekendDates());</script></span>
    </div> 
    <div id="FooterRightSection" style="position:absolute;left:500px;width:350px;" class="footerTellUsText">
        <span><a href="http://mta-nyc8.custhelp.com/cgi-bin/mta_nyc8.cfg/php/enduser/ask.php?&p_prods=4005&prod_lvl1=4005&p_cats=4006" class="footerTellUsText" target="_blank">Tell us what you think</a></span>
    </div>  
    </div>  
   
    
	
		<?php print render($page['footer']);?>	
</div>
