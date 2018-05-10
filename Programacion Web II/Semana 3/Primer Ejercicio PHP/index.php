<!DOCTYPE HTML>
<html>
<head>
	<title>Primer PHP</title>
</head>
<body>

	<!--FORMULARIO-->
	<form method="post" id="formulario">
		Usuario<br/>
		<input type="text" name="usuario"></input><br/>
		Clave<br/>
		<input type="password" name="clave"></input><br/>
		<input type="submit" name="ingresar" value="Ingresar"></input>
	</form>
	
	<!--LLAMADO AL ARCHIVO PHP DE VALIDACION-->
	<?php	
		include_once('php/validacion.php');	
	?>	

</body>
</html>