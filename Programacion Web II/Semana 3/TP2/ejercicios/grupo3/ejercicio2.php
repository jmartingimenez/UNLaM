<?php
/*Diseñar un programa de php que devuelva el nombre de un libro a leer de entre siete
disponibles a partir del valor de un autor determinado.*/
?>

<!DOCTYPE html>
<html>
<head>
	<title>Trabajo Pr&aacute;ctico 2 - Ejercicio 2 - Gimenez</title>
	<style>table,th,td{border: solid 1px; border-collapse: collapse;text-align: center;}</style>
</head>
<body>
	<a href="/">Volver</a><br/>
	<table style="width:70%">
		<tr style="font-size:30px">
			<td>Libro</td>
			<td>Autor</td>
		</tr>	
			<td>1</td>
			<td>A</td>
		</tr>
		</tr>	
			<td>2</td>
			<td>B</td>
		</tr>
		</tr>	
			<td>3</td>
			<td>C</td>
		</tr>
		</tr>	
			<td>4</td>
			<td>D</td>
		</tr>
		</tr>	
			<td>5</td>
			<td>C</td>
		</tr>
		</tr>	
			<td>6</td>
			<td>F</td>
		</tr>
		</tr>	
			<td>7</td>
			<td>G</td>
		</tr>												
	</table><br/>
	<form method="post">
		Ingrese un autor:<br/>
		<input type="text" name="autor"></input>
		<input type="submit" name="buscar" value="Buscar"></input>	
	</form>	
	<?php
		if(isset($_POST['buscar']) AND !empty($_POST['autor']))
			{
				$autorBuscado = $_POST['autor'];
				$listadoCompleto= array(
						array(1,"A"),
						array(2,"B"),
						array(3,"C"),
						array(4,"D"),
						array(5,"C"),
						array(6,"F"),
						array(7,"G"));
				print("El autor " . $autorBuscado . " posee los libros n&uacute;mero:<br/>");
				for ($i=0; $i<7; $i++)
					{ 
						if(strcasecmp($autorBuscado,$listadoCompleto[$i][1])==0)
							print($listadoCompleto[$i][0] . "<br/>");
					}
			}
	?>							
</body>
</html>