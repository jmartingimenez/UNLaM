<!DOCTYPE HTML>
<html>
<head>
	<title>Ejemplo Ajax</title>
	<meta charset="UTF-8"></meta>
	<script src="lib/jquery/jquery-3.1.0.min.js"></script>
	<script src="js/control.js"></script>
	<link rel="stylesheet" type="text/css" href="css/colorInput.css">
</head>
<body>
	Escriba algo mayor a 3 caracteres:<br/>
	<input type="text" id="cajita" onkeyup="controlTecla(this.value)"></input><br/>
	<div id="letraIngresada"></div>
</body>
</html>
