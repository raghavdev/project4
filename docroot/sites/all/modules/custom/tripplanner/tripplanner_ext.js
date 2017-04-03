//
//This js is used from mta.home page. The main difference between this and triplanner.js is that it has date/time
//function for the calendar control and code for service in the area and point to point is not included.

//This file is used for widgets also

//date/time
//var loadDate = new Date();
//var loadHour = loadDate.getHours()
//var loadMinute = loadDate.getMinutes()
//var loadAMPM
//if (loadHour > 11) {
//    loadAMPM = 1
//}
//else {
//    loadAMPM = 0
//}

//if (loadHour > 12) {
//    loadHour = loadHour - 12
//}

//if (loadHour == 0) {
//    loadHour = 12
//}

//alert('tpload');
//takes out 2 digit from 4 digit year
function reformatDate(d) {
    var r
    r = d.split("/")[0] + "/" + d.split("/")[1] + "/" + d.split("/")[2].substr(2, 2)
    return (r)
}

function formatMinute(m) {
    var r
    if (m.toString().length < 2) {
        r = "0" + m.toString()
    }
    else {
        r = m.toString()
    }
    return r
}
//end date/time

var g_BrowserType = "EXTERNAL-PAGE";
var useFromSuggestion
var useToSuggestion

var fromSuggestionIndex = 0;
var fromAddressIndex = 0;

var fromCoordinates
var toCoordinates

var fromAddress
var toAddress


var map1

var mapCenterLat = "40.73013692682768"
var mapCenterLon = "-73.99131059646606"
var mapZoomLevel = "14"
var mapStyle = "r"

var landmark_id = 0;

//limit Bing address resolution to NY Metro area (found let lon from http://www.mashupsoft.com/maps/latlonlocator)
//east - Suffolk County Parkland 41.07,-71.84
//west - port jervis             41.57,-74.90
//north - wassic                   41.81,  -73.55
//south tottenville SI             40.495,-74.24

var lon_min = -74.90;  //x coordinate min
var lon_max = -71.84;  // x coordinate max

var lat_min = 40.495;   //y coordinate min
var lat_max = 41.85;   //y coordinate Max




//called from mta home page and interactive map and widgets
function GoToTPResult() {//alert('GoToTPResult');
    g_BrowserType = "EXTERNAL-PAGE";
    //calling startmap here instaed of onload of body tag of mta home page, So that mta home page is faster
    startMap();
    //Validation if Origin and destination address entered
    if (!checkAddressFields()) {
        return false;
    }
	alert('!');
    submitAddresses();
}


//called from mta home page - advance option
function GoToTripplaner() {
    g_BrowserType = "EXTERNAL-ADV-OPTION";
    //calling startmap here instaed of onload of body tag of mta home page, So that mta home page is faster
    startMap();
    var TPAddressDefaultMsg = "Full Address, Landmark or Station Name"

    //we want to go to TP+ page even without entering start and End address from TP+ box on mta home page
    if (document.getElementById('txtOriginInput').value == TPAddressDefaultMsg || document.getElementById('txtDestinationInput').value == TPAddressDefaultMsg) {
        window.location = "http://tripplanner.mta.info/MyTrip/"
    }
    else {
        submitAddresses();
    }


}

function IsNYMetroAddress(lat, lon) {
    if (lat > lat_min && lat < lat_max && lon > lon_min && lon < lon_max) {
        return true;
    }
    else {
        return false;
    }
}

// To Load and Show Origin List using Landmark
function ShowOriginListUsingLandmark(limit) {

    HideList('toAutoFillList');
    var j
    if (limit == -1)// means show all landmark in first go
    {
        j = 100;
    }
    else // means show first 20 and then more...
    {
        j = 20;
    }
    showSubmitButton();
    useFromSuggestion = false;
    var input = document.getElementById('txtOriginInput').value;

    var suggestItems = 0; // No of suggested
    var x = 0; // Match count

    var moreText = "";

    var htmlText = "";

    // Loop all Landmark array
    for (i = 0; i < lListArray.length; i++) {
        // add into HTML till count j
        if (input.length > 0 && lListArray[i].split('$')[2].substr(0, input.length).toLowerCase() == input.toLowerCase() && x < j) {
            x = x + 1;
            htmlText = htmlText + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick='SetOriginTextBoxValueUsingLandmark(" + i + ")'>" + lListArray[i].split('$')[2] + "</td></tr>"
            suggestItems = suggestItems + 1;
        }
    }
    if (x == 20) {
        moreText = "<tr><td style='cursor:pointer; font-weight:bold; background-color:silver; color:black; padding:2px;' onclick='ShowOriginListUsingLandmark(-1)'>More...</td></tr>"
    }
    htmlText = htmlText + moreText
    document.getElementById("fromAutoFillList").style.zIndex = 1000
    document.getElementById("fromAutoFillList").innerHTML = "<table class='listing'>" + htmlText + "</table>"
    if (suggestItems > 0) {
        document.getElementById("fromAutoFillList").style.visibility = "visible"
        if (limit == -1) {
            document.getElementById("fromAutoFillList").style.height = "600px"
            document.getElementById("fromAutoFillList").style.width = "220px"
            document.getElementById("fromAutoFillList").style.overflow = "auto"
        }
        else {
            document.getElementById("fromAutoFillList").style.height = "20px"
            document.getElementById("fromAutoFillList").style.width = "200px"
            document.getElementById("fromAutoFillList").style.overflow = "visible"
        }
    }
    else {
        document.getElementById("fromAutoFillList").style.visibility = "hidden"
    }
}

