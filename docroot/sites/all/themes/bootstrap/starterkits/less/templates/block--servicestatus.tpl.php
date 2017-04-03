<?php
/**
 * @file
 * Zen theme's implementation to display a block.
 *
 * Available variables:
 * - $title: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be "block-user".
 *   - first: The first block in the region.
 *   - last: The last block in the region.
 *   - odd: An odd-numbered block in the region's list of blocks.
 *   - even: An even-numbered block in the region's list of blocks.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see zen_preprocess_block()
 * @see template_process()
 * @see zen_process_block()
 */
?>

<?php 
    global $base_url;
    $transparent_img = $base_url.'/'.drupal_get_path('module','servicestatus').'/images/img_trans.gif';
    $script_path = $base_url.'/'.drupal_get_path('module','servicestatus').'/ss.js';
?>

<script type="text/javascript" src="<?php echo $script_path; ?>"></script>

<div id="<?php print $block_html_id; ?>" class="roundCorners featurebox">

    <span class="span-12"><h2>Service Status</h2></span>
    <span class="statusDateTime"><?php /*print $timestamp;*/ ?></span>
	<div id = "statusblock-tabs">
    <ul>
        <li class="t tdiv selectedStatusTab" id="subwayTab">Subway</li>
        <li class="t tdiv notselectedStatusTab" id="railTab">Rail</li>
        <li class="t tdiv notselectedStatusTab" id="busTab">Bus</li>
        <li class="t tlast tdiv notselectedStatusTab" id="bntTab">Bridges &amp; Tunnels</li>
    </ul>
	</div>
    <div class="content"<?php print $content_attributes; ?> style="clear:both;">

        

        <div id="subwayDiv" style="float: left; margin-top: 1px;">
            <ul style="float: right; padding:0; margin:0">
                <!-- <li class="gw list_h" onClick="window.parent.location=\'http://mta.info/weekender\'">The Weekender</li> -->
                <li class="gw list_h"><a style="color: #555;" href="http://web.mta.info/weekender.html">The Weekender</a></li>
                <li class="gw list_h"><a style="color: #555;" href="http://travel.mtanyct.info/serviceadvisory">Future Date</a></li>
            </ul>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img src="<?php echo $transparent_img; ?>" class="subwayIcon_123" alt="1 2 3 Subway"/></div>
                <div style="margin-top: 4px;" id="123" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_456" alt="4 5 6 Subway"/></div>
                <div style="margin-top: 4px;" id="456" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_7" alt="7 Subway"/></div>
                <div style="margin-top: 4px;" id="7" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_ACE" alt="A C E Subway"/></div>
                <div style="margin-top: 4px;" id="ACE" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_BDFM" alt="B D F M Subway"/></div>
                <div style="margin-top: 4px;" id="BDFM" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_G" alt="G Subway"/></div>
                <div style="margin-top: 4px;" id="G" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_JZ" alt="J Z Subway"/></div>
                <div style="margin-top: 4px;" id="JZ" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_L" alt="L Subway"/></div>
                <div style="margin-top: 4px;" id="L" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_NQR" alt="N Q R Subway"/></div>
                <div style="margin-top: 4px;" id="NQR" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_S" alt="S Subway"/></div>
                <div style="margin-top: 4px;" id="S" class="subwayCategory"></div>
            </div>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 4px 0;">
                <div class="span-11"><img width="1" height="1" src="<?php echo $transparent_img; ?>" class="subwayIcon_SIR" alt="Staten Island Railway"/></div>
                <div style="margin-top: 4px;" id="SIR" class="subwayCategory"></div>
            </div>
        </div>
        <!-- End of Subway -->

        <!-- Rail Div -->
        <div id="railDiv" style="float: left; display: none;">
            <span class="RailRoadCompany">Long Island Rail Road</span>
            <ul style="float: right; padding:0; margin:0">
                <li class="gw list_h"><a style="color: #555;" href="http://web.mta.info/lirr/News/PlannedService.htm">Future Date</a></li>
            </ul>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare2"></div>
                <div class="span-11 railLineItem">Babylon</div>
                <div id="Babylon" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare1"></div>
                <div class="span-11 railLineItem">City Terminal Zone</div>
                <div id="CityTerminalZone" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare3"></div>
                <div class="span-11 railLineItem">Far Rockaway</div>
                <div id="FarRockaway" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare4"></div>
                <div class="span-11 railLineItem">Hempstead</div>
                <div id="Hempstead" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare5"></div>
                <div class="span-11 railLineItem">Long Beach</div>
                <div id="LongBeach" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare6"></div>
                <div class="span-11 railLineItem">Montauk</div>
                <div id="Montauk" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare7"></div>
                <div class="span-11 railLineItem">Oyster Bay</div>
                <div id="OysterBay" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare8"></div>
                <div class="span-11 railLineItem">Port Jefferson</div>
                <div id="PortJefferson" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare9"></div>
                <div class="span-11 railLineItem">Port Washington</div>
                <div id="PortWashington" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare10"></div>
                <div class="span-11 railLineItem">Ronkonkoma</div>
                <div id="Ronkonkoma" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare11"></div>
                <div class="span-11 railLineItem">West Hempstead</div>
                <div id="WestHempstead" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 100%;"><span class="RailRoadCompany">Metro-North Railroad</span>
                <ul style="float: right; padding:0; margin:0">
                    <li class="gw list_h"><a style="color: #555;" href="http://web.mta.info/mnr/html/serviceupdates.htm">Future Date</a></li>
                </ul>
            </div>


            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare12"></div>
                <div class="span-11 railLineItem">Hudson</div>
                <div id="Hudson" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare13"></div>
                <div class="span-11 railLineItem">Harlem</div>
                <div id="Harlem" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus"></div>
                <div style="margin-left: 10px;" class="span-10 railLineItem">Wassaic</div>
                <div id="Wassaic" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare15"></div>
                <div class="span-11 railLineItem">New Haven</div>
                <div id="NewHaven" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus"></div>
                <div style="margin-left: 10px;" class="span-10 railLineItem">New Canaan</div>
                <div id="NewCanaan" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus"></div>
                <div style="margin-left: 10px;" class="span-10 railLineItem">Danbury</div>
                <div id="Danbury" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus"></div>
                <div style="margin-left: 10px;" class="span-10 railLineItem">Waterbury</div>
                <div id="Waterbury" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare19"></div>
                <div class="span-11 railLineItem">Pascack Valley</div>
                <div id="PascackValley" class="railStation railCategory"></div>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 1px 0;">
                <div class="railLineStatus" id="railSquare20"></div>
                <div class="span-11 railLineItem">Port Jervis</div>
                <div id="PortJervis" class="railStation railCategory"></div>
            </div>
        </div>
        <!-- End of Rail -->

        <!-- Bus -->
        <div id="busDiv" style="float: left; display: none; margin-top: 11px;">
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                    <span class="span-11 busLineItem">B1 - B84</span>
                    <span id="B1-B84" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">B100 - B103</span>
                <span id="B100-B103" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">BM1 - BM5</span>
                <span id="BM1-BM5" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">BX1 - BX46</span>
                <span id="BX1-BX55" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">BXM1 - BXM18</span>
                <span id="BXM1-BXM18" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">M1 - M116</span>
                <span id="M1-M116" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">Q1 - Q114</span>
                <span id="Q1-Q113" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">QM1 - QM44</span>
                <span id="QM1-QM44" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">S40 - S98</span>
                <span id="S40-S98" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 9px 0;">
                <span class="span-11 busLineItem">x1 - x68</span>
                <span id="x1-x68" class="busCategory"></span>
            </div>
        </div>
        <!-- End of Bus -->

        <!-- Bridges & Tunnels -->
        <div id="bntDiv" style="float: left; display: none; margin-top: 12px;">
            <ul style="float: right; padding:0; margin:0">
                <li class="gw list_h"><a style="color: #555;" href="http://mta.info/bandt/traffic">Future Date</a></li>
            </ul>

            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Throgs Neck</span>
                <span id="ThrogsNeck" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Henry Hudson</span>
                <span id="HenryHudson" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Marine Parkway</span>
                <span id="MarineParkway" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Bronx-Whitestone</span>
                <span id="Bronx-Whitestone" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Hugh L. Carey</span>
                <span id="HughLCarey" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Queens Midtown</span>
                <span id="QueensMidtown" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Robert F. Kennedy</span>
                <span id="RobertFKennedy" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Cross Bay</span>
                <span id="CrossBay" class="busCategory"></span>
            </div>
            <div style="float: left; width: 220px; border-bottom: 1px solid #7B7B98; padding: 10px 0;">
                <span class="span-11 busLineItem">Verrazano-Narrows</span>
                <span id="Verrazano-Narrows" class="busCategory"></span>
            </div>
        </div>

        <?php //print $content; ?>
    </div>
    <div id="bottom-status-box-links">
    <ul>
        <li class="list_h"><a class="gw" target="_top" href="http://web.mta.info/mta/eles.html">Elevator &amp; Escalator</a></li>
		<li class="list_h"><a class="gw" target="_top" href="http://www.mta.info/mta-service-status-widget">Get Widget</a></li>
    
    </ul>
    </div>

</div><!-- /.block -->  
