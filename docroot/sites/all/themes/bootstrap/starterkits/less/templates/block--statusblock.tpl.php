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
<div id="<?php print $block_html_id; ?>" class="roundCorners featurebox">
    
    <span class="span-12"><h2>Service Status</h2></span>
    <span class="statusDateTime"><?php print $timestamp; ?></span>
	<div id = "statusblock-tabs">
    <ul>
        <li class="t tdiv selectedStatusTab" id="subwayTab">Subway</li>
        <li class="t tdiv notselectedStatusTab" id="railTab">Rail</li>
        <li class="t tdiv notselectedStatusTab" id="busTab">Bus</li>
        <li class="t tlast tdiv notselectedStatusTab" id="bntTab">Bridges &amp; Tunnels</li>
    </ul>
	</div>
    <div class="content"<?php print $content_attributes; ?> style="clear:both;">
        <?php print $content; ?>
    </div>
    <div id="bottom-status-box-links">
    <ul>
        <li class="list_h"><a class="gw" target="_top" href="http://www.mta.info/mta/eles.html">Elevator &amp; Escalator</a></li>
       <li class="list_h"><a class="gw" target="_top" href="http://www.mta.info/mta-service-status-widget">Get Widget</a></li>
    </ul>
    </div>

</div><!-- /.block test -->  