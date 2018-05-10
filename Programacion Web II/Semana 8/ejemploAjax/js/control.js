$(document).ready(function(){
	$("#boton").click(function(){
		var ingreso 	=	$("#cajita").val();
		callAjax(ingreso);
	})
});

function callAjax(ingreso){
	$.ajax({
		type: "GET",
		data: "string="+ingreso,
		url: "../comprobacion.php",
		success: function(respuesta)
					{
						$("#cajita").removeClass();
						if(respuesta == 1)			$("#cajita").addClass("ok");
						else						$("#cajita").addClass("mal");	
					},
		error: function(respuesta){
			alert("Ocurrio un problema con ajax. El programa no funciona, igual que tu vida. Morite!!");}
		
	})
};


/*
Pasos:
	- Cuando se presiona el boton de enviar se ejecuta la funcion (.click)
	- Se guarda en la variable 'ingreso' lo escrito dentro del imput de id '#cajita'
	- Se llama a la funcion 'callAjax' dandole 'ingreso' como parametro

	- Se ejecuta ajax..
		* Se define el metodo, ira por GET
		* Se define el formato '"string"+ingreso', si se ingreso 'hola', seria 'string=hola'
		* Se define la url completa. Con el ej. anterior seria 'comprobacion.php?string=hola'

	- Se ejecuta el script PHP en 'comprobacion.php' (devolvera 1/0 -ver ese script para los comments-)
	- Se ejecuta el caso success
		* Se crea una funcion dandole como parametro 'respuesta' que sera lo devuelto por 'comprobacion.php'
		* Se remueve cualquier clase que tenga la id 'cajita' 
		* Se da una clase u otra segun el valor de respuesta (1 o 0)

*/