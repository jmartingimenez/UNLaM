<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 1 - Gimenez</title>	
</head>
<body>
	<a href="/">Volver</a><br/>
	<form method="post">
		Ingrese un numero:<br/>
		<input type="text" name="numero"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></br>		
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$numero=$_REQUEST['numero'];
				if(is_numeric($numero))
					{
						calculoNumero($numero);	
					}					
				else print("Ingrese un numero por favor");					
			}

		function calculoNumero($numero)
			{
				print("\n<br/>Valor ingresado = " . $numero . "<br/>\n");
				for ($nuevoNumero=1; $nuevoNumero<=$numero; $nuevoNumero++) 
					{ 
						print(	"Iteraci&oacute;n = " . $nuevoNumero . " - " .
								"Valor = " . $numero*$nuevoNumero . 
								"<br/>\n");
					}				
			}	
	?>
</body>	
</html>