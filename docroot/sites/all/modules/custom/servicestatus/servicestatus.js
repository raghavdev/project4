/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function ShowHide(div)
{
    (jQuery)("#" + div).toggle();
}

(function($) {

    Drupal.behaviors.servicestatus = {
        attach: function (context, settings) {
            
            var t = parseInt($.cookie('ss_mode'));
            
            // alert ("cookie is : '" + t + "'");

            var page_req = window.location.pathname;

            if (page_req == "/nyct")
                t = 1;
            else if (page_req == "/lirr" || page_req == "/mnr")
                t = 2;
            else if (page_req == "/bandt")
                t = 4;

            switch (t) {
                case 1:
                    selectSubwayTab();
                    break;
                case 2:
                    selectRailTab();
                    break;
                case 3:
                    selectBusTab();
                    break;
                case 4:
                    selectBntTab();
                    break;
                default:
                    selectSubwayTab();
                    break;
            }
            
            // Add custom function here
            $("#subwayTab", context).click(function() {
                selectSubwayTab();
            });            
            
            $("#railTab", context).click(function() {
                selectRailTab();
            });
            
            $("#busTab", context).click(function() {
                selectBusTab();
            });
            
            $("#bntTab", context).click(function() {
                selectBntTab();
            });
            
            function selectSubwayTab () {
                $("#bntDiv").hide();
                $("#subwayDiv").show();
                $("#railDiv").hide();
                $("#busDiv").hide();

                $("#bntTab").removeClass("selectedStatusTab");
                $("#busTab").removeClass("selectedStatusTab");
                $("#subwayTab").removeClass("notselectedStatusTab");
                $("#railTab").removeClass("selectedStatusTab");
                $("#subwayTab").addClass("selectedStatusTab");

                $.cookie('ss_mode', '1', {path: '/'});
//                alert ("Subway - cookie is : " + $.cookie('ss_mode'));
            }
            
            function selectRailTab () {
                $("#subwayDiv").hide();
                $("#busDiv").hide();
                $("#bntDiv").hide();
                $("#railDiv").show();

                $("#bntTab").removeClass("selectedStatusTab");
                $("#busTab").removeClass("selectedStatusTab");
                $("#railTab").removeClass("notselectedStatusTab");
                $("#subwayTab").removeClass("selectedStatusTab");
                $("#railTab").addClass("selectedStatusTab");

                $.cookie('ss_mode', '2', {path: '/'});
//                alert ("Rail - cookie is : " + $.cookie('tab'));
            }
            
            function selectBusTab () {
                $("#subwayDiv").hide();
                $("#railDiv").hide();
                $("#bntDiv").hide();
                $("#busDiv").show();

                $("#bntTab").removeClass("selectedStatusTab");
                $("#railTab").removeClass("selectedStatusTab");
                $("#subwayTab").removeClass("selectedStatusTab");
                $("#busTab").removeClass("notselectedStatusTab");
                $("#busTab").addClass("selectedStatusTab");

                $.cookie('ss_mode', '3', {path: '/'});
//                alert ("Bus - cookie is : " + $.cookie('ss_mode'));
            }

            function selectBntTab () {
                $("#subwayDiv").hide();
                $("#railDiv").hide();
                $("#busDiv").hide();
                $("#bntDiv").show();

                $("#busTab").removeClass("selectedStatusTab");
                $("#railTab").removeClass("selectedStatusTab");
                $("#subwayTab").removeClass("selectedStatusTab");
                $("#bntTab").removeClass("notselectedStatusTab");
                $("#bntTab").addClass("selectedStatusTab");

                $.cookie('ss_mode', '4', {path: '/'});
//                alert ("Bnt - cookie is : " + $.cookie('tab'));
            }
        }       
    }
}(jQuery));