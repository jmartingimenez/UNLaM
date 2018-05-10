<!DOCTYPE HTML>
<html>
<head>
	<title>TP5 - Gimenez - Log Out</title>
</head>
<body>
	<?php
		//Si no hay cookie se redirecciona a la web de login
		if(!isset($_COOKIE['usuarioValido']))
			header("location:/");

		//Si hay cookie pero no hay sesion activa se redirecciona a una pagina de error
		SESSION_START();
		if(!isset($_SESSION['log']))
			{
				SESSION_DESTROY();
			header('location:error.php');
			}

		//Si se llego hasta aca es por que se cerro sesion correctamente
		SESSION_DESTROY();		
	?>	
	User deslogeado<br/>
	<a href="/">Inicio</a>
</body>
</html>