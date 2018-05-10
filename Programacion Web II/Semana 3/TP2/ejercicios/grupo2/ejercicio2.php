<?php
/*Realice un bucle que imprima los números del 0 al 100 en orden invertido y en incrementos de 2
-ME CONFUNDIO LO DE INCREMENTOS, SUPONGO QUE SE REFIERE A DECREMENTOS (100,98,96,ETC..)*/
?>
<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 2 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<?php
		for($numero=100;$numero>=0;$numero-=2)
			{
				print($numero);
				if($numero>0) print(", "); else print(".");					
			}
	?>	
</body>
</html>
