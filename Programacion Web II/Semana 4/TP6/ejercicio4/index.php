<!--USA LA BASE 'tp6E3Cliente' DEL EJERCICIO ANTERIOR-->
<!DOCTYPE HTML>
<html>
<head>
	<title>TP6 - Ejercicio 4 - Index</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<h3>Administraci&oacute;n de clientes</h3>
	<h5>Busque clientes por nombre y/o apellido</h5>
	<form>
		Nombre:<br/>
		<input type="text" name="nombre"></input><br/>
		Apellido:<br/>
		<input type="text" name="apellido"></input><br/>
		<input type="submit" name="busqueda" value="Consultar"></input><br/>
	</form>
	<?php
		if(isset($_GET['busqueda']) AND (!empty($_GET['nombre']) OR !empty($_GET['apellido'])))
			{
				//Se declara si su campo no esta vacio
				if(!empty($_GET['nombre'])) 		$nombre 	=	$_GET['nombre'];
				if(!empty($_GET['apellido']))		$apellido 	=	$_GET['apellido'];

				//Definiendo la query

				if(isset($nombre) AND isset($apellido))
					$query			=	"SELECT * FROM Cliente WHERE nombre='$nombre' AND apellido='$apellido'";
				else if(isset($nombre)) 
					$query			=	"SELECT * FROM Cliente WHERE nombre='$nombre'";
					else 
						$query		=	"SELECT * FROM Cliente WHERE apellido='$apellido'";

				session_start();
				$_SESSION['query']	=	$query;
				header("location:formulario.php");
			}	
		else if(isset($_GET['busqueda'])) print("Complemete al menos un campo.");	
	?>	
</body>
</html>