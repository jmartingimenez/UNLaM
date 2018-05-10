$(document).ready
	(
		function validar_formulario()									//Si, es una sinxtasis de mierda..
			{
				//$(".campo").css ("border", "2px solid black");			//Cuando carge el documento, todos los
																		//bordes de los campos obligatorios
																		//tendran un borde negro grueso
																		
				$("#send").click										//Cuando se envie el formulario...
					(
						function validar_campos()						//Sin estos nombres funciona igual					
							{											//lo deje por un tema de legibilidad
							
								$(".error").remove();					//Quitamos cualquier efecto que les
																		//hallamos agregado a los input
																		//sin esto, cuando se corrija un error
																		//seguira la advertencia
																		
								if($("#name").val()=="")				//checkeando que este el nombre	
									{

										$("#name").focus().after("<span class='error'>Ingrese su nombre</span>");
										/*Ponemos el cursor en el campo que da el error y mostramos ese mensaje*/
										return false;
									}
								if($("#age").val()=="")						//checkeando que este la edad
									{
										$("#age").focus().after("<span class='error'>Ingrese su edad</span>");
										return false;
									}								
								if($.isNumeric($("#age").val())==false)		//checkeando que la edad sea un numero
									{
										$("#age").focus().after("<span class='error'>Ingrese una edad real</span>");
										return false;
									}
								if($("#mail").val()=="")					//checkeando que el mail este
									{
										$("#mail").focus().after("<span class='error'>Ingrese su mail</span>");
										return false;
									}								
								var regexp=/^[0-9a-zA-Z._.-]+\@[0-9a-zA-Z._.-]+\.[0-9a-zA-Z]+$/
								if(regexp.test($("#mail").val())==0)		//checkeando que el formato sea bueno
									{
										$("#mail").focus().after("<span class='error'>Ingrese un mail real</span>");
										return false;
									}
								if($("#datepicker").val()=="")				//checkeando que el datepicker se haya
									{										//usado

										$("#datepicker").focus().after("<span class='error'>Ingrese su fecha de nacimiento</span>");														
										return false;
									}										
								contacto.submit();							//enviamos el formulario
							}
					);				
			}
	);
	
//$("#datepicker").css ("border", "2px solid red");	
/*
Eso sirve para recuadrar un campo, es una forma facil de mostrar un error
*/	