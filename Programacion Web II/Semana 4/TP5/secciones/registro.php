<!DOCTYPE HTML>
<html>
<head>
	<title>TP5 - Gimenez - Registro</title>
</head>
<body>
	<a href="/">Inicio</a>
	<h1>Nuevo usuario</h1>
	<form method="post">
		Nombre<br/>
		<input type="text" name="nuevoUsuario"></input><br/>
		Clave<br/>
		<input type="password" name="pass"></input><br/><br/>
		<input type="submit" name="registro" value="Registrar"></input>
	</form>
	<?php
		if(isset($_POST['registro']) AND !empty($_POST['nuevoUsuario']) AND !empty($_POST['pass']))
			{
				$nuevoUsuario	=	$_POST['nuevoUsuario'];
				$nuevoPassword	=	md5($_POST['pass']);
				accesoBDD($nuevoUsuario,$nuevoPassword);
			}
		else if(isset($_POST['registro']))
			{
				print("Complete todos los campos.");
			}	

		function accesoBDD($nuevoUsuario,$nuevoPassword)
			{
				$conexion 	= mysqli_connect("localhost","root","","tp5")
					or die("No se puede conectar con el servidor");

				$query 		= "SELECT nombre FROM Usuario WHERE nombre='$nuevoUsuario'";
				$consulta	= mysqli_query($conexion,$query)
					 or die("Fallo la consulta");
					 //or die(mysqli_error($conexion));	//<--Da el error sql en la pagina

				$nfilas		= mysqli_num_rows($consulta);
				if($nfilas > 0)
					print("El nombre de usuario ya se encuentra en uso");
				else
					{
						$query 		= "INSERT INTO Usuario (idUsuario,	nombre,				clave) 
													VALUES (DEFAULT,	'$nuevoUsuario',	'$nuevoPassword')";
						$consulta	= mysqli_query($conexion,$query)
							//or die(mysqli_error($conexion));
							or die("Error al agregar el usuario a la base de datos.");
						print("Usuario registrado satisfactoriamente.");
					}
				mysqli_close($conexion);
			}	
	?>
</body>
</html>