<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 3 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	Array: $pepe = ("gato","perro","caballo","pez","tomate");<br/>
	<form method="POST">
		Ingrese alguno de los elementos mencionados arriba para obtener su posicion: 
		<input type="text" name="busqueda" size="15"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input><br/>
	</form>
	<?php
		if(isset($_POST['enviar']) AND !empty($_POST['busqueda']))
			{
				$pepe 		= 	array('gato','perro','caballo','pez','tomate');
				$busqueda 	= 	$_POST['busqueda'];
				foreach ($pepe as $indice => $asociativo)
					{
						if(strcmp($busqueda,$asociativo)==0)
							{
								print("<p>&Iacute;ndice: " . $indice . "</p>");
								die();
							}								
					}
				print("No se encontro la busqueda.");	
			}
	?>
</body>
</html>
