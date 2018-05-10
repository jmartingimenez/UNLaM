<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 2 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		date_default_timezone_set("America/Argentina/Mendoza");
		$horaActual = date("H:i");
		$horaActual = date("H:i A",strtotime($horaActual));
		print("Son las " . $horaActual);
		switch($horaActual)
			{
				case ($horaActual > "05:00" AND $horaActual < "13:00"):	
					print(	". Buenos D&iacute;as!!<br/>\n\t" . 
							'<img src="/imagenes/dia.png" alt="dia"/>' . "\n");					
					break;
				case ($horaActual > "13:00" AND $horaActual < "20:00"):
					print(	". Buenas Tardes!!<br/>\n\t" .  
							'<img src="/imagenes/tarde.png" alt="tarde"/>' . "\n");					
					break;
				default: 
					print(	". Buenas Noches!!<br/>\n\t" . 
							'<img src="/imagenes/noche.png" alt="noche"/>' . "\n");					
			}
	?>
</body>
</html>