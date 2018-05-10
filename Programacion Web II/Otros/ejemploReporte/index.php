<!DOCTYPE html>
<html>
<head>
	<title>Ejemplo de generacion de reporte</title>
	<meta charset="UTF-8"></meta>
</head>
<body>
<a href="graficoRandom.php">Ver gr&aacute;ficos generados con datos randoms</a><br/>
<a href="graficoBDD.php">Ver n gr&aacute;fico generado con conexi&oacute;n a la base de datos</a><br/>
<h3>Cosas a tener en cuenta</h3><br/>
<p>
	<ol>
		<li>
			Hice gr&aacute;ficos de los generos existentes (una query simple para probar). Para que funcione
			hay que tener la BDD que subi la ultima vez con los inserts (o al menos, generos ingresados).
		</li>
		<li>
			Los gr&aacute;ficos randoms son interactivos. El generado por la BDD no, 
			lo transforme en imagen (la tabla si es interactiva) por que es mas util para despues 
			pasar a PDF si no me equivoco.
		</li>
		<li>
			En los gr&aacute;ficos de barras y lineas, si se fijan, las aclaraciones de los items 
			no se ven completas (Esto es por que no dependen del tama&ntilde;o del div contenedor, sino 
			de los atributos 'width' y 'height' del metodo draw).<br/>
			Ejemplo que puse en el gr&aacute;fico que conecta a la BDD:<br/> 
			'chart.draw(lineData,{title:'G\u00e9neros',width:600,height:400});'
		</li>
	</ol>
</p>
</body>
</html>