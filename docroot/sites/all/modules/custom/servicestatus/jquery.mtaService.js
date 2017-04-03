/*!
 * MTA Service Status Plugin
 */
 (function($) {

    $.fn.mtaService = function(service, line) {

        var ele = $(this);

        var differential = Math.round((new Date().getTime())/60000);
        // var url = "http://newdev.mta-hq.info/service_status_json/" + differential;
        // var url = "http://new.mta-hq.info/service_status_json/" + differential;
        var url = "/service_status_json/" + differential;
        
        // console.log("plugin making a request." + differential);

        $.getJSON(url,
            function(d){
                var data = $.parseJSON(d);
                var arr;
                var notFound = true;

                // console.log("plugin got data back.");

                $.each(data, function(index, d){
                    if (service == "subway")
                        arr = data.subway;
                    else if (service == "LIRR")
                        arr = data.LIRR;
                    else if (service == "MetroNorth")
                        arr = data.MetroNorth;
                    else if (service == "bus")
                        arr = data.bus;
                    else if (service == "BT")
                        arr = data.BT;

                    $.each(arr, function(key, val){
                        if (notFound){
                            $.each(val, function(index, v){
                                if (notFound){
                                    if ((v.name.replace(/\s+/g, '').replace(".", '')) == line)
                                    {  
                                        // console.log("Data returned : " + v.text);
                                        var heading = "";
                                        
                                        if (service == "LIRR" || service == "MetroNorth") {
                                            switch (line) {
                                                // LIRR
                                                case "Babylon":
                                                    linename = "Babylon Branch Customers";
                                                    color = "#00985F";
                                                    break;
                                                case "CityTerminalZone":
                                                    linename = "City Terminal Zone Branch Customers";
                                                    color = "#4D5357";
                                                    break;
                                                case "FarRockaway":
                                                    linename = "Far Rockaway Branch Customers";
                                                    color = "#6E3219";
                                                    break;                
                                                case "Hempstead":
                                                    linename = "Hempstead Branch Customers";
                                                    color = "#CE8E00";
                                                    break;
                                                case "LongBeach":
                                                    linename = "Long Beach Branch Customers";
                                                    color = "#FF6319";
                                                    break;
                                                case "Montauk":
                                                    linename = "Montauk Branch Customers";
                                                    color = "#006983";
                                                    break;
                                                case "OysterBay":
                                                    linename = "Oyster Bay Branch Customers";
                                                    color = "#00AF3F";
                                                    break;
                                                case "PortJefferson":
                                                    linename = "Port Jefferson Branch Customers";
                                                    color = "#0039A6";
                                                    break;
                                                case "PortWashington":
                                                    linename = "Port Washington Branch Customers";
                                                    color = "#C60C30";
                                                    break;
                                                case "Ronkonkoma":
                                                    linename = "Ronkonkoma Branch Customers";
                                                    color = "#A626AA";
                                                    break;
                                                case "WestHempstead":
                                                    linename = "West Hempstead Branch Customers";
                                                    color = "#00A1DE";
                                                    break;
                                                // MNR
                                                case "Hudson":
                                                    linename = "Hudson Line Customers";
                                                    color = "#009B3A";
                                                    break;
                                                case "Harlem":
                                                    linename = "Harlem Line Customers";
                                                    color = "#0039A6";
                                                    break;
                                                case "Wassaic":
                                                    linename = "Wassaic Line Customers";
                                                    color = "#0039A6";
                                                    break;                
                                                case "NewHaven":
                                                    linename = "New Haven Line Customers";
                                                    color = "#EE0034";
                                                    break;
                                                case "NewCanaan":
                                                    linename = "New Canaan Line Customers";
                                                    color = "#EE0034";
                                                    break;
                                                case "Danbury":
                                                    linename = "Danbury Line Customers";
                                                    color = "#EE0034";
                                                    break;
                                                case "Waterbury":
                                                    linename = "Waterbury Line Customers";
                                                    color = "#EE0034";
                                                    break;
                                                case "PascackValley":
                                                    linename = "Pascack Valley Line Customers";
                                                    color = "#8E258D";
                                                    break;
                                                case "PortJervis":
                                                    linename = "Port Jervis Line Customers";
                                                    color = "#FF7900";
                                                    break;
                                            }

                                            heading = '<span style="color:' + color + ';font-size:large;font-weight:bold">'+linename+'</span><br/>';
                                        }
                                        
                                        if (v.text.length)
                                            ele.html(heading + v.text);
                                        else
                                            ele.html(heading + "Your data is stale. Please go back to MTA home page and refresh your page.")

                                        notFound = false;

                                        return notFound;
                                    }
                                }
                            });
                        }
                        
                    });
                });
            }
        );
    }
}(jQuery));