var selectedLine = 1;
var selLines = '';
var selRoute = '';
var selectedStationIDs = '';
var selectedStation = ""
var ZoomMapName = 'SubwayMap';
var selectedLeftDiv = 'weekenderleftPanel';
var systemMapLoaded = false;
var zooming = false;
//weekendstatus
var ZoomInImg = false;
/* Route Array */
var routes = new Array()
routes[0] = "1"
routes[1] = "2"
routes[2] = "3"
routes[3] = "4"
routes[4] = "5"
routes[5] = "6"
routes[6] = "7"
routes[7] = "8"
routes[8] = "9"
routes[9] = "A"
routes[10] = "B"
routes[11] = "C"
routes[12] = "D"
routes[13] = "E"
routes[14] = "F"
routes[15] = "G"
routes[16] = "J"
routes[17] = "L"
routes[18] = "M"
routes[19] = "N"
routes[20] = "Q"
routes[21] = "R"
routes[22] = "S"
routes[23] = "V"
routes[24] = "W"
routes[25] = "Z"
routes[26] = "SIR"


function closeStatusDetailDiv() {
    document.getElementById("weekenderleftStatus").style.display = "none"
}

function onImgStationClick(e) {     
    onStationClick(e, e.id.split("_")[0]);
}

function onStationClick(e, stationID) {
    //showSystemDiagram()    
    if (stationID.substring(0, 5) == '99999') {
        window.open('http://www.panynj.gov/airports/jfk-airtrain.html');
    }
    else {
        if (document.getElementById("splashScreen")) {
            document.getElementById("splashScreen").style.display = "none";
        }
        if (stationMapCoordinates[stationID]) {
            recenterSystemMap(stationID)
            //getServiceStatusByStationID(e,stationID);
            //ShowStatusMessage(e)
            var stationID = e.id.split("_")[0];
            var routeID = e.id.split("_")[1];
            DisplayStatusMessage(stationID, routeID);
        }
    }
}

function getServiceStatusByStationID(stationID, routeid) {
    var divID = 1000;
    var sCount = 0;
    var statusMsg = '';
    var displayText = '';
    var statusID = '';
    
    for (i = 0; i < weekendstatus.length; i++) {
        if (weekendstatus[i].split(",")[2] == stationID) {
            if (statusID != weekendstatus[i].split(",")[0]) {
                statusID = weekendstatus[i].split(",")[0];
                //align all route images to center
                var title = GetTitle(statustext[statusID]);                
                //align all route images to center
                title = title.replace(/<img/g, "<img style='top:2px;' ")
                divID = divID + i;

                detail = GetDetail(statustext[statusID])
                //align all route images to center
                detail = detail.replace(/<img/g, "<img style='position:relative; top:2px;' ")
                title = title.replace(/<br>/g, "")
                title = '<span style="cursor:pointer;cursor:hand;font-family:arial;font-size:12px;color:#888888;font-weight:normal;" onclick="ShowHide(' + divID + ');" onMouseOver="TitleOnMouseOver(this);" onMouseOut="TitleOnMouseOut(this);">' + title + '</span><br>'

                sCount++;
                
                displayText = title + '<br/><div id=' + divID + ' style=display:none;top:20px;font-weight:normal;>' + detail;
                displayText += '<a href="http://tripplanner.mta.info/MyTrip/ui_web/customplanner/tripplanner.aspx" target=_blank><img src=images/TPLink.jpg border=0></a>';
                displayText += '<br><br></div>';

                statusMsg = statusMsg + displayText;
            }
        }
    }
    document.getElementById('statusCaptionSpan').style.display = 'inline';
    if (sCount > 1)
        document.getElementById('statusCaptionSpan').innerText = 'Select one for details';
    else
        document.getElementById('statusCaptionSpan').innerText = 'Click for details';
    if (statusMsg != undefined && statusMsg != 'undefined' && statusMsg != '') {
        statusMsg = statusMsg.replace(/travel.mtanyct/g, "tripplanner.mta")
    }
    else {
        document.getElementById('statusCaptionSpan').style.display = 'none';
        //statusMsg = '<span style="font-weight:normal;">No scheduled work affecting service at this station.</span>';
        statusMsg = getStationDefaultLanguage(stationID, routeid);  
    }
    return statusMsg
}


