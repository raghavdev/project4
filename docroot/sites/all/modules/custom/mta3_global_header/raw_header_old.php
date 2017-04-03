<?php //header('Access-Control-Allow-Origin: *'); ?>
<!-- This header necessary using CORS http://www.nczonline.net/blog/2010/05/25/cross-domain-ajax-with-cross-origin-resource-sharing/ -->

<div id="topbar">


    <div id="branding">
        <a href="http://web.mta.info"><img alt="Metropolitan Transportation Authority logo"  src="/sites/all/themes/mta/images/mta_info.gif"> </a>
    </div>


    <div id="search">

        <ul id="topbar-links">

            <li class="list_h" style="margin-left:4px;"><a href="http://web.mta.info/accessibility">Accessibility</a></li>

            <li class="list_h" style="margin-left:4px;"><a href="http://assistive.usablenet.com/tt/http://www.mta.info">Text-only</a></li>

            <li class="list_h" style="margin-left:4px;"><a href="http://web.mta.info/selfserve">Customer Self-Service</a></li>

            <li class="list_h" style="margin-left:4px;"><a href="http://web.mta.info/faqs.htm">FAQs/Contact Us</a></li>

        </ul><br>


        <div id="search-box" style="width:230px; height:32px; float:right; margin-top:4px; margin-right:0; padding-right:0;">

            <form id="searchform" method="get" action="http://search.mta.info/search" style="margin:0; padding:0; height:32px; float:left;">

                <input name="site" value="my_collection" type="hidden">

                <input name="client" value="my_collection" type="hidden">

                <input name="proxystylesheet" value="my_collection" type="hidden">

                <input name="output" value="xml_no_dtd" type="hidden">

                <!--<label for "searchinputbox" style="margin-left:-999px; margin-top:0; font-size:10px;">Enter search term:</label>-->

                <input name="q" id="searchinputbox" alt="searchinputbox" size="20" maxlength="255" style="margin-right:6px;float:left;" type="text"><input name="btnG" value="search" id="searchbutton" style="padding:1px 8px; float:right; margin-left:0;margin-top:-1px;" type="submit">

            </form>

        </div>



    </div>


    <div id="horizontalcssmenu" style="clear: both;">

        <ul id="cssmenu1">

            <li style="width: 75px; border-left: none;"><a href="http://www.mta.info/" style="padding-left:18px;">Home<span class="arrowdiv"></span></a>

                <ul style="top: 31px;">

                    <li><a href="http://www.mta.info/">MTA Home</a></li>

                    <li><a href="http://new.mta.info/nyct">NYC Subways and Buses</a></li>

                    <li><a href="http://new.mta.info/lirr">Long Island Rail Road</a></li>

                    <li><a href="http://new.mta.info/mnr">Metro-North Railroad</a></li>

                    <li><a href="http://new.mta.info/bandt">Bridges and Tunnels</a></li>

                    <li><a href="http://web.mta.info/capital">MTA Capital Program</a></li>

                </ul>

            </li>

            <li style="width: 99px;"><a href="http://web.mta.info/schedules">Schedules</a></li>

            <li style="width: 117px;"><a href="http://web.mta.info/fares">Fares &amp; Tolls</a></li>

            <li style="width: 65px;"><a href="http://web.mta.info/maps">Maps</a></li>

            <li style="width: 199px;"><a href="http://web.mta.info/service">Planned Service Changes</a></li>

            <li style="width: 96px;"><a href="http://web.mta.info/about">MTA Info</a></li>

            <li style="width: 183px;"><a href="http://web.mta.info/business">Doing Business With Us</a></li>

            <li style="width: 119px;"><a href="http://web.mta.info/accountability/" style="padding-right:23px;">Transparency<span class="arrowdiv"></span></a>

                <ul style="top: 31px;">

                    <li><a href="http://web.mta.info/accountability">Main Page</a></li>

                    <li><a href="http://web.mta.info/mta/boardmaterials.html">Board Materials</a></li>

                    <li><a href="http://web.mta.info/mta/budget/">Budget Info</a></li>

                    <li><a href="http://web.mta.info/capital">Capital Program Info</a></li>

                    <li><a href="http://web.mta.info/capitaldashboard/CPDHome.html">Capital Program Dashboard</a></li>

                    <li><a href="http://web.mta.info/mta/leadership/">MTA Leadership</a></li>

                    <li><a href="http://web.mta.info/persdashboard/performance14.html">Performance Indicators</a></li>
                    <li><a href="http://new.mta.info/mta-news">Press Releases and News</a></li>

                    <li><a href="http://web.mta.info/mta/news/hearings">Public Hearingss</a></li>



                </ul>

            </li>

        </ul>

    </div>


</div>
