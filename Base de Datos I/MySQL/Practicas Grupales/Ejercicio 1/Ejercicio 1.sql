DROP DATABASE ejercicio;
CREATE DATABASE if not exists ejercicio;

USE ejercicio;

CREATE TABLE almacen (
	nro INT,
	nombre CHAR(20),
	responsable CHAR(20),
	PRIMARY KEY (nro)
);

CREATE TABLE articulo (
	cod_art INT,
	descripcion VARCHAR(20),
	precio DECIMAL,
	PRIMARY KEY (cod_art)
);

CREATE TABLE material (
	cod_mat INT,
	descripcion VARCHAR(20),
	PRIMARY KEY (cod_mat)
);

CREATE TABLE ciudad (
	cod_ciu INT,
	nombre CHAR(20),
	PRIMARY KEY (cod_ciu)
);


CREATE TABLE proveedor (
	cod_prov INT,
	nombre CHAR(20),
	domicilio CHAR (30),
	cod_ciu INT,
	fecha_alta DATE,
	PRIMARY KEY (cod_prov),
	FOREIGN KEY (cod_ciu) REFERENCES ciudad (cod_ciu)
);


CREATE TABLE contiene (
	nro INT,
	cod_art INT,
	PRIMARY KEY (nro, cod_art),
	FOREIGN KEY (nro) REFERENCES almacen (nro),
	FOREIGN KEY (cod_art) REFERENCES articulo (cod_art)
);

CREATE TABLE compuesto_por (
	cod_art INT,
	cod_mat INT,
	PRIMARY KEY (cod_art, cod_mat),
	FOREIGN KEY (cod_art) REFERENCES articulo (cod_art),
	FOREIGN KEY (cod_mat) REFERENCES material (cod_mat)
);

CREATE TABLE provisto_por (
	cod_mat INT,
	cod_prov INT,
	PRIMARY KEY (cod_mat, cod_prov),
	FOREIGN KEY (cod_mat) REFERENCES material (cod_mat),
	FOREIGN KEY (cod_prov) REFERENCES proveedor (cod_prov)
);

-- **************************************

INSERT INTO almacen (nro, nombre, responsable)
	VALUES (21,'juan', 'martin gomez'),
		(45, 'juan', 'juan carlos'),
		(10, 'jose', 'axel'),
		(20, 'josefa', 'pepita');

INSERT INTO articulo (cod_art, descripcion, precio)
	VALUES (1,'A', 50),
		(2, 'A esto lo compran', 200),
		(3,'Ponele', 400);

INSERT INTO material (cod_mat, descripcion)
	VALUES (1, 'muy caro'),
		(2, 'muy barato'),
		(18, 'buen precio');

INSERT INTO ciudad (cod_ciu, nombre)
	VALUE (1708, 'rosario'),
		(2346, 'la plata'),
		(1757, 'laferrere');

INSERT INTO proveedor (cod_prov, nombre, domicilio, cod_ciu, fecha_alta)
	VALUES (64, 'mariano', 'suipacha', 1708, '2002-04-12'),
		(23, 'jorge', 'rivadavia', 2346, '2014-03-25'),
		(36, 'marcos', 'suipacha', 1757, '1999-06-06');

INSERT INTO contiene (nro, cod_art)
	VALUES (21, 1),
		(45, 3),
		(10, 2);

INSERT INTO provisto_por (cod_mat, cod_prov)
	VALUES (1,64),
		(18, 36);

INSERT INTO compuesto_por (cod_art, cod_mat)
	VALUES (1, 1),
		(3, 18);

		