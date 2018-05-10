function miMain()
	{
		var Boton				=	document.getElementById('botoncito');	
		if(Boton.innerHTML		==	'Cuando nos vamos?')				//Usar innerHTML para el texto del boton
			{															//(no me funciono 'value')
				Boton.innerHTML	=	"Limpiar";
				tiempoRestante();
			}
		else
			{
				Boton.innerHTML	=	"Cuando nos vamos?";
				vaciarDiv();
			}	
	}

function tiempoRestante()
	{
		
		/*DECLARACION DE VARIABLES*/
		var fecha 			= 	new Date();								//obteniendo la fecha
		var hora  			= 	fecha.getHours();						//obteniendo la hora actual
		var minuto			=	fecha.getMinutes();						//obteniendo el minuto actual
		var horaDeSalida	=	23;										//declarando la hora de salida

		/*SI ESTAMOS EN LA MISMA HORA... MOSTRAMOS 'Ahora'*/
		if(hora==horaDeSalida)
			{
				document.getElementById('idvacio').innerHTML="Ahora";	//Se agrega el msj al id que no tiene nada
				return;
			}

		/*SI FALTA MENOS DE UNA HORA, MOSTRAMOS LOS MINUTOS RESTANTES*/
		if(hora==horaDeSalida-1)
			{
				document.getElementById('idvacio').innerHTML="A las " + horaDeSalida + ". Faltan " + (60-minuto)
				+ "minuto/s."; 
			}	
		
		/*DE LO CONTRARIO, MOSTRAMOS LA HORAS RESTANTES*/	
		else
			{
				document.getElementById('idvacio').innerHTML="A las " + horaDeSalida + ". Faltan " + 
				(horaDeSalida-hora) + "hora/s."
			}	
	};

function vaciarDiv()
	{
		var elIdVacio			=	document.getElementById('idvacio');
		elIdVacio.innerHTML		=	'';					
	}	