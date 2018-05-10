<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 1 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		//Para setear la zona desde la cual tomar la hora (GMT -3)
		date_default_timezone_set("America/Argentina/Mendoza");

		//Formato extendido ("j/m/y H:i")	<--'h' toma hora de 01 a 12/'H' de 00 a 23.
		$horaActual=date("H:i");							//Obtiene la hora actual.
		$horaActual=date("H:i A",strtotime($horaActual));	//Para ver el AM/PM
		print("Son las " . $horaActual);
		switch($horaActual)
			{
				case ($horaActual > "05:00" AND $horaActual < "13:00"):	
					print(". Buenos D&iacute;as!!\n");
					break;
				case ($horaActual > "13:00" AND $horaActual < "20:00"):
					print(". Buenas Tardes!!\n");
					break;
				default: print(". Buenas Noches!!\n");	
			}
	?>
</body>
</html>