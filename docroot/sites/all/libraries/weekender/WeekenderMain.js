/* Global Variables */
var currentPagename = 'diagram';
var firstClick = true;
var detail_loaded = false;
var timer_fun;
var rawjsfilename = "../status/weekendstatusraw.js";

function loadjsfile(filename) {
    var fileref = document.createElement('script');
    fileref.setAttribute("type", "text/javascript");
    fileref.setAttribute("src", filename);

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
    detail_loaded = true;
}

function ShowCompleteStatus(statusID) {
    if (firstClick == true) {
        //load required js files
        loadjsfile(rawjsfilename);
        firstClick = false;
    }
    timer_fun = setTimeout(function() { DisplayCompleteStatus(statusID) }, 200);
   // DisplayCompleteStatus(statusID);
}

function getWeekendDates() {
    var months = new Array()
    months[0] = "January"
    months[1] = "February"
    months[2] = "March"
    months[3] = "April"
    months[4] = "May"
    months[5] = "June"
    months[6] = "July"
    months[7] = "August"
    months[8] = "September"
    months[9] = "October"
    months[10] = "November"
    months[11] = "December"

    var date = new Date();
    var intdaydiff = 0;

    var wkday = Date.today().getDay();
    
    if (wkday == 0) intdaydiff = -2;
    if (wkday == 1) intdaydiff = 4;  //regular weekend
    //if (wkday == 1) intdaydiff = -3;   //long weekend
    if (wkday == 2) intdaydiff = 3;
    if (wkday == 3) intdaydiff = 2;
    if (wkday == 4) intdaydiff = 1;
    if (wkday == 5) intdaydiff = 0;
    if (wkday == 6) intdaydiff = -1;

    var d1 = Date.today().add(intdaydiff).days();
    //var d2 = Date.today().add(intdaydiff+4).days();  //long weekend
    var d2 = Date.today().add(intdaydiff+3).days();    //regular weekend


    var d = d2.getDate();
    var m = d2.getMonth();
    var y = d2.getFullYear();
    //document.getElementById('dateSpan').innerText = d1.getDate() + '-' + d2.getDate() + ' ' + months[d2.getMonth()] + ' ' + y;
    return d1.getDate() + ' ' + months[d1.getMonth()] + '-' + d2.getDate() + ' ' + months[d2.getMonth()] + ' ' + y;
}
function centerPage() {
    var c = (document.body.clientWidth / 2) - (960 / 2)    
    if (c < 0) {
        c = 0
    }
    document.getElementById("mainDiv").style.left = c + "px";
    document.getElementById("mainDiv").style.display = "inline"
}
window.onresize = function() {
    centerPage()
}

function menuOver(e) {
    e.style.color = "white"
}
function menuOut(e) {
    e.style.color = "gray"
}
function childstationOver(e) {
    e.parentNode.childNodes[0].style.color = 'black';
}
function childstationOut(e) {
    e.parentNode.childNodes[0].style.color = "#888888";
    e.parentNode.childNodes[0].style.fontWeight = 'bold';
}
function stationOver(e) {
    e.style.color = "black";
}
function stationOut(e) {
    e.style.color = "#888888";
    e.style.fontWeight = "bold";
}
function AllStationMouseOver(e) {
    e.style.color = "black";
}
function AllStationMouseOut(e) {
    if (e.id == 'spanStationView' && ZoomMapName == "SubwayMap")
    { e.style.color = 'black'; }
    else {
        if (e.id == 'spanNeighborhoodView' && ZoomMapName == "neighborhoodMap")
        { e.style.color = 'black'; }
        else { e.style.color = '#888888'; }
    }
}

