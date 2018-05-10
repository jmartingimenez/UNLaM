DROP DATABASE ejercicio1;
CREATE DATABASE IF NOT EXISTS ejercicio1;
USE ejercicio1;

CREATE TABLE almacen(
	nro INT UNSIGNED,
	nombre VARCHAR(20),
	responsable VARCHAR(20),
	PRIMARY KEY (nro)
);

CREATE TABLE articulo(
	cod_art INT UNSIGNED,
	descripcion VARCHAR(30),
	precio DECIMAL,
	PRIMARY KEY (cod_art)
);

CREATE TABLE material(
	cod_mat INT UNSIGNED,
	descripcion VARCHAR(30),
	PRIMARY KEY (cod_mat)
);

CREATE TABLE ciudad(
	cod_ciu INT UNSIGNED,
	nombre VARCHAR(20),
	PRIMARY KEY (cod_ciu)
);

CREATE TABLE proveedor(
	cod_prov INT UNSIGNED,
	nombre VARCHAR(20),
	domicilio VARCHAR(20),
	cod_ciu INT UNSIGNED,
	fecha_alta DATE,
	PRIMARY KEY (cod_prov),
	CONSTRAINT codigoCiudad
	FOREIGN KEY (cod_ciu)
		REFERENCES ciudad (cod_ciu)
);

CREATE TABLE contiene(
	nro INT UNSIGNED,
	cod_art INT UNSIGNED,
	PRIMARY KEY (nro,cod_art),
	CONSTRAINT numeroDeAlmacen
	FOREIGN KEY (nro)
		REFERENCES almacen (nro),
	CONSTRAINT codigoDeArticulo
	FOREIGN KEY (cod_art)
		REFERENCES articulo (cod_art)
);

CREATE TABLE compuesto_por(
	cod_art INT UNSIGNED,
	cod_mat INT UNSIGNED,
	PRIMARY KEY (cod_art,cod_mat),
	CONSTRAINT codigoArticulo
	FOREIGN KEY (cod_art)
		REFERENCES articulo (cod_art),
	CONSTRAINT codigoMaterial
	FOREIGN KEY (cod_mat)
		REFERENCES material (cod_mat)
);

CREATE TABLE provisto_por(
	cod_mat INT UNSIGNED,
	cod_prov INT UNSIGNED,
	PRIMARY KEY (cod_mat,cod_prov),
	CONSTRAINT codigoDeMaterial
	FOREIGN KEY (cod_mat)
		REFERENCES material (cod_mat),
	CONSTRAINT codigoDeProveedor
	FOREIGN KEY (cod_prov)
		REFERENCES proveedor (cod_prov)
);