<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 5 - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a>
	<form method="post">
		Ingrese el primer numero:<br/>
		<input type="text" name="Numeros[]"></input><br/>
		Ingrese el segundo numero:<br/>
		<input type="text" name="Numeros[]"></input><br/>
		Ingrese el tercer numero:<br/>
		<input type="text" name="Numeros[]"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>				
	</form>
	<?php
		if(isset($_POST['enviar']))
			{
				$listadoDeNumeros=$_POST['Numeros'];
				foreach ($listadoDeNumeros as $subIndice)
					{
						if(!is_numeric($subIndice))
							{
								print("Ingrese los tres valores. Solo se permiten n&uacute;meros");
								exit();
							}
					}
				sort($listadoDeNumeros);
				print("El n&uacute;mero medio es " . $listadoDeNumeros[1]);	
												//No es muy elegante que digamos pero no estaba seguro de
			}									//como aplicar el ltrim() y el rtrim() para dejar solo el
												//del medio
	?>											
</body>
</html>