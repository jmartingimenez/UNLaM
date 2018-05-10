<!DOCTYPE HTML>
<html>
<head>
	<title>TP6 - Ejercicio 5 - Edici&oacute;n</title>
	<?php
		session_start();
		if(!is_numeric($_GET['id']) OR !isset($_SESSION['log']))				
			header("location:/");
	?>
	<script type="text/javascript" src="js/jquery-3.1.0.min.js"></script>
	<script type="text/javascript" src="js/confirmacion.js"></script>
</head>
<body>
	<?php
		print("<a href='/'>Volver</a><br/>");

		$idElegida	=	$_GET['id'];
		
		//Acceso a la base de datos
		$bdd		=	"tp6E3Cliente";
		$conexion	=	mysqli_connect("localhost","root","",$bdd)
			or die("Error en la conexi&oacute;n");

		$query		=	"SELECT * FROM Cliente WHERE id='$idElegida'";	

		$consulta	=	mysqli_query($conexion,$query)
			or die("Fallo en la consulta.");

		if(mysqli_num_rows($consulta)==0)
			die("No se encontro al usuario.");	

		$fila=mysqli_fetch_assoc($consulta);

		print(	"<form method='post' id='formulario'>\n" .
					"Nombre:<br/>" .
					"<input type='text' name='nombre' value='".$fila['nombre']."'</input><br/>" .  
					"Apellido:<br/>" .
					"<input type='text' name='apellido' value='".$fila['apellido']."'</input><br/>" .	
					"<input type='submit' name='cambio' value='Modificar'></input>" .	
					"<input type='submit' name='eliminacion' value='Eliminar'></input>" .		
				"</form>");

		//Comprobando que se completaron ambos campos
		if((isset($_POST['cambio']) OR isset($_POST['eliminacion'])) AND 
			(empty($_POST['nombre']) OR empty($_POST['apellido'])))
				die("\nComplete todos los campos.<br/>\n");
		else if(isset($_POST['cambio']) OR isset($_POST['eliminacion']))
			{
				$nuevoNombre	=	$_POST['nombre'];
				$nuevoApellido	=	$_POST['apellido'];	
				if(isset($_POST['cambio']))
					$query = "	UPDATE Cliente 
								SET nombre='$nuevoNombre', apellido='$nuevoApellido'
							 	WHERE id='$idElegida'";
				else if(isset($_POST['eliminacion']))
					$query = "	DELETE
								FROM Cliente 
								WHERE id='$idElegida'";
				
				$consulta	=	mysqli_query($conexion,$query)
					or die("Fallo en la consulta.");	

				mysqli_close($conexion);

				$_SESSION['verId']			=	$idElegida;
				$_SESSION['verNombre']		=	$nuevoNombre;
				$_SESSION['verApellido']	=	$nuevoApellido;

				header("location:mensajefinal.php");				

			}

	?>
</body>	
</html>