var neighborhoodMapLoaded = false;
function recenterNeighborhoodMap(staID)
{
	if(neighborhoodMapLoaded)
	{
		window.frames["neighborhoodMap"].centerOnStation(staID)
	}
	else
	{
		window.frames["neighborhoodMap"].location.href = "tileMap.html?staID=" + staID
	}		
}

function zoomNeighborhoodMap(i)
{
	if(!neighborhoodMapLoaded)
	{
		return false;
	}
	else
	{
	window.frames["neighborhoodMap"].zoom(i)
	}
}

function hideMaps()
{
//document.getElementById("mapIframe").style.display = "none"
document.getElementById("neighborhoodMapDiv").style.display = "none"
document.getElementById("mapDivouter").style.display = "none"
document.getElementById('moreStatusDiv').style.display = "none";
document.getElementById('moreStatusDiv_raw').style.display = "none";
}

function showNeighborhoodMap()
{
hideMaps()
document.getElementById('staticmap').style.display = 'none';
document.getElementById("neighborhoodMapDiv").style.display = "inline";
document.getElementById('diagram').src = 'images/diagram.png';
recenterNeighborhoodMap(selectedStation);
ZoomMapName = 'neighborhoodMap';
document.getElementById("drawer").style.display = 'none';
document.getElementById("spanStationView").style.color = '#888888';
document.getElementById("spanNeighborhoodView").style.color = 'black';
}

function showBingMap()
{
var lat;
var lon;
document.getElementById('diagram').src = 'images/diagram.png';
lat = stationGeo[selectedStation].split(",")[0]
lon = stationGeo[selectedStation].split(",")[1]
hideMaps()
document.getElementById("mapIframe").style.display = "inline"
window.frames[1].showMap(lat,lon);
ZoomMapName = 'BingMap';
document.getElementById("drawer").style.display = 'none';
}

function showSystemDiagram()
{
hideMaps();
document.getElementById("mapDivouter").style.display = "inline";
document.getElementById('diagram').src = 'images/diagram_over.png';
recenterSystemMap(selectedStation);
ZoomMapName = 'SubwayMap';
EnableZoomDrawerIconsInHeader();
document.getElementById("spanStationView").style.color = 'black';
document.getElementById("spanNeighborhoodView").style.color = '#888888';
}
