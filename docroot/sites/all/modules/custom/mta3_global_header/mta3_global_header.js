//cross-browser see http://www.nczonline.net/blog/2010/05/25/cross-domain-ajax-with-cross-origin-resource-sharing/

function createCORSRequest(method, url){
    var xhr = new XMLHttpRequest();
    if ("withCredentials" in xhr){
        xhr.open(method, url, true);
    } else if (typeof XDomainRequest != "undefined"){ //IE
        xhr = new XDomainRequest();
        xhr.open(method, url);
    } else {
        xhr = null;
    }
    return xhr;
}

var request = createCORSRequest("get", "http://newdev.mta.info/sites/all/modules/custom/mta3_global_header/raw_header.php");
var sourceURL = 'http://newdev.mta.info'; //http://new.mta.info http://new2dev.mta.info
/*
if (request){
    request.onload = function(){ 
		// do stuff if request is successful; if it fails, there is no replacement of existing HTML in target site
        // look first if a container with id #mta-global-header exists, if not use the existing #topbar container
		document.getElementById('mta-global-header') ? document.getElementById('mta-global-header').innerHTML = request.responseText : document.getElementById('topbar').innerHTML = request.responseText;
		// change relative image URL into absolute
		document.getElementById('branding').getElementsByTagName('img')[0].src = sourceURL + '/sites/default/files/mta_logo_top_0.png';
		// change relative Google Appliance Search action into absolute
		document.getElementById('google-appliance-block-form').action = sourceURL + '/';
    };
    request.send();
}
*/

	function launch(){
		jQuery.get("/sites/all/modules/custom/mta3_global_header/raw_header.php", function(response){
			jQuery("#mta-global-header").html(response);
			jQuery("#topbar").html(response);

			
			if (window.XDomainRequest){
				jQuery("#mta-global-header").html(response);
				jQuery("#topbar").html(response);
				jQuery(".menu-depth-1").unbind("mouseover").unbind("mouseout");
				jQuery(".showmenu").removeClass("showmenu");
				jQuery(".hidemenu").removeClass("hidemenu");
				jQuery("#block-menu-block-3 > div > div > ul.menu").css("padding", "0").css("margin", "0").css("overflow", "hidden").css("width", "100%").css("z-index", "101");
				jQuery("#block-menu-block-3").css("z-index", "101");
				jQuery("#nav-wrapper").css("height", "27px");
				jQuery("#block-menu-block-3").css("width", "110%");
				
				
				jQuery(".menu-depth-2 > .menu-toggle > .menu").css("list-style-type", "none!important");
				jQuery(".menu-depth-2 > .menu-toggle > .menu > li").css("display", "inline");
				jQuery("#search-top-inline").css("overflow", "hidden");
				
				jQuery("#topbar").css("height", "130px");
				jQuery("#contentbox").css("overflow", "hidden").css("min-height", "519px");
			}
			
			
			
			
			jQuery("#nav-wrapper").css("z-index", 100);
			jQuery(".menu-bar").css("position", "relative");		
			jQuery(".expanded.menu-mlid-8396.menu-depth-1.menu-item-8396 > ul.menu").css("position", "absolute").css("left", "0px");

			jQuery(".expanded.menu-mlid-8397.menu-depth-1.menu-item-8397 > ul.menu").css("position", "absolute").css("left", "0px");

			jQuery(".expanded.menu-mlid-8398.menu-depth-1.menu-item-8398 > ul.menu").css("position", "absolute").css("left", "0px");

			jQuery(".expanded.menu-mlid-8594.menu-depth-1.menu-item-8594 > ul.menu").css("position", "absolute").css("left", "0px");

			jQuery(".expanded.menu-mlid-9710.menu-depth-1.menu-item-9710 > ul.menu").css("position", "absolute").css("left", "0px");

			jQuery(".last.leaf.menu-mlid-9714.menu-depth-1.menu-item-9714 > ul.menu").css("position", "absolute").css("left", "0px");
			jQuery("body").css("background-color", "#fff").css("background-image", "none");
			jQuery("<div id='nav-wrapper-bg' style='width:100%;height:27px;background-color:#525257;position:absolute;top:103px'></div>").prependTo(jQuery("body"));
			// change relative image URL into absolute
			// CHANGE LOGO HERE
			if (document.getElementById('branding')){
				document.getElementById('branding').getElementsByTagName('img')[0].src = sourceURL + '/sites/default/files/mta_logo_top_0.png';
				//document.getElementById('branding').getElementsByTagName('img')[0].src = sourceURL + '/sites/all/themes/mta/images/mta_info.gif';
				// change relative Google Appliance Search action into absolute
			}
			if (document.getElementById('google-appliance-block-form')){
				document.getElementById('google-appliance-block-form').action = sourceURL + '/';

			}
			
			
		});
	}

jQuery(document).ready(function(){
	
	
	
	launch();
	launch();
});