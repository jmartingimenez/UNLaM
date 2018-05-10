<!DOCTYPE HTML>
<html>
<head>
	<title>Lista de autos</title>
	<?php
		require_once("../clases/Concesionaria.php");
	?>
	<style type="text/css">
		th,td{border:1px solid black;font-weight:normal;}
		table{border-collapse: 	collapse;width:100%;margin:auto;}
		.titulo{background-color:yellow;}
	</style>	
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		$miConcesionaria	=	new Concesionaria();
		$miConcesionaria->obtenerAuto();
		$miConcesionaria->mostrarAuto();
	?>
</body>
</html>