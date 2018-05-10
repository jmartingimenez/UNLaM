<?php
	if(isset($_POST['ingresar']))								
		{
			comprobacion();										
		}
	
	/*=========================================================================================\
	\ESTA FUNCION OBTIENE EL USUARIO Y LA CONTRASEÑA INGRESADOS A TRAVES DEL FORMULARIO Y EN   \
	\BASE AL CONTENIDO MUESTRA DIVERSOS MENSAJES.										       \
	\=========================================================================================*/
	function comprobacion()
		{
			$usuario	=	$_POST['usuario'];					
			$clave 		=	$_POST['clave'];	
			if($usuario ==	'facu' AND $clave == 123)
				{
					print("<p>Hola " . $usuario . "\n</p>");	
				}
			else
				{
					print("<p>Quien te conoce " . $usuario . "??\n</p>");
				}	
		}	
?>

