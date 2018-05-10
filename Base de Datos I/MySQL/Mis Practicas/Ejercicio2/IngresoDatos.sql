-- Consulta 1

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'A','F','2000-01-01',1),
		(2,'A','C','2000-01-01',2);

-- Consulta 2

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'C','D','2000-01-01',1),
		(2,'A','D','2000-01-01',2);

INSERT INTO pasajero(nro_vuelo,documento,nombre)
VALUES	(2,35137586,'esteSeVe'),
		(1,11444333,'esteNoSeVe');

-- Consulta 3

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2'),
		(3,'esteSi','M3');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'C','F','2000-01-01',1),
		(2,'A','C','2000-01-01',2),
		(3,'C','E','2000-01-01',1),
		(4,'C','H','2000-01-01',3);

-- Consulta 4

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2'),
		(3,'esteSi','M3');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'B','D','2000-01-01',1),
		(2,'A','C','2000-01-01',2),
		(3,'A','D','2000-02-01',1),
		(4,'C','D','2000-01-01',3);

-- Consulta 5

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2'),
		(3,'esteSi','M3');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'B','D','2000-01-01',2),
		(2,'A','C','2000-01-01',1),
		(3,'A','D','2000-02-01',2),
		(4,'C','D','2000-01-01',3);

-- Consulta 6

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','B-777'),
		(2,'esteNo','M2');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'A','B','2000-01-01',1),
		(2,'C','D','2000-01-02',2),
		(3,'E','F','2000-01-03',1),
		(4,'G','H','2000-01-04',1);

INSERT INTO pasajero(nro_vuelo,documento,nombre)
VALUES	(1,35137586,'esteSeVe'), -- Si entendi bien dara 3
		(1,11444333,'esteNoSeVe'),
		(3,89654221,'quienSabe'),
		(2,77548114,'noVole');

-- Consulta 7

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'tipo1','B-777'), 
		(2,'tipo2','M2'),     
		(3,'tipo3','M3'),    
		(4,'tipo3','M4');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'A','B','2000-01-01',1), 
		(2,'C','D','2000-01-02',2), 
		(3,'A','H','2000-01-03',2), 
		(4,'B','G','2000-01-04',1), 
		(5,'C','G','2000-01-05',2);

INSERT INTO pasajero(nro_vuelo,documento,nombre)
VALUES	(1,35137586,'esteSeVe'), 
		(5,11444333,'esteNoSeVe'),
		(3,89654221,'quienSabe'),
		(2,77548114,'noVole'),
		(1,44682000,'what');




-- Consulta 8

INSERT INTO avion(nro_avion,tipo_avion,modelo_avion)
VALUES 	(1,'esteSeVe','M1'),
		(2,'esteNo','M2'),
		(3,'esteTmbSi','M3');

INSERT INTO vuelo(nro_vuelo,desde,hasta,fecha,nro_avion)
VALUES	(1,'A','F','2000-01-01',1),
		(2,'B','C','2000-02-01',2),
		(3,'A','B','2000-03-01',2),
		(4,'C','H','2000-04-01',3);