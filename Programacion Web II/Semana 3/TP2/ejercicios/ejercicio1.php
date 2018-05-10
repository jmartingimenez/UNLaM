<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 1 - Gimenez</title>
</head>
<body>
	<form method="post">
		Ingrese algo:<br/>
		<input type="text" name="ingreso"></input>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$ingresoDeUsuario	=	$_POST['ingreso'];
				print("<br/>Contenido: " . $ingresoDeUsuario . "\n<br/>Tipo de dato: " . gettype($ingresoDeUsuario));
			}
	?>
</body>
</html>

