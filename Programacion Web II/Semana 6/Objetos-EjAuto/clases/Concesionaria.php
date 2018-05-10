<?php
	require_once("Auto.php");

	Class Concesionaria
		{
			//Atributo privado de la clase
			private $miLista;

			//Constructor de la clase
			public function __construct()
				{
					$this->miLista 	=	array();					
				}

			//Esta funcion obtiene los autos desde la bdd, guarda cada fila en un objeto de tipo 'Auto'
			//el cual es guardado en el array de tipo 'Concesionaria'	
			public function obtenerAuto()
				{
					$bdd		=	"Concesionaria";
					$conexion	=	mysqli_connect("localhost","root","",$bdd)
						or die("Fallo la conexi&oacute;n");

					$query		=	"SELECT patente, modelo, color FROM Auto";
					$consulta	=	mysqli_query($conexion,$query)
						or die("Fallo la consulta");

					while($fila=mysqli_fetch_assoc($consulta))
						{
							//Se crea un objeto de tipo 'Auto' y se le dan 3 argumentos para su
							//constructor, esta fila ahora se guardo en un nuevo auto
							$miAuto				=	new Auto($fila['patente'],$fila['modelo'],$fila['color']);

							//Esta posicion del array de la concesionaria guarda el objeto de tipo 'Auto'
							$this->miLista[]	=	$miAuto;
						}	

					mysqli_close($conexion);							
				}

			public function mostrarAuto()
				{
					print("<table>\n");
					print(	"<tr class='titulo'>\n" 		.
								"<th>Patente</th>\n"		.
								"<th>Modelo</th>\n" 		.
								"<th>Color</th>\n"			.
							"</tr>\n");
					foreach($this->miLista as $auto)
						{
							print(	"<tr>\n" 												.
										"<th>" 		. $auto->getPatente() 	. "</th>\n" 	.
										"<th>" 		. $auto->getModelo() 	. "</th>\n" 	.
										"<th>" 		. $auto->getcolor() 	. "</th>\n" 	.
									"</tr>\n"); 												
						}
					print("</table>");	
				}		
		}
?>