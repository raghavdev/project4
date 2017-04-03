(function ($) {
$(document).ready(function(){
	SetTimeMyTrip();
	$("body").mouseup(function() {
		$("#fromAutoFillList").css('visibility', 'hidden');
		$("#toAutoFillList").css('visibility', 'hidden');
	});
	
	/* For date control in Trip Planner */
//	$("#fdate").datepicker()({ minDate: 0, maxDate: "+20D" }); this code breaks status block
//	$("#fdate").datepicker({ minDate: 0, maxDate: '+20D'}); jim w. tried to fix but it still does not work although the chANGES DO NOT BREAK STATUS BLOCK.
	$("#fdate").datepicker({ minDate: 0, maxDate: '20D' }); 
    $("#fdate").datepicker();
	$("#fdate").datepicker("setDate", new Date());

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
});

}(jQuery));
