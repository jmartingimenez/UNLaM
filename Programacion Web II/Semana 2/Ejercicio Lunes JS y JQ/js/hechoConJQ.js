$(document).ready(function()
{
	$("#botoncito").click(function()
	{
		var textoDelBoton=$("#botoncito").html();
		if(textoDelBoton=="Cuando nos vamos?")
			{
				
				$("#botoncito").html("Limpiar");
				var horaDeSalida=23;
				var fecha=new Date();
				var horaActual=fecha.getHours();				
				if((horaDeSalida-horaActual)>1)
					$("#idvacio").html("Faltan " + (horaDeSalida-horaActual) + " hora/s.");
				else
					{
						var minutoActual=fecha.getMinutes();
						$("#idvacio").html("Faltan " + (60-minutoActual) + " minuto/s.");
					}
			}
		else
			{
				$("#idvacio").html("");
				$("#botoncito").html("Cuando nos vamos?");
			}
	});
});

