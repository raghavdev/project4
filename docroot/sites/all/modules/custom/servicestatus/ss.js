/*!
 * MTA Service Status Plugin
 * Fetches service status data.
 */
 (function($) {

    $().ready(function(){

        $('#pageTitleArea').html("<h2>MTA Service Status</h2>");

        var differential = Math.round((new Date().getTime())/60000);
        var url = "/service_status_json/" + differential;

        $.ajaxSetup({ 
            // cache: false,
            async: false,
            contentType: "application/json; charset=utf-8"
        });

         

        $.ajax({
            url: url,
            dataType: 'json',
            success: function(d) {
                var data = $.parseJSON(d);

                var ts = (data.timestamp).split(" ");
                $(".statusDateTime").html("as of " + ts[1] + " " + ts[2]);

                $.each(data.subway, function(key, val){
                    $.each(val, function(index, val){
                        generateHTML(val.name, val.status, differential);
                    });
                });

                $.each(data.LIRR, function(key, val){
                    $.each(val, function(index, val){
                        generateRailHTML(val.name, val.status, "LIRR", differential);
                    });
                });

                $.each(data.MetroNorth, function(key, val){
                    $.each(val, function(index, val){
                        generateRailHTML(val.name, val.status, "MetroNorth", differential);
                    });
                });

                $.each(data.bus, function(key, val){
                    $.each(val, function(index, val){
                        generateBusHTML(val.name, val.status, differential);
                    });
                });

                $.each(data.BT, function(key, val){
                    $.each(val, function(index, val){
                        generateBnTHTML(val.name, val.status, differential);
                    });
                });
            },
            error: function(jqxhr, msg, exception) {
                $('#123').html(msg);
            }
        });

    });

    function generateHTML(name, val, differential)
    {
        switch(val) {
            case 'GOOD SERVICE':
                $('#'+name).addClass("subway_GoodService");
                $('#'+name).html("Good Service");
                break;
            case 'PLANNED WORK':
                $('#'+name).addClass("subway_PlannedWork");
                var html = '<a style="color: #996600" href="/status/subway/' + name + '/' + differential +'">Planned Work</a>';
                $('#'+name).html(html);
                break;
            case 'SERVICE CHANGE':
                $('#'+name).addClass("subway_ServiceChange");
                var html = '<a style="color: #996600" href="/status/subway/' + name + '/' + differential +'">Service Change</a>';
                $('#'+name).html(html);
                break;
            case 'DELAYS':
                $('#'+name).addClass("subway_Delays");
                var html = '<a style="color: #990033" href="/status/subway/' + name + '/' + differential +'">Delays</a>';
                $('#'+name).html(html);
                break;
            case 'SANDY REROUTE':
                $('#'+name).addClass("subway_sandyreroute");
                var html = '<a style="color: #5d0dff" href="/status/subway/' + name + '/' + differential +'">Sandy Reroute</a>';
                $('#'+name).html(html);
                break;
            case 'SUSPENDED':
                $('#'+name).addClass("subway_Suspended");
                var html = '<a style="color: #996600" href="/status/subway/' + name +  '/' + differential +'">Suspended</a>';
                $('#'+name).html(html);
                break;
        }

        return html;
    }

    function generateRailHTML(name, val, service, differential)
    {
        var n = name.replace(/\s+/g, '');

        switch(val) {
            case 'GOOD SERVICE':
                $('#'+n).addClass("rail_GoodService");
                $('#'+n).html("Good Service");
                break;
            case 'PLANNED WORK':
                $('#'+n).addClass("rail_PlannedWork");
                var html = '<a style="color: #996600" href="/status/' + service + '/' + n + '/' + differential +'">Planned Work</a>';
                $('#'+n).html(html);
                break;
            case 'SERVICE CHANGE':
                $('#'+n).addClass("rail_ServiceChange");
                var html = '<a style="color: #996600" href="/status/' + service + '/' + n + '/' + differential +'">Service Change</a>';
                $('#'+n).html(html);
                break;
            case 'DELAYS':
                $('#'+n).addClass("rail_Delays");
                var html = '<a style="color: #990033" href="/status/' + service + '/'  + n + '/' + differential +'">Delays</a>';
                $('#'+n).html(html);
                break;
            case 'SUSPENDED':
                $('#'+n).addClass("rail_Suspended");
                var html = '<a style="color: #996600" href="/status/' + service + '/'  + n + '/' + differential +'">Suspended</a>';
                $('#'+n).html(html);
                break;
        }

        return html;
    }

    function generateBusHTML(name, val, differential)
    {
        var n = name.replace(/\s+/g, '');

        switch(val) {
            case 'GOOD SERVICE':
                $('#'+n).addClass("bus_GoodService");
                $('#'+n).html("Good Service");
                break;
            case 'PLANNED WORK':
                $('#'+n).addClass("bus_PlannedWork");
                var html = '<a style="color: #996600" href="/status/bus/' + n + '/' + differential +'">Planned Detour</a>';
                $('#'+n).html(html);
                break;
            case 'SERVICE CHANGE':
                $('#'+n).addClass("bus_PlannedWork");
                var html = '<a style="color: #996600" href="/status/bus/' + n + '/' + differential +'">Service Change</a>';
                $('#'+n).html(html);
                break;
            case 'DELAYS':
                $('#'+n).addClass("bus_Delays");
                var html = '<a style="color: #990033" href="/status/bus/' + n + '/' + differential +'">Delays</a>';
                $('#'+n).html(html);
                break;
            case 'SUSPENDED':
                $('#'+n).addClass("bus_Suspended");
                var html = '<a style="color: #996600" href="/status/bus/' + n + '/' + differential +'">Suspended</a>';
                $('#'+n).html(html);
                break;
        }

        return html;
    }

    function generateBnTHTML(name, val, differential)
    {
        var n = name.replace(/\s+/g, '').replace(".", '');

        switch(val) {
            case 'GOOD SERVICE':
                $('#'+n).addClass("bus_GoodService");
                $('#'+n).html("Good Service");
                break;
            case 'PLANNED WORK':
                $('#'+n).addClass("bus_PlannedWork");
                var html = '<a style="color: #996600" href="/status/BT/' + n + '/' + differential +'">Planned Work</a>';
                $('#'+n).html(html);
                break;
            case 'SERVICE CHANGE':
                $('#'+n).addClass("bus_PlannedWork");
                var html = '<a style="color: #996600" href="/status/BT/' + n + '/' + differential +'">Service Change</a>';
                $('#'+n).html(html);
                break;
            case 'DELAYS':
                $('#'+n).addClass("bus_Delays");
                var html = '<a style="color: #990033" href="/status/BT/' + n + '/' + differential +'">Delays</a>';
                $('#'+n).html(html);
                break;
        }

        return html;
    }     

}(jQuery));
