<!DOCTYPE html>
<html>
<head>
	<title>Ejemplo de generacion de reporte Random</title>
	<meta charset="UTF-8"></meta>
	<style type="text/css">
		.grafico{
			display: inline-block;
			width: 400px;
			height: 300px;
		}
		.mensaje{
			color: red;
			font-size: 24px;
		}
	</style>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
	<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
	<script type="text/javascript">
		google.charts.load('current',{'packages':['corechart']});
		google.charts.setOnLoadCallback(drawChart);

		//Funcion para generar graficos sin conexion a la base de datos
		function drawChart(){
			var data = google.visualization.arrayToDataTable([
					['Task','Hours per Day'],
					['Work',11],
					['Eat',2],
					['Commute',2],
					['Watch TV',2],
					['Sleep',7]
				]);

			var options = {'title':'Que haces durante el d\u00eda?',
            		         'width':400,
                    		 'height':300};


			var chart = new google.visualization.PieChart(document.getElementById('piechart'));
			chart.draw(data,options);

			var chart = new google.visualization.ColumnChart(document.getElementById('columnchart'));
			chart.draw(data,options);

			var chart = new google.visualization.LineChart(document.getElementById('linechart'));
			chart.draw(data,options);
		}		
	</script>
</head>
<body>
	<span class="mensaje">Ejemplos sin conexi&oacute;n a la Base de datos</span><br/>
	<a href="/">Volver</a>
	<div id="ContenedorEjemplos">
		<div id="piechart" class="grafico"></div>
		<div id="columnchart" class="grafico"></div>
		<div id="linechart" class="grafico"></div>		
	</div>
</body>
</html>