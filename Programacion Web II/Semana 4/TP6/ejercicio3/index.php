<!--Solo valide la fecha-->
<!DOCTYPE HTML>
<html>
<head>
	<title>TP6 - Ejercicio 3 - Index</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<form method="POST">
		Nombre:<br/>
		<input type="text" name="nombre"></input><br/>
		Apellido:<br/>
		<input type="text" name="apellido"></input><br/>
		DNI:<br/>
		<input type="text" name="dni" size="8"></input><br/>
		E-Mail:<br/>
		<input type="text" name="email"></input><br/>
		Sexo:<br/>
		<input type="radio" name="sexo" value="M" checked>Mujer</input>
		<input type="radio" name="sexo" value="H">Hombre</input><br/>
		Nacimiento: (D&iacute;a/Mes/A&ntilde;o)<br/>
		<input type="text" name="diaNac" maxlength="2" size="2"></input>/
		<input type="text" name="mesNac" maxlength="2" size="2"></input>/
		<input type="text" name="anioNac" maxlength="4" size="4"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input><br/>
	</form>	
	<?php
		//Viendo si el form esta lleno
		if(isset($_POST['enviar']) AND !empty($_POST['nombre']) AND !empty($_POST['apellido']) AND
			!empty($_POST['dni']) AND !empty($_POST['email']) AND !empty($_POST['sexo']) AND
				!empty($_POST['diaNac']) AND !empty($_POST['mesNac']) AND !empty($_POST['anioNac']))
			{
				//Viendo si la fecha es valida
				if(checkdate($_POST['mesNac'],$_POST['diaNac'],$_POST['anioNac'])===false)
					die("\nError!!: Ingrese una fecha valida.");
				
				//Viendo si el mail es valido
				if(!filter_var($_POST['email'],FILTER_VALIDATE_EMAIL))
					die("\nError!!: Ingrese un E-Mail valido.");


				/*INSERSION EN LA BASE DE DATOS*/

				//Variables
				$nombre 			=		$_POST['nombre'];
				$apellido 			=		$_POST['apellido'];
				$DNI 				=		$_POST['dni'];
				$email 				=		$_POST['email'];
				$sexo 				=		$_POST['sexo'];
				$diaNac 			=		$_POST['diaNac'];
				$mesNac 			=		$_POST['mesNac'];
				$anioNac 			=		$_POST['anioNac'];
				$fecha 				=		strtotime($anioNac.$mesNac.$diaNac);
				$fechaNacimiento	=		date('Y-m-d',$fecha);
				
				//Acceso a la base de datos

				$bdd				=		"tp6E3Cliente";
				$conexion			=		mysqli_connect("localhost","root","",$bdd)
					or die("\n<br/>Error de conexi&oacute;n con el servidor.");

				$query				=		"INSERT INTO Cliente
					(id,		nombre,		apellido,		DNI,	email,		sexo,		fechaNac) 			
					VALUES
					(DEFAULT,	'$nombre',	'$apellido',	'$DNI',	'$email',	'$sexo',	'$fechaNacimiento')";

				$consulta			=		mysqli_query($conexion,$query)
					or die("\n<br/>Error en la consulta SQL.");

				mysqli_close($conexion);

				header("location:registracion.php");		

			}
		else if(isset($_POST['enviar'])) print("Complete todos los campos.");			
	?>

</body>
</html>