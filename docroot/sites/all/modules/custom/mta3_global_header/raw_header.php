<?php
header('Access-Control-Allow-Origin: *');
header("Access-Control-Allow-Credentials: true"); 
header("Access-Control-Allow-Methods: OPTIONS, GET, POST"); 
header("Access-Control-Allow-Headers: Content-Type, Depth, User-Agent, X-File-Size, X-Requested-With, If-Modified-Since, X-File-Name, Cache-Control");
?>
<!-- This header necessary using CORS http://www.nczonline.net/blog/2010/05/25/cross-domain-ajax-with-cross-origin-resource-sharing/ -->

<!DOCTYPE html>
<script type="text/javascript" src="http://modernizr.com/downloads/modernizr-latest.js"></script>
<!--script type="text/javascript">
/* Modernizr 2.7.1 (Custom Build) | MIT & BSD
 * Build: http://modernizr.com/download/#-shiv-cssclasses-load
 */
;window.Modernizr=function(a,b,c){function u(a){j.cssText=a}function v(a,b){return u(prefixes.join(a+";")+(b||""))}function w(a,b){return typeof a===b}function x(a,b){return!!~(""+a).indexOf(b)}function y(a,b,d){for(var e in a){var f=b[a[e]];if(f!==c)return d===!1?a[e]:w(f,"function")?f.bind(d||b):f}return!1}var d="2.7.1",e={},f=!0,g=b.documentElement,h="modernizr",i=b.createElement(h),j=i.style,k,l={}.toString,m={},n={},o={},p=[],q=p.slice,r,s={}.hasOwnProperty,t;!w(s,"undefined")&&!w(s.call,"undefined")?t=function(a,b){return s.call(a,b)}:t=function(a,b){return b in a&&w(a.constructor.prototype[b],"undefined")},Function.prototype.bind||(Function.prototype.bind=function(b){var c=this;if(typeof c!="function")throw new TypeError;var d=q.call(arguments,1),e=function(){if(this instanceof e){var a=function(){};a.prototype=c.prototype;var f=new a,g=c.apply(f,d.concat(q.call(arguments)));return Object(g)===g?g:f}return c.apply(b,d.concat(q.call(arguments)))};return e});for(var z in m)t(m,z)&&(r=z.toLowerCase(),e[r]=m[z](),p.push((e[r]?"":"no-")+r));return e.addTest=function(a,b){if(typeof a=="object")for(var d in a)t(a,d)&&e.addTest(d,a[d]);else{a=a.toLowerCase();if(e[a]!==c)return e;b=typeof b=="function"?b():b,typeof f!="undefined"&&f&&(g.className+=" "+(b?"":"no-")+a),e[a]=b}return e},u(""),i=k=null,function(a,b){function l(a,b){var c=a.createElement("p"),d=a.getElementsByTagName("head")[0]||a.documentElement;return c.innerHTML="x<style>"+b+"</style>",d.insertBefore(c.lastChild,d.firstChild)}function m(){var a=s.elements;return typeof a=="string"?a.split(" "):a}function n(a){var b=j[a[h]];return b||(b={},i++,a[h]=i,j[i]=b),b}function o(a,c,d){c||(c=b);if(k)return c.createElement(a);d||(d=n(c));var g;return d.cache[a]?g=d.cache[a].cloneNode():f.test(a)?g=(d.cache[a]=d.createElem(a)).cloneNode():g=d.createElem(a),g.canHaveChildren&&!e.test(a)&&!g.tagUrn?d.frag.appendChild(g):g}function p(a,c){a||(a=b);if(k)return a.createDocumentFragment();c=c||n(a);var d=c.frag.cloneNode(),e=0,f=m(),g=f.length;for(;e<g;e++)d.createElement(f[e]);return d}function q(a,b){b.cache||(b.cache={},b.createElem=a.createElement,b.createFrag=a.createDocumentFragment,b.frag=b.createFrag()),a.createElement=function(c){return s.shivMethods?o(c,a,b):b.createElem(c)},a.createDocumentFragment=Function("h,f","return function(){var n=f.cloneNode(),c=n.createElement;h.shivMethods&&("+m().join().replace(/[\w\-]+/g,function(a){return b.createElem(a),b.frag.createElement(a),'c("'+a+'")'})+");return n}")(s,b.frag)}function r(a){a||(a=b);var c=n(a);return s.shivCSS&&!g&&!c.hasCSS&&(c.hasCSS=!!l(a,"article,aside,dialog,figcaption,figure,footer,header,hgroup,main,nav,section{display:block}mark{background:#FF0;color:#000}template{display:none}")),k||q(a,c),a}var c="3.7.0",d=a.html5||{},e=/^<|^(?:button|map|select|textarea|object|iframe|option|optgroup)$/i,f=/^(?:a|b|code|div|fieldset|h1|h2|h3|h4|h5|h6|i|label|li|ol|p|q|span|strong|style|table|tbody|td|th|tr|ul)$/i,g,h="_html5shiv",i=0,j={},k;(function(){try{var a=b.createElement("a");a.innerHTML="<xyz></xyz>",g="hidden"in a,k=a.childNodes.length==1||function(){b.createElement("a");var a=b.createDocumentFragment();return typeof a.cloneNode=="undefined"||typeof a.createDocumentFragment=="undefined"||typeof a.createElement=="undefined"}()}catch(c){g=!0,k=!0}})();var s={elements:d.elements||"abbr article aside audio bdi canvas data datalist details dialog figcaption figure footer header hgroup main mark meter nav output progress section summary template time video",version:c,shivCSS:d.shivCSS!==!1,supportsUnknownElements:k,shivMethods:d.shivMethods!==!1,type:"default",shivDocument:r,createElement:o,createDocumentFragment:p};a.html5=s,r(b)}(this,b),e._version=d,g.className=g.className.replace(/(^|\s)no-js(\s|$)/,"$1$2")+(f?" js "+p.join(" "):""),e}(this,this.document),function(a,b,c){function d(a){return"[object Function]"==o.call(a)}function e(a){return"string"==typeof a}function f(){}function g(a){return!a||"loaded"==a||"complete"==a||"uninitialized"==a}function h(){var a=p.shift();q=1,a?a.t?m(function(){("c"==a.t?B.injectCss:B.injectJs)(a.s,0,a.a,a.x,a.e,1)},0):(a(),h()):q=0}function i(a,c,d,e,f,i,j){function k(b){if(!o&&g(l.readyState)&&(u.r=o=1,!q&&h(),l.onload=l.onreadystatechange=null,b)){"img"!=a&&m(function(){t.removeChild(l)},50);for(var d in y[c])y[c].hasOwnProperty(d)&&y[c][d].onload()}}var j=j||B.errorTimeout,l=b.createElement(a),o=0,r=0,u={t:d,s:c,e:f,a:i,x:j};1===y[c]&&(r=1,y[c]=[]),"object"==a?l.data=c:(l.src=c,l.type=a),l.width=l.height="0",l.onerror=l.onload=l.onreadystatechange=function(){k.call(this,r)},p.splice(e,0,u),"img"!=a&&(r||2===y[c]?(t.insertBefore(l,s?null:n),m(k,j)):y[c].push(l))}function j(a,b,c,d,f){return q=0,b=b||"j",e(a)?i("c"==b?v:u,a,b,this.i++,c,d,f):(p.splice(this.i++,0,a),1==p.length&&h()),this}function k(){var a=B;return a.loader={load:j,i:0},a}var l=b.documentElement,m=a.setTimeout,n=b.getElementsByTagName("script")[0],o={}.toString,p=[],q=0,r="MozAppearance"in l.style,s=r&&!!b.createRange().compareNode,t=s?l:n.parentNode,l=a.opera&&"[object Opera]"==o.call(a.opera),l=!!b.attachEvent&&!l,u=r?"object":l?"script":"img",v=l?"script":u,w=Array.isArray||function(a){return"[object Array]"==o.call(a)},x=[],y={},z={timeout:function(a,b){return b.length&&(a.timeout=b[0]),a}},A,B;B=function(a){function b(a){var a=a.split("!"),b=x.length,c=a.pop(),d=a.length,c={url:c,origUrl:c,prefixes:a},e,f,g;for(f=0;f<d;f++)g=a[f].split("="),(e=z[g.shift()])&&(c=e(c,g));for(f=0;f<b;f++)c=x[f](c);return c}function g(a,e,f,g,h){var i=b(a),j=i.autoCallback;i.url.split(".").pop().split("?").shift(),i.bypass||(e&&(e=d(e)?e:e[a]||e[g]||e[a.split("/").pop().split("?")[0]]),i.instead?i.instead(a,e,f,g,h):(y[i.url]?i.noexec=!0:y[i.url]=1,f.load(i.url,i.forceCSS||!i.forceJS&&"css"==i.url.split(".").pop().split("?").shift()?"c":c,i.noexec,i.attrs,i.timeout),(d(e)||d(j))&&f.load(function(){k(),e&&e(i.origUrl,h,g),j&&j(i.origUrl,h,g),y[i.url]=2})))}function h(a,b){function c(a,c){if(a){if(e(a))c||(j=function(){var a=[].slice.call(arguments);k.apply(this,a),l()}),g(a,j,b,0,h);else if(Object(a)===a)for(n in m=function(){var b=0,c;for(c in a)a.hasOwnProperty(c)&&b++;return b}(),a)a.hasOwnProperty(n)&&(!c&&!--m&&(d(j)?j=function(){var a=[].slice.call(arguments);k.apply(this,a),l()}:j[n]=function(a){return function(){var b=[].slice.call(arguments);a&&a.apply(this,b),l()}}(k[n])),g(a[n],j,b,n,h))}else!c&&l()}var h=!!a.test,i=a.load||a.both,j=a.callback||f,k=j,l=a.complete||f,m,n;c(h?a.yep:a.nope,!!i),i&&c(i)}var i,j,l=this.yepnope.loader;if(e(a))g(a,0,l,0);else if(w(a))for(i=0;i<a.length;i++)j=a[i],e(j)?g(j,0,l,0):w(j)?B(j):Object(j)===j&&h(j,l);else Object(a)===a&&h(a,l)},B.addPrefix=function(a,b){z[a]=b},B.addFilter=function(a){x.push(a)},B.errorTimeout=1e4,null==b.readyState&&b.addEventListener&&(b.readyState="loading",b.addEventListener("DOMContentLoaded",A=function(){b.removeEventListener("DOMContentLoaded",A,0),b.readyState="complete"},0)),a.yepnope=k(),a.yepnope.executeStack=h,a.yepnope.injectJs=function(a,c,d,e,i,j){var k=b.createElement("script"),l,o,e=e||B.errorTimeout;k.src=a;for(o in d)k.setAttribute(o,d[o]);c=j?h:c||f,k.onreadystatechange=k.onload=function(){!l&&g(k.readyState)&&(l=1,c(),k.onload=k.onreadystatechange=null)},m(function(){l||(l=1,c(1))},e),i?k.onload():n.parentNode.insertBefore(k,n)},a.yepnope.injectCss=function(a,c,d,e,g,i){var e=b.createElement("link"),j,c=i?h:c||f;e.href=a,e.rel="stylesheet",e.type="text/css";for(j in d)e.setAttribute(j,d[j]);g||(n.parentNode.insertBefore(e,n),m(c,0))}}(this,document),Modernizr.load=function(){yepnope.apply(window,[].slice.call(arguments,0))};
</script-->

