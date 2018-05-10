-- DROP DATABASE IF EXISTS videoclub;
CREATE DATABASE IF NOT EXISTS videoclub;
USE videoclub;

CREATE TABLE cliente(
			tipo_doc CHAR(4),
			nro_doc INT UNSIGNED,
			nombre VARCHAR(20),
			domicilio VARCHAR(20),
			edad TINYINT UNSIGNED,
			tipo_doc_titular CHAR(4),
			nro_doc_titular INT UNSIGNED,
	PRIMARY KEY (tipo_doc,nro_doc),
	CONSTRAINT extiende_cliente
	FOREIGN KEY (tipo_doc_titular,nro_doc_titular)
		REFERENCES cliente (tipo_doc,nro_doc)
	);
		

CREATE TABLE proveedor(
			cuit INT UNSIGNED,
			nombre VARCHAR(20),
			domicilio VARCHAR(20),
			telefono INT UNSIGNED,
			mail VARCHAR(20),
	PRIMARY KEY (cuit)
	);

CREATE TABLE pelicula(
			cod_pel INT UNSIGNED AUTO_INCREMENT, 
			titulo VARCHAR(20),
			genero VARCHAR(20),
			cuit_proveedor INT UNSIGNED,
		PRIMARY KEY (cod_pel),
		CONSTRAINT provieneDe
		FOREIGN KEY (cuit_proveedor)
			REFERENCES proveedor (cuit)
	);

CREATE TABLE cliente_pelicula(
			tipo_doc CHAR(4),
			nro_doc INT UNSIGNED,
			cod_pel INT UNSIGNED AUTO_INCREMENT,
			fecha DATE,
		PRIMARY KEY (tipo_doc,nro_doc,cod_pel,fecha),
		CONSTRAINT datosCliente
		FOREIGN KEY (tipo_doc,nro_doc)
			REFERENCES cliente (tipo_doc,nro_doc),
		CONSTRAINT datosPelicula
		FOREIGN KEY (cod_pel)
			REFERENCES pelicula (cod_pel)
	);