function ShowDestinationListUsingLandmark(limit) {
    HideList('fromAutoFillList');
    var j
    if (limit == -1) {
        j = 100
    }
    else {
        j = 20
    }

    showSubmitButton()
    useToSuggestion = false
    var input
    input = document.getElementById('txtDestinationInput').value

    var suggestItems = 0
    var x
    x = 0

    var moreText = ""

    var htmlText
    htmlText = ""
    for (i = 0; i < lListArray.length; i++) {
        if (input.length > 0 && lListArray[i].split('$')[2].substr(0, input.length).toLowerCase() == input.toLowerCase() && x < j) {
            x = x + 1
            htmlText = htmlText + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick='SetDestinationTextBoxValueUsingLandmark(" + i + ")'>" + lListArray[i].split('$')[2] + "</td></tr>"
            suggestItems = suggestItems + 1
        }
    }

    if (x == 20) {
        moreText = "<tr><td style='cursor:pointer; font-weight:bold; background-color:silver; color:black; padding:2px;' onclick='ShowDestinationListUsingLandmark(-1)'>More...</td></tr>"
    }

    htmlText = htmlText + moreText

    document.getElementById("toAutoFillList").innerHTML = "<table class='listing'>" + htmlText + "</table>"
    if (suggestItems > 0) {
        document.getElementById("toAutoFillList").style.visibility = "visible"
        if (limit == -1) {
            document.getElementById("toAutoFillList").style.height = "600px"
            document.getElementById("toAutoFillList").style.width = "220px"
            document.getElementById("toAutoFillList").style.overflow = "auto"
        }
        else {
            document.getElementById("toAutoFillList").style.height = "20px"
            document.getElementById("toAutoFillList").style.width = "200px"
            document.getElementById("toAutoFillList").style.overflow = "visible"
        }
    }
    else {
        document.getElementById("toAutoFillList").style.visibility = "hidden"
    }

}



// Set Origin text box value from Landmark suggestion list
function SetOriginTextBoxValueUsingLandmark(i) {
    //var atisId = "0";
    //lListArray[i] has lat$lon$address
    var coordinateString = lListArray[i];
    useFromSuggestion = true;
    document.getElementById('txtOriginInput').value = lListArray[i].split("$")[2]
    fromCoordinates = coordinateString;
    setMyCookie(fromCoordinates, 'txtOriginInput');
    HideList('fromAutoFillList');
}

// Set Destination text box value from Landmark suggestion list
function SetDestinationTextBoxValueUsingLandmark(i) {
    //var atisId = "0";
    var coordinateString = lListArray[i];
    useToSuggestion = true
    document.getElementById('txtDestinationInput').value = lListArray[i].split("$")[2]
    toCoordinates = coordinateString;
    setMyCookie(toCoordinates, 'txtDestinationInput');
    HideList('toAutoFillList');
}

// Called from onClick from suggested drop down list (MAP API call back)
function SetOriginAddress(lat, lon, fullAddress) {

    document.getElementById('txtOriginInput').value = fullAddress;
    fromCoordinates = lat + "$" + lon + "$" + fullAddress + "$" + landmark_id;
    useFromSuggestion = true;
    setMyCookie(fromCoordinates, 'txtOriginInput');
    //Close DDL
    HideList('fromAutoFillList');

    if (document.getElementById('currentmodule').value != "serviceinthearea") {
        // Check if destination address available from Landmark or cookie
        if (!useToSuggestion)//if ToAddress coordinates are not available then go to map api
        {
            //Check TO address againt landmarklist if user did not select from list
            var matchIndex = FindExactMatchFromLandmarlist(toAddress);
            if (matchIndex >= 0) {
                SetDestinationTextBoxValueUsingLandmark(matchIndex)
                submitTPForm();
            }
            //Go to map api
            else {
                // set Destination coordinate to empty
                toCoordinates = "";
                // MAP API call to fetch coordinate for destination address entered/selected by user
                FetchResultsForDestinationAddress(toAddress);
            }
        }
        else {
            submitTPForm();
        }
    }
    else {
        submitTPForm();
    }

}


// Called from onClick to suggested drop down list (MAP API call back)
function SetDestinationAddress(lat, lon, fullAddress) {

    document.getElementById('txtDestinationInput').value = fullAddress;
    toCoordinates = lat + "$" + lon + "$" + fullAddress + "$" + landmark_id;
    useToSuggestion = true;
    setMyCookie(toCoordinates, 'txtDestinationInput');
    //Close DDL
    HideList('toAutoFillList');
    if (AreOriginAndDestinationCoordinateAvailable()) {
        hideSubmitButton();
        submitTPForm();
    }
}



