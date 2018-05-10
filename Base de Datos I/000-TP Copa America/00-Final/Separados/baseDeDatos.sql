/*Creación de la Base de Datos*/
DROP DATABASE IF EXISTS copaAmerica;
CREATE DATABASE IF NOT EXISTS copaAmerica;
USE copaAmerica;

CREATE TABLE Grupo(
	nombre CHAR(1) PRIMARY KEY
);

CREATE TABLE Equipo(
	cod CHAR(2) PRIMARY KEY,
	nombre VARCHAR(30),
	nombre_grupo CHAR(1),
	FOREIGN KEY (nombre_grupo)
		REFERENCES Grupo (nombre)
);

CREATE TABLE Arbitro(
	nro TINYINT UNSIGNED PRIMARY KEY,
	nombre VARCHAR(30)
);

CREATE TABLE Ronda(
	cod TINYINT UNSIGNED PRIMARY KEY,
	descripcion VARCHAR(25)
);

CREATE TABLE Provincia(
	cod_prov TINYINT UNSIGNED PRIMARY KEY,
	nombre VARCHAR(25)
);

CREATE TABLE Localidad(
	cod_prov TINYINT UNSIGNED,
	cod_loc SMALLINT UNSIGNED,
	nombre VARCHAR(25),
	PRIMARY KEY (cod_prov,cod_loc),
	FOREIGN KEY (cod_prov)
		REFERENCES Provincia (cod_prov)
);

CREATE TABLE Estadio(
	cod TINYINT UNSIGNED PRIMARY KEY,
	nombre VARCHAR(25),
	cod_prov TINYINT UNSIGNED,
	cod_loc SMALLINT UNSIGNED,
	FOREIGN KEY (cod_prov,cod_loc)
		REFERENCES Localidad (cod_prov,cod_loc)
);

CREATE TABLE Posicion(
	cod TINYINT UNSIGNED PRIMARY KEY,
	descripcion VARCHAR(15)
);

CREATE TABLE Tipo_doc(
	cod TINYINT UNSIGNED PRIMARY KEY,
	tipo VARCHAR(10)
);

CREATE TABLE Persona(
	nro_doc INT UNSIGNED,
	tipo_doc TINYINT UNSIGNED,
	nombre VARCHAR(25),
	fecha_debut DATE,
	fecha_nac DATE,
	cod_equipo CHAR(2),
	PRIMARY KEY (nro_doc,tipo_doc),
	FOREIGN KEY (tipo_doc)
		REFERENCES Tipo_doc (cod),
	FOREIGN KEY (cod_equipo)
		REFERENCES Equipo (cod)
);

CREATE TABLE DT(
	nro_doc INT UNSIGNED,
	tipo_doc TINYINT UNSIGNED,
	anios_exp TINYINT UNSIGNED,
	PRIMARY KEY (nro_doc,tipo_doc),
	FOREIGN KEY (nro_doc,tipo_doc)
		REFERENCES Persona (nro_doc,tipo_doc)
);

CREATE TABLE Jugador (
	nro_doc INT UNSIGNED,
	tipo_doc TINYINT UNSIGNED,
	goles_seleccion SMALLINT UNSIGNED,
	cod_posicion TINYINT UNSIGNED,
	PRIMARY KEY (nro_doc,tipo_doc),
	FOREIGN KEY (nro_doc,tipo_doc)
		REFERENCES Persona (nro_doc,tipo_doc),
	FOREIGN KEY (cod_posicion)
		REFERENCES Posicion (cod)
);

CREATE TABLE Partido(
	nro TINYINT UNSIGNED PRIMARY KEY,
	fecha DATE,
	cod_ronda TINYINT UNSIGNED,
	cod_local CHAR(2),
	gol_local TINYINT UNSIGNED,
	cod_visitante CHAR(2),
	gol_visitante TINYINT UNSIGNED,
	cod_estadio TINYINT UNSIGNED,
	FOREIGN KEY (cod_ronda)
		REFERENCES Ronda (cod),
	FOREIGN KEY (cod_local)
		REFERENCES Equipo (cod),
	FOREIGN KEY (cod_visitante)
		REFERENCES Equipo (cod),
	FOREIGN KEY (cod_estadio)
		REFERENCES Estadio (cod)
);

CREATE TABLE Dirige(
	nro_arbitro TINYINT UNSIGNED,
	nro_partido TINYINT UNSIGNED,
	PRIMARY KEY (nro_arbitro,nro_partido),
	FOREIGN KEY (nro_arbitro)
		REFERENCES Arbitro (nro),
	FOREIGN KEY (nro_partido)
		REFERENCES Partido (nro)
);