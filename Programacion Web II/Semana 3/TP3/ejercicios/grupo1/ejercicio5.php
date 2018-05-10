<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 5 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		$pepe 			= 	array(23,35,24,12,34);
		$numeroMayor	=	max($pepe);
		$numeroMenor	=	min($pepe);
		print('Array $pepe: ');
		foreach ($pepe as $elemento)
				{
					print($elemento . " ");				
				}
		print(	"<br/>\nEl numero mas alto (" . $numeroMayor . ")" . 
				", multiplicado por el mas bajo (" . $numeroMenor . ")" .
				", da como resultado " . ($numeroMayor*$numeroMenor) . ".\n");		
	?>
</body>
</html>