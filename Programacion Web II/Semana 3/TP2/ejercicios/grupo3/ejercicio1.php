<?php
/*Escribir un programa php que resuelva la ecuación x2+2*x+b, conociendo los valores de x y b
 - NO ESTABA SEGURO SI ERA LA CUADRATICA (ax2+bx+c). LO HICE DE MANERA SIMPLE TOMANDO ESA ECUACION LITERAL-*/
?>

<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 1 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<form method="post">
		Ecuaci&oacute;n x<sup>2</sup>+2x+b.<br/>Ingrese los valores correspondientes:<br/>
		x: <input type="text" name="x"></input><br/>
		b: <input type="text" name="b"></input>
		<input type="submit" name="calcular" value="Calcular"/>
	</form>
	<?php
		if(isset($_POST['calcular']))
			{
				$x=$_POST['x'];
				$b=$_POST['b'];
				if(is_numeric($x) AND is_numeric($b))
					print("Resultado: " . ( pow($x, 2) + (2*$x) + $b) );
				else print("Ingrese los dos numeros.");			
			}
	?>
</body>
</html>
