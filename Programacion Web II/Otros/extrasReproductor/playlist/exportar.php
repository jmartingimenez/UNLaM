<!DOCTYPE HTML>
<html>
<head></head>
<body>
	<a href="/">Volver</a><br/>
	<form method="post">
		<input type="submit" name="exportar" value="Exportar"></input>
	</form>
</body>
</html>

	<?php
		$nombrePlaylist = "playlistAImportar";
		$array = array
		  (
		  array("Volvo","urlDeVolvo"),
		  array("BMW","urlDeVolvo"),
		  array("Saab","urlDeVolvo"),
		  array("Land Rover","urlDeVolvo")
		  );


		if(isset($_POST['exportar'])){
			$fp=fopen($nombrePlaylist.".xspf","w");

			$headerXSPF = '<?xml version="1.0" encoding="UTF-8"?>'.PHP_EOL.
							'<playlist version="1" xmlns="http://xspf.org/ns/0/">'.PHP_EOL.
								'<trackList>'.PHP_EOL;
			fwrite($fp,$headerXSPF);
			foreach ($array as $track) {
				fwrite($fp,'<track>'.PHP_EOL);
				fwrite($fp, '<title>'. $track[0] .'</title>'.PHP_EOL);
				fwrite($fp, '<location>'. $track[1] .'</location>'.PHP_EOL);
				fwrite($fp,'</track>'.PHP_EOL);
			}
			fwrite($fp,'</trackList>'.PHP_EOL.'</playlist>');	
			fclose($fp);
		}  
	?>

