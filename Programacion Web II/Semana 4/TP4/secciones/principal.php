<?php
	//Si hay cookie pero no hay sesion activa se redirecciona a una pagina de error
	SESSION_START();
	if(!isset($_SESSION['log']))
		{
			SESSION_DESTROY();
			header('location:error.php');
		}	
	print("Este ser&iacute;a el index principal. Si no hay sesi&oacute;n activa se redirige a una web de error<br/>");	
?>
<html>
<head>
	<title>TP4 - Gimenez - Index</title>
</head>
</html>