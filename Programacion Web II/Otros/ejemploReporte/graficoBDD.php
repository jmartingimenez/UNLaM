<!DOCTYPE html>
<html>
<head>
	<title>Ejemplo de generacion de reporte</title>
	<meta charset="UTF-8"></meta>
	<style type="text/css">
		.graficoBDD{
			display: inline-block;
		}
		.mensaje{
			color: red;
			font-size: 24px;
		}
	</style>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
	<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
	<script type="text/javascript">
		$(function(){
			google.charts.load('current',{'packages':['corechart','table']});
			google.charts.setOnLoadCallback(loadData);
		});

		function loadData(){
			$.ajax({
				url: "getData.php",
				dataType: "JSON",
				success: drawChartBDD
			});
		}

		function drawChartBDD(jsonData){
			var lineData = new google.visualization.arrayToDataTable(jsonData);

			var chart_div = document.getElementById('ejemploBDD');
			var chart = new google.visualization.LineChart(document.getElementById('ejemploBDD'));

			//Que se dibuje cuando haya cargado la pagina (util para pasar a pdf)
			google.visualization.events.addListener(chart,'ready',function(){
				chart_div.innerHTML='<img src="'+chart.getImageURI()+'">';
			});	

			chart.draw(lineData,{title:'G\u00e9neros',width:600,height:400});

			var table = new google.visualization.Table(document.getElementById('ejemploBDDTabla'));
			table.draw(lineData,{showRowNumber:true,width:200});
		}
	</script>
</head>
<body>
	<span class="mensaje">Ejemplo con conexi&oacute;n a la Base de datos</span><br/>
	<a href="/">Volver</a>
	<div id="contenedorEjemplosBDD">
		<div id="ejemploBDD" class="graficoBDD"></div>
		<div id="ejemploBDDTabla" class="graficoBDD"></div>
	</div>

</body>
</html>