<!--link rel="stylesheet" href="mta3_global_header.css" type="text/css"/-->
<link rel="stylesheet" href="http://newdev.mta.info/sites/all/modules/custom/mta3_global_header/mta3_global_header.css" type="text/css"/>

<!-- header -->
<div class="nav-header-top">
	<div class="container">
		<div class="region region-header">
			<div class="region-inner clearfix">
				<div id="block-menu-menu-topbar-links" class="block block-menu no-title" role="navigation">
					<div class="block-inner clearfix">
						<ul class="menu clearfix">
							<li class="first leaf menu-depth-1 menu-item-468">
								<a href="http://web.mta.info/accessibility" title="">Accessibility</a>
							</li>
							<li class="leaf menu-depth-1 menu-item-469">
								<a href="http://assistive.usablenet.com/tt/new.mta.info/mta" title="">Text-only</a>
							</li>
							<li class="leaf menu-depth-1 menu-item-4976">
								<a href="http://web.mta.info/selfserve" title="">Customer Self-Service</a>
							</li>
							<li class="last leaf menu-depth-1 menu-item-470">
								<a href="http://web.mta.info/faqs.htm" title="">Contact Us</a>
							</li>
						</ul>
					</div>
				</div>
				<div id="block-google-appliance-ga-block-search-form" class="block block-google-appliance no-title">
					<div class="block-inner clearfix">
						<div class="block-content content">
							<form action="/" method="post" id="google-appliance-block-form--2" accept-charset="UTF-8">
								<div>
									<div id="search-top-inline" class="container-inline">
										<h2 class="element-invisible">Search Google Appliance</h2>
										<div class="form-item form-type-textfield form-item-search-keys">
											<label class="element-invisible" for="edit-search-keys--2">Enter the terms you wish to search for. </label>
											<input type="text" id="edit-search-keys--2" name="search_keys" value="" size="15" maxlength="128" class="form-text">
										</div>
										<div class="url-textfield">
											<div class="form-item form-type-textfield form-item-url">
												<label for="edit-url--2">Leave this field blank </label>
												<input autocomplete="off" type="text" id="edit-url--2" name="url" value="" size="20" maxlength="128" class="form-text">
											</div>
										</div>
										<div class="form-actions form-wrapper" id="edit-actions--2">
											<input type="submit" id="edit-submit--2" name="op" value="Search" class="form-submit">
										</div>
										<input type="hidden" name="form_build_id" value="form-euTFfu0mB5gf8qvavdj2sp6vG8_8o_ugCYB3IzbVVDI">
										<input type="hidden" name="form_id" value="google_appliance_block_form">
										<input type="hidden" name="honeypot_time" value="1394131270">
									</div>
								</div>
							</form>
						</div>
					</div>
				</div>
			</div>
		</div>
		<div id="branding" class="branding-elements">
			<div id="logo">
				<a href="/" title="Home page" class="active"><img class="site-logo" typeof="foaf:Image" src="http://new2dev.mta.info/sites/default/files/mta_logo_top_0.png" alt="MTA"></a>
			</div>
			<!-- start: Site name and Slogan hgroup -->
			<hgroup class="element-invisible" id="name-and-slogan">
				<h1 class="element-invisible" id="site-name"><a href="/" title="Home page" class="active">MTA</a></h1>
			</hgroup><!-- /end #name-and-slogan -->
		</div>
	</div>