function menuImageOver(imgId) {
    var currentimage;
    if (imgId == 'status') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/status_over.png';
    if (imgId == 'station') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/station_over.png';
    if (imgId == 'line') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/line_over.png';
    if (imgId == 'borough') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/borough_over.png';
    if (imgId == 'planner') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/planner_over.png';
    if (imgId == 'subway') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram_over.png';
    
    //if (imgId == 'zoom_out') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_out_over.png';
    //if (imgId == 'zoom_in') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_in_over.png';

    if (imgId == 'zoom_out') {
        if (document.getElementById(imgId).src.indexOf("gray_zoom_out.png") <= 0)
            document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_out_over.png';
    }

    if (imgId == 'zoom_in') {
        if (document.getElementById(imgId).src.indexOf("gray_zoom_in.png") <= 0)
            document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_in_over.png';
    }
    
    if (imgId == 'drawer') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/drawer_over.png';
    if (imgId == 'metronorth') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/metro_north_over.png';
    if (imgId == 'lirr') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/lirr_over.png';
    if (imgId == 'buses') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/buses_over.png';
    if (imgId == 'bridges') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/bridges_over.png';
    if (imgId == 'legend') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/legend_over.png';
    if (imgId == 'mtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mta_logo_over.png';
    if (imgId == 'diagram') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram_over.png';
    if (imgId == 'footermtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mtainfo_over.png';
    if (imgId == 'mtahome') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mta_home_over.png';
    if (imgId == 'video') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/tutorial_over.gif';    
}

function menuImageOut(imgId) {
    if (imgId == 'status' && currentPagename != 'status') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/status.png';
    if (imgId == 'station' && currentPagename != 'station') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/station.png';
    if (imgId == 'line' && currentPagename != 'line') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/line.png';
    if (imgId == 'borough' && currentPagename != 'borough') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/borough.png';
    if (imgId == 'planner' && currentPagename != 'planner') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/planner.png';
    if (imgId == 'subway' && currentPagename != 'subway') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram.png';
    
    
    //if (imgId == 'zoom_out' && currentPagename != 'zoom_out') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_out.png';
    //if (imgId == 'zoom_in' && currentPagename != 'zoom_in') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_in.png';

    if (imgId == 'zoom_out' && currentPagename != 'zoom_out') 
    {
        if (document.getElementById(imgId).src.indexOf("gray_zoom_out.png") <= 0)
            document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_out.png';
    }

    if (imgId == 'zoom_in' && currentPagename != 'zoom_in') {
        if (document.getElementById(imgId).src.indexOf("gray_zoom_in.png") <= 0)
            document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_in.png';
    }
    
    if (imgId == 'drawer' && currentPagename != 'drawer') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/drawer.png';
    if (imgId == 'metronorth' && currentPagename != 'metronorth') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/metro_north.png';
    if (imgId == 'lirr' && currentPagename != 'lirr') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/lirr.png';
    if (imgId == 'buses' && currentPagename != 'buses') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/buses.png';
    if (imgId == 'bridges' && currentPagename != 'bridges') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/bridges.png';
    if (document.getElementById("LegendDiv").style.display != "block") {
        if (imgId == 'legend') document.getElementById(imgId).src = 'images/legend.png';
    }
    if (imgId == 'mtainfo' && currentPagename != 'mtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mta_logo.png';
    if (imgId == 'diagram' && currentPagename != 'diagram') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram.png';
    if (imgId == 'footermtainfo' && currentPagename != 'footermtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mtainfo.png';
    if (imgId == 'mtahome') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mta_home.png';
    if (imgId == 'video') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/tutorial.gif';    
}
function EnableLegend() {
    if (document.getElementById("LegendDiv").style.display == "block") {
        document.getElementById("LegendDiv").style.display = 'none';
    }
    else {
        document.getElementById("LegendDiv").style.display = 'block';        
        document.getElementById('legend').src = 'sites/all/themes/mta/images/weekender/legend_over.png';
    }
}

function EnableZoomDrawerIconsInHeader() {
    document.getElementById("zoom_out").style.display = 'block';
    document.getElementById("zoom_in").style.display = 'block';
    document.getElementById("drawer").style.display = 'block';
}

function DisableZoomDrawerIconsInHeader() {
    document.getElementById("zoom_out").style.display = 'none';
    document.getElementById("zoom_in").style.display = 'none';
    document.getElementById("drawer").style.display = 'none';
}

function getPosition(e) {
    e = e || window.event;
    var cursor = { x: 0, y: 0 };
    if (e.pageX || e.pageY) {
        cursor.x = e.pageX;
        cursor.y = e.pageY;
    }
    else {
        var de = document.documentElement;
        var b = document.body;
        cursor.x = e.clientX +
            (de.scrollLeft || b.scrollLeft) - (de.clientLeft || 0);
        cursor.y = e.clientY +
            (de.scrollTop || b.scrollTop) - (de.clientTop || 0);
    }
    return cursor;
}

function setPageMenuSelection(imgId) {
    if (imgId == 'status') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/status_over.png';
    if (imgId == 'station') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/station_over.png';
    if (imgId == 'line') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/line_over.png';
    if (imgId == 'borough') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/borough_over.png';
    if (imgId == 'planner') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/planner_over.png';
    if (imgId == 'subway') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram_over.png';
    if (imgId == 'zoom_out') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_out_over.png';
    if (imgId == 'zoom_in') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/zoom_in_over.png';
    if (imgId == 'drawer') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/drawer_over.png';
    if (imgId == 'metronorth') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/metro_north_over.png';
    if (imgId == 'lirr') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/lirr_over.png';
    if (imgId == 'buses') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/buses_over.png';
    if (imgId == 'bridges') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/bridges_over.png';
    if (imgId == 'diagram') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/diagram_over.png';
    if (imgId == 'legend') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/legend_over.png';
    if (imgId == 'mtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mta_logo.png';
    if (imgId == 'footermtainfo') document.getElementById(imgId).src = 'sites/all/themes/mta/images/weekender/mtainfo_over.png';
    currentPagename = imgId;
}
function ShowHideLeftDiv() {
    var control;
    /*if(selectedLeftDiv == 'weekenderleftPanel')
    {
    control = document.getElementById('weekenderleftPanel');
    }
    if(selectedLeftDiv == 'weekenderleftStatus')
    {
    control = document.getElementById('weekenderleftStatus');
    }		
    if (control.style.display == "inline" || control.style.display == "" || control.style.display == "block")
    control.style.display = 'none';
    else
    control.style.display = 'inline';*/
    control = document.getElementById('weekenderleftPanel');
    setDivVisibility(control);
}
function setDivVisibility(control) {
    if (control.style.display == "inline" || control.style.display == "" || control.style.display == "block")
        control.style.display = 'none';
    else
        control.style.display = 'block';
}

function onSystemDiagramClick(e) {

    var x = getPosition(e).x;
    alert(x);
    var y = getPosition(e).y;
    //window.location.href = 'subwaydiagram.html?x=' + x + '&y=' + y;
}
function onSystemDiagramClickXY(x, y) {
    //window.location.href = 'subwaydiagram.html?x=' + x + '&y=' + y;
    window.location.href = 'stationview.html?x=' + x + '&y=' + y;
}