// Function called from on click of "submit" button
function submitAddresses() {


    var inputdate = document.forms["tpForm"].elements["date"].value;
    if (!checkdate(inputdate)) {
        return false;
    }
    // Hide submit button and show "wait..." text
    hideSubmitButton();


    //Origin address
    fromAddress = document.getElementById('txtOriginInput').value
    if (document.getElementById('currentmodule').value == "serviceinthearea") {

        // Check if origin address available from Landmark or cookie
        if (!useFromSuggestion)//if fromAddress coordinates are not available then go to map api
        {
            // set origin coordinate to empty
            fromCoordinates = "";
            // MAP API call to fetch coordinate for origin address enteredselected by user
            FetchResultsForOriginAddress(fromAddress)
        }
        else {
            submitTPForm();
        }

    }

    else {

        //Destination address
        toAddress = document.getElementById('txtDestinationInput').value

        var matchIndex;

        // Check if origin address available from Landmark or cookie    
        if (!useFromSuggestion)//if user did not select from landmark list, check for exct match before sending to map api
        {
            //Check FROM address againt landmarklist if user did not select from list
            matchIndex = FindExactMatchFromLandmarlist(fromAddress);
            if (matchIndex >= 0) {
                SetOriginTextBoxValueUsingLandmark(matchIndex)
                useFromSuggestion = true;
                if (!useToSuggestion)//check for exact match for TO address
                {
                    //Check TO address againt landmarklist for exact match if user did not select from list
                    matchIndex = FindExactMatchFromLandmarlist(toAddress);
                    if (matchIndex >= 0) {
                        SetDestinationTextBoxValueUsingLandmark(matchIndex)
                        submitTPForm();
                    }
                    //Go to map api
                    else {
                        // set Destination coordinate to empty
                        toCoordinates = "";
                        // MAP API call to fetch coordinate for destination address entered/selected by user
                        FetchResultsForDestinationAddress(toAddress);
                    }
                }
                if (useFromSuggestion && useToSuggestion) {
                    submitTPForm();
                }
            }
            //Go to map api
            else {
                // set origin coordinate to empty
                fromCoordinates = "";
                // MAP API call to fetch coordinate for origin address enteredselected by user
                FetchResultsForOriginAddress(fromAddress)
            }
        }

        // Check if destination address available from Landmark or cookie
        else if (!useToSuggestion)//if user did not select TO address from landmark list, check for exct match before sending to map api
        {
            //Check TO address againt landmarklist if user did not select from list
            matchIndex = FindExactMatchFromLandmarlist(toAddress);
            if (matchIndex >= 0) {
                SetDestinationTextBoxValueUsingLandmark(matchIndex)
                submitTPForm();
            }
            //Go to map api
            else {
                // set Destination coordinate to empty
                toCoordinates = "";
                // MAP API call to fetch coordinate for destination address entered/selected by user
                FetchResultsForDestinationAddress(toAddress);
            }
        }
        else if (useFromSuggestion && useToSuggestion) {
            submitTPForm();
        }
    }

}

function FindExactMatchFromLandmarlist(address) {
    var matchFound;
    for (i = 0; i < lListArray.length; i++) {
        if (lListArray[i].split('$')[2].toLowerCase() == trim(address.toLowerCase())) {
            matchFound = true;
            return i;
        }
    }
    if (!(matchFound)) {
        return -1;
    }
}

//functions to trim in javascript
function trim(stringToTrim) {
    return stringToTrim.replace(/^\s+|\s+$/g, "");
}
function ltrim(stringToTrim) {
    return stringToTrim.replace(/^\s+/, "");
}
function rtrim(stringToTrim) {
    return stringToTrim.replace(/\s+$/, "");
}


function AreOriginAndDestinationCoordinateAvailable() {
    if (fromCoordinates == "" || toCoordinates == "") {
        return false;
    }
    return true;
}


//validate date from mta home page
function checkdate(input) {
    var validformat = /^\d{2}\/\d{2}\/\d{4}$/ //Basic check for format validity
    var returnval = false
    if (!validformat.test(input))
        showTPAlert("Invalid Date Format. Please correct and submit again.")
    else { //Detailed check for valid date ranges
        var monthfield = input.split("/")[0]
        var dayfield = input.split("/")[1]
        var yearfield = input.split("/")[2]
        var dayobj = new Date(yearfield, monthfield - 1, dayfield)
        if ((dayobj.getMonth() + 1 != monthfield) || (dayobj.getDate() != dayfield) || (dayobj.getFullYear() != yearfield))
            showTPAlert("Invalid Day, Month, or Year range detected. Please correct and submit again.")
        else
            returnval = true
    }
    return returnval
}

