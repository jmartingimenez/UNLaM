DROP DATABASE IF EXISTS testfutbol;
CREATE DATABASE IF NOT EXISTS testfutbol;
USE testfutbol;

CREATE TABLE equipo(
	cod CHAR(2) NOT NULL,
	nombre VARCHAR(20) NOT NULL,
	PRIMARY KEY (cod)
);

CREATE TABLE partido(
	nro INT UNSIGNED NOT NULL,
	cod_local CHAR(2) NOT NULL,
	gol_local TINYINT UNSIGNED NOT NULL,
	cod_visitante CHAR(2) NOT NULL,
	gol_visitante TINYINT UNSIGNED NOT NULL,
	fecha DATE NOT NULL, -- UNIQUE PARA EVITAR REPETICION
	PRIMARY KEY (nro),
	FOREIGN KEY (cod_local)
		REFERENCES equipo (cod),
	FOREIGN KEY (cod_visitante)
		REFERENCES equipo (cod)
);




-- Ingreso de prueba

INSERT INTO equipo (cod,nombre)
VALUES 	('AR','Argentina'),
		('BR','Brasil'),
		('CL','Chile'),
		('CO','Colombia');

INSERT INTO partido	(nro,cod_local,gol_local,
					cod_visitante,gol_visitante,fecha)
VALUES 	(1,'AR',3,'BR',1,'2016-06-03'),
		(2,'CL',1,'CO',5,'2016-06-03'),
		(3,'AR',2,'CO',0,'2016-06-09'),
		(4,'BR',6,'CL',1,'2016-06-10');

-- Consultas de prueba

/*VER LOS PARTIDOS*/
SELECT * FROM partido;

/*VER TODOS LOS EQUIPOS*/
SELECT * FROM equipo;

/*VER LOS PARTIDOS CON MEJOR FORMATO*/
SELECT 	P.nro AS 'Partido',
		L.nombre AS 'Local',
		gol_local AS 'Goles',
		V.nombre AS 'Visitante',
		gol_visitante AS 'Goles',
		P.fecha AS 'Fecha'
FROM partido AS P
	JOIN equipo AS L ON P.cod_local=L.cod
	JOIN equipo AS V ON P.cod_visitante=V.cod;




