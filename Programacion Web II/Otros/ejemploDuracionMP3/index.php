<!DOCTYPE HTML>
<html>
<head><title>Ejemplo duraci&oacute;n de MP3</title></head>
<body>
	<form enctype="multipart/form-data" method="post">
		<input type="file" name="subir"></input><br/> 
		<input type="submit" name="importar" value="Importar"></input><br/>
	</form>
</body>
</html>

<?php

	if(isset($_POST['importar'])){

		$target_dir = "uploads/";
		$target_file = $target_dir . basename($_FILES["subir"]["name"]);
		$uploadOk = 1;
		$extension = pathinfo($target_file,PATHINFO_EXTENSION);
		$nombreArchivo = "cancion.mp3";

		//Comprobando que el archivo subido sea .xspf
		if($extension!="mp3")
			die("Solo se admiten archivos .mp3");

		// Check if $uploadOk is set to 0 by an error
		if ($uploadOk == 0)    echo "Sorry, your file was not uploaded.";
		// if everything is ok, try to upload file
		else {
		    if (move_uploaded_file($_FILES["subir"]["tmp_name"], $target_dir.$nombreArchivo)){ 
		        $msj = basename( $_FILES["subir"]["name"]);
		        getDuracion($msj,$nombreArchivo);	
		    }	     
		    else 	echo "Sorry, there was an error uploading your file.";
		}
	}

?>

<?php
	function getDuracion($msj,$nombreArchivo){
		echo "The file ". $msj . " has been uploaded.<br/\n>";
		require_once 'class/mp3Class.php';

		$dirArchivo = "uploads/".$nombreArchivo;

		$mp3file = new MP3File($dirArchivo);
		$duration1 = $mp3file->getDurationEstimate();
		$duration2 = $mp3file->getDuration();
		echo "duration: $duration1 seconds"."<br/>\n";
		echo "estimate: $duration2 seconds"."<br/>\n";
		echo MP3File::formatTime($duration2)."<br/>\n";
	}
?>