<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 4 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		$pepe 		= 	array('gato','perro','caballo','pez','tomate');
		$pepeInv	=	array_reverse($pepe);
		print('Array $pepe:' . "<br/>\n");
		foreach ($pepe as $elemento)
				{
					print("\t\t" . $elemento . "<br/>");				
				}
		print("<br/>\n\t" . 'Array $pepe invertido:' . "<br/>\n");	
		foreach ($pepeInv as $elemento)
			{
				print("\t\t" . $elemento . "<br/>");				
			}
		print("\n");		
	?>
</body>
</html>