function getStationDefaultLanguage(stationID, routeID) {

    var defaultmsg = '<span style="font-weight:normal;">No scheduled work affecting service at this station.</span>';

    if (routeID == "B") {
        for (i = 0; i < B_Stations_Default.length; i++) {
            if (B_Stations_Default[i].split("|")[0] == stationID) {
                 defaultmsg = '<span style="font-weight:normal;">' + B_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }

    if (routeID == "Z") {
        for (i = 0; i < Z_Stations_Default.length; i++) {
            if (Z_Stations_Default[i].split("|")[0] == stationID) {
                defaultmsg = '<span style="font-weight:normal;">' + Z_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }

    if (routeID == "M") {
        for (i = 0; i < M_Stations_Default.length; i++) {
            if (M_Stations_Default[i].split("|")[0] == stationID) {
                defaultmsg = '<span style="font-weight:normal;">' + M_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }

    if (routeID == "Q") {
        for (i = 0; i < Q_Stations_Default.length; i++) {
            if (Q_Stations_Default[i].split("|")[0] == stationID) {
                defaultmsg = '<span style="font-weight:normal;">' + Q_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }

    if (routeID == "J") {
        for (i = 0; i < J_Stations_Default.length; i++) {
            if (J_Stations_Default[i].split("|")[0] == stationID) {
                defaultmsg = '<span style="font-weight:normal;">' + J_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }

    if (routeID == "5") {
        for (i = 0; i < Five_Stations_Default.length; i++) {
            if (Five_Stations_Default[i].split("|")[0] == stationID) {
                defaultmsg = '<span style="font-weight:normal;">' + Five_Stations_Default[i].split("|")[1] + '</span>'
            }
        }
    }
  
    defaultmsg = defaultmsg.replace('[TP+]', '<a href="http://tripplanner.mta.info/MyTrip/ui_web/customplanner/tripplanner.aspx" target=_blank><img src=images/TPLinkSmall.jpg border=0></a>');
    defaultmsg = defaultmsg.replace('[B]', '<span><img src=images/routes/14px/B.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[Q]', '<span><img src=images/routes/14px/Q.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[Z]', '<span><img src=images/routes/14px/Z.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[M]', '<span><img src=images/routes/14px/M.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[5]', '<span><img src=images/routes/14px/5.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[J]', '<span><img src=images/routes/14px/J.gif border=0></span>');

    return defaultmsg;

}


/* Function - to plot WhiteIcon on Clicking of the staion */
function SelectedStationSetToWhiteIcon(stationID) {
    var imgElementID = '';
    SelectedStationBackToNormalIcon();
    selectedStationIDs = '';
    for (i = 0; i < routes.length; i++) {
        imgElementID = stationID + "_" + routes[i];
        if (document.getElementById(imgElementID)) {
            plotIconByRoute(routes[i], 'White', imgElementID);
            selectedStationIDs = selectedStationIDs + imgElementID + ",";
        }
    }
    if (selectedStationIDs != '') {
        selectedStationIDs = selectedStationIDs.substring(0, selectedStationIDs.length - 1);
    }
}

/* Function - to set the White Icon back to normal|flashing */
function SelectedStationBackToNormalIcon() {
    if (selectedStationIDs) {
        var stationArray = selectedStationIDs.split(",");
        for (i = 0; i < stationArray.length; i++) {
            imgElementID = stationArray[i];
            if (document.getElementById(imgElementID)) {
                if (document.getElementById(imgElementID).name == "normal") {
                    plotIconByRoute(routes[i], 'Black', imgElementID);
                }
                else { plotIconByRoute(routes[i], 'Flashing', imgElementID); }
            }
        }
    }
}

/* Plot the Icon */
var imgpxSize = '11px';
function plotIconByRoute(routeID, iconCategory, imgsrcID) {
    var strImgsrc = '';
    if (iconCategory == 'Flashing')
        strImgsrc = 'images/FlashingDots/' + imgpxSize;
    else {
        strImgsrc = 'images/routes/' + imgpxSize + '/';
        if (iconCategory == 'White')
            strImgsrc = strImgsrc + 'White';
        else if (iconCategory == 'Black')
            strImgsrc = strImgsrc + 'Black';
        else if (iconCategory == 'Grey')
            strImgsrc = strImgsrc + 'Grey';
    }

    if (routeID == '1' || routeID == '2' || routeID == '3')
        strImgsrc = strImgsrc + '/123.gif';
    if (routeID == '4' || routeID == '5' || routeID == '6')
        strImgsrc = strImgsrc + '/456.gif';
    if (routeID == 'A' || routeID == 'C' || routeID == 'E')
        strImgsrc = strImgsrc + '/ACE.gif';
    if (routeID == 'B' || routeID == 'D' || routeID == 'F' || routeID == 'M')
        strImgsrc = strImgsrc + '/BDFM.gif';
    if (routeID == 'J' || routeID == 'Z')
        strImgsrc = strImgsrc + '/JZ.gif';
    if (routeID == 'N' || routeID == 'Q' || routeID == 'R')
        strImgsrc = strImgsrc + '/NQR.gif';
    if (routeID == 'S')
        strImgsrc = strImgsrc + '/S.gif';
    if (routeID == 'L')
        strImgsrc = strImgsrc + '/L.gif';
    if (routeID == 'G')
        strImgsrc = strImgsrc + '/G.gif';
    if (routeID == '7')
        strImgsrc = strImgsrc + '/7.gif';
    if (routeID == 'AIRTRAIN')
        strImgsrc = strImgsrc + '/NQR.gif';
    if (routeID == 'SIR')
        strImgsrc = strImgsrc + '/ACE.gif';

    document.getElementById(imgsrcID).style.height = imgpxSize;
    document.getElementById(imgsrcID).style.width = imgpxSize;
    document.getElementById(imgsrcID).src = strImgsrc;
}
/* Function to ZoomIn|ZoomOut */
var divMenuLeftWidth = 200;
function reCenter(s) {
    if (!zooming) { return false; }
    var currentCenterX = -1 * (parseInt(document.getElementById("mapDivInner").style.left) - 300);
    var currentCenterY = -1 * (parseInt(document.getElementById("mapDivInner").style.top) - 200);
    var newCenterX = currentCenterX * s;
    var newCenterY = currentCenterY * s;
    document.getElementById("mapDivInner").style.left = (-1 * (newCenterX - 300)) + "px";
    document.getElementById("mapDivInner").style.top = (-1 * (newCenterY - 200)) + "px";
}
/* function to get Dot Image Source based on IconCategory (Black|White|Falshing) */
function getDotImageSource(routeID, iconCategory) {
    var strImgsrc = '';
    if (iconCategory == 'Flashing')
        strImgsrc = 'images/FlashingDots/8px';
    else
        strImgsrc = 'images/routes/8px' + '/';

    if (iconCategory == 'White')
        strImgsrc = strImgsrc + 'White';
    if (iconCategory == 'Black')
        strImgsrc = strImgsrc + 'Black';
    if (iconCategory == 'Grey')
        strImgsrc = strImgsrc + 'Grey';
    if (iconCategory == 'LightGrey')
        strImgsrc = strImgsrc + 'LightGrey';

    if (routeID == '1' || routeID == '2' || routeID == '3')
        strImgsrc = strImgsrc + '/123.gif';
    else if (routeID == '4' || routeID == '5' || routeID == '6')
        strImgsrc = strImgsrc + '/456.gif';
    else if (routeID == 'A' || routeID == 'C' || routeID == 'E')
        strImgsrc = strImgsrc + '/ACE.gif';
    else if (routeID == 'B' || routeID == 'D' || routeID == 'F' || routeID == 'M')
        strImgsrc = strImgsrc + '/BDFM.gif';
    else if (routeID == 'J' || routeID == 'Z')
        strImgsrc = strImgsrc + '/JZ.gif';
    else if (routeID == 'N' || routeID == 'Q' || routeID == 'R')
        strImgsrc = strImgsrc + '/NQR.gif';
    else if (routeID == 'S')
        strImgsrc = strImgsrc + '/S.gif';
    else if (routeID == 'L')
        strImgsrc = strImgsrc + '/L.gif';
    else if (routeID == 'G')
        strImgsrc = strImgsrc + '/G.gif';
    else if (routeID == '7')
        strImgsrc = strImgsrc + '/7.gif';
    else if (routeID == 'SIR')
        strImgsrc = strImgsrc + '/ACE.gif';
    return strImgsrc;
}
/* Function to plot Weekend Status Icons */
function LineRenderFlashingIcons() {
    for (i = 0; i < weekendstatus.length; i++) {
        var imgElementID;
        var routeID = weekendstatus[i].split(",")[1];
        var splFlag = weekendstatus[i].split(",")[5];
        /* Special Flag - nonbliking station but has some status message */
        if (splFlag != "Y") {
            imgElementID = parseInt(weekendstatus[i].split(",")[2]);
            imgElementID = imgElementID + '_' + routeID + 'l';
            if (document.getElementById(imgElementID)) {
                document.getElementById(imgElementID).name = 'changes';
                plotLineIconByRoute(routeID, 'Flashing', imgElementID);
            }
        }
    }
}
/* function to render Normal Icons */
function LineRenderNormalIcons(route) {

    var lineArrayName = 'line_';
    lineArrayName = lineArrayName + route;
    lineArrayName = lineArrayName + '_Data';

    //if (route != 'SIR') {
        var lineStationData = eval(lineArrayName);

        for (i = 0; i < lineStationData.length; i++) {
            var statusID = '';
            var ctrlID = '';

            if (lineStationData[i].split(",")[0] != 'X') {
                lineIndex = parseInt(lineStationData[i].split(",")[0]);

                var stationrouteIndex = lineIndex + '_' + route;
                if (stationRouteMapCoordinates[stationrouteIndex]) {

                    var lineData = stationRouteMapCoordinates[stationrouteIndex];
                    var iconCategory = '';

                    xLeftPoint = parseInt(lineData.split(",")[0] * (630 / 3410) - 4) + "px";
                    yTopPoint = parseInt(lineData.split(",")[1] * (630 / 3410) - 4) + "px";
                    iconCategory = lineData.split(",")[4];

                    ctrlID = lineIndex + '_' + route + 'l';
                    statusIcon = document.createElement('img');
                    statusIcon.setAttribute('style', 'width:8px; height:8px; position:absolute; top:' + yTopPoint + '; left:' + xLeftPoint + '; cursor:pointer;');
                    statusIcon.setAttribute('onclick', 'ShowStatusMessage(this);');
                    statusIcon.setAttribute('onmouseout', 'HideStatusMessage();');

                    statusIcon.setAttribute('alt', '');
                    statusIcon.setAttribute('id', ctrlID);
                    statusIcon.style.position = "absolute";

                    statusIcon.style.top = yTopPoint;
                    statusIcon.style.left = xLeftPoint;
                    statusIcon.style.width = "8px";
                    statusIcon.style.height = "8px";
                    statusIcon.style.cursor = "pointer";

                    if (iconCategory == 'B') {
                        iconCategory = 'Black';
                        statusIcon.setAttribute('name', 'normal');
                        statusIcon.name = 'normal';
                    }
                    if (iconCategory == 'LG') {
                        iconCategory = 'LightGrey';
                        statusIcon.setAttribute('name', 'LGnormal');
                        statusIcon.name = 'LGnormal';
                    }
                    var imgSrc = getDotImageSource(route, iconCategory);
                    statusIcon.setAttribute('src', imgSrc);
                    statusIcon.src = imgSrc;

                    statusIcon.id = ctrlID;

                    statusIcon.onclick = function() { ShowStatusMessage(this); }
                    statusIcon.onmouseover = function() { LineMouseRollOver(this); }
                    statusIcon.onmouseout = function() { LineMouseRollOut(this); }
                    document.getElementById('lineIconsDiv').appendChild(statusIcon);
                }
                //else { alert(stationrouteIndex); }
            }
        }
    //}
}

/* Function - On Station Roll OnMouseOver - WhiteIcon */
function LineMouseRollOver(e) {
    var stationID = e.id.split("_")[0];
    var routeID = e.id.split("_")[1];
    routeID = routeID.substring(0, 1);
    var imgid = e.id;
    plotLineIconByRoute(routeID, 'White', e.id);
    ShowStationInfo(e);
}
/* Function - On Station Roll OnMouseOut - WhiteIcon */
function LineMouseRollOut(e) {
    var stationID = e.id.split("_")[0];
    var routeID = e.id.split("_")[1];
    routeID = routeID.substring(0, 1);
    if (document.getElementById(e.id).name == "LGnormal")
        plotLineIconByRoute(routeID, 'LightGrey', e.id);
    else if (document.getElementById(e.id).name == "normal")
        plotLineIconByRoute(routeID, 'Black', e.id);
    else
        plotLineIconByRoute(routeID, 'Flashing', e.id);

    document.getElementById('stationNameInfoDiv').style.display = 'none';
}
/* functino ShowStationName on Mouse Roll Over */
function ShowStationInfo(e) {
    
    var lineData = stationMapCoordinates[e.id.split("_")[0]];
    var xLeftPoint, yTopPoint = 0;
    var ImgID = e.id;
    var divLeftOffsetPoint, divTopOffSetPoint;

    document.getElementById('stationNameInfoDiv').innerHTML = lineData.split(",")[2];

    var imgxLeftPoint, imgyTopPoint;

    imgxLeftPoint = parseInt(document.getElementById(ImgID).style.left);
    imgyTopPoint = parseInt(document.getElementById(ImgID).style.top);

    /* Station Div Alignment based on L|R|T|B */    
    var strID = e.id.substring(0, e.id.length - 1);
    var offsetData = stationRouteMapCoordinates[strID];

    // Exception station offset Point
    if (offsetData.split(",")[3] == 'E') {
        document.getElementById('stationNameInfoDiv').style.top = "280px";
        document.getElementById('stationNameInfoDiv').style.left = "850px";
        document.getElementById('stationNameInfoDiv').style.width = "100px";
        document.getElementById('stationNameInfoDiv').style.display = 'block';
        return;
    }
        
    if (offsetData.split(",")[3] == 'L') 
    {
        divLeftOffsetPoint = eval(350);
        divTopOffSetPoint = eval(-1);
        document.getElementById('stationNameInfoDiv').style.textAlign = 'left';
    }
    if (offsetData.split(",")[3] == 'T') 
    {
        divLeftOffsetPoint = eval(347);
        divTopOffSetPoint = eval(10);
        document.getElementById('stationNameInfoDiv').style.textAlign = 'left';
    }
    if (offsetData.split(",")[3] == 'B') {
        divLeftOffsetPoint = eval(328);
        divTopOffSetPoint = eval(-17);
        document.getElementById('stationNameInfoDiv').style.textAlign = 'left';
    }
    
    if (offsetData.split(",")[3] == 'R') {
        divLeftOffsetPoint = eval(70);
        divTopOffSetPoint = eval(-1);
        document.getElementById('stationNameInfoDiv').style.textAlign = 'right';
    }    

    xLeftPoint = parseInt(imgxLeftPoint) + eval(divLeftOffsetPoint) + "px";
    yTopPoint = parseInt(imgyTopPoint) + eval(divTopOffSetPoint) + "px";

    document.getElementById('stationNameInfoDiv').style.top = yTopPoint;
    document.getElementById('stationNameInfoDiv').style.left = xLeftPoint;
    document.getElementById('stationNameInfoDiv').style.width = "250px";
    document.getElementById('stationNameInfoDiv').style.display = 'block';
}
function ChangeColor(route) {
    document.getElementById(route).src = "images/routes/22px/" + route + "_Over.gif";
}
function ChangeColorBackTo(route) {
    document.getElementById(route).src = "images/routes/22px/" + route + ".gif";
    if (route == selRoute)
        document.getElementById(route).src = "images/routes/22px/" + route + "_Over.gif";
}

function ShowAllLinePage() {
    window.location = "AlllineView.html";
}

function MakeBorderNull() {
    document.getElementById('1').src = "images/routes/22px/1.gif"
    document.getElementById('2').src = "images/routes/22px/2.gif"
    document.getElementById('3').src = "images/routes/22px/3.gif"
    document.getElementById('4').src = "images/routes/22px/4.gif"
    document.getElementById('5').src = "images/routes/22px/5.gif"
    document.getElementById('6').src = "images/routes/22px/6.gif"
    document.getElementById('A').src = "images/routes/22px/A.gif"
    document.getElementById('C').src = "images/routes/22px/C.gif"
    document.getElementById('E').src = "images/routes/22px/E.gif"
    document.getElementById('B').src = "images/routes/22px/B.gif"
    document.getElementById('D').src = "images/routes/22px/D.gif"
    document.getElementById('F').src = "images/routes/22px/F.gif"
    document.getElementById('M').src = "images/routes/22px/M.gif"
    document.getElementById('J').src = "images/routes/22px/J.gif"
    document.getElementById('Z').src = "images/routes/22px/Z.gif"
    document.getElementById('N').src = "images/routes/22px/N.gif"
    document.getElementById('Q').src = "images/routes/22px/Q.gif"
    document.getElementById('R').src = "images/routes/22px/R.gif"
    document.getElementById('7').src = "images/routes/22px/7.gif"
    document.getElementById('G').src = "images/routes/22px/G.gif"
    document.getElementById('L').src = "images/routes/22px/L.gif"
    document.getElementById('S').src = "images/routes/22px/S.gif"
    document.getElementById('SIR').src = "images/routes/22px/SIR.gif"
}

function TitleOnMouseOver(e) {
    e.style.color = "black";
}

function TitleOnMouseOut(e) {
    if (selLines == '') e.style.color = '#888888';
}


function ShowTextOnLeftDiv(selectedLine) {
    
    var title = "";
    var detail = "";
    var displayText = "";
    var allDisplayText = "";
    divID = 100;
    var sCount = 0;
    for (i = 0; i < weekendroutestatus.length; i++) {
        if (weekendroutestatus[i].split("||")[0] == selectedLine) {
            divID = divID + 1;
            title = GetTitle(weekendroutestatus[i].split("||")[2])
            //align all route images to center
            title = title.replace(/<img/g, "<img style='position:relative; top:2px;' ")
            detail = GetDetail(weekendroutestatus[i].split("||")[2])
            //align all route images to center
            detail = detail.replace(/<img/g, "<img style='position:relative; top:2px;' ")
            title = title.replace(/<br>/g, "")
            //title = title + '... <a href="#" onclick="ShowHide(' + divID + ');">more</span><br>';
            title = '<span style="cursor:pointer;cursor:hand;font-family:arial;font-size:12px;color:#888888;font-weight:normal;" onclick="ShowHide(' + divID + ');" onMouseOver="TitleOnMouseOver(this);" onMouseOut="TitleOnMouseOut(this);">' + title + '</span><br>'
            
            displayText  = title + '<br/><div id=' + divID + ' style=display:none;top:20px;font-weight:normal;>' + detail;
            displayText += '<a href="http://tripplanner.mta.info/MyTrip/ui_web/customplanner/tripplanner.aspx" target=_blank><img src=images/TPLink.jpg border=0></a>';
            displayText += '<br><br></div>';
            
            allDisplayText = allDisplayText + displayText;
            sCount++;
        }

        if (selectedLine == "ALL") {
            divID = divID + 1;
            title = GetTitle(weekendroutestatus[i].split("||")[2])
            detail = GetDetail(weekendroutestatus[i].split("||")[2])
            title = '<a style="cursor:pointer;" onclick=ShowHide(' + divID + ');>' + title + '</a>'
            displayText = title + '<br/><div id=' + divID + ' style=display:none; >' + detail + '</div>'
            allDisplayText = allDisplayText + displayText
        }
    }
    document.getElementById('linestatusCaptionSpan').style.display = 'inline';
    if (sCount > 1)
        document.getElementById('linestatusCaptionSpan').innerText = 'Select one for details';
    else
        document.getElementById('linestatusCaptionSpan').innerText = 'Click for details';

    if (allDisplayText == "") {
        allDisplayText = '<span style="font-weight:normal;">No scheduled work affecting service on this line.</span>';
        allDisplayText = getLineDefaultLanguage(selectedLine, allDisplayText);
        document.getElementById('linestatusCaptionSpan').style.display = 'none';
    }
    document.getElementById('statusDiv').style.display = "block";
    document.getElementById("statusDiv").innerHTML = allDisplayText;
}

function getLineDefaultLanguage(route, allDisplayText) {

    var defaultmsg = allDisplayText;
    
    if (route=="B")
        defaultmsg = line_B_Default[0];
    
    if (route=="Z")
        defaultmsg = line_Z_Default[0];
        
    if (route=="M")
        defaultmsg = line_M_Default[0];
        
    if (route=="Q")
        defaultmsg = line_Q_Default[0];
        
    if (route=="J")
        defaultmsg = line_J_Default[0];  
        
    if (route=="5")
        defaultmsg = line_5_Default[0];

    defaultmsg = '<br/><div id=' + route + '_default' + ' style=top:20px;font-weight:normal;>' + defaultmsg + '<br><br></div>';
    defaultmsg = defaultmsg.replace('[TP+]', '<a href="http://tripplanner.mta.info/MyTrip/ui_web/customplanner/tripplanner.aspx" target=_blank><img src=images/TPLinkSmall.jpg border=0></a>');
    defaultmsg = getdefaultMsgWithRouteImageInfo(defaultmsg);
    
    return defaultmsg;
    
}


function getdefaultMsgWithRouteImageInfo(defaultmsg) {
    var retvalue = "";

    defaultmsg = defaultmsg.replace('[B]', '<span><img src=images/routes/14px/B.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[A]', '<span><img src=images/routes/14px/A.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[C]', '<span><img src=images/routes/14px/C.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[D]', '<span><img src=images/routes/14px/D.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[Q]', '<span><img src=images/routes/14px/Q.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[Z]', '<span><img src=images/routes/14px/Z.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[M]', '<span><img src=images/routes/14px/M.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[5]', '<span><img src=images/routes/14px/5.gif border=0></span>');
    defaultmsg = defaultmsg.replace('[J]', '<span><img src=images/routes/14px/J.gif border=0></span>');

    return defaultmsg;

}

function showStatustext(id) {
    //    document.getElementById('statusDiv').style.display = "block";
    document.getElementById("statusDiv").innerHTML = weekendroutestatus[id].split("||")[2];
}


function ShowHide(div) {
    //selLines = div;
    var control = document.getElementById(div);
    if (control.style.display == "inline" || control.style.display == "" || control.style.display == "block")
        control.style.display = 'none';
    else
        control.style.display = 'inline';
}

function ShowHideLeftDiv() {
    var control;
    if (selectedLeftDiv == 'weekenderleftPanel') {
        control = document.getElementById('weekenderleftPanel');
    }
    if (selectedLeftDiv == 'weekenderleftStatus') {
        control = document.getElementById('weekenderleftStatus');
    }
    if (control.style.display == "inline" || control.style.display == "" || control.style.display == "block")
        control.style.display = 'none';
    else
        control.style.display = 'inline';
}


function GetTitle(text) {
    var startindex = 0
    var endindex = text.indexOf("$$", 0)
    var title = text.substring(startindex, endindex)
    return title
}


function GetDetail(text) {
    var startindex = text.indexOf("$$", 0)
    var detail = text.substring(startindex + 2)
    return detail
}

//* Plot the Icon */
function plotLineIconByRoute(routeID, iconCategory, imgsrcID) {
    var strImgsrc = '';
    if (iconCategory == 'Flashing')
        strImgsrc = 'images/FlashingDots/8px';
    else {
        strImgsrc = 'images/routes/8px/';
        if (iconCategory == 'White')
            strImgsrc = strImgsrc + 'White';
        if (iconCategory == 'Black')
            strImgsrc = strImgsrc + 'Black';
        if (iconCategory == 'Grey')
            strImgsrc = strImgsrc + 'Grey';
        if (iconCategory == 'LightGrey')
            strImgsrc = strImgsrc + 'LightGrey';
    }

    if (routeID == '1' || routeID == '2' || routeID == '3')
        strImgsrc = strImgsrc + '/123.gif';
    if (routeID == '4' || routeID == '5' || routeID == '6')
        strImgsrc = strImgsrc + '/456.gif';
    if (routeID == 'A' || routeID == 'C' || routeID == 'E')
        strImgsrc = strImgsrc + '/ACE.gif';
    if (routeID == 'B' || routeID == 'D' || routeID == 'F' || routeID == 'M')
        strImgsrc = strImgsrc + '/BDFM.gif';
    if (routeID == 'J' || routeID == 'Z')
        strImgsrc = strImgsrc + '/JZ.gif';
    if (routeID == 'N' || routeID == 'Q' || routeID == 'R')
        strImgsrc = strImgsrc + '/NQR.gif';
    if (routeID == 'S')
        strImgsrc = strImgsrc + '/S.gif';
    if (routeID == 'L')
        strImgsrc = strImgsrc + '/L.gif';
    if (routeID == 'G')
        strImgsrc = strImgsrc + '/G.gif';
    if (routeID == '7')
        strImgsrc = strImgsrc + '/7.gif';
    if (routeID == 'SIR')
        strImgsrc = strImgsrc + '/ACE.gif';

    document.getElementById(imgsrcID).src = strImgsrc;
}
function setCenter(t, l) {
    var imgTop = 280 - t - 5
    var imgLeft = 480 - l - 5 + 150
    document.getElementById('mapDivInner').style.top = imgTop + "px";
    document.getElementById('mapDivInner').style.left = imgLeft + "px";
}
/* Function to Show Status Message */
function ShowStatusMessage(e) {    
    var stationID = e.id.split("_")[0];
    var routeID = e.id.split("_")[1];
    routeID = routeID.substring(0, routeID.length - 1);
    DisplayStatusMessage(stationID, routeID);    
}
function DisplayStatusMessage(stationID, routeID) {
    var lineData = stationMapCoordinates[stationID];
    var stationName = lineData.split(",")[2];
    selectedStation = stationID;
    var imgID = stationID + '_' + routeID;
    if (stationRouteMapCoordinates[imgID]) {
        var lineData = stationRouteMapCoordinates[imgID];
        var l = parseInt(lineData.split(",")[0]);
        var t = parseInt(lineData.split(",")[1]);
        //var id = e.id.split("_")[0];
        document.getElementById('mapLineDivInner').style.display = 'none';
        document.getElementById('systemMap').style.display = 'inline';
        document.getElementById('weekenderleftPanel').style.display = 'block';
        recenterSystemMap(stationID)
        document.getElementById('statusOuterDiv').style.display = 'none';
        document.getElementById('stationleftStatusMessage').style.display = 'inline';

	 var routeimg = routeID;
        if (routeID == "6D")
            routeimg = "6";

        if (routeID == "7D")
            routeimg = "7";

        document.getElementById('imgSelectedLine').src = 'images/routes/14px/' + routeimg + '.gif';
        //document.getElementById('imgSelectedLine').src = 'images/routes/14px/' + routeID + '.gif';

        document.getElementById('spanStationName').innerHTML = stationName;
        document.getElementById('divNeighbourhoodLink').style.display = 'inline';
        var statusMsg = getServiceStatusByStationID(stationID, routeID)
        document.getElementById('spanStatusByStation').innerHTML = statusMsg;
        document.getElementById("spanStationView").style.color = "black";
        EnableZoomDrawerIconsInHeader();
    }
}

/* Function to Hide Status Message */
function HideStatusMessage() {
    var str = '';
    document.getElementById('stationNameInfo').style.display = "none";
}
/* function to set the Top menu links */
function stripoutTags(text, tag) {

    var re = new RegExp('<' + tag + '[^><]*>|<.' + tag + '[^><]*>', 'g');
    return text.replace(re, '');

}
function GetStatusTitle(text) {
    var startindex = 0
    var endindex = text.indexOf("$$", 0);
    var title = "<b>" + text.substring(startindex, endindex) + "</b>";
    return title;
}

/* Function to avoid duplicate heading */
function GetStatusDetailText(text) {
    var startindex = text.indexOf("$$", 0);
    var detail = text.substring(startindex + 2);
    return detail;
}


function DisplayCompleteStatus(statusID) {
    if (detail_loaded) {
        var status = statustextraw[statusID]
        document.getElementById('mapDivouter').style.display = 'none';
        document.getElementById('mapLineDivInner').style.display = 'none';
        document.getElementById("moreStatusDiv").innerHTML = "<span class='detailcenterdiv'><span class='boldtext'>Details</span><span style='position:absolute;cursor:pointer;left:575px;' onclick='hideCompleteStatus();'><b>Close</b></span></span><br>";
        document.getElementById("moreStatusDiv_raw").innerHTML = status;
        document.getElementById("moreStatusDiv_raw").style.display = "inline";
        document.getElementById("moreStatusDiv").style.display = "inline";
        document.getElementById('drawer').style.display = 'none';
        clearTimeout(timer_fun);
    }
    else {
        timer_fun = setTimeout(function() { DisplayCompleteStatus(statusID) }, 150);
    }
}

function hideCompleteStatus() {
    document.getElementById("moreStatusDiv_raw").style.display = "none";
    document.getElementById("moreStatusDiv").style.display = "none";
    document.getElementById('mapDivouter').style.display = 'block';
    document.getElementById('mapLineDivInner').style.display = 'block';
    document.getElementById('drawer').style.display = 'block';
}


/* function to change thumbnail image by Line */
function Showthumbnail(route) {
    ZoomMapName = ''
    MakeBorderNull();
    document.getElementById('systemMap').style.display = 'none';
    document.getElementById('stationleftStatusMessage').style.display = 'none';
    document.getElementById('divNeighbourhoodLink').style.display = 'none';
    document.getElementById("moreStatusDiv_raw").style.display = "none";
    document.getElementById("moreStatusDiv").style.display = "none";
    document.getElementById("neighborhoodMapDiv").style.display = "none";
    document.getElementById('mapLineDivInner').style.display = 'block';
    document.getElementById('statusOuterDiv').style.display = 'block';
    document.getElementById('mapDivouter').style.display = 'block';
    document.getElementById("lineIconsDiv").innerHTML = "";
    selRoute = route;
    document.getElementById(route).src = "images/routes/22px/" + route + "_Over.gif"
    selectedLine = route;    
    ShowTextOnLeftDiv(selectedLine);
    document.getElementById("thumbnailImg").src = 'images/linemaps/Line' + selectedLine + '.png'
    LineRenderNormalIcons(selectedLine);
    LineRenderFlashingIcons();
}

/* Function to ZoomIn */
function zoomIn() {
    if (ZoomMapName == 'neighborhoodMap') {
        zoomNeighborhoodMap(1);
    }
    if (ZoomMapName == 'SubwayMap') {
        if (parent.document.getElementById("zoom_in").src.indexOf("gray_zoom_in.png") <= 0) {
            window.frames["systemMap"].zoom(1)
        }                
    }
    if (ZoomMapName == 'BingMap') {
        window.frames[1].zoomBingMap(1);
    }
}

/* Function to ZoomOut */
function zoomOut() {
    if (ZoomMapName == 'neighborhoodMap') {
        zoomNeighborhoodMap(-1);
    }
    if (ZoomMapName == 'SubwayMap') {
        if (parent.document.getElementById("zoom_out").src.indexOf("gray_zoom_out.png") <= 0) {
            currentZoomLevel = -1;
            window.frames["systemMap"].zoom(-1);
        }
    }    
    if (ZoomMapName == 'BingMap') {
        window.frames[1].zoomBingMap(-1);
    }
}

function recenterSystemMap(staID) {
    ZoomMapName = 'SubwayMap'
    if (systemMapLoaded) {
        window.frames["systemMap"].zoom(-1);
        window.frames["systemMap"].centerOnStation(staID)
    }
    else {        
        window.frames["systemMap"].location.href = "tileMapSubway.html?staID=" + staID
    }
}

function ChangeColor2(route) {
    document.getElementById(route).src = "/weekender/images/routes/22px/" + route + ".gif";
}

function ChangeColorBackTo2(route) {
    document.getElementById(route).src = "/weekender/images/routes/22px/" + route + "_Over.gif";
    if (route == selRoute)
        document.getElementById(route).src = "/weekender/images/routes/22px/" + route + ".gif";
}

/* show line view screen with route querystring   */
function Showlineview(route) {
    var url = "/weekender/lineview.html?r=" + route;
    window.location.href = url;
}

