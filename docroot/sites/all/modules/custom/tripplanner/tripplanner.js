
(function ($) {
  /* to use this toggle, name the sliding div with a class corresponding to the id of the bar with the .tools4ride_bar class */
  Drupal.behaviors.tripplanner_toggle = {
    attach: function (context, settings) {
		$('.tools4ride_bar').toggle( 
				function(){
					clsid = "." + $(this).attr('id');
					$(clsid).slideDown();
					$(this).addClass('open').removeClass('closed');
				},
				function() {
					clsid = "." + $(this).attr('id');
					$(clsid).slideUp();
					$(this).addClass('closed').removeClass('open');
				}
		);
	}
  };  
  
  Drupal.behaviors.tripplanner_metrota3 = {
    attach: function (context, settings) {
		//open Trip Planner on page load
		//$('.tp-bar').slideDown();
		
		//reset wait status so the form is ready when navigating with the back button
		$(window).unload(function() {
			//we don't have to put any code in here, it 'just works'
		});
		
		$('#FromTo').mousedown( function() { 
			$('.tp-bar').once().slideDown();
			$('#tp-bar').once().addClass('open').removeClass('closed');
		});

		$('#txtOriginInput, #txtDestinationInput').val('Full Address, Landmark or Station Name').css('font-size','10px');
		
		$('#txtOriginInput').click( function() {
			$(this).val('');
			$('#tpAlert').hide();
			OnAddressTextBoxClick(this, 'fromAutoFillList');
			$('#fromAutoFillList').css({'padding-top':'0px','background':'none','display':'block'});
		});
		
		$('#txtOriginInput').keyup( function() {
			ShowFromOptions(this,'fromAutoFillList');
		});
		
		$('#fromAutoFillList').mouseleave( function() {
			$(this).css('display','none');
			if (!$('#txtOriginInput').val()) $('#txtOriginInput').val('Full Address, Landmark or Station Name')
			
		});
		
		$("#txtDestinationInput").click( function() {
			$(this).val('');
			$('#tpAlert').hide();
			OnAddressTextBoxClick(this,'toAutoFillList');
			$('#toAutoFillList').css({'padding-top':'60px','background':'none','display':'block'});
		});
		
		$("#txtDestinationInput").keyup( function() {
			ShowFromOptions(this,'toAutoFillList');
		});
		
		$('#toAutoFillList').mouseleave( function() {
			$(this).css('display','none');
			if (!$('#txtDestinationInput').val()) $('#txtDestinationInput').val('Full Address, Landmark or Station Name')
			
		});		
		
	
		// For Default time on Smart Trip 
		var loadDate = new Date();
		var loadHour = loadDate.getHours()
		var loadMinute = loadDate.getMinutes()
		var loadAMPM
		if (loadHour > 11) {
			loadAMPM = 1
		}
		else {
			loadAMPM = 0
		}
		if (loadHour > 12) {
			loadHour = loadHour - 12
		}

		if (loadHour == 0) {
			loadHour = 12
		}
		
		//see http://wvega.github.io/timepicker/
		$("#ftime").timepicker({
			timeFormat: 'h:mm',
			startTime: new Date(),
            interval: 15, // 5 minute intervals
			scrollbar: true,			
			change: function(time) {
				// the input field
				var element = $(this), text;
				// get access to this TimePicker instance
				var timepicker = element.timepicker();
				fieldtext = timepicker.format(time);
				//we need to set the hidden selects for tripplanner_ext.js
				loadHour = fieldtext.substr(0,fieldtext.indexOf(':'));
				loadMinute = fieldtext.substr(fieldtext.indexOf(':') + 1);
				$('#ddlMinute').attr('selectedIndex',loadMinute);
				$('#ddlHour').attr('selectedIndex',loadHour -1);
			}
		});

		
		/* As of jQuery 1.6, the .prop() method provides a way to explicitly retrieve property values, while .attr() retrieves attributes. We are using jQuery 1.4.4 so we use attr() */
		$('#ddlampm').attr('selectedIndex',loadAMPM);
		switch (loadAMPM){
			case 0:
				$('#setAM').attr('checked',true);
				break;
			case 1:
				$('#setPM').attr('checked',true);
				break;		
		}
		//we need to hide #ddlampm select, but set it from the radio buttons so that tripplanner_ext.js reads the selectedIndex
		$('.setampm').click( function () {
			$('#ddlampm').attr('selectedIndex',$(this).val());
		});
		$('#ddlMinute').attr('selectedIndex',loadMinute);
		$('#ddlHour').attr('selectedIndex',loadHour -1);
		fminute = loadMinute < 10 ? '0' + loadMinute : loadMinute;
		
		//initialize the timepicker input field
		$('#ftime').val(loadHour + ':' + fminute);
		
		//initialize the datepicker
		$("#fdate").datepicker({ minDate: 0, maxDate: '+20d'});
		$("#fdate").datepicker("setDate", loadDate);
		
		// is this being used?
		var bingMapToken = "";		
		
		//this calls a function loaded in http://Tripplanner.mta.info/MyTrip/js/tripplanner_ext.js
		$('#submitButton').click( function() {
			GoToTPResult();
		});

		$('#divCP').click( function() {
			$('#currentmodule').val('tripplanner');
			// we can't use jQuery to assign the action here because it detaches the hidden "jsonpacket" field
			document.forms["tpSubmit"].action = 'http://Tripplanner.mta.info/MyTrip/handler/customplannerHandler.ashx?cid=mtahome';
            $('#labelForStartAddress').text('From');
            $('#divCP').css({'background-color':'white'});
            $('#divSIA').css({'background-color':'#d1d1d1'});
            $("#divWalkDist").css('display','none');
            $('#tpForm,#divTransitMode,#divLeaveArr').css('display','block');
			$('#divEndAddress').css('visibility','visible');
		});
		
		$('#divSIA').click( function() {
			$('#currentmodule').val('serviceinthearea');
			// we can't use jQuery to assign the action here because it detaches the hidden "jsonpacket" field
			document.forms["tpSubmit"].action = 'http://Tripplanner.mta.info/MyTrip/handler/ServiceintheArea.ashx?cid=mtahome';
			$('#labelForStartAddress').text('From');
            $('#divCP').css({'background-color':'#d1d1d1'});
            $('#divSIA').css({'background-color':'white'});
            $('#tpForm,#divWalkDist').css('display','block');
			$('#divTransitMode,#divLeaveArr').css('display','none');
			$('#divEndAddress').css('visibility','hidden');
		});
		
		/* no schdule info
		$('#divSCH').click( function() {
			$('#currentmodule').val('point2point');
			$('form').attr('name','tpSubmit').attr('action','http://Tripplanner.mta.info/MyTrip/handler/Point2Point.ashx?cid=mtahome');
            $('#labelForStartAddress').text('From');
            $('#divCP').css({'background-color':'white','color':'black'});
            $('#divSIA').css({'background-color':'white','color':'black'});
            $('#divSCH').css({'background-color':'#00C521','color':'white'});           
            $('#schMenuLinks,#SpanAdv,#divWalkDist,#divEndAddress,#lbltime').css('display','block');
            $('#tpForm,#divTransitMode,.SpanAdvAdvanced,#divLeaveArr').css('display','none'); 
			$('#divP2PHeadline').css('visibility','hidden');
		});
		
		$('#ShowSubwayP2P').click( function() {
			$('#tpForm,#divWalkDist,#divEndAddress,#lbltime').css('display','block');
			$('#schMenuLinks,#divTransitMode,#divLeaveArr').css('display','none');
			$('#divP2PHeadline').css('visibility','visible');
		});
		*/
		
		/* Not in use?
		$("#f511link").hover(
			function() {
				$("#f511tip").css('display', 'block');
			},
			function() {
				$("#f511tip").css('display', 'none');
			});
		$("#triplink").hover(
			function() {
				$("#triptip").css('display', 'block');
			},
			function() {
				$("#triptip").css('display', 'none');
			});
		*/
		


	}
  };

})(jQuery);
