<!DOCTYPE HTML>
<html>
<head>
	<title>Ejemplo de generaci&oacute;n de QR - Gimenez</title>
	
	<?php
		//Libreria para generar QR
		include_once("lib/phpqrcode/qrlib.php");
	?>
</head>
<body>

	<?php
		//Mostrando la imagen random
		print('<img src="img/imagenSimpson.jpg"/>');

		//Donde se guardara el QR
		$tempDir		=	'tempQR/';						

		//Preparando los datos para la tarjeta personal (Mantener las variables en ingles)
		$name			=	'pepe';
		$phone			=	'(011)123-456-789';

		$codeContents = 'BEGIN:VCARD'."\n";
		$codeContents .= 'FN:'.$name."\n";
		$codeContents .= 'TEL;WORK;VOICE:'.$phone."\n";
		$codeContents .= 'END:VCARD';

		//Generando el archivo de imagen que tiene el codigo QR
		QRcode::PNG($codeContents,$tempDir.'ultimoQRGenerado.png',QR_ECLEVEL_H,5);		

		//Mostramos el codigo generado
		print('<img src="'.$tempDir.'ultimoQRGenerado.png"/>');
	?>
</body>
</html>