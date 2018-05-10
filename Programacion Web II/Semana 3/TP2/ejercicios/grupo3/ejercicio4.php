<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 4 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a>
	<form method="post">
		Ingrese el primer numero:<br/>
		<input type="text" name="primerNumero"></input><br/>
		Ingrese el segundo numero:<br/>
		<input type="text" name="segundoNumero"></input><br/>
		Ingrese el tercer numero:<br/>
		<input type="text" name="tercerNumero"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>				
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$primerNumero	=	$_POST['primerNumero'];
				$segundoNumero	=	$_POST['segundoNumero'];
				$tercerNumero	=	$_POST['tercerNumero'];
				if(is_numeric($primerNumero) AND is_numeric($segundoNumero) AND is_numeric($tercerNumero))
					{
						$numeroMenor	=	$primerNumero;
						if($segundoNumero < $numeroMenor)	$numeroMenor=$segundoNumero;
						if($tercerNumero < $numeroMenor)	$numeroMenor=$tercerNumero;	
						print("El n&uacute;mero mas bajo es: " . $numeroMenor);
					}
				else print("Ingrese los tres valores. Solo se permite n&uacute;meros");	
			}
	?>
</body>
</html>