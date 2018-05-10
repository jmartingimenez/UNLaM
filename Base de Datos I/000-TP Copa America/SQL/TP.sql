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
/*Carga de datos para las consultas*/
INSERT INTO Grupo (nombre)
VALUES ('A'),('B'),('C'),('D');

INSERT INTO Equipo (cod,nombre,nombre_grupo)
VALUES 	('US','Estados Unidos','A'),
		('CO','Colombia','A'),
		('CR','Costa Rica','A'),
		('PR','Paraguay','A'),
		('PE','Peru','B'),
		('EC','Ecuador','B'),
		('BR','Brasil','B'),
		('HA','Haiti','B'),
		('MX','Mexico','C'),
		('VE','Venezuela','C'),
		('UR','Uruguay','C'),
		('JA','Jamaica','C'),
		('AR','Argentina','D'),
		('CL','Chile','D'),
		('PA','Panama','D'),
		('BO','Bolivia','D');

INSERT INTO Ronda (cod,descripcion)
VALUES (1,'Primera Fase');

INSERT INTO Provincia (cod_prov,nombre)
VALUES (1,'Orlando');

INSERT INTO Localidad (cod_prov,cod_loc,nombre)
VALUES 	(1,1,'Laferrere'),
		(1,2,'Seattle'),
		(1,3,'Miami');

INSERT INTO Estadio (cod,nombre,cod_prov,cod_loc)
VALUES 	(1,'Orlando Citrus Bowl',1,1),
		(2,'Lincoln Financial Field',1,2),
		(3,'Soldier Field',1,3);

INSERT INTO Partido (nro,fecha,cod_ronda,cod_local,
					gol_local,cod_visitante,gol_visitante,cod_estadio)
VALUES	(1,'2016-06-10',1,'AR',2,'CL',1,1),
		(2,'2016-06-11',1,'US',0,'CO',2,1),
		(3,'2016-06-12',1,'BR',7,'HA',1,2),
		(4,'2016-06-13',1,'MX',1,'VE',1,2),
		(5,'2016-07-14',1,'PA',0,'AR',2,3),
		(6,'2016-07-15',1,'PE',0,'BR',8,3),
		(7,'2016-07-16',1,'CO',1,'PR',0,2),
		(8,'2016-08-10',1,'AR',1,'VE',0,2),
		(9,'2016-08-11',1,'BR',1,'AR',1,3),
		(10,'2016-08-12',1,'MX',0,'CR',0,1);

INSERT INTO Posicion (cod,descripcion)
VALUES 	(1,'Arquero'),
		(2,'Delantero');

INSERT INTO Tipo_doc (cod,tipo)
VALUES	(1,'DNI'),
		(2,'Cedula');

INSERT INTO Persona (nro_doc,tipo_doc,nombre,fecha_debut,fecha_nac,
					cod_equipo)
VALUES 	(123,1,'sinNombre','2005-09-02','1985-11-29','AR'),
		(123,2,'conNombre','2010-02-14','1990-06-14','PA'),
		(666,1,'Juan Perez','2000-08-17','1977-06-24','EC');

INSERT INTO Jugador (nro_doc,tipo_doc,goles_seleccion,cod_posicion)
VALUES 	(123,1,67,1),
		(123,2,4,2),
		(666,1,12,2);

INSERT INTO Arbitro (nro,nombre)
VALUES	(1,'Horacio Elizondo'),
		(2,'Javier Castrilli');

INSERT INTO Dirige (nro_arbitro,nro_partido)
VALUES	(2,4),
		(1,3),
		(1,4),
		(1,7),
		(1,8);
/*Consultas*/
-- f.a
SELECT 	EQL.nombre AS 'Local',
		EQV.nombre AS 'Visitante',
		ES.nombre AS 'Estadio'
FROM Partido AS PA
	JOIN Estadio AS ES ON PA.cod_estadio=ES.cod
	JOIN Equipo AS EQL ON PA.cod_local=EQL.cod
	JOIN Equipo AS EQV ON PA.cod_visitante=EQV.cod
WHERE PA.fecha='2016-06-10';

-- f.b
SELECT 	PE.nombre AS 'Nombre',
		PE.fecha_debut AS 'Debut',
		PO.descripcion AS 'Posicion'
FROM Persona AS PE
	JOIN Jugador AS JU ON PE.nro_doc=JU.nro_doc
		AND PE.tipo_doc=JU.tipo_doc
	JOIN Posicion AS PO ON JU.cod_posicion=PO.cod
WHERE PE.cod_equipo='AR';

-- f.c
SELECT	PA.fecha AS 'Fecha',ES.nombre AS 'Estadio',
		LO.nombre AS 'Localidad',PR.nombre AS 'Provincia',
		RO.descripcion AS 'Ronda'
FROM Partido AS PA
	JOIN Ronda AS RO ON PA.cod_ronda=RO.cod
	JOIN Estadio AS ES ON PA.cod_estadio=ES.cod
	JOIN Localidad AS LO ON ES.cod_loc=LO.cod_loc
	JOIN Provincia AS PR ON LO.cod_prov=PR.cod_prov
WHERE(PA.cod_local='BR' AND PA.gol_local>PA.gol_visitante)
	OR(PA.cod_visitante='BR' AND PA.gol_visitante>PA.gol_local);

-- f.d
INSERT INTO Persona (nro_doc,tipo_doc,nombre,fecha_debut,fecha_nac,
					cod_equipo)
VALUES 	(101010,1,'Lionel Messi','2005-08-17','1987-06-24','AR');

INSERT INTO Jugador(nro_doc,tipo_doc,goles_seleccion,cod_posicion)
VALUES (101010,1,50,2);

-- f.f
UPDATE Partido
SET cod_estadio=
	(
		SELECT ESN.cod
		FROM Estadio AS ESN
		WHERE ESN.nombre='Soldier Field'
	)
WHERE cod_estadio=
	(
		SELECT ESV.cod
		FROM Estadio AS ESV
		WHERE ESV.nombre='Orlando Citrus Bowl'
	)
	AND (fecha >= '2016-06-01' AND fecha < '2016-07-01');

-- f.g
SELECT AR.nombre
FROM Arbitro AS AR
WHERE NOT EXISTS
	(
		SELECT 1
		FROM Partido AS PA
			JOIN Estadio AS ES ON PA.cod_estadio=ES.cod
		WHERE ES.nombre='Lincoln Financial Field'
			AND NOT EXISTS
				(
					SELECT 1
					FROM Dirige AS DI
					WHERE DI.nro_arbitro=AR.nro
						AND DI.nro_partido=PA.nro
				)
	);

-- f.h
SELECT EQ.nombre
FROM Equipo AS EQ
WHERE NOT EXISTS
	(
		SELECT 1
		FROM Partido AS PA
			JOIN Estadio AS ES ON PA.cod_estadio=ES.cod
			JOIN Localidad AS LO ON ES.cod_loc=LO.cod_loc
		WHERE LO.nombre='Seattle'
			AND (EQ.cod=PA.cod_local
			OR EQ.cod=PA.cod_visitante)
	);

-- f.i
DELETE FROM Jugador
WHERE EXISTS
	(
		SELECT 1
		FROM Persona
		WHERE Jugador.nro_doc=Persona.nro_doc
			AND Jugador.tipo_doc=Persona.tipo_doc
			AND cod_equipo='EC'
			AND nombre='Juan Perez'
	);












