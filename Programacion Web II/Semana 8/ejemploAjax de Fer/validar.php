<?php
header('Content-type: application/json');
if(isset($_GET['string'])){
	$str = $_GET['string'];
	if(strlen($str) > 3){
		echo "true";
	}
	else{
		echo "false";
	}
}
else{
	echo "false";
}
?>
