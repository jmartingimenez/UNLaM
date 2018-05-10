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
	JOIN Equipo AS EQ ON PE.cod_equipo=EQ.cod
WHERE EQ.nombre='Argentina';

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

-- f.e

SELECT E.nombre
FROM Equipo AS E 
JOIN(
         SELECT cod_local AS pais, gol_local AS goles
         FROM Partido
         UNION ALL
         SELECT cod_visitante,gol_visitante 
         FROM Partido
     ) AS tot ON E.cod=tot.pais
GROUP BY E.cod,E.nombre
HAVING AVG(tot.goles)>2;

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
		FROM Persona AS P
			JOIN Equipo AS E ON P.cod_equipo=E.cod
		WHERE (Jugador.nro_doc=P.nro_doc AND Jugador.tipo_doc=P.tipo_doc)
			AND E.nombre='Ecuador'
			AND P.nombre='Juan Perez'
	);

DELETE FROM Persona
WHERE Persona.nombre='Juan Perez'
	AND EXISTS
		(
			SELECT 1
			FROM Equipo AS E
			WHERE E.nombre='Ecuador'
				AND Persona.cod_equipo=E.cod
		);
