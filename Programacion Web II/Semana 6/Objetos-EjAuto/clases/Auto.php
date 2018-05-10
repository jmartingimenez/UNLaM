<?php
	Class Auto
		{
			//Atributos privados de la clase
			private $patente;
			private $modelo;
			private $color;

			//Constructor de la clase
			public function __construct($patenteDada,$modeloDado,$colorDado)
				{
					$this->patente 	=	$patenteDada;
					$this->modelo 	=	$modeloDado;
					$this->color 	=	$colorDado;
				}

			//Funciones get
			public function getPatente()
				{
					return $this->patente;
				}	

			public function getModelo()
				{
					return $this->modelo;
				}	

			public function getColor()
				{
					return $this->color;
				}									

			//Insercion del auto a la base de datos
			public function guardarAuto()
				{
					$bdd		=	"Concesionaria";
					$conexion	=	mysqli_connect("localhost","root","",$bdd)
						or die("Fallo la conexi&oacute;n");

					$query		=	"INSERT INTO Auto
									(id,		patente,			modelo,				color) 			
									VALUES
									(DEFAULT,	'$this->patente',	'$this->modelo',	'$this->color')";

					$consulta	=	mysqli_query($conexion,$query)
						or die("Fallo la consulta");	

					mysqli_close($conexion);
					print("Auto registrado.");					
				}		
		}
?>