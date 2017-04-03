<script>

//used in mta.info home page

//default functions

// For Default time on Smart Trip 


var loadDate = new Date();
var loadHour = loadDate.getHours()
var loadMinute = loadDate.getMinutes()
var loadAMPM
if (loadHour > 11) {
    loadAMPM = 1
}
else {
    loadAMPM = 0
}
if (loadHour > 12) {
    loadHour = loadHour - 12
}

if (loadHour == 0) {
    loadHour = 12
}
	
	/* For date control in Trip Planner */
//	document.forms["tpForm"].elements["fdate"].datepick({ showDefault: true });


		
function SetTimeMyTrip() {
//	alert("made it");
    document.forms["tpForm"].elements["ampm"].selectedIndex = loadAMPM
    document.forms["tpForm"].elements["minute"].selectedIndex = loadMinute
    document.forms["tpForm"].elements["hour"].selectedIndex = loadHour - 1

}


//varibale to check if it is first click on address boxes or submit button
var firstClick = true;

var bingMapToken = ""

var json_loaded = false;
var cookie_loaded = false;
var tripplanner_ext_loaded = false;
var landmark_loaded = false;
var VE_loaded = false;

var TPAddressDefaultMsg = "Full Address, Landmark or Station Name"
var TPAddressNormalSize = document.getElementById("txtOriginInput").style.fontSize

document.getElementById("txtOriginInput").value = TPAddressDefaultMsg
document.getElementById("txtDestinationInput").value = TPAddressDefaultMsg
document.getElementById("txtOriginInput").style.fontSize = "11px"
document.getElementById("txtDestinationInput").style.fontSize = "11px"

function clearDefaultText(e) {
    if (e.value == TPAddressDefaultMsg) {
        e.value = ""
        e.style.fontSize = TPAddressNormalSize
    }
}

//called from mta home page on click of Address boxes, Submit button or Advance option button
function SmartTripClick(ojectType, Obj, ToFrom) {
   
    clearDefaultText(Obj);
    
    if (firstClick == true) {
        document.getElementById('tpimageForWait').style.visibility = "visible";
        
        //load required js files 
        loadfunctions();
        firstClick = false;
    }
    else {
        switch (ojectType.toUpperCase()) {
            case "SUBMIT":
                GoToTPResult();
                break;
            case "ADVANCEOPTION":
                GoToTripplaner();
                break;
            case "ADDRESSTEXTBOX":
                OnAddressTextBoxClick(Obj, ToFrom);
                break;
        }
    }
    setTimeout(function() { checkIFscriptsloaded(ojectType, Obj, ToFrom) }, 200);
}


//The js files which are loaded on first click
function loadfunctions() {
    loadjsfile("http://Tripplanner.mta.info/MyTrip/js/JSON.js");
    loadjsfile("http://Tripplanner.mta.info/MyTrip/js/CookieFunctions.js");
    loadjsfile("http://Tripplanner.mta.info/MyTrip/js/tripplanner_ext.js");
    loadjsfile("http://Tripplanner.mta.info/MyTrip/js/landmarks.js");
    loadjsfile("http://dev.virtualearth.net/mapcontrol/mapcontrol.ashx?v=6.3");
    loadjsfile("http://advisory.mtanyct.info/token/bingToken.js");
}

//When all the scripts are loaded, do necessary depending on the objectType
function checkIFscriptsloaded(ojectType, Obj, ToFrom) {
    if (json_loaded && cookie_loaded && tripplanner_ext_loaded && landmark_loaded && VE_loaded) {
        document.getElementById('tpimageForWait').style.visibility = "hidden";
        postionBoxes();
        switch (ojectType.toUpperCase()) {
            case "SUBMIT":
                GoToTPResult();
                break;
            case "ADVANCEOPTION":
                GoToTripplaner();
                break;
            case "ADDRESSTEXTBOX":
                OnAddressTextBoxClick(Obj, ToFrom);
                break;
        }
    }
    else {
        setTimeout(function() { checkIFscriptsloaded(ojectType, Obj, ToFrom) }, 200);
    }
}

//function to load js files 
var fname;
function loadjsfile(filename) {

    var fileref = document.createElement('script');
    fileref.setAttribute("type", "text/javascript");
    fileref.setAttribute("src", filename);
    fname = filename;

    //for most browsers
    fileref.onload = oCallback(filename);
    // IE 6 & 7
    fileref.onreadystatechange = function() {
        if (this.readyState == 'loaded' || this.readyState == 'complete') {
            oCallback(filename);
        }
    }
    document.getElementsByTagName("head")[0].appendChild(fileref);
}

//function called when a js file load is complete
function oCallback(filename) {
    switch (filename) {
        case "http://Tripplanner.mta.info/MyTrip/js/JSON.js":
            json_loaded = true;
            break;
        case "http://Tripplanner.mta.info/MyTrip/js/CookieFunctions.js":
            cookie_loaded = true;
            break;
        case "http://Tripplanner.mta.info/MyTrip/js/tripplanner_ext.js":
            tripplanner_ext_loaded = true;
            break;
        case "http://Tripplanner.mta.info/MyTrip/js/landmarks.js":
            landmark_loaded = true;
            break;
        case "http://dev.virtualearth.net/mapcontrol/mapcontrol.ashx?v=6.3":
            VE_loaded = true;
            break;
    }
}

