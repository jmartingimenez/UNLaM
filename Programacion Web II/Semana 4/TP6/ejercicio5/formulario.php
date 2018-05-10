<!DOCTYPE HTML>
<html>
<head>
	<?php
		session_start();
		if(!isset($_SESSION['log']))
			header("location:/");
	?>
	<title>TP6 - Ejercicio 5 - Formulario</title>
	<style type="text/css">
		th,td{border:1px solid black;font-weight:normal;}
		table{border-collapse: 	collapse;width:100%;margin:auto;}
		.titulo{background-color:yellow;}
	</style>
</head>
<body>
	<a href="/">Volver</a><br/>

	<?php
		
		//Acceso a la base de datos
		$bdd		=	"tp6E3Cliente";
		$conexion	=	mysqli_connect("localhost","root","",$bdd)
			or die("Error en la conexi&oacute;n");

		$query		=	$_SESSION['query'];

		$consulta	=	mysqli_query($conexion,$query)
			or die("Fallo en la consulta.");

		if(mysqli_num_rows($consulta)==0)
			die("No se encontraron resultados");	

		print("<table>\n");
		print(	"<tr class='titulo'>\n" 				.
					"<th>ID</th>\n"						.
					"<th>Nombre</th>\n" 				.
					"<th>Apellido</th>\n"				.
					"<th>DNI</th>\n" 					.
					"<th>E-Mail</th>\n"					.
					"<th>Sexo</th>\n" 					.
					"<th>Fecha de Nacimiento</th>\n" 	.
					"<th>Editar</th>\n" 				.
				"</tr>\n");
		while($fila=mysqli_fetch_assoc($consulta))
			{
				print("<tr>\n");
				print("<th>" 	. $fila["id"]			. "</th>\n");	
				print("<th>" 	. $fila["nombre"] 		. "</th>\n");
				print("<th>" 	. $fila["apellido"] 	. "</th>\n");
				print("<th>" 	. $fila["DNI"] 			. "</th>\n");
				print("<th>" 	. $fila["email"] 		. "</th>\n");
				print("<th>"	. $fila["sexo"] 		. "</th>\n");
				print("<th>" 	. $fila["fechaNac"] 	. "</th>\n");
				print(	"<th>"	.
						"<a href='edicion.php?id=".$fila['id']."'>CLICK</a>" . 
						"</th><tr/>\n");
			}
		print("</table>\n");		
			
		mysqli_close($conexion);	

	?>
</body>
</html>