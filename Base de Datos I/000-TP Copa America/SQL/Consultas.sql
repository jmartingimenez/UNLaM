/* Punto f.a
Listar los partidos del 10/06/2016, indicando el nombre de los equipos
participantes y el estadio.
*/

SELECT 	EQL.nombre AS 'Local',
		EQV.nombre AS 'Visitante',
		ES.nombre AS 'Estadio'
FROM Partido AS PA
	JOIN Estadio AS ES ON PA.cod_estadio=ES.cod
	JOIN Equipo AS EQL ON PA.cod_local=EQL.cod
	JOIN Equipo AS EQV ON PA.cod_visitante=EQV.cod
WHERE PA.fecha='2016-06-10';

/* Punto f.b
Mostrar los jugadores de la selección Argentina, indicando su nombre,
fecha debut y posición que desempeña.
*/

SELECT 	PE.nombre AS 'Nombre',
		PE.fecha_debut AS 'Debut',
		PO.descripcion AS 'Posicion'
FROM Persona AS PE
	JOIN Jugador AS JU ON PE.nro_doc=JU.nro_doc
		AND PE.tipo_doc=JU.tipo_doc
	JOIN Posicion AS PO ON JU.cod_posicion=PO.cod
WHERE PE.cod_equipo='AR';

/* Punto f.c
Indicar fecha, estadio, localidad, provincia y ronda, de todos
los partidos que haya ganado el seleccionado de Brasil.
*/

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

/* Punto f.d
Cargar al jugador nro. 10, Lionel Messi, nacido el 24/06/1987,
quien debutó en 17/08/2005 y lleva 50 goles como Delantero
en la selección Argentina.
*/

INSERT INTO Persona (nro_doc,tipo_doc,nombre,fecha_debut,fecha_nac,
					cod_equipo)
VALUES 	(101010,1,'Lionel Messi','2005-08-17','1987-06-24','AR');

INSERT INTO Jugador(nro_doc,tipo_doc,goles_seleccion,cod_posicion)
VALUES (101010,1,50,2);

/* Punto f.e
Listar el nombre de todos los equipos que tengan un promedio de goles
mayor a 2.
*/

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

/* Punto f.f
Por problemas de infraestructura, los partidos disputados en el estadio
Orlando Citrus Bowl en el mes de junio de 2016, deberán moverse al
estadio Soldier Field.
*/

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

/* Punto f.g
Listar el nombre de árbitros que dirigieron todos los partidos disputados en
el estadio Lincoln Financial Field.
*/

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

/* Punto f.h
Mostrar el nombre de los equipos que no hayan jugado en estadios de la
localidad de Seattle.
*/

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

/* Punto f.i
Por una lesión de último momento, es necesario eliminar al jugador de
nombre ‘Juan Pérez’ que juega en la selección de Ecuador.
*/

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

