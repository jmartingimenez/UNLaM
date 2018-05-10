<?php
	session_start();
	if(!isset($_SESSION['log']))
		header("location:/");

	print("<title>TP6 - Ejercicio 5 - Final</title>");
	print("<a href='/'>Volver</a><br/>");
	print(	"\nCambios aplicados.<br/>\n" . 
			"id: " 			. $_SESSION['verId'] 			. 	"<br/>\n"	.
			"nombre: "		. $_SESSION['verNombre']		. 	"<br/>\n"	.
			"apellido: "	. $_SESSION['verApellido']		.	"<br/>\n"	);

	session_destroy();

?>