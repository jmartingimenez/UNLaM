<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 3 - Ejercicio 1 (Formulario) - Gimenez</title>
</head>
<body>
	<a href="/">Volver</a><br/>
	<form method="post" name="formulario">
		Nombre:<br/>
		<input type="text" name="nombre" maxlength="10"></input><br/>
		Apellido:<br/>
		<input type="text" name="apellido" maxlength="10"></input><br/>
		DNI:<br/>
		<input type="text" name="DNI" maxlength="8"></input><br/>
		Email:<br/>
		<input type="text" name="mail"></input><br/>
		Nacimiento (d&iacute;a/mes/a&ntilde;o):<br/>
		<input type="text" name="nacDia" size="1" maxlength="2"></input>
		/ <input type="text" name="nacMes" size="1" maxlength="2"></input>
		/ <input type="text" name="nacAnio" size="1" maxlength="4"></input><br/>
		Sexo:
		<input type="radio" name="sexo" value="Masculino" checked>Masculino</input>
		<input type="radio" name="sexo" value="Femenino">Femenino</input><br/><br/>
		Documentaci&oacute;n presentada:
		<ul>
			<li>
				DNI<input type="checkbox" name="documentacion[]" value="DNI" checked></input>
			</li>
			<li>
				Partida de nacimiento
				<input type="checkbox" name="documentacion[]" value="Partida de nacimiento"></input>
			</li>
			<li>
				Libreta de casamiento
				<input type="checkbox" name="documentacion[]" value="Libreta de casamiento"></input>
			</li>
			<li>
				Certificado de convivencia
				<input type="checkbox" name="documentacion[]" value="Certificado de convivencia"></input>
			</li>
		</ul>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
		<input type="submit" name="cancelar" value="Cancelar"></input>
	</form>	
	<?php
		if(	isset($_POST['enviar'])		AND !empty($_POST['nombre']) 	AND !empty($_POST['apellido']) 	AND
			!empty($_POST['DNI'])		AND	!empty($_POST['mail'])		AND	!empty($_POST['nacDia'])	AND
			!empty($_POST['nacMes'])	AND	!empty($_POST['nacAnio']))
				{
					//Comienzo y seteo de variables de sesion
					SESSION_START();
					$_SESSION['log']			=		1;
					$_SESSION['nombre']			=		$_POST['nombre'];
					$_SESSION['apellido']		=		$_POST['apellido'];
					$_SESSION['DNI']			=		$_POST['DNI'];
					$_SESSION['mail']			=		$_POST['mail'];
					$_SESSION['nacDia']			=		$_POST['nacDia'];
					$_SESSION['nacMes']			=		$_POST['nacMes'];
					$_SESSION['nacAnio']		=		$_POST['nacAnio'];
					$_SESSION['sexo']			=		$_POST['sexo'];
					$_SESSION['documentacion']	=		$_POST['documentacion'];
					header('location:registracion.php');
				}
			else if(isset($_POST['enviar']))
				print("Complete todo el formulario.");	
	?>
</body>
</html>