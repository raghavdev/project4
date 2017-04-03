<h2 class="tools4ride_bar closed" id="tp-bar">Trip Planner<span id="tpplussign">+</span></h2>
<div id="mytrip"><!-- mytrip div -->
	<img src="/sites/all/themes/mta/images/loading.gif" id="tpimageForWait" />

<div id="FromTo">
	<div class="clearfix">
		<div class="tp-tabs" id="divCP">Custom Planner</div>
		<!-- <div class="tp-tabs" id="divSIA">Service in the Area</div> -->
	</div>
	<form name="tpForm" id="tpForm">
		 <div id="divStartAddress" style="">
			<label for="txtOriginInput" id="labelForStartAddress">From</label>
			<input id="txtOriginInput" maxlength="2048" name="fromAddress" type="text" value="" />
		</div>

		<div id="divEndAddress">
			<label for="txtDestinationInput">To</label>
			<input id="txtDestinationInput" maxlength="2048" name="toAddress" type="text" value="" />
		</div>
</div>
<div class='tp-bar'>
		<fieldset>
				<div id="divLeaveArr">
					<input id="DepId" checked="checked" name="Arrdep" type="radio" value="D" />
					<label for="DepId">Leave at</label>
					<input id="ArrId" name="Arrdep" type="radio" value="A" />
					<label for="ArrId">Arrive by</label>
				</div>
				<!-- processing in tripplanner_ext.js @ ln 919
				hour = document.getElementById('ddlHour').options[document.getElementById('ddlHour').selectedIndex].value;
				minute = formatMinute(document.getElementById('ddlMinute').selectedIndex);
				ampm = document.getElementById('ddlampm').options[document.getElementById('ddlampm').selectedIndex].value;
				selectedDate = reformatDate(document.forms["tpForm"].elements["date"].value); -->

				<div id="divTime">
					<input id="ftime" class="timepicker" name="settime" type="text"/>
					<!-- we need to hide these selects for hour and minute, but set set them from the timepicker field so tripplanner_ext.js reads the selectedIndex -->
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
					<!-- we need to hide this select, but set it from the radio buttons so that tripplanner_ext.js reads the selectedIndex -->
					<select id="ddlampm" name="ampm">
						<option value="am">a.m.</option>
						<option value="pm">p.m.</option>
					</select>
					<input type="radio" class="setampm" id="setAM" name="ampmset" value="0"><label for="ampmset">AM</label>
					<input type="radio" class="setampm" id="setPM" name="ampmset" value="1"><label for="ampmset">PM</label>
					<div id="tpDate">
			<label for="fdate">Date</label>
			<input id="fdate" name="date" type="text"/>
		</div>

				</div>

			</fieldset>


		<div>
			<div id="divTransitMode">
					<label>Using:</label>
					<input id="xmodeB" checked="checked" name="xmodeB" type="checkbox" value="B" />
					<label for="xmodeB">Bus</label>
					<input id="xmodeX" name="xmodeX" type="checkbox" value="X" />
					<label for="xmodeX">Express Bus</label>
					<input id="xmodeCT" checked="checked" name="xmodeCT" type="checkbox" value="C" />
					<label id="labelRail" for="xmodeCT">Rail</label>
					<input id="xmodeR" checked="checked" name="xmodeR" type="checkbox" value="R" />
					<label for="xmodeR">Subway</label>
			</div>
			<div id="divAccessible">
				<label for="accessibleChkbox">Accessible Trip?</label>
				<input id="accessibleChkbox" name="Atr" title="Do you want your trip to be wheelchair accessible?" type="checkbox" value="Y" />
			</div>


		   <div id="divWalkDist">
				<label>Walking distance</label>
				<select name="Walkdist" id="ddlWalkdistance">
					<option value="0.25">1/4 mile</option>
					<option value="0.50" selected="selected">1/2 mile</option>
					<option value="0.75">3/4 mile</option>
					<option value="1.00" >1 mile</option>
				</select>
			</div>


			<div>
				<input id="submitButton" type="button" value="SUBMIT" />
				<p id="waitMsg">&nbsp;<br />Please Wait...</p>
			</div>
		</div>
		<div id="fromAutoFillList">
		</div>
		<div id="toAutoFillList">
		</div>
		<div id="tpAlert">&nbsp;</div>
		<div class="tpMaps" id="map1">&nbsp;</div>
		<div class="tpMaps" id="map2">&nbsp;</div>
		<input type="hidden" id="currentmodule" name="currentmodule" value="tripplanner" />
	</form>

	<div id="tp-footer-links">
		<span class="list_h"><a href="http://tripplanner.mta.info/MyTrip/ui_web/customplanner/tripplanner.aspx">Advanced</a></span>
		<span class="list_h"><a href="http://tripplanner.mta.info/MyTrip/common/help.aspx">Help</a></span>
		<span class="list_h"><a href="https://511ny.org/transittripplanner/index/1">511NY</a></span>

	</div>


	<form name="tpSubmit" id="tpSubmitForm" action="http://Tripplanner.mta.info/mytrip/handler/customplannerHandler.ashx?cid=mtahome"
	method="get" target="_top">
	<input type="hidden" name="jsonpacket" value="" />
	</form>
  </div> <!-- .tp-bar end-->
 </div><!-- mytrip end-->
 <br class="clearfix" />
