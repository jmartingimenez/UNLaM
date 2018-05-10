<!DOCTYPE HTML>
<html>
<head>
	<title>TP4 - Gimenez - Log In</title>
	<?php
		SESSION_START();
		if(isset($_SESSION['log']))
			header("location:secciones/principal.php");
	?>
</head>
<body>
	<h4>Ingrese los siguientes datos para validarse..</h4>
	User: root<br/>
	Password: not123<br/>
	<h1>Log In</h1>
	<form method="post">
		Usuario<br/>		
		<input type="text" name="user"
			 value="<?php if(isset($_COOKIE['usuarioValido'])) print("root"); ?>">
		</input><br/>
		Contrase&ntilde;a<br/>
		<input type="password" name="pass"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
		<input type="submit" name="deleteCookie" value="Borrar Cookie"></input>
	</form>
	<?php
		if(isset($_POST['enviar']) AND !empty($_POST['user']) AND !empty($_POST['pass']))
			{
				if($_POST['user'] == "root" AND $_POST['pass'] == "not123")
					{
						//nombreCookie/valor/vencimiento(20 dias despues)/directorio donde esta disponible
						setcookie("usuarioValido","root",time()+60*60*24*20,"/");
						print("Ingreso exitoso. Se ha generado una cookie.\n");
						SESSION_START();
						$_SESSION['log'] = 1;
						header("location:secciones/principal.php");
					}					
				else print("El nombre de usuario y la contrase&ntilde;a no coinciden.");		
			}
		else if(isset($_POST['enviar']))
			print("Complete todos los campos.");	
	?>	

	<?php
		if(isset($_POST['deleteCookie']) AND isset($_COOKIE['usuarioValido']))
			{
				setcookie("usuarioValido","",time()-3600);
				print("Cookie eliminada.");
			}
		else if(isset($_POST['deleteCookie']))
			print("No existe cookie guardada.");
		$_POST['user']="";			
	?>
</body>
</html>