</div>
<!-- /header -->
<!-- navigation -->
<div id="nav-wrapper">
	<div class="container clearfix">
		<div id="menu-bar" class="nav clearfix">
			<nav id="block-menu-block-3" class="block block-menu-block no-title menu-wrapper menu-bar-wrapper clearfix at-menu-toggle" role="navigation">
				<div class="menu-block-wrapper menu-block-3 menu-name-menu-new-site-main-menu parent-mlid-0 menu-level-1">
					<div class="menu-toggle">
						<ul class="menu clearfix">
							<li class="first expanded menu-mlid-8395 menu-depth-1 menu-item-8395">
								<a href="/nyct-subways" title="">Subways</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-8402 menu-depth-2 menu-item-8402">
											<a href="/nyct-subways" title="">Popular Links</a><br/>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-8404 menu-depth-3 menu-item-8404">
														<a href="/nyc-transit/schedules">Schedules</a>
													</li>
													<li class="leaf menu-mlid-9522 menu-depth-3 menu-item-9522">
														<a href="http://web.mta.info/nyct/fare/FaresatAGlance.htm" title="">Fares</a>
													</li>
													<li class="leaf menu-mlid-9524 menu-depth-3 menu-item-9524">
														<a href="http://www.mta.info/maps/submap.html " title="">Map </a>
													</li>
													<li class="leaf menu-mlid-9526 menu-depth-3 menu-item-9526">
														<a href="http://mymtaalerts.com/LoginC.aspx" title="">Get Email/Text Alerts</a>
													</li>
													<li class="leaf menu-mlid-9527 menu-depth-3 menu-item-9527">
														<a href="http://www.mta.info/nyct/paratran/guide.htm" title="">Access-A-Ride </a>
													</li>
													<li class="leaf menu-mlid-9528 menu-depth-3 menu-item-9528">
														<a href="http://travel.mtanyct.info/serviceadvisory/default.aspx" title="">Planned Service Changes</a>
													</li>
													<li class="leaf menu-mlid-9529 menu-depth-3 menu-item-9529">
														<a href="http://web.mta.info/nyct/service/airport.htm" title="">Airport Information</a>
													</li>
													<li class="leaf menu-mlid-9530 menu-depth-3 menu-item-9530">
														<a href="http://web.mta.info/metrocard/tourism/mc_promotions.htm" title="">Deals &amp; Trips</a>
													</li>
													<li class="leaf menu-mlid-9531 menu-depth-3 menu-item-9531">
														<a href="http://new2dev.mta.info/nyct" title="">Visit our Main Page </a>
													</li>
													<li class="last leaf has-children menu-mlid-9726 menu-depth-3 menu-item-9726">
														<a href="/nyc-transit/metrocard">MetroCard</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-8403 menu-depth-2 menu-item-8403">
											<a href="/nyct-subways" title="">Just For You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9566 menu-depth-3 menu-item-9566">
														<a href="/nyc-transit/seniors">Seniors</a>
													</li>
													<li class="leaf menu-mlid-9536 menu-depth-3 menu-item-9536">
														<a href="http://www.mta.info/accessibility" title="">Customers with Disabilities</a>
													</li>
													<li class="leaf menu-mlid-9573 menu-depth-3 menu-item-9573">
														<a href="/mta-headquarters/mobile-users" title="">Mobile Users</a>
													</li>
													<li class="leaf menu-mlid-9719 menu-depth-3 menu-item-9719">
														<a href="http://web.mta.info/mta/sports/" title="">Sports Fans</a>
													</li>
													<li class="leaf menu-mlid-9571 menu-depth-3 menu-item-9571">
														<a href="http://web.mta.info/mta/realestate/ad_tele.html" title="">Advertisers</a>
													</li>
													<li class="leaf menu-mlid-9572 menu-depth-3 menu-item-9572">
														<a href="http://web.mta.info/mta/employment/" title="">Careers</a>
													</li>
													<li class="last leaf menu-mlid-9539 menu-depth-3 menu-item-9539">
														<a href="http://www.mta.info/mta/phone.htm" title="">Call 511: for voice-activated travel information</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-8478 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_5 view-dom-id-b649109e890f232571404b1d3b54fdf5">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="http://www.mta.info/nyct/service/events/HongKongDragonBoatFestivalinFlushingMeadows2013.htm"></a><a href="/news/2013/08/07/take-7-train-dragon-boat-festival-weekend"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/dragonboat_new.jpg?itok=MqWKkMq_" width="438" height="220" alt=""></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="http://www.mta.info/nyct/service/events/HongKongDragonBoatFestivalinFlushingMeadows2013.htm">
																<p>
																	Take the 7 to the Dragon Boat Festival This Weekend
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="expanded menu-mlid-8396 menu-depth-1 menu-item-8396">
								<a href="/nyct" title="">Buses</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-9541 menu-depth-2 menu-item-9541">
											<a href="/nyct" title="">Popular Links</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9542 menu-depth-3 menu-item-9542">
														<a href="http://tripplanner.mta.info/MyTrip/ui_web/point2point/Default.aspx" title="">Schedules </a>
													</li>
													<li class="leaf menu-mlid-9543 menu-depth-3 menu-item-9543">
														<a href="http://web.mta.info/nyct/fare/FaresatAGlance.htm" title="">Fares</a>
													</li>
													<li class="leaf menu-mlid-9544 menu-depth-3 menu-item-9544">
														<a href="http://web.mta.info/metrocard/index.html" title="">MetroCard </a>
													</li>
													<li class="leaf menu-mlid-9545 menu-depth-3 menu-item-9545">
														<a href="http://bustime.mta.info/" title="">Bus TIme </a>
													</li>
													<li class="leaf menu-mlid-9546 menu-depth-3 menu-item-9546">
														<a href="http://mymtaalerts.com/LoginC.aspx" title="">Get Email/Text Alerts</a>
													</li>
													<li class="leaf menu-mlid-9547 menu-depth-3 menu-item-9547">
														<a href="http://www.mta.info/nyct/paratran/guide.htm" title="">Access-A-Ride </a>
													</li>
													<li class="leaf menu-mlid-9548 menu-depth-3 menu-item-9548">
														<a href="http://travel.mtanyct.info/serviceadvisory/busplanwork.aspx" title="">Planned Service Changes </a>
													</li>
													<li class="leaf menu-mlid-9549 menu-depth-3 menu-item-9549">
														<a href="http://web.mta.info/nyct/service/airport.htm" title="">Airport Information </a>
													</li>
													<li class="leaf menu-mlid-9550 menu-depth-3 menu-item-9550">
														<a href="http://web.mta.info/metrocard/tourism/mc_promotions.htm" title="">Deals &amp; Trips </a>
													</li>
													<li class="last leaf menu-mlid-9551 menu-depth-3 menu-item-9551">
														<a href="http://new.mta.info/nyct" title="">Visit our Main Page </a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-9552 menu-depth-2 menu-item-9552">
											<a href="/nyct" title="">Just For You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf has-children menu-mlid-9720 menu-depth-3 menu-item-9720">
														<a href="/nyc-transit/seniors" title="">Seniors</a>
													</li>
													<li class="leaf menu-mlid-9556 menu-depth-3 menu-item-9556">
														<a href="http://www.mta.info/accessibility" title="">Customers with Disabilities</a>
													</li>
													<li class="leaf menu-mlid-9721 menu-depth-3 menu-item-9721">
														<a href="/mta-headquarters/mobile-users" title="">Mobile Users</a>
													</li>
													<li class="leaf menu-mlid-9585 menu-depth-3 menu-item-9585">
														<a href="http://web.mta.info/mta/employment/" title="">Careers </a>
													</li>
													<li class="last leaf menu-mlid-9584 menu-depth-3 menu-item-9584">
														<a href="http://web.mta.info/mta/realestate/ad_tele.html" title="">Advertisers </a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-9715 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_5 view-dom-id-b649109e890f232571404b1d3b54fdf5">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="http://www.mta.info/nyct/service/events/HongKongDragonBoatFestivalinFlushingMeadows2013.htm"></a><a href="/news/2013/08/07/take-7-train-dragon-boat-festival-weekend"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/dragonboat_new.jpg?itok=MqWKkMq_" width="438" height="220" alt=""></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="http://www.mta.info/nyct/service/events/HongKongDragonBoatFestivalinFlushingMeadows2013.htm">
																<p>
																	Take the 7 to the Dragon Boat Festival This Weekend
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="expanded menu-mlid-8397 menu-depth-1 menu-item-8397">
								<a href="/lirr" title="">Long Island Rail Road</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-9455 menu-depth-2 menu-item-9455">
											<a href="/lirr" title="">Popular Links</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9477 menu-depth-3 menu-item-9477">
														<a href="/lirr/schedules-fares">Schedules</a>
													</li>
													<li class="leaf menu-mlid-8975 menu-depth-3 menu-item-8975">
														<a href="/lirr/fares-ticket-information">Fares</a>
													</li>
													<li class="leaf menu-mlid-9457 menu-depth-3 menu-item-9457">
														<a href="http://wx3.lirr.org/lirr/TrainTime/" title="">TrainTime</a>
													</li>
													<li class="leaf menu-mlid-9199 menu-depth-3 menu-item-9199">
														<a href="/lirr/lirr-map">Map</a>
													</li>
													<li class="leaf menu-mlid-9458 menu-depth-3 menu-item-9458">
														<a href="http://www.mta.info/lirr/News/PlannedService.htm" title="">Planned Service Changes</a>
													</li>
													<li class="leaf menu-mlid-8983 menu-depth-3 menu-item-8983">
														<a href="http://www.mymtaalerts.com/LoginC.aspx" title="">Get Email/Text Alerts</a>
													</li>
													<li class="leaf menu-mlid-8986 menu-depth-3 menu-item-8986">
														<a href="/lirr/deals-getaways" title="">Long Island Getaways</a>
													</li>
													<li class="leaf menu-mlid-9459 menu-depth-3 menu-item-9459">
														<a href="/lirr" title="">Visit our Main page</a>
													</li>
													<li class="last leaf menu-mlid-8982 menu-depth-3 menu-item-8982">
														<a href="http://www.coocoo.com/lirr" title="">CooCoo</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-9456 menu-depth-2 menu-item-9456">
											<a href="/lirr" title="">Just For You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9460 menu-depth-3 menu-item-9460">
														<a href="http://www.mta.info/lirr/Travel/SeniorGuide/" title="">Seniors</a>
													</li>
													<li class="leaf menu-mlid-8978 menu-depth-3 menu-item-8978">
														<a href="/lirr/accessibility" title="">Customers with Disabilities</a>
													</li>
													<li class="leaf menu-mlid-9462 menu-depth-3 menu-item-9462">
														<a href="/mta-headquarters/mobile-users">Mobile Users</a>
													</li>
													<li class="leaf menu-mlid-9463 menu-depth-3 menu-item-9463">
														<a href="http://web.mta.info/lirr/Travel/" title="">Regional Travelers </a>
													</li>
													<li class="leaf menu-mlid-9464 menu-depth-3 menu-item-9464">
														<a href="http://web.mta.info/mta/sports/" title="">Sports Fans</a>
													</li>
													<li class="leaf menu-mlid-9465 menu-depth-3 menu-item-9465">
														<a href="http://web.mta.info/mta/realestate/ad_tele.html " title="">Advertisers</a>
													</li>
													<li class="last leaf menu-mlid-9466 menu-depth-3 menu-item-9466">
														<a href="http://web.mta.info/mta/employment/ " title="">Careers </a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-9257 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_2 view-dom-id-9bfb9178576948c5012c22abd78bde29">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="#"></a><a href="#"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/lirr_36003_4_0.jpg?itok=UfQqcFHs" width="438" height="220" alt=""></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="#">
																<p>
																	All-Star Service to All-Star Game &amp; Events
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="expanded menu-mlid-8398 menu-depth-1 menu-item-8398">
								<a href="/mnr" title="">Metro-North Railroad</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-9467 menu-depth-2 menu-item-9467">
											<a href="/mnr" title="">Popular Links</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-8560 menu-depth-3 menu-item-8560">
														<a href="/metro-north/mta-metro-north-railroad-schedules">Schedules</a>
													</li>
													<li class="leaf menu-mlid-8559 menu-depth-3 menu-item-8559">
														<a href="/metro-north/fares-ticket-information" title="">Fares</a>
													</li>
													<li class="leaf menu-mlid-8561 menu-depth-3 menu-item-8561">
														<a href="https://ec0.mta.info/mnr/Cvar_MR/index.cfm" title="">Mail &amp; Ride</a>
													</li>
													<li class="leaf menu-mlid-8547 menu-depth-3 menu-item-8547">
														<a href="/metro-north/mnr-map" title="">Map</a>
													</li>
													<li class="leaf menu-mlid-8571 menu-depth-3 menu-item-8571">
														<a href="http://www.mymtaalerts.com/LoginC.aspx" title="">Get Email/Text Alerts</a>
													</li>
													<li class="leaf menu-mlid-8575 menu-depth-3 menu-item-8575">
														<a href="/metro-north/destination-deals-getaways" title="">Metro North Getaways!</a>
													</li>
													<li class="leaf menu-mlid-9469 menu-depth-3 menu-item-9469">
														<a href="http://as0.mta.info/mnr/mstations/default.cfm" title="">TrainTime</a>
													</li>
													<li class="last leaf menu-mlid-9470 menu-depth-3 menu-item-9470">
														<a href="/mnr" title="">Visit our Main page</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-9468 menu-depth-2 menu-item-9468">
											<a href="/mnr" title="">Just For You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9594 menu-depth-3 menu-item-9594">
														<a href="http://www.mta.info/lirr/Travel/SeniorGuide/" title="">Seniors</a>
													</li>
													<li class="leaf menu-mlid-9595 menu-depth-3 menu-item-9595">
														<a href="/metro-north/accessibility" title="">Customers with Disabilities </a>
													</li>
													<li class="leaf menu-mlid-9471 menu-depth-3 menu-item-9471">
														<a href="/mta-headquarters/mobile-users" title="">Mobile Users</a>
													</li>
													<li class="leaf menu-mlid-9472 menu-depth-3 menu-item-9472">
														<a href="http://web.mta.info/mta/sports/" title="">Sports Fans</a>
													</li>
													<li class="leaf menu-mlid-9473 menu-depth-3 menu-item-9473">
														<a href="http://web.mta.info/mta/realestate/ad_tele.html" title="">Advertisers</a>
													</li>
													<li class="last leaf menu-mlid-9474 menu-depth-3 menu-item-9474">
														<a href="http://web.mta.info/mta/employment/" title="">Careers</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-9476 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_4 view-dom-id-ac0ee8207920234885f6a1821cd47c2a">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="/node/%5Bnid%5D"></a><a href="/news/2013/08/26/pearl-wisdom-don%E2%80%99t-miss-norwalk-oyster-fest"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/oyster.jpg?itok=0vuwh1Rb" width="438" height="220" alt=""></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="/node/%5Bnid%5D">
																<p>
																	Oyster Festival Logo
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="expanded menu-mlid-8594 menu-depth-1 menu-item-8594">
								<a href="/sir" title="">Staten Island Railway</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-8593 menu-depth-2 menu-item-8593">
											<a href="/sir" title="">Popular Links</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9603 menu-depth-3 menu-item-9603">
														<a href="http://web.mta.info/nyct/service/pdf/sircur.pdf" title="">Schedules</a>
													</li>
													<li class="leaf menu-mlid-9604 menu-depth-3 menu-item-9604">
														<a href="http://www.mta.info/nyct/sir/sirfare.htm" title="">Fares</a>
													</li>
													<li class="leaf menu-mlid-8649 menu-depth-3 menu-item-8649">
														<a href="/staten-island-railway/system-map" title="">System Map</a>
													</li>
													<li class="leaf menu-mlid-9202 menu-depth-3 menu-item-9202">
														<a href="/staten-island-railway/mta-staten-island-railway-strip-map" title="">Strip map: Bus Transfers and Parking</a>
													</li>
													<li class="leaf menu-mlid-9605 menu-depth-3 menu-item-9605">
														<a href="http://www.mta.info/nyct/service/subsrvnsir.htm" title="">Planned Service Changes</a>
													</li>
													<li class="leaf menu-mlid-9606 menu-depth-3 menu-item-9606">
														<a href="http://www.nyc.gov/html/dot/html/ferrybus/staten-island-ferry.shtml" title="">Staten Island Ferry Information </a>
													</li>
													<li class="last leaf menu-mlid-9608 menu-depth-3 menu-item-9608">
														<a href="http://new.mta.info/sir" title="">Visit our Main Page</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-9607 menu-depth-2 menu-item-9607">
											<a href="/sir" title="">Just for You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9609 menu-depth-3 menu-item-9609">
														<a href="http://www.mta.info/lirr/Travel/SeniorGuide/" title="">Seniors</a>
													</li>
													<li class="leaf menu-mlid-9611 menu-depth-3 menu-item-9611">
														<a href="http://web.mta.info/accessibility/" title="">Customers with Disabilities</a>
													</li>
													<li class="leaf menu-mlid-9722 menu-depth-3 menu-item-9722">
														<a href="/mta-headquarters/mobile-users" title="">Mobile Users</a>
													</li>
													<li class="leaf menu-mlid-9612 menu-depth-3 menu-item-9612">
														<a href="http://web.mta.info/mta/sports/" title="">Sports Fans </a>
													</li>
													<li class="last leaf menu-mlid-9613 menu-depth-3 menu-item-9613">
														<a href="http://web.mta.info/mta/employment/" title="">Careers </a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-9712 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_2 view-dom-id-9bfb9178576948c5012c22abd78bde29">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="/node/%5Bnid%5D"></a><a href="/news/2013/07/10/lirr-provides-extra-service-all-star-game-events"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/lirr_36003_4_0.jpg?itok=UfQqcFHs" width="438" height="220" alt=""></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="/node/%5Bnid%5D">
																<p>
																	All-Star Service to All-Star Game &amp; Events
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="expanded menu-mlid-9710 menu-depth-1 menu-item-9710">
								<a href="/bandt" title="">Bridges &amp; Tunnels</a>
								<div class="menu-toggle hidemenu">
									<ul class="menu clearfix">
										<li class="first expanded menu-mlid-8549 menu-depth-2 menu-item-8549">
											<a href="/bandt" title="">Popular Links</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-8545 menu-depth-3 menu-item-8545">
														<a href="/bridges-tunnels/crossing-charges-%E2%80%94-effective-2am-march-3-2013" title="">Crossing Charges</a>
													</li>
													<li class="leaf menu-mlid-9618 menu-depth-3 menu-item-9618">
														<a href="http://mta.info/bandt/ezpass/" title="">E-ZPass Information</a>
													</li>
													<li class="leaf menu-mlid-8548 menu-depth-3 menu-item-8548">
														<a href="/bridges-tunnels/tolls-mail-henry-hudson-bridge" title="">Henry Hudson Bridge Toll</a>
													</li>
													<li class="leaf menu-mlid-9619 menu-depth-3 menu-item-9619">
														<a href="http://mymtaalerts.com/LoginC.aspx" title="">Get Email/Text Alerts </a>
													</li>
													<li class="leaf menu-mlid-9723 menu-depth-3 menu-item-9723">
														<a href="http://traveltime.mta.info/traveltime/index_pc.html" title="">Drive Time</a>
													</li>
													<li class="last leaf menu-mlid-9724 menu-depth-3 menu-item-9724">
														<a href="/sir" title="">Visit our Main Page</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="expanded menu-mlid-8550 menu-depth-2 menu-item-8550">
											<a href="/bandt" title="">Just for You</a>
											<div class="menu-toggle">
												<ul class="menu clearfix">
													<li class="first leaf menu-mlid-9621 menu-depth-3 menu-item-9621">
														<a href="http://web.mta.info/accessibility/rail.htm" title="">Customers with Disabilities </a>
													</li>
													<li class="leaf menu-mlid-8552 menu-depth-3 menu-item-8552">
														<a href="/bridges-tunnels/truckcommercial-vehicle-information" title="">Truckers</a>
													</li>
													<li class="leaf menu-mlid-9622 menu-depth-3 menu-item-9622">
														<a href="http://webcam.mta.info/mta3/index.jsp" title="">Commuters</a>
													</li>
													<li class="leaf has-children menu-mlid-9725 menu-depth-3 menu-item-9725">
														<a href="/mta-headquarters/mobile-users" title="">Mobile Users</a>
													</li>
													<li class="last leaf menu-mlid-8553 menu-depth-3 menu-item-8553">
														<a href="/bridges-tunnels/job-vacancy-notices" title="">Careers</a>
													</li>
												</ul>
											</div>
										</li>
										<li class="last leaf menu-mlid-9713 menu-views">
											<div class="view view-news-rotator-v3 view-id-news_rotator_v3 view-display-id-block_3 view-dom-id-8a2212f99b7c21dec83e5f31acd8c3b0">
												<div class="view-content">
													<div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
														<div class="views-field views-field-field-rotator-horizontal-image">
															<div class="field-content">
																<a href="/node/%5Bnid%5D"></a><a href="/news/2013/08/02/henry-hudson-upper-level-permanent-lane-closure-lifted"><img typeof="foaf:Image" class="image-style-rotator-horizontal" src="http://new2dev.mta.info/sites/default/files/styles/rotator_horizontal/public/mta/images/rotator_horizontal/img_0033.jpg?itok=G-HhDEqY" width="438" height="220" alt="New roadway ready for striping " title="Henry Hudson UpNew roadway ready for striping "></a>
															</div>
														</div>
														<div class="views-field views-field-field-news-rotator-caption">
															<div class="field-content">
																<a href="/node/%5Bnid%5D">
																<p>
																	Henry Hudson Upper Level Permanent Lane Closure Lifted
																</p> </a>
															</div>
														</div>
													</div>
												</div>
											</div>
										</li>
									</ul>
								</div>
							</li>
							<li class="last leaf menu-mlid-9714 menu-depth-1 menu-item-9714">
								<a href="/visitors">Visitors to New York</a>
							</li>
						</ul>
					</div>
				</div>
			</nav>
		</div>
	</div>
</div>
<script src="http://new2dev.mta.info/misc/jquery.js?v=1.4.4"></script>
<script src="http://new2dev.mta.info/misc/jquery.once.js?v=1.2"></script>
<script src="http://new2dev.mta.info/misc/drupal.js?n212hk"></script>
<script src="http://new2dev.mta.info/misc/ui/jquery.ui.core.min.js?v=1.8.7"></script>
<script src="http://new2dev.mta.info/misc/ui/jquery.ui.widget.min.js?v=1.8.7"></script>
<script src="http://new2dev.mta.info/misc/jquery.cookie.js?v=1.0"></script>
<!-- /navigation -->
<script type="text/javascript">

jQuery(document).ready(function(){
	jQuery(".menu-depth-1").mouseover(function(e){
		jQuery(this).children(".menu-toggle").removeClass("hidemenu").addClass("showmenu");
	});
	
	jQuery(".menu-depth-1").mouseout(function(e){
		jQuery(this).children(".menu-toggle").removeClass("showmenu").addClass("hidemenu");
	});	
})

	
</script>