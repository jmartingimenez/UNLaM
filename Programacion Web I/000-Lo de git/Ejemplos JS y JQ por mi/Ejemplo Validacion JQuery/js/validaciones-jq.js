$(document).ready (function () 
{
	$("#mensaje1, #mensaje2").fadeOut();
	
	$("#enviar").click (function ()
	{
		var formulario = $("#formulario").val();
		var usuario = $("#usuario").val();
		
		if (usuario == "")
		{
			$("#mensaje1").fadeIn();
			$("#usuario").css ("background-color", "red");
		}
		else
		{
			$("#mensaje1").fadeOut();
			$("#usuario").css ("borderColor", "green");
			$("#mensaje2").fadeIn();
		}
	});
	
	$("#limpiar").click (function ()
	{
	$("#mensaje1, #mensaje2").fadeOut();
	$("#usuario").css ("background-color", "white");
	});
	
	
});