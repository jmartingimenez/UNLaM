$(document).ready (function () 
{
	$("#mensaje1, #mensaje2, #mensaje3, #mensaje4").fadeOut();
	$("#mensaje5").fadeOut();
	
	$("#enviar").click (function ()
	{
		var formulario = $("#form").val();
		var usuario = $("#usuario").val();
		var password = $("#password1").val();
		var password2 = $("#password2").val();
		
		if (usuario == "")
		{
			$("#mensaje1").fadeIn();
			$("#usuario").css ("borderColor", "red");
		}
		else
		{
			$("#mensaje1").fadeOut();
			$("#usuario").css ("borderColor", "gray");
			
			if (password == "")
			{
				$("#mensaje2").fadeIn();
				$("#password1").css ("borderColor", "red");
			}
			else
			{
				$("#mensaje2").fadeOut();
				$("#usuario").css ("borderColor", "gray");
				
				if (password2 == "")
				{
					$("#mensaje3").fadeIn();
					$("#password2").css ("borderColor", "red");
				}
				else
				{
					$("#mensaje3").fadeOut();
					$("#usuario").css ("borderColor", "gray");
					
					if (password != password2)
					{
						$("#mensaje4").fadeIn();
						$("#password2").css ("borderColor", "red");
					}
					else
					{
						$("#mensaje4").fadeOut();
						$("#usuario").css ("borderColor", "gray");
						$("#mensaje5").fadeIn();
					}
				}
			}
		}
	});
});