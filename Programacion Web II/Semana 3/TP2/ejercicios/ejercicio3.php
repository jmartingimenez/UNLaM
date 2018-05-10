<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 3 - Gimenez</title>
</head>
<body>
	<form method="post">
		Base:<br/>
		<input type="text" name="base"></input><br/>
		Altura:<br/>
		<input type="text" name="altura"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$base			=	$_POST['base'];
				$altura			=	$_POST['altura'];
			if(!is_numeric($base) OR !is_numeric($altura))
				{
					print("\n<br/>Ingrese numeros. No se permiten letras.");				
				}
			else
				{
					$areaRectangulo	=	($base*$altura);
					print("\n<br/> El area es: " . $areaRectangulo);						
				}
			}
	?>
</body>
</html>