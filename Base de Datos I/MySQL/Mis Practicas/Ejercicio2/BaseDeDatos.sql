DROP DATABASE IF EXISTS ejercicio2;
CREATE DATABASE IF NOT EXISTS ejercicio2;
USE ejercicio2;

CREATE TABLE avion(
	nro_avion INT UNSIGNED NOT NULL PRIMARY KEY,
	tipo_avion CHAR(10) NOT NULL,
	modelo_avion CHAR(5) NOT NULL
);

CREATE TABLE vuelo(
	nro_vuelo INT UNSIGNED NOT NULL PRIMARY KEY,
	desde CHAR(1) NOT NULL,
	hasta CHAR(1) NOT NULL,
	fecha DATE,
	nro_avion INT UNSIGNED NOT NULL,
	CONSTRAINT avion_fk	FOREIGN KEY (nro_avion)
		REFERENCES avion (nro_avion)
); 

CREATE TABLE pasajero(
	nro_vuelo INT UNSIGNED NOT NULL,
	documento INT(8),
	nombre VARCHAR(20),
	PRIMARY KEY (nro_vuelo,documento),
	CONSTRAINT vuelo_fk FOREIGN KEY (nro_vuelo)
		REFERENCES vuelo (nro_vuelo)
);

