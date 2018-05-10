<!DOCTYPE HTML>
<html>
<head>
	<title>TP5 - Gimenez - Log In</title>
	<?php
		//Si sesion activa se redirecciona a la web principal
		SESSION_START();
		if(isset($_SESSION['log']))
			header("location:secciones/principal.php");
	?>
</head>
<body>
	<h1>Log In</h1>
	<form method="post">
		Usuario<br/>		
		<input type="text" name="user"
			 value="<?php if(isset($_COOKIE['usuarioValido'])) print($_COOKIE['usuarioValido']); ?>">
		</input><br/>
		Contrase&ntilde;a<br/>
		<input type="password" name="pass"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
		<input type="submit" name="deleteCookie" value="Borrar Cookie"></input><br/>
	</form>
	<br/><a href="secciones/registro.php">Haga click aqu&iacute; para registrar una nueva cuenta</a>
	<?php
		if(isset($_POST['enviar']) AND !empty($_POST['user']) AND !empty($_POST['pass']))
			{
				$usuarioLog	=$_POST['user'];
				$passLog	=md5($_POST['pass']);

				$conexion 	= mysqli_connect("localhost","root","","tp5")
					or die("No se puede conectar con el servidor");

				$query 		= "SELECT nombre FROM Usuario WHERE nombre='$usuarioLog' AND clave='$passLog'";
				$consulta	= mysqli_query($conexion,$query)
					 or die("Fallo la consulta");
					 //or die(mysqli_error($conexion));	//<--Da el error sql en la pagina

				$nfilas = mysqli_num_rows($consulta);
				if($nfilas == 0)
					die("\n<br/>Usuario y/o contrase&ntilde;a invalido");
				mysqli_close($conexion);		

				//nombreCookie/valor/vencimiento(20 dias despues)/directorio donde esta disponible
				setcookie("usuarioValido",$usuarioLog,time()+60*60*24*20,"/");
				SESSION_START();
				$_SESSION['log'] = 1;
				header("location:secciones/principal.php");
			}
		else if(isset($_POST['enviar']))
			print("Complete todos los campos.");	

	?>	

	<?php
		if(isset($_POST['deleteCookie']) AND isset($_COOKIE['usuarioValido']))
			{
				setcookie("usuarioValido","",time()-3600);
				print("\n<br/>Cookie eliminada.");
			}
		else if(isset($_POST['deleteCookie']))
			print("\n<br/>No existe cookie guardada.");
		$_POST['user']="";			
	?>
</body>
</html>