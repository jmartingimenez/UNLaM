function validacion_formulario()

	{
		/*-------------CAMPO NOMBRE-------------*/	
			
				//Revisando que el campo del nombre no este vacio	
				
				if (document.getElementById("name").value.length==0)
					{
						alert("Tiene que escribir su nombre");
						document.getElementById("name").focus();
						return 0;
					}
					
		/*-------------CAMPO EDAD-------------*/

					//Revisando que el campo de la edad no este vacio
				
				if(document.getElementById("age").value.length==0)
					{
						alert("Tiene que escribir su edad");
						document.getElementById("age").focus();
						return 0;
					}
					
					//Revisando que en la edad se hayan ingresado numeros
					
					else if(isNaN(document.getElementById("age").value))
							{
								alert("Por favor ingrese una edad real");
								document.getElementById("age").focus();
								return 0;
							}

		/*-------------CAMPO EMAIL-------------*/

/*		
Expresiones regulares. Vamos a comprobar que el E-Mail ingresado contenga caracteres permitidos		

				var regexp=/^[0-9a-zA-Z._.-]+\@[0-9a-zA-Z._.-]+\.[0-9a-zA-Z]+$/

		/		= 		Todas las expresiones estaran entre estas barras (marca inicio y final)
		^		=		Se debe comenzar a buscar coincidencia desde el inicio de la cadena
		[]		=		Estamos separando la busqueda en bloques, si se presta atencion a
						los primeros corchetes, solo permiten numeros o letras por que el principio
						de la cadena se corresponde a lo que seria el NOMBRE DE USUARIO
		\		=		Esto es un delimitador que marca que cuando se encuentre el caracter que le sigue
						comienze a analizar el siguiente 'bloque'. En este caso es el arroba, que ademas
						es lo que debe ingresarse para pasar al siguiente bloque que tendria el nombre
						del servicio de correo (hotmail/gmail, etc). Luego viene otro delimitador para 
						el punto y de nuevo se piden caracteres alfanumericos, esto te obliga a 
						escribir algo como			"nombredeusuario@serviciodecorreo.algo"
		+		=		Supongo yo que une los 'bloques' para que se siga analizando (?)				
		$		=		Estamos indicando que se debe recorrer hasta el final de la cadena
		
		regexp.test 		->		Usamos la propiedad 'test' para testear el contenido ingresado
									en mail con los caracteres de la cadena regexp
		Si esto ultimo devuelve 0 o si no hay caracteres ingresados, mostramos el mensaje de error		

	
*/
		
				var regexp=/^[0-9a-zA-Z._.-]+\@[0-9a-zA-Z._.-]+\.[0-9a-zA-Z]+$/
				if((regexp.test(document.getElementById("mail").value)==0)		//En el ejemplo de jQuery
				||																//esto se ve mas simple y 			
				(document.getElementById("mail").value.length==0))				//claro separado en 2 ifs
					{
						alert("Ingrese una direccion de mail valida");
						document.getElementById("mail").focus();
						return 0;
					}	
					
				document.getElementById("contacto").submit();		//Enviamos el formulario
	}