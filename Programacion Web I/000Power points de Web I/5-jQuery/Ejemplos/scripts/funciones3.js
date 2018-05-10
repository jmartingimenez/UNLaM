$(document).ready(function() {
	
	$("#btnAgregarClase").click(function(event){
		$("#lblMensaje").addClass("negrita");
	});
	

	$("#btnQuitarClase").click(function(event){
		$("#lblMensaje").removeClass("negrita");
	});	
});
