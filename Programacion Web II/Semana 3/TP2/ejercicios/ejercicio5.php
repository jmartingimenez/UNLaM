<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 5 - Gimenez</title>	
</head>
<body>
	Variables<br/>
	$a = 3<br/>
	$b = 5<br/>
	<?php
		$a=3;
		$b=5;
		$aux=$a;
		$a=$b;
		$b=$aux;
		print("\n<br/>Variables cambiadas\n<br/>" . '$a = ' . $a . "\n<br/>" . '$b = '. $b);	
	?>
</body>
</html>