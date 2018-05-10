function saludo()											//funcion para pop-up
	
	{
		alert("Hola mundo");
	}

function guardar_var()										//declaracion de variable tipo string
															//el tipo se asigna automaticamente
	{
		 pregunta="C&oacute;mo les va?";
	}	
	
function mostrar()											//mostrando el contenido de la variable
															//por lo que se ve, las variables son globales
	{
		 document.write(pregunta);
	}