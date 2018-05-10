<!DOCTYPE HTML>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 4 - Gimenez</title>
</head>
<body>
	<form method="post">
		Base mayor:<br/>
		<input type="text" name="baseMayor"></input><br/>
		Base menor:<br/>
		<input type="text" name="baseMenor"></input><br/>		
		Altura:<br/>
		<input type="text" name="altura"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$baseMayor		=	$_POST['baseMayor'];
				$baseMenor		=	$_POST['baseMenor'];				
				$altura			=	$_POST['altura'];
			if(!is_numeric($baseMayor) OR !is_numeric($baseMenor) OR !is_numeric($altura))
				{
					print("\n<br/>Ingrese numeros. No se permiten letras.");				
				}
			else
				{
					$areaTrapecio	=	(($baseMayor+$baseMenor)/2)*$altura;
					print("\n<br/> El area es: " . $areaTrapecio);						
				}
			}
	?>
</body>
</html>