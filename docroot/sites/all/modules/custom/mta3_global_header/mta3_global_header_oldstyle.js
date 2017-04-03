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

var request = createCORSRequest("get", "http://new2dev.mta.info/sites/all/modules/custom/mta3_global_header/raw_header.php");
var sourceURL = 'http://new2dev.mta.info'; //http://new.mta.info http://new2dev.mta.info

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
