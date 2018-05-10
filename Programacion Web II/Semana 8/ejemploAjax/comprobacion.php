<?php
header('Content-type: application/json');			//Se aclara que sera un json. Esto hara que la pagina solo 
if(isset($_GET['string']))							//muestre 1 o 0 segun el caso	
	{
		$ingreso = $_GET['string'];
		if(strlen($ingreso) > 3)
			print("1");
		else print("0");
	}
else print("0");	
?>