<?php
   	$host = '127.0.0.1';
	$user = 'root';
 	$pass = '';
 	$db = 'negrify';

 	//Conexion a la base de datos
 	$conexion = mysqli_connect($host,$user,"",$db)
 					or die("No se puede conectar con la base de datos.");

 	$sql = "SELECT nombre,COUNT(*) AS 'cantidad' 
 			FROM Genero 
 			GROUP BY nombre 
 			ORDER BY cantidad DESC";
 	$query = mysqli_query($conexion,$sql)
 				or die("Fallo la consulta");				

 	$dataTable = array(array("Nombre","Cantidad"));
 	while($fila=mysqli_fetch_assoc($query)){
 		$dataTable[]=array($fila['nombre'],(int)$fila['cantidad']);
 	}

 	mysqli_close($conexion);				

 	print(json_encode($dataTable));

?>