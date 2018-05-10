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











