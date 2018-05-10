<!DOCTYPE HTML>
<html>
<head>
	<title>TP6 - Ejercicio 1</title>
</head>	
<body>
	<?php

		$bdd		=	"tp5";	//Reemplezar por alguna existente donde se ejecute esto para probar

		$conexion	=	mysqli_connect("localhost","root","",$bdd)
			or die("Conexi&oacute;n a la base de datos " . $bdd . ": fallida.<br/>\n");

		print("Conexi&oacute;n a la base de datos " . $bdd . ": exitosa.<br/>\n");	

		mysqli_close($conexion);	
	?>	
	<a href="/">Volver</a>
</body>
</html>