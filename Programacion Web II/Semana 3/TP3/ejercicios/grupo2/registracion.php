<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 1 (Registraci&oacute;n) - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<a href="formulario.php">Volver al formulario</a><br/>
	<?php
		SESSION_START();
		if(!isset($_SESSION['log']))
			{
				SESSION_DESTROY();
				header('location:error.php');
			}		
		
		//Seteo de variables		
		$nombre			=	$_SESSION['nombre'];
		$apellido		=	$_SESSION['apellido'];
		$DNI 			=	$_SESSION['DNI'];
		$mail			=	$_SESSION['mail'];
		$diaNacimiento	=	$_SESSION['nacDia'];
		$mesNacimiento	=	$_SESSION['nacMes'];
		$anioNacimiento	=	$_SESSION['nacAnio'];
		$sexo			=	$_SESSION['sexo'];
		$documentacion	=	$_SESSION['documentacion'];

		//Mostrando el contenido.
		print("<h3>Datos ingresados</h3>");

		print(	"Nombre: " 			.	 $nombre 			. "<br/>\n" .
				"Apellido: " 		. 	 $apellido 			. "<br/>\n" .
				"DNI: " 			. 	 $DNI				. "<br/>\n" .
				"E-Mail: " 			.	 $mail 				. "<br/>\n" .
				"D&iacute;a: " 		.	 $diaNacimiento		. "<br/>\n" .
				"Mes: " 			.	 $mesNacimiento 	. "<br/>\n" .
				"A&ntilde;o: " 		.	 $anioNacimiento 	. "<br/>\n" .
				"Sexo: " 			.	 $sexo 				. "<br/>\n");

		print("Documentaci&oacute;n: ");
		foreach($documentacion as $documento)
			print($documento . ". ");
		print("\n");			

		/*------------------------------VALIDACION DE ERRORES-------------------------------*/

		print("<h3>Verificaci&oacute;n</h3>");
		
		$mensajeTodoOK=5;	//Si se mantiene asi se muestra un mensaje que dice que todo esta perfecto.

		//Nombre (El '$' si no estoy equivocado obliga a que todo sea como esta en la regexp)
		if(strlen($nombre) >= 5 AND strlen($nombre) <= 10 AND preg_match('/^[a-zA-Z]+$/',$nombre))
			print("\nNombre ingresado correctamente.<br/>\n");
		else
			{
				print("\nError: El nombre debe tener entre 5 y 10 caracteres. Solo se admiten letras.<br/>\n");
				$mensajeTodoOK--;
			}			

		//Apellido
		if(strlen($apellido) >= 3 AND strlen($apellido) <= 10 AND preg_match('/^[a-zA-Z]+$/',$apellido))
			print("\nApellido ingresado correctamente.<br/>\n");
		else
			{
				print("\nError: El apellido debe tener entre 3 y 10 caracteres. Solo se admiten letras.<br/>\n");
				$mensajeTodoOK--;
			}
				
		//DNI
		if(strlen($DNI) == 8 AND is_numeric($DNI))
			print("\nDNI Ingresado correctamente.<br/>\n");
		else
			{
				print("\nError: El DNI debe conteneter 8 numeros. No se admiten letras.<br/>\n");
				$mensajeTodoOK--;
			}			

		//E-mail (encontre sobre la funcion 'filter_var' pero segun lei puede dar falsos positivos)
		if(preg_match('/[a-zA-Z0-9_\-.+]+@[a-zA-Z0-9\-]+.[a-zA-Z]+/',$mail))
			print("\nEl E-mail ingresado parece ser correcto.<br/>\n");
		else
			{
				print("\nError: El E-mail ingresado no parece ser valido.<br/>\n");
				$mensajeTodoOK--;
			}			

		//Fecha de nacimiento
		if(checkdate($mesNacimiento,$diaNacimiento,$anioNacimiento==TRUE))
			print("\nFecha ingresada correctamente.<br/>\n");
		else
			{
				print("\nError: Ingrese una fecha real. Solo se admiten n&uacute;meros.<br/>\n");
				$mensajeTodoOK--;
			}			

		//Mensaje Final (Si esta todo bien)
		if($mensajeTodoOK==5)	
			print("\n<p><h3>Todo fue ingresado correctamente</h3></p><br/>\n");	
		
		//Destruccion de la sesion (no se puede recargar la pagina, hay que volver a llenar el form)
		SESSION_DESTROY();
	?>
</body>
</html>