function checkAddressFields() {

    var TPAddressDefaultMsg = "Full Address, Landmark or Station Name"

    if (document.getElementById('currentmodule').value == "serviceinthearea") {
        if (document.getElementById('txtOriginInput').value == "" || document.getElementById('txtOriginInput').value == TPAddressDefaultMsg) {
            showTPAlert("Please enter From address.");
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if (document.getElementById('txtDestinationInput').value == "" || document.getElementById('txtOriginInput').value == "" || document.getElementById('txtDestinationInput').value == TPAddressDefaultMsg || document.getElementById('txtOriginInput').value == TPAddressDefaultMsg) {
            showTPAlert("Please enter From and To address.");
            return false;
        }
        else {
            return true;
        }
    }
}

function showTPAlert(msg) {
    document.getElementById("tpAlert").innerHTML = msg + "<br /><br /><span style='cursor:pointer' onclick='hideTPAlert()'>OK</span>"
    document.getElementById("tpAlert").style.display = "inline"
}

function hideTPAlert() {
    document.getElementById("tpAlert").style.display = "none"
    showSubmitButton()
}



function startMap() {
    //clearForm();
    map1 = new VEMap('map1');
    if (bingMapToken != "") {
        map1.SetClientToken(bingMapToken);
    }
}

//moved to smartTrip.js
//function SetTimeMyTrip() {

//    document.forms["tpForm"].elements["ampm"].selectedIndex = loadAMPM
//    document.forms["tpForm"].elements["minute"].selectedIndex = loadMinute
//    document.forms["tpForm"].elements["hour"].selectedIndex = loadHour - 1

//}



// MAP API Call
// Call Back function "ProcessOriginResult"
function FetchResultsForOriginAddress(address) {
    startMap();
    map1.LoadMap(new VELatLong(mapCenterLat, mapCenterLon), mapZoomLevel, mapStyle, false);
    map1.Find("address", address, null, null, 0, 10, true, false, false, false, ProcessOriginResult);
}


//from map api
function LoadMultipleOriginOption(places) {

    var html = ""
    for (i = 0; i < places.length; i++) {

        if (places[i].LatLong.Latitude.toString().indexOf(".") != -1) {
            lat = places[i].LatLong.Latitude.toString().split('.')[0] + "." + (places[i].LatLong.Latitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lat = places[i].LatLong.Latitude.toString() + "." + "00000";
        }

        if (places[i].LatLong.Longitude.toString().indexOf(".") != -1) {
            lon = places[i].LatLong.Longitude.toString().split('.')[0] + "." + (places[i].LatLong.Longitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lon = places[i].LatLong.Longitude.toString() + "." + "00000";
        }

        //exclude addresses outside NY area from the html list
        if (IsNYMetroAddress(lat, lon) == true) {
            fullAddress = places[i].Name;
            html = html + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick=\"SetOriginAddress(" + lat + "," + lon + ",\'" + fullAddress + "\'" + ")\">" + fullAddress + "</td></tr>"
        }
    }
    if (html == "") {
        showTPAlert("START address is outside NY Metro area. Please enter address again.")
        return false;
    }
    else {
        document.getElementById("fromAutoFillList").innerHTML = "<table class='listing'>" + html + "</table>"
        document.getElementById("fromAutoFillList").style.visibility = "visible"
    }

}


//from map api
function LoadMultipleDestinationOption(places) {
    var html = "";
    for (i = 0; i < places.length; i++) {

        if (places[i].LatLong.Latitude.toString().indexOf(".") != -1) {
            lat = places[i].LatLong.Latitude.toString().split('.')[0] + "." + (places[i].LatLong.Latitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lat = places[i].LatLong.Latitude.toString() + "." + "00000";
        }

        if (places[i].LatLong.Longitude.toString().indexOf(".") != -1) {
            lon = places[i].LatLong.Longitude.toString().split('.')[0] + "." + (places[i].LatLong.Longitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lon = places[i].LatLong.Longitude.toString() + "." + "00000";
        }

        //exclude addresses outside NY area from the html list
        if (IsNYMetroAddress(lat, lon) == true) {
            fullAddress = places[i].Name;
            html = html + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick=\"SetDestinationAddress(" + lat + "," + lon + ",\'" + fullAddress + "\'" + ")\">" + fullAddress + "</td></tr>"
        }
    }
    if (html == "") {
        showTPAlert("Destination address is outside NY Metro area. Please enter address again.")
        return false;
    }
    else {
        document.getElementById("toAutoFillList").innerHTML = "<table class='listing'>" + html + "</table>"
        document.getElementById("toAutoFillList").style.visibility = "visible"
    }
}


// Process Origin Coordinate(s) returned from Map API.
function ProcessOriginResult(layer, resultsArray, places, hasMore, veErrorMessage) {//debugger;
    var lat
    var lon
    var address
    if (places == null) {
        showTPAlert("Cannot find START address\n Please check spelling and format.")
        return false;
    }
    // if MAP API returns only single place then fill Global varible fromCoordinates
    if (places.length == 1) {

        if (places[0].LatLong.Latitude.toString().indexOf(".") != -1) {
            lat = places[0].LatLong.Latitude.toString().split('.')[0] + "." + (places[0].LatLong.Latitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lat = places[0].LatLong.Latitude.toString() + "." + "00000";
        }

        if (places[0].LatLong.Longitude.toString().indexOf(".") != -1) {
            lon = places[0].LatLong.Longitude.toString().split('.')[0] + "." + (places[0].LatLong.Longitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lon = places[0].LatLong.Longitude.toString() + "." + "00000";
        }


        if (IsNYMetroAddress(lat, lon) == false) {
            showTPAlert("START address is outside NY Metro area. Please enter address again.")
            return false;
        }

        address = places[0].Name;
        fromCoordinates = lat + "$" + lon + "$" + address + "$" + landmark_id;

        document.getElementById('txtOriginInput').value = address;
        // set Origin cookie when we found origin coordinate
        setMyCookie(fromCoordinates, 'txtOriginInput');
        if (document.getElementById('currentmodule').value != "serviceinthearea") {
            // Check if destination address available from Landmark or cookie
            if (!useToSuggestion)//if user did not select TO address from landmark list, check for exct match before sending to map api
            {
                //Check TO address againt landmarklist if user did not select from list
                var matchIndex = FindExactMatchFromLandmarlist(toAddress);
                if (matchIndex >= 0) {
                    SetDestinationTextBoxValueUsingLandmark(matchIndex)
                    submitTPForm();
                }
                //Go to map api
                else {
                    // set Destination coordinate to empty
                    toCoordinates = "";
                    // MAP API call to fetch coordinate for destination address entered/selected by user
                    FetchResultsForDestinationAddress(toAddress);
                }
            }

            else {
                submitTPForm();



            }
        }
        else {
            submitTPForm();
        }

    }
    // if MAP API returns multiple place then give option to user to choose from in drop down list
    else {
        LoadMultipleOriginOption(places);
        showSubmitButton();
    }
}


// MAP API Call
// Call Back function "ProcessDestinationResult"
function FetchResultsForDestinationAddress(address) {

    //if map is loaded already, do not load again
    //if useFromSuggestion is true then load the map as it was not loaded for start address
    if (useFromSuggestion) {
        startMap();
        map1.LoadMap(new VELatLong(mapCenterLat, mapCenterLon), mapZoomLevel, mapStyle, false);
    }

    //map.find API parameter list
    // VEMap.Find(what, where, findType, shapeLayer, startIndex, numberOfResults, showResults, createResults, useDefaultDisambiguation, setBestMapView, callback);
    map1.Find("address", address, null, null, 0, 10, true, false, false, false, ProcessDestinationResult);


}


// Process Destination Coordinate(s) returned from Map API.
function ProcessDestinationResult(layer, resultsArray, places, hasMore, veErrorMessage) {

    var lat
    var lon
    var address
    if (places == null) {
        showTPAlert("Cannot find Destination address\n Please check spelling and format.")
        return false;
    }
    // if MAP API returns only single place then fill Global varible toCoordinates
    if (places.length == 1) {

        if (places[0].LatLong.Latitude.toString().indexOf(".") != -1) {
            lat = places[0].LatLong.Latitude.toString().split('.')[0] + "." + (places[0].LatLong.Latitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lat = places[0].LatLong.Latitude.toString() + "." + "00000";
        }

        if (places[0].LatLong.Longitude.toString().indexOf(".") != -1) {
            lon = places[0].LatLong.Longitude.toString().split('.')[0] + "." + (places[0].LatLong.Longitude.toString().split('.')[1] + "00000").substr(0, 6)
        }
        else {
            lon = places[0].LatLong.Longitude.toString() + "." + "00000";
        }

        if (IsNYMetroAddress(lat, lon) == false) {
            showTPAlert("Destination address is outside NY Metro area. Please enter address again.")
            return false;
        }

        address = places[0].Name;
        toCoordinates = lat + "$" + lon + "$" + address + "$" + landmark_id;

        document.getElementById('txtDestinationInput').value = address;

        // set Destination cookie when we found origin coordinate
        setMyCookie(toCoordinates, 'txtDestinationInput');
        // submit form only when origin and destination co-ordinate available
        if (AreOriginAndDestinationCoordinateAvailable()) {
            submitTPForm()
        }
        else {
            // if coordinate not available then show submit button
            showSubmitButton();
        }
    }
    // if MAP API returns multiple place then give option to user to choose from in drop down list
    else {
        LoadMultipleDestinationOption(places);
        showSubmitButton();
    }
}

function HideList(listId) {
    if (document.getElementById(listId)) {
        document.getElementById(listId).style.visibility = "hidden"
    }
}

function hideSubmitButton() {
    document.getElementById("submitButton").style.display = "none"
    document.getElementById("waitMsg").style.display = "inline"
}

function showSubmitButton() {
    document.getElementById("submitButton").style.display = "inline"
    document.getElementById("waitMsg").style.display = "none"
}

function initialDisplayDate() {
    var dy
    var dt

    dy = loadDate.getDate().toString()
    if (dy.length < 2) {
        dy = "0" + dy
    }
    dt = (loadDate.getMonth() + 1).toString() + "/" + dy + "/" + loadDate.getFullYear().toString()
    return dt
}


function clearForm() {

    useFromSuggestion = false
    useToSuggestion = false
    useFromAddressSelection = false
    fromSuggestionIndex = 0
    fromAddressIndex = 0

    //document.getElementById('txtOriginInput').value = ""
    //document.getElementById('txtDestinationInput').value = ""

    showSubmitButton()
}



var Arrdep
var AccessibleTrip
var month
var day
var hour
var minute
var ampm
var minimize = "X"; //Transfer
var walkdistance = "0.50" //default
var mode = "FRBC1";
var selectedDate
var originCoors
var destinationCoors
var startAddr
var endAddr
var lineStart = "";
var startServiceType = "train"; //default
var startTrainType = "subway" //default
var startBorough = "MN"; //default

var lineEnd = "";
var endServiceType = "train"; //default
var endTrainType = "subway" //default
var endBorough = "MN"; //default
var walkincrease = "" //default
var maxinitialwait = "" //default
var maxtriptime = "" //default
var maxtransfers = ""//default



//used for managing state for route preference not sent for itinerary web service
function GetVariablesForStartRoute() {
    if (document.getElementById('trainStart').checked == true) {
        startServiceType = "train";
        startTrainType = document.getElementById('SelectStartTrainType').value;
        //select mode in backgrond if not selected by user but route preference for that mode is selected
        switch (startTrainType) {
            case "subway":
                document.getElementById('xmodeR').checked = true; break;
            case "LIRR":
                document.getElementById('xmodeCT').checked = true; break;
            case "MNR":
                document.getElementById('xmodeCT').checked = true; ; break;
        }
    }
    else if (document.getElementById('busStart').checked == true) {
        startServiceType = "bus";
        startBorough = document.getElementById('SelectStartBoro').value;
        //if radio button busstart is selected for route preference, the mode should include bus when submitting
        if (document.getElementById('xmodeB').checked == false) {
            document.getElementById('xmodeB').checked = true;
        }
    }
    else if (document.getElementById('XbusStart').checked == true) {
        startServiceType = "Xbus";
        startBorough = document.getElementById('SelectStartBoro').value;
        //set mode in the background
        if (document.getElementById('xmodeX').checked == false) {
            document.getElementById('xmodeX').checked = true;
        }
    }
}


function GetVariablesForEndRoute() {
    if (document.getElementById('trainEnd').checked == true) {
        endServiceType = "train";
        endTrainType = document.getElementById('SelectEndTrainType').value;
        //set mode
        switch (endTrainType) {
            case "subway":
                document.getElementById('xmodeR').checked = true; break;
            case "LIRR":
                document.getElementById('xmodeCT').checked = true; break;
            case "MNR":
                document.getElementById('xmodeCT').checked = true; ; break;
        }
    }
    else if (document.getElementById('busEnd').checked == true) {
        endServiceType = "bus";
        endBorough = document.getElementById('SelectEndBoro').value;
        //set mode
        if (document.getElementById('xmodeB').checked == false) {
            document.getElementById('xmodeB').checked = true;
        }

    }
    else if (document.getElementById('XbusEnd').checked == true) {
        endServiceType = "Xbus";
        endBorough = document.getElementById('SelectEndBoro').value;
        //set mode
        if (document.getElementById('xmodeX').checked == false) {
            document.getElementById('xmodeX').checked = true;
        }

    }
}


function submitTPForm() {
    originCoors = fromCoordinates

    startAddr = document.getElementById('txtOriginInput').value;

    if (document.getElementById('txtDestinationInput')) {
        endAddr = document.getElementById('txtDestinationInput').value;
        destinationCoors = toCoordinates
    }

    AccessibleTrip = 'N';
    if (document.getElementById('accessibleChkbox').checked == true) {
        AccessibleTrip = 'Y'
    }

    hour = document.getElementById('ddlHour').options[document.getElementById('ddlHour').selectedIndex].value;
    minute = formatMinute(document.getElementById('ddlMinute').selectedIndex);
    ampm = document.getElementById('ddlampm').options[document.getElementById('ddlampm').selectedIndex].value;
    selectedDate = reformatDate(document.forms["tpForm"].elements["date"].value);


    if (document.getElementById('ddlWalkdistance') != null && document.getElementById('ddlWalkdistance') != "") {
        walkdistance = document.getElementById('ddlWalkdistance').options[document.getElementById('ddlWalkdistance').selectedIndex].value;
    }


    //Tripplanner Request
    if (document.getElementById('currentmodule').value == "tripplanner") {
        if ((document.getElementById('xmodeR').checked == 0) && (document.getElementById('xmodeB').checked == 0) && (document.getElementById('xmodeX').checked == 0) && (document.getElementById('xmodeCT').checked == 0)) {
            showTPAlert("You must choose Travel mode before proceeding.");
        }
        else {

            if (document.getElementById('DepId')) {
                if (document.getElementById('DepId').checked == true) {
                    Arrdep = document.getElementById('DepId').value;
                }
                else if (document.getElementById('ArrId').checked == true) {
                    Arrdep = document.getElementById('ArrId').value;
                }
            }

            if (document.getElementById('ddlminimize')) {
                if (document.getElementById('ddlminimize').selectedIndex != -1) {
                    minimize = document.getElementById('ddlminimize').options[document.getElementById('ddlminimize').selectedIndex].value;
                }
            }

            if (document.getElementById('lineStart')) {
                if (document.getElementById('lineStart').selectedIndex != -1) {
                    lineStart = document.getElementById('lineStart').options[document.getElementById('lineStart').selectedIndex].value;
                    if (lineStart == "0") {
                        lineStart = ""
                    }
                    else {
                        GetVariablesForStartRoute(); //for maintaining state for Route Preference
                    }
                }
                if (document.getElementById('lineEnd').selectedIndex != -1) {
                    lineEnd = document.getElementById('lineEnd').options[document.getElementById('lineEnd').selectedIndex].value;
                    if (lineEnd == "0") {
                        lineEnd = ""
                    }
                    else {
                        GetVariablesForEndRoute(); //for maintaining state for Route Preference
                    }
                }
            }

            if (document.getElementById('xmodeR')) {
                //set mode after checking linestart and lineEnd, Because is set in the background 
                //if user does not elect the mode but route preference for that mode.
                mode = "F"  //F is for staten ISland Ferry, always include that
                if (document.getElementById('xmodeR').checked == true) {
                    mode = mode + "R";  //rail (means subway)
                }
                if (document.getElementById('xmodeB').checked == true) {
                    mode = mode + "B";  //local bus
                }
                if (document.getElementById('xmodeX').checked == true) {
                    mode = mode + "X";  //express bus
                }
                if (document.getElementById('xmodeCT').checked == true) {
                    mode = mode + "C";  //Commuter Rail
                }

                //mode = mode + "1"; //added for shuttle

		mode = mode + "1"+ "2"; //1 added for shuttle, 2 added for Tram

            }

            //if only Commuter Rail is selected then make <maxinitialwait> = 120 minutes (mode F and 1 are added by default)
            if (mode == "FC1") {
                maxinitialwait = "120";
            }

            //If start and End address are Rail Stations make longest trip time to (450 minutes) : Greg 6/15/2012
            if ((originCoors.split("$")[4] == 'RS') && (destinationCoors.split("$")[4] == 'RS')) {
                maxtriptime = "450";
                maxinitialwait = "240";
                walkincrease = "Y";
                maxtransfers = 4;
            }
            
            
            if (document.getElementById('rbWalkIncrease')) {
                if (document.getElementById('rbWalkIncrease').checked == true) {
                    walkincrease = document.getElementById('rbWalkIncrease').value;
                }
            }
            submit_CustomPlanner(g_BrowserType,
                              startAddr,
                              endAddr,
                              Arrdep,
                              hour,
                              minute,
                              ampm,
                              selectedDate,
                              minimize,
                              walkdistance,
                              mode,
                              lineStart,
                              lineEnd,
                              AccessibleTrip,
                              originCoors,
                              destinationCoors,
                              startServiceType,
                              startTrainType,
                              startBorough,
                              endServiceType,
                              endTrainType,
                              endBorough,
                              walkincrease,
                              maxinitialwait,
                              maxtriptime,
                              maxtransfers)
        }
    }


    //Point2Point Request
    if (document.getElementById('currentmodule').value == "point2point") {

        submit_Point2Point(g_BrowserType,
                          startAddr,
                          endAddr,
                          hour,
                          minute,
                          ampm,
                          selectedDate,
                          walkdistance,
                          AccessibleTrip,
                          originCoors,
                          destinationCoors)
    }


    //ServiceintheArea Request
    if (document.getElementById('currentmodule').value == "serviceinthearea") {

        submit_ServiceintheArea(g_BrowserType,
                          startAddr,
                          hour,
                          minute,
                          ampm,
                          selectedDate,
                          walkdistance,
                          AccessibleTrip,
                          originCoors
                         )
    }


} //ends submit TPForm




function ShowListUsingCookies(srcObj, formOrToDDL) {

    //show one list at a time
    if (formOrToDDL == 'toAutoFillList') {
        HideList('fromAutoFillList');
    }
    else {
        HideList('toAutoFillList');
    }

    showSubmitButton()
    var innerhtml = ""
    if (srcObj.id == "txtOriginInput") {
        for (x = 0; x < cookieArrayStart.length; x++) {
            innerhtml = innerhtml + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick='SetOriginTextBoxValueUsingCookie(" + x + ")'>" + cookieArrayStart[x].split('|')[0]; +"</td></tr>"
        }
    }
    else if (srcObj.id == "txtDestinationInput") {
        for (x = 0; x < cookieArrayEnd.length; x++) {
            innerhtml = innerhtml + "<tr><td style='padding:3px; cursor:pointer; border-bottom:solid silver 1px;' onclick='SetDestinationTextBoxValueUsingCookie(" + x + ")'>" + cookieArrayEnd[x].split('|')[0]; +"</td></tr>"
        }
    }
    document.getElementById(formOrToDDL).style.zIndex = 1000
    document.getElementById(formOrToDDL).innerHTML = "<table class='listing'>" + innerhtml + "</table>"
    if (cookieArrayStart.length > 0) {
        document.getElementById(formOrToDDL).style.visibility = "visible"
        document.getElementById(formOrToDDL).style.height = "20px"
        document.getElementById(formOrToDDL).style.width = "200px"
        document.getElementById(formOrToDDL).style.overflow = "visible"
    }
    else {
        document.getElementById(formOrToDDL).style.visibility = "hidden"
    }
}

// Called from onfoucs and onKeyup events of origin / Destination textbox 
function ShowFromOptions(srcObj, formOrToDDL) {
    var inputTextValue = "" + srcObj.value;
    if (inputTextValue.length == 0) {
        // mean user didn't enter any letter from key board... so fill respective DDL using cookies
        ShowListUsingCookies(srcObj, formOrToDDL)
    }
    else {
        if (srcObj.id == "txtOriginInput") {
            // User entered some text in Origin text box
            ShowOriginListUsingLandmark();
        }
        else if (srcObj.id == "txtDestinationInput") {
            // User entered some text in Destination text box
            ShowDestinationListUsingLandmark()
        }
    }
}

//moved to smart trip.js
//function HideLandmarkLists() {
//    if (document.getElementById('fromAutoFillList')){
//    HideList('fromAutoFillList');
//    }
//    if (document.getElementById('toAutoFillList')){
//    HideList('toAutoFillList');
//    }
//}

// Set Origin text box value using cookies
function SetOriginTextBoxValueUsingCookie(index) {  //loadfromCookie
    document.getElementById('txtOriginInput').value = cookieArrayStart[index].split('|')[0];
    fromCoordinates = cookieArrayStart[index].split('|')[1];
    setMyCookie(fromCoordinates, 'txtOriginInput');
    useFromSuggestion = true;
    HideList('fromAutoFillList');
}
// Set Destination text box value using cookies
function SetDestinationTextBoxValueUsingCookie(index) { //loadToCookie
    document.getElementById('txtDestinationInput').value = cookieArrayEnd[index].split('|')[0];
    toCoordinates = cookieArrayEnd[index].split('|')[1];
    setMyCookie(toCoordinates, 'txtDestinationInput');
    useToSuggestion = true;
    HideList('toAutoFillList');
}



// called from tripplanner.aspx + modifty user controls onlick of address text box [from and to]
function OnAddressTextBoxClick(obj, listId) {
    setTimeout(function() { ShowFromOptions(obj, listId) }, 20);
}




function submit_CustomPlanner(browserType,
                              startAddr,
                              endAddr,
                              Arrdep,
                              hour,
                              minute,
                              ampm,
                              selectedDate,
                              minimize,
                              walkdistance,
                              mode,
                              lineStart,
                              lineEnd,
                              accessible,
                              OriginCoors,
                              DestinationCoors,
                              startServiceType,
                              startTrainType,
                              startBorough,
                              endServiceType,
                              endTrainType,
                              endBorough,
                              walkincrease,
                              maxinitialwait,
                              maxtriptime,
                              maxtransfers) {
    var objJSON = createJSONObj(browserType,
                                  startAddr,
                                  endAddr,
                                  Arrdep,
                                  hour,
                                  minute,
                                  ampm,
                                  selectedDate,
                                  minimize,
                                  walkdistance,
                                  mode,
                                  lineStart,
                                  lineEnd,
                                  accessible,
                                  OriginCoors,
                                  DestinationCoors,
                                  startServiceType,
                                  startTrainType,
                                  startBorough,
                                  endServiceType,
                                  endTrainType,
                                  endBorough,
                                  walkincrease,
                                  maxinitialwait,
                                  maxtriptime,
                                  maxtransfers);

    var stringifyJSON = JSON.stringify(objJSON);
    document.forms["tpSubmit"].elements["jsonpacket"].value = stringifyJSON;
    hideSubmitButton();
    document.forms["tpSubmit"].submit()

}


function submit_Point2Point(browserType,
                              startAddr,
                              endAddr,
                              hour,
                              minute,
                              ampm,
                              selectedDate,
                              walkdistance,
                              accessible,
                              OriginCoors,
                          DestinationCoors) {


    var objJSON = createJSONObj(browserType,
                                  startAddr,
                                  endAddr,
                                  "",
                                  hour,
                                  minute,
                                  ampm,
                                  selectedDate,
                                  "",
                                  walkdistance,
                                  "",
                                  "",
                                  "",
                                  accessible,
                                  OriginCoors,
                          DestinationCoors,
                          "",
                          "",
                          "",
                          "",
                          "",
                          "",
                          "",
                          "",
                          "",
                          "");

    var stringifyJSON = JSON.stringify(objJSON);
    document.forms["tpSubmit"].elements["jsonpacket"].value = stringifyJSON;
    hideSubmitButton();
    document.forms["tpSubmit"].submit()
}

function submit_ServiceintheArea(browserType,
                              startAddr,
                              hour,
                              minute,
                              ampm,
                              selectedDate,
                              walkdistance,
                              accessible,
                              OriginCoors) {
    var objJSON = createJSONObj(browserType,
                                  startAddr,
                                  "",
                                  "",
                                  hour,
                                  minute,
                                  ampm,
                                  selectedDate,
                                  "",
                                  walkdistance,
                                  "",
                                  "",
                                  "",
                                  accessible,
                                  OriginCoors,
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "",
                                  "");
    var stringifyJSON = JSON.stringify(objJSON);
    document.forms["tpSubmit"].elements["jsonpacket"].value = stringifyJSON;
    hideSubmitButton();
    document.forms["tpSubmit"].submit()
}
function createJSONObj(browserType,
                          startAddr,
                          endAddr,
                          Arrdep,
                          hour,
                          minute,
                          ampm,
                          selectedDate,
                          minimize,
                          walkdistance,
                          mode,
                          lineStart,
                          lineEnd,
                          accessible,
                          OriginCoors,
                          DestinationCoors,
                          startServiceType,
                          startTrainType,
                          startBorough,
                          endServiceType,
                          endTrainType,
                          endBorough,
                          walkincrease,
                          maxinitialwait,
                          maxtriptime,
                          maxtransfers) {

    var JOSONCustObj = {
        RequestDevicename: browserType,
        OriginInput: startAddr,
        DestinationInput: endAddr,
        Arrdep: Arrdep,
        Hour: hour,
        Minute: minute,
        Ampm: ampm,
        InputDate: selectedDate,
        Minimize: minimize,
        Walkdist: walkdistance,
        Mode: mode,
        LineStart: lineStart,
        LineEnd: lineEnd,
        Accessible: accessible,
        OriginCoordinates: OriginCoors,
        DestinationCoordinates: DestinationCoors,
        LocationType: "",
        StartServiceType: startServiceType,
        StartTrainType: startTrainType,
        StartBorough: startBorough,
        EndServiceType: endServiceType,
        EndTrainType: endTrainType,
        EndBorough: endBorough,
        Walkincrease: walkincrease,
        Maxinitialwait: maxinitialwait,
        Maxtriptime: maxtriptime,
        Maxtransfers: maxtransfers
    };

    return JOSONCustObj;
}

function getPos(obj) {
    var curleft = curtop = 0;
    if (obj.offsetParent) {
        do {
            curleft += obj.offsetLeft;
            curtop += obj.offsetTop;
        }
        while (obj = obj.offsetParent);
        return (curleft + "," + curtop)
    }
}


function postionBoxes() {
    var input1Height
    var input1Left
    var input1Top

    var input2Height
    var input2Left
    var input2Top


    var box1Left
    var box1Top

    var box2Left
    var box2Top

    var verticleSpacing = 5

    var leftOffset = 0
    //'mainbox' centers the page so we have to subtract the left offset (It is referred in master page for mta template)
    //document.writeln('<div id="mainbox" style="background-color:#E1E0CD;">')

    if (document.getElementById('mainbox') != null && document.getElementById('mainbox') != "") {
        var leftOffset = getPos(document.getElementById('mainbox')).split(",")[0];
    }

    //if the page contains the text boxes then only position the drop down lists
    if (document.getElementById('txtOriginInput') != null && document.getElementById('txtOriginInput') != "") {
        input1Left = getPos(document.getElementById('txtOriginInput')).split(",")[0] - leftOffset
        input1Top = getPos(document.getElementById('txtOriginInput')).split(",")[1]
        input1Height = document.getElementById('txtOriginInput').offsetHeight
        box1Left = parseInt(input1Left) + "px"
        box1Top = (parseInt(input1Top) + input1Height + verticleSpacing) + "px"

        document.getElementById('fromAutoFillList').style.left = box1Left;
        document.getElementById('fromAutoFillList').style.top = box1Top;




        input2Left = getPos(document.getElementById('txtDestinationInput')).split(",")[0] - leftOffset
        input2Top = getPos(document.getElementById('txtDestinationInput')).split(",")[1]
        input2Height = document.getElementById('txtDestinationInput').offsetHeight
        box2Left = parseInt(input2Left) + "px"
        box2Top = (parseInt(input2Top) + input2Height + verticleSpacing) + "px"

        document.getElementById('toAutoFillList').style.left = box2Left
        document.getElementById('toAutoFillList').style.top = box2Top
    }
}
