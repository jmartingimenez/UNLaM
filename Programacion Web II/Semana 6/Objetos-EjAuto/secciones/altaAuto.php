<!DOCTYPE HTML>
<html>
<head>
	<title>Carga de autos</title>

	<!-- Archivos externos requeridos -->
	<?php 
		require_once("../clases/Auto.php") 
	?>
</head>
<body>
	<!-- Link para volver al principio -->
	<a href="/">Volver</a><br/>

	<!-- Formulario para dar de alta un auto -->
	<form method="post">
		Patente:<br/>
		<input type="text" name="patente"></input><br/>
		Modelo:<br/>
		<input type="text" name="modelo"></input><br/>
		Color:<br/>
		<input type="text" name="color"></input><br/>
		<input type="submit" name="enviar" value="Env&iacute;ar"></input>
	</form>	

	<!-- Validaciones de PHP -->
	<?php
		if(isset($_POST['enviar']) AND (!empty($_POST['patente'])
			 OR !empty($_POST['modelo']) OR !empty($_POST['color'])))
			{
				$patenteDada	=	$_POST['patente'];
				$modeloDado		=	$_POST['modelo'];
				$colorDado		=	$_POST['color'];

				$nuevoAuto		=	new Auto($patenteDada,$modeloDado,$colorDado);

				//Si todo se valido bien se guarda en la base de datos
				//Las validaciones pueden ir en el constructor, no hay ninguna al ser un ejercicio
				//de prueba
				$nuevoAuto->guardarAuto();
			}
		else if(isset($_POST['enviar'])) print("Complete todos los datos");	
	?>	

</body>
</html>

