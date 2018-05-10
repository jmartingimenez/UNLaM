<!DOCTYPE HTML>
<html>
<head></head>
<body>
	<a href="/">Volver</a><br/>
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
		$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
		// Check if file already exists
		if (file_exists($target_file)) {
		    echo "Sorry, file already exists.";
		    $uploadOk = 0;
		}


		// Check if $uploadOk is set to 0 by an error
		if ($uploadOk == 0) {
		    echo "Sorry, your file was not uploaded.";
		// if everything is ok, try to upload file
		} else {
		    if (move_uploaded_file($_FILES["subir"]["tmp_name"], "archivoSubido.xspf")) {
		        echo "The file ". basename( $_FILES["subir"]["name"]). " has been uploaded.";

				$xml=simplexml_load_file("archivoSubido.xspf") or die("Error: Cannot create object");				
				print("<br/>\nCANCION - URL<br/>\n");
				foreach($xml->trackList->track as $cancion){
					print($cancion->title." - ".$cancion->location."<br/>\n");
				}	



		    } else {
		        echo "Sorry, there was an error uploading your file.";
		    }
		}
	}
?>