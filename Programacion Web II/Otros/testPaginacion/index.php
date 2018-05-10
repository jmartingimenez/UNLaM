<!DOCTYPE html>
<html>
<head>
	<title>Test Paginaci&oacute;n</title>
	<!--Import Google Icon Font-->
      <link href="http://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
      <!--Import materialize.css-->
      <link type="text/css" rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/css/materialize.min.css"  media="screen,projection"/>

      <!--Let browser know website is optimized for mobile-->
      <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
      <meta charset="UTF-8">
</head>
<body>
	<div class="container">
       <table class="col s6">
        	<thead>
        		<th>Cabecera A</th>
        		<th>Cabecera B</th>
        	</thead>
	            <tbody id="pages">
	            <tr class="page">
	            <td value="row" onclick ="eliminarFila($(this))">A1</td>
	            <td value="row" onclick ="eliminarFila($(this))">B1</td>  
	            </tr>                   	            	
	            <tr class="page">
	            <td value="row" onclick ="eliminarFila($(this))">A2</td>
	            <td value="row" onclick ="eliminarFila($(this))">B2</td>  
	            </tr>                 
            </tbody>
        </table>
	</div>

	<ul class="pagination" id="myPager"></ul>


<!--Import jQuery before materialize.js-->
      <script src="https://code.jquery.com/jquery-2.1.1.min.js"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
      <script src="paginacion.js"></script>
      <script src="removerFila.js"></script>


</body>
</html>