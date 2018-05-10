<?php
/*
Realice un programa en php que recorra los números del 1 al 20 y
a cada uno de ellos los multiplique por los números del 25 al 30. Imprima el resul-
tado en el navegador del usuario formateado en HTML.
*/
?>
<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 3 - Gimenez</title>
</head>
<body>
	<?php
		print('<a href="/">Volver</a><br/>' . "\n");
		for ($numero=1; $numero <= 20; $numero++) 
			{ 
				print("\t<p>\n");
				for ($segundoNumero=25; $segundoNumero <= 30; $segundoNumero++) 
					{ 
						print("\t" . $numero . " x " . $segundoNumero . "= " . $numero*$segundoNumero . "<br/>\n");
					}
				print("\t</p>\n");	
			}
	?>
</body>
</html>