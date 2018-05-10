-- Prueba parcial viejo
DROP DATABASE IF EXISTS batman;
CREATE DATABASE IF NOT EXISTS batman;
USE batman;

CREATE TABLE Cientifico(
		dni VARCHAR(8) PRIMARY KEY,
		nombre VARCHAR(255)
);

CREATE TABLE Proyecto(
	id VARCHAR(4) PRIMARY KEY,
	nombre VARCHAR(255)
);

CREATE TABLE Asignado_A(
	cientifico VARCHAR(8),
	proyecto VARCHAR(4),
	horas INT,
	PRIMARY KEY (cientifico,proyecto),
	FOREIGN KEY (cientifico)
		REFERENCES Cientifico (dni),
	FOREIGN KEY (proyecto)
		REFERENCES Proyecto (id)
);

INSERT INTO Cientifico (dni,nombre)
VALUES	('123','c1'),
		('456','c2'),
		('789','c3');

INSERT INTO Proyecto (id,nombre)
VALUES	('1','p1'),
		('2','p2');

INSERT INTO Asignado_A (cientifico,proyecto,horas)
VALUES	('123','1',160),
		('123','2',2),
		('456','1',170),
		('789','2',39);


-- 1
SELECT C.dni,C.nombre,P.id,P.nombre
FROM Cientifico C
	JOIN Asignado_A A ON C.dni=A.cientifico
	JOIN Proyecto P ON A.proyecto=P.id;

-- 2
SELECT C.dni,C.nombre,COUNT(*) AS 'cant proyectos'
FROM Cientifico C
	JOIN Asignado_A A ON C.dni=A.cientifico
GROUP BY C.dni,C.nombre;

-- 3
SELECT P.id,P.nombre,COUNT(*) AS 'cant cientificos'
FROM Proyecto P
	JOIN Asignado_A A ON P.id=A.proyecto
GROUP BY P.id,P.nombre;

-- 4
SELECT A.cientifico,SUM(A.horas)
FROM Asignado_A A
GROUP BY A.cientifico;

-- 5
/*
Obtener DNI y nombre de los cientificos que se dedican  más de un
proyecto y cuya dedicación media a los proyectos sea superior
a las 80 horas
*/

SELECT C.dni,C.nombre
FROM Cientifico C
WHERE C.dni IN
	(
		SELECT A.cientifico
		FROM Asignado_A A
		HAVING (COUNT(*)>1 AND AVG(A.horas)>80)
	);
