<!DOCTYPE HTML>
<html>
<head>
	<title>TP6 - Ejercicio 2</title>
</head>	
<body>
	<?php

		$bdd		=	"tp5";	//Reemplezar por alguna existente donde se ejecute esto para probar

		$conexion	=	mysqli_connect("localhost","root","",$bdd)
			or die("Conexi&oacute;n a la base de datos " . $bdd . ": fallida.<br/>\n");

		$query		=	"SELECT * FROM Usuario"; 
			
		$consulta 	=	mysqli_query($conexion,$query)
			or die("Fallo en la consulta.<br/>\n");

		$nfilas		=	mysqli_num_rows($consulta);

		print(	"Base de datos usada: " . $bdd . "<br/>\n\t" . 
				"Consulta usada: " . $query . "<br/>\n\t" . 
				"N&uacute;mero de filas afectadas: " . $nfilas . "<br/>\n");

		mysqli_close($conexion);

	?>	
	<a href="/">Volver</a>
</body>
</html>