//To hide landmark dropdowns when clicked anywhere on the page except dropdowns
function HideLandmarkLists() {
    if (document.getElementById('fromAutoFillList')) {
        document.getElementById('fromAutoFillList').style.visibility = "hidden";
    }
    if (document.getElementById('toAutoFillList')) {
        document.getElementById('toAutoFillList').style.visibility = "hidden";
    }
}



//........5/31/2012 Adding Point2Point and Service in the Area on mta TP+ box

function ShowTpForm(module) {
    switch (module) {
        case "CP":
            document.getElementById('currentmodule').value = "tripplanner"
            document.forms["tpSubmit"].action = "http://Tripplanner.mta.info/MyTrip/handler/customplannerHandler.ashx?cid=mtahome";

            document.getElementById("labelForStartAddress").innerText = "From";

            document.getElementById('divCP').style.backgroundColor = '#00C521';
            document.getElementById('divSIA').style.backgroundColor = '#FFFFFF';
            document.getElementById('divSCH').style.backgroundColor = '#FFFFFF';

            document.getElementById('divCP').style.color = '#FFFFFF';
            document.getElementById('divSIA').style.color = '#000000';
            document.getElementById('divSCH').style.color = '#000000';

            document.getElementById("divWalkDist").style.display = "none";
            document.getElementById("lbltime").style.display = "none";

            document.getElementById('divP2PHeadline').style.display = "none";
            document.getElementById('schMenuLinks').style.display = "none";
            document.getElementById('tpForm').style.display = "block";

            document.getElementById("divEndAddress").style.display = "block";
            document.getElementById("divTransitMode").style.display = "block";
            document.getElementById("divLeaveArr").style.display = "block";

            document.getElementById("SpanAdv").style.display = "inline";

            break;
        case "SIA":
            document.getElementById('currentmodule').value = "serviceinthearea"
            document.forms["tpSubmit"].action = "http://Tripplanner.mta.info/MyTrip/handler/ServiceintheArea.ashx?cid=mtahome";

            document.getElementById("labelForStartAddress").innerText = "Location";

            document.getElementById('divCP').style.backgroundColor = '#FFFFFF';
            document.getElementById('divSIA').style.backgroundColor = '#00C521';
            document.getElementById('divSCH').style.backgroundColor = '#FFFFFF';

            document.getElementById('divCP').style.color = '#000000';
            document.getElementById('divSIA').style.color = '#FFFFFF';
            document.getElementById('divSCH').style.color = '#000000';

            document.getElementById('divP2PHeadline').style.display = "none";
            document.getElementById('schMenuLinks').style.display = "none";
            document.getElementById('tpForm').style.display = "block";

            document.getElementById("divWalkDist").style.display = "block";
            document.getElementById("lbltime").style.display = "block";

            document.getElementById("divEndAddress").style.display = "none";
            document.getElementById("divTransitMode").style.display = "none";
            document.getElementById("divLeaveArr").style.display = "none";
            document.getElementById("SpanAdv").style.display = "none";

            break;
        case "SCH":
            document.getElementById('currentmodule').value = "point2point"
            document.forms["tpSubmit"].action = "http://Tripplanner.mta.info/MyTrip/handler/Point2Point.ashx?cid=mtahome";

            document.getElementById("labelForStartAddress").innerText = "From";

            document.getElementById('divCP').style.backgroundColor = '#FFFFFF';
            document.getElementById('divSIA').style.backgroundColor = '#FFFFFF';
            document.getElementById('divSCH').style.backgroundColor = '#00C521';

            document.getElementById('divCP').style.color = '#000000';
            document.getElementById('divSIA').style.color = '#000000';
            document.getElementById('divSCH').style.color = '#FFFFFF';
            
            document.getElementById('divP2PHeadline').style.display = "none";
            document.getElementById('schMenuLinks').style.display = "block";
            document.getElementById('tpForm').style.display = "none";

            document.getElementById("divWalkDist").style.display = "block";
            document.getElementById("divEndAddress").style.display = "block";
            document.getElementById("lbltime").style.display = "block";

            document.getElementById("divTransitMode").style.display = "none";
            document.getElementById("divLeaveArr").style.display = "none";
            document.getElementById("SpanAdv").style.display = "none";

            break;
        
    }
}



function ShowSubwayP2P() {
    document.getElementById('divP2PHeadline').style.display = "block";
    document.getElementById('schMenuLinks').style.display = "none";
    document.getElementById('tpForm').style.display = "block";

    document.getElementById("divWalkDist").style.display = "block";
    document.getElementById("divEndAddress").style.display = "block";
    document.getElementById("lbltime").style.display = "block";

    document.getElementById("divTransitMode").style.display = "none";
    document.getElementById("divLeaveArr").style.display = "none";
}


</script>