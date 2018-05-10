<!DOCTYPE html>
<html>
<head><title>Extras Reproductor</title></head>
<body>
	<!-- Link para volver al home -->
	<a href="/">Volver</a><br/>

	<!-- Explicacion de lo que captura lo de abajo -->
	<p>Esto captura una URL estilo 'http://127.0.0.1/testParametro/extras.php?id=8'</p>
	
	<!-- Script PHP que captura  la URL y la muestra -->
	<?php
	$url =  "{$_SERVER['HTTP_HOST']}{$_SERVER['REQUEST_URI']}";
	$escaped_url = htmlspecialchars( $url, ENT_QUOTES, 'UTF-8' );	
	print("Link Capturado: ".$escaped_url);
	?>

	<!-- Form con boton para descargar el archivo -->
	<br/><br/>
	<form method="POST">
		<input type="submit" name="descargar" value="Descargar .TXT con URL"></input>
	</form>

	<!-- Script que genera el TXT y lo ofrece para descargar -->
	<?php
		if(isset($_POST['descargar'])){
			$nombreArchivo = "URL capturada.txt";
			$fp = fopen($nombreArchivo, "w");						//Crea el archivo
			fwrite($fp,$escaped_url);								//Se escribe		
			fclose($fp);											//Se cierra
			
			if (file_exists($nombreArchivo)) {
			    header('Content-Description: File Transfer');
			    header('Content-Type: application/octet-stream');
			    header('Content-Disposition: attachment; filename="'.$nombreArchivo.'"');
			    header('Content-Transfer-Encoding: binary');
			    header('Expires: 0');
			    header('Cache-Control: must-revalidate');
			    header('Pragma: public');
			    header('Content-Length: ' . filesize($nombreArchivo));
			    ob_clean();
			    flush();
			    readfile($nombreArchivo);
			    unlink($nombreArchivo);								//Se borra	
			}
		}
	?>
</body>
</html>



