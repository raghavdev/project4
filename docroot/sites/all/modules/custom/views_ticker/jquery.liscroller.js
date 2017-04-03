/*!
 * liScroll 1.0
 * Examples and documentation at:
 * http://www.gcmingati.net/wordpress/wp-content/lab/jquery/newsticker/jq-liscroll/scrollanimate.html
 * 2007-2010 Gian Carlo Mingati
 * Version: 1.0.2.1 (22-APRIL-2011)
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 * Requires:
 * jQuery v1.2.x or later
 *
 */


jQuery.fn.liScroll = function(settings) {
	settings = jQuery.extend({
		travelocity: 0.5,
		direction: "left",
		pauseOnMouse: true
	}, settings);
	return this.each(function(){

		var $strip = jQuery(this);
		$strip.addClass("liScroll");
// added hack to automate the scroll buffer size for single line scroll regardless of char count and font 		
		charCount = jQuery(this,"scan.views-liScroll-tick-field").text().length;
		fontSize = jQuery(this,"scan.views-liScroll-tick-field").css("font-size");
		var num = new Number(fontSize.substr(0,2));
		var stripWidth = Math.round((charCount * num)/2.65);
// end hack
		$strip.find("li").each(function(i){
			stripWidth += jQuery(this, i).outerWidth(true); // thanks to Michael Haszprunar and Fabien Volpi
		});
		var $mask = $strip.wrap("<div class='mask'></div>");
		var $tickercontainer = $strip.parent().wrap("<div class='liScroll-container'></div>");
		var containerWidth = $strip.parent().parent().width();	//a.k.a. 'mask' width
		$strip.width(stripWidth);
		var totalTravel = stripWidth+containerWidth;
		var defTiming = Math.round(totalTravel/settings.travelocity);	// thanks to Scott Waye
		//alert ("font size = "+ fontSize +" defTiming  = "+ defTiming + " total traval = "+ totalTravel);
		function scrollnews(spazio, tempo){
			//jQuery(".views-liScroll-tick-field").css("display","inline");
			jQuery("div#middle-header").css("display","inline-block");

			if(settings.direction == "right"){
				if(spazio==stripWidth+containerWidth)
					$strip.css("left", -stripWidth);
				spazio=-spazio-20;
			}

			$strip.animate(
				{left: '-='+ spazio},
				tempo,
				"linear",
				function(){
					//jQuery(this).show();
					$strip.css("left", containerWidth);
					//$strip.parent().parent().css("display","block");
					scrollnews(totalTravel, defTiming);
				}
			);
		}
		scrollnews(totalTravel, defTiming);

		if(settings.pauseOnMouse==true)
		{
			$strip.hover(function(){
				jQuery(this).stop();
			},

			function(){
				var offset = jQuery(this).offset();
				var residualSpace = offset.left + stripWidth;
				if(settings.direction == "right"){
					residualSpace = -offset.left+containerWidth+20;
				}

				var residualTime = Math.round(residualSpace/settings.travelocity);
				scrollnews(residualSpace, residualTime);
			});
		}
	});
};
