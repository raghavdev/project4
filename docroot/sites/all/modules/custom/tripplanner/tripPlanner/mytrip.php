


<div id ="mytrip" class="roundCorners">
<!--My Trip start 1-->
<h2 class="tp-logo"><span></span><!--Trip Planner+ --></h2>
    <style type="text/css">
	.listing
	{
		font-family: helvetica, arial, sans-serif;
		font-size: 12px;
		font-weight: normal;
		width: 200px;
		border: solid 1px black;
	}
	#tp-footer .list_h {
		padding-top:2px;
		font-size:85%;
	}
    </style>

    <!-- My Trip end 1-->
<img src="/sites/all/themes/mta/images/loading.gif" id="tpimageForWait"
                            style="visibility:hidden; position:absolute; left: 780px; top: 190px;" />


                   <!--My Trip start 2-->

                        <img src="/sites/all/themes/mta/images/loading.gif" id="tpimageForWait" style="visibility: hidden;
                            position: absolute; left: 780px; top: 190px;" />
                        <table cellpadding="0" cellspacing="0" style="width: 100%;   margin-bottom: 0;" >
                            <tr>
                                <td id="divCP" onclick="ShowTpForm('CP')" style="background-color: #00BB11; color: White;
                                    border: solid 1px gray; cursor: pointer;">
                                    Custom Planner
                                </td>
                                <td id="divSIA" onclick="ShowTpForm('SIA')" style="cursor: pointer; border-bottom: solid 1px gray;
                                    border-top: solid 1px gray;">
                                    Service in the Area
                                </td>
                                <td id="divSCH" onclick="ShowTpForm('SCH')" style="cursor: pointer; border: solid 1px gray;">
                                    Schedules
                                </td>
                            </tr>
                        </table>
                        <div id="schMenuLinks" style="display: none; background-color: #00BB11; width: 100%;">
                            <table style="background-color: #00BB11; width: 100%; padding-bottom: 10px; padding-top: 10px;
                                color: White" cellpadding="0" cellspacing="0" border="0">
                                <tr>
                                    <td style="background-color: #00BB11; padding-bottom: 10px; cursor: pointer" onclick="ShowSubwayP2P()">
                                        <b onclick="ShowSubwayP2P()" style="margin-left: 20px; border-bottom: solid 1px white">
                                            Subway and Bus</b>
                                    </td>
                                </tr>
                                <tr>
                                    <td style="background-color: #00BB11; padding-bottom: 10px; cursor: pointer">
                                        <b onclick="window.location='http://lirr42.mta.info/'" style="margin-left: 20px;
                                            cursor: pointer; border-bottom: solid 1px white">Long Island Rail Road</b>
                                    </td>
                                </tr>
                                <tr>
                                    <td style="background-color: #00BB11; padding-bottom: 10px; cursor: pointer">
                                        <b onclick="window.location='http://as0.mta.info/mnr/schedules/sched_form.cfm'" style="margin-left: 20px;
                                            cursor: pointer; border-bottom: solid 1px white">Metro-North Railroad</b>
                                    </td>
                                </tr>
                                <tr>
                                    <td style="background-color: #00BB11; padding-bottom: 10px; cursor: pointer">
                                        <b onclick="window.location='http://as0.mta.info/mnr/schedules/sched_form.cfm'" style="margin-left: 40px;
                                            cursor: pointer; border-bottom: solid 1px white">East of Hudson</b>
                                    </td>
                                </tr>
                                <tr>
                                    <td style="background-color: #00BB11; padding-bottom: 10px; cursor: pointer">
                                        <b onclick="window.location='http://web.mta.info/mnr/html/planning/schedules/linkwest.html'" style="margin-left: 40px;
                                            cursor: pointer; border-bottom: solid 1px white">West of Hudson</b>
                                    </td>
                                </tr>
                                
                            </table>
                        </div>

                        <form name="tpForm" id="tpForm">
						<label id="divP2PHeadline" style="font-weight:bold; margin-top: 15px; display:none">Subway &amp; Bus Schedules</label>
                         <div style="margin-bottom: 10px; margin-top: 5px;">
                            <label for="txtOriginInput" id="labelForStartAddress">From</label>
                            <input id="txtOriginInput" maxlength="2048" name="fromAddress" onclick="SmartTripClick('ADDRESSTEXTBOX',this, 'fromAutoFillList');"
                                onkeyup="ShowFromOptions(this, 'fromAutoFillList' );" style="width: 100%;" type="text"
                                value="" />
                        </div>

                        <div id="divEndAddress" style="margin-bottom: 10px;">
                            <label for="txtDestinationInput">
                                To</label>
                            <input id="txtDestinationInput" maxlength="2048" name="toAddress" onclick="SmartTripClick('ADDRESSTEXTBOX',this, 'toAutoFillList' );"
                                onkeyup="ShowFromOptions(this, 'toAutoFillList' );" style="width: 100%;" type="text"
                                value="" />
                        </div>
                        <div style="margin-bottom: 10px;">
                            <label for="fdate">
                                Date</label>
                            <input id="fdate" maxlength="10" name="date" size="8" style="width: 115px;" type="text"/>
                            <img alt="calendar" onclick="document.forms['tpForm'].elements['date'].focus()" src="/sites/all/themes/mta/images/calendar-icon.jpg"
                                style="margin-left: 6px; display: none;" />
                        </div>
                        <div>
							<div id="divTransitMode" style="display: block;  height: 35px; margin-bottom: 15px;">
                                <div style="float: left; width: 38px; height: 35px; margin-left: 3px;">
                                    <label>Using</label>
                                </div>
                                <div style="float: left; width: 150px;">
                                    <input id="xmodeB" checked="checked" name="xmodeB" type="checkbox" value="B" />
                                    <label for="xmodeB">
                                        Bus</label>
                                    <input id="xmodeX" name="xmodeX" type="checkbox" value="X" />
                                    <label for="xmodeX">
                                        Express Bus</label>
                                </div>
                                <div style="float: left; width: 150px; margin-top: 3px;">
                                    <input id="xmodeCT" checked="checked" name="xmodeCT" type="checkbox" value="C" />
                                    <label for="xmodeCT" style="margin-right: 1px;">
                                        Rail</label>
                                    <input id="xmodeR" checked="checked" name="xmodeR" type="checkbox" value="R" />
                                    <label for="xmodeR">
                                        Subway</label>
                                </div>
                            </div>
                            <fieldset>
                                <div id="divLeaveArr" style="margin-left: 3px; display: block">
                                    <label for="DepId">
                                        Leave at</label>
                                    <input id="DepId" checked="checked" name="Arrdep" type="radio" value="D" />
                                    <label for="ArrId">
                                        Arrive by</label>
                                    <input id="ArrId" name="Arrdep" type="radio" value="A" />
                                </div>
                                <label for="divTime" id="lbltime" style="display: none;">
                                    Time</label>
                                <div id="divTime" style="margin-left: 3px; margin-top: 5px;">
                                    <select id="ddlHour" name="hour">
                                        <option value="1">1</option>
                                        <option value="2">2</option>
                                        <option value="3">3</option>
                                        <option value="4">4</option>
                                        <option value="5">5</option>
                                        <option value="6">6</option>
                                        <option value="7">7</option>
                                        <option value="8">8</option>
                                        <option value="9">9</option>
                                        <option value="10">10</option>
                                        <option value="11">11</option>
                                        <option value="12">12</option>
                                    </select>
                                    <select id="ddlMinute" name="minute">
                                        <option>00</option>
                                        <option>01</option>
                                        <option>02</option>
                                        <option>03</option>
                                        <option>04</option>
                                        <option>05</option>
                                        <option>06</option>
                                        <option>07</option>
                                        <option>08</option>
                                        <option>09</option>
                                        <option>10</option>
                                        <option>11</option>
                                        <option>12</option>
                                        <option>13</option>
                                        <option>14</option>
                                        <option>15</option>
                                        <option>16</option>
                                        <option>17</option>
                                        <option>18</option>
                                        <option>19</option>
                                        <option>20</option>
                                        <option>21</option>
                                        <option>22</option>
                                        <option>23</option>
                                        <option>24</option>
                                        <option>25</option>
                                        <option>26</option>
                                        <option>27</option>
                                        <option>28</option>
                                        <option>29</option>
                                        <option>30</option>
                                        <option>31</option>
                                        <option>32</option>
                                        <option>33</option>
                                        <option>34</option>
                                        <option>35</option>
                                        <option>36</option>
                                        <option>37</option>
                                        <option>38</option>
                                        <option>39</option>
                                        <option>40</option>
                                        <option>41</option>
                                        <option>42</option>
                                        <option>43</option>
                                        <option>44</option>
                                        <option>45</option>
                                        <option>46</option>
                                        <option>47</option>
                                        <option>48</option>
                                        <option>49</option>
                                        <option>50</option>
                                        <option>51</option>
                                        <option>52</option>
                                        <option>53</option>
                                        <option>54</option>
                                        <option>55</option>
                                        <option>56</option>
                                        <option>57</option>
                                        <option>58</option>
                                        <option>59</option>
                                    </select>
                                    <select id="ddlampm" name="ampm">
                                        <option value="am">a.m.</option>
                                        <option value="pm">p.m.</option>
                                    </select>
                                </div>
                            </fieldset>

                           <div id="divWalkDist" style="display: none; margin-top: 15px; ">
                                <label>
                                    Walking distance</label>
                                <select name="Walkdist" id="ddlWalkdistance">
                                    <option value="0.25">1/4 mile</option>
                                    <option value="0.50" selected="selected">1/2 mile</option>
                                    <option value="0.75">3/4 mile</option>
                                    <option value="1.00" >1 mile</option>
                                </select>
                            </div>

                            <div style="margin-top:8px;margin-left:0px;">
                                <label for="accessibleChkbox">
                                    Accessible Trip?</label>
                                <input id="accessibleChkbox" name="Atr" title="Do you want your trip to be wheelchair accessible?"
                                    type="checkbox" value="Y" />
                            </div>
                            <div style="margin-top: 10px;">
                                <input id="submitButton"  onclick="SmartTripClick('SUBMIT','' , '')" type="button" value="submit" />
                                <span id="waitMsg" style="display: none; white-space: nowrap; color: red; font-size: 11px; font-weight: bold;">Please Wait...</span>
                            </div>
                        </div>
                        <div id="fromAutoFillList" style="visibility: hidden; position: absolute; top: 252px;
                            left: 735px; width: 200px; background-color: blue; overflow: visible;">
                        </div>
                        <div id="toAutoFillList" style="visibility: hidden; position: absolute; top: 268px;
                            left: 735px; width: 200px; height: 20px; background-color: #fff; overflow: visible;">
                        </div>
                        <div id="tpAlert" style="display: none; padding: 10px; border: solid black 2px; text-align: center;
                            position: absolute; top: 200px; left: 750px; width: 170px; background-color: silver;
                            font-size: 12px; font-weight: bold;">
                        </div>
                        <div id="map1" style="width: 200px; height: 200px; display: none;">
                        </div>
                        <div id="map2" style="width: 200px; height: 200px; display: none;">
                        </div>
                        <input type="hidden" id="currentmodule" name="currentmodule" value="tripplanner" />
                         </form>

                            <p style="margin: 10px 0 0 6px;">
                                <span id="SpanAdv" class="list_h" style="display: inline"><a style="color: #555; cursor:pointer;"  onclick="SmartTripClick('ADVANCEOPTION','' ,'' )">
                                    Advanced</a></span> <span class="list_h"><a style="color: #555;" href="http://tripplanner.mta.info/MyTrip/common/help.aspx">
                                        Help</a></span> <span class="list_h"><a style="color: #555;" href="https://511ny.org/transittripplanner/index/1">511NY</a></span></p>
							<p style="margin:0 0 0 6px;"><span class="list_h"><a style="color:#555;" href="http://web.mta.info/nyct/service/OnTheGo.htm">Go Mobile</a></span> 
                            <span class="list_h"><a href="http://www.mta.info/trip-planner-widgets">Get Widgets</a></span></p>


                        <form name="tpSubmit" action="http://Tripplanner.mta.info/mytrip/handler/customplannerHandler.ashx?cid=mtahome"
                        method="get" target="_top" style="display: none">
                        <input type="hidden" name="jsonpacket" value="" />
                        </form>
                        <!--My Trip end-->
 </div>
