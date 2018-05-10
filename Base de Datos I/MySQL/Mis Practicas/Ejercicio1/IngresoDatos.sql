-- *****************CONSULTA 9
INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (6,'Ricardo Fort','Suipacha 444',6,'2001-11-23');

INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (7,'La Cuca','Calle Falsa 123',7,'2001-10-03');

INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (8,'La Coca','Calle Falsa 13',3,'2001-12-03');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (9,'Vendo Faso','ABC 125',1,'1997-03-18');

INSERT INTO provisto_por(cod_mat,cod_prov)
VALUES (2,7);

INSERT INTO provisto_por(cod_mat,cod_prov)
VALUES (3,9);

INSERT INTO material (cod_mat,descripcion)
VALUES (1,'Esto deberia verse'),
		(2,'Esto no'),
		(3,'Esto si'),
		(4,'Por supesto que no'),
		(18,'Obvio que si');

INSERT INTO contiene(nro,cod_art)
VALUES 	(28,7),
		(14,3);

-- 

INSERT INTO ciudad(cod_ciu,nombre)
VALUES (1,'Laferrere');

INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (6,'Ricardo Fort','Suipacha 444',1,'2001-11-23');

INSERT INTO material (cod_mat,descripcion)
VALUES (5,'Pasta Base');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES (5,6);

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES (4,'Pegamento',10);

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES (4,5);

INSERT INTO almacen (nro,nombre,responsable)
VALUES (45,'El BriaAn','Martin Gomez');

INSERT INTO contiene (nro,cod_art)
VALUES (45,4);


-- *****************Consulta 12

INSERT INTO ciudad(cod_ciu,nombre)
VALUES (1,'Tokyo');

INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (6,'Ricardo Fort','Suipacha 444',1,'2001-11-23');

INSERT INTO proveedor(cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES (7,'Fernando','ketimporta 12',1,'2001-10-23');

-- ****************Consulta 13

INSERT INTO almacen (nro,nombre,responsable)
VALUES	(1,'Hatake Kakashi','Minato Namikaze'),
		(2,'Uchina Sasuke','Orochimaru'),
		(3,'Rock Lee','Maito Gai');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'Kunai',200),
		(2,'Bomba de humo',35),
		(3,'Shuriken',100),
		(4,'Libro de Jiraiya',65);

INSERT INTO contiene (nro,cod_art)
VALUES 	(1,1),
		(2,2),
		(1,3),
		(3,4);

INSERT INTO contiene (nro,cod_art)
VALUES (2,4);

-- **********************Consulta 14

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'PrimerArt',50),
		(2,'SegundoArt',60),
		(3,'TercerArt',70);

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES 	(1,1),
		(1,2),
		(2,3),
		(3,1);

-- ***********************Consulta 15

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO ciudad (cod_ciu,nombre)
VALUES (1,'Laferrere');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',1,'2000-01-01'),
		(3,'P-Chan','Casa de Ranma 55',1,'2000-01-01');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,2),
		(2,3),
		(3,2);

-- ***********************Consulta 16

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Laferrere'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',2,'2000-01-01'),
		(3,'P-Chan','Casa de Ranma 55',2,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,1),
		(2,3),
		(3,2);

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'Papel',20),
		(2,'Lavarropa',50),
		(3,'Television',100),
		(4,'Mesa',180),
		(5,'Ventilador',60);

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES 	(1,1),
		(4,2),
		(2,2);

-- ***********************Consulta 17

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Laferrere'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',2,'2000-01-01'),
		(3,'P-Chan','Casa de Ranma 55',2,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,1),
		(2,2),
		(3,2);

-- ***********************Consulta 18

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Laferrere'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(10,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(15,'Cell','paqquieressabereso 12',2,'2000-01-01'),
		(3,'P-Chan','Casa de Ranma 55',2,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,10),
		(2,10),
		(3,10),
		(1,15);

-- ***********************Consulta 19

INSERT INTO almacen (nro,nombre,responsable)
VALUES 	(1,'name1','res1'),
		(2,'name2','res2'),
		(3,'name3','res3'),
		(4,'name4','res4');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'Papel',20),
		(2,'A',50),
		(3,'Television',100),
		(4,'B',180);

INSERT INTO contiene (nro,cod_art)
VALUES 	(1,2),
		(2,2),
		(2,4),
		(3,4),
		(4,3);

-- ***********************Consulta 20

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Piedra'),
		(2,'Madera'),
		(3,'Carton');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'esteSeVe',200),
		(2,'esteNoSeVe',444);

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES 	(2,1),
		(2,2),
		(1,1),
		(1,2),
		(1,3);

-- ***********************Consulta 21

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Laferrere'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',2,'2000-01-01'),
		(3,'noDeberiaAparecer','noMeVeas',2,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'Papel',120),
		(2,'A',50);

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES 	(1,1),
		(2,2);

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,1),
		(2,2),
		(3,1);

-- ***********************Consulta 22

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'esteNoSeVe',200),
		(2,'esteSeVe',444);

-- ***********************Consulta 23

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Capital Federal'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',1,'2000-01-01'),
		(3,'noDeberiaAparecer','noMeVeas',2,'2000-01-01'),
		(4,'noProveoUnCarajo','toldYou',1,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,1),
		(1,3),
		(3,2);			-- Este prov se tiene que ver
			

-- ***********************Consulta 24

INSERT INTO almacen (nro,nombre,responsable)
VALUES	(1,'esteNoSeVe','kheNo'),
		(2,'esteSiSeVe','kheSi'),
		(3,'noSalgo','Tampoco'),
		(4,'noVendoNada','deNada');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'articuloCaro',2000),
		(2,'articuloBarato',444);

INSERT INTO contiene (nro,cod_art) -- es el alm 2 el q mas tiene
VALUES 	(1,1),
		(2,1),
		(3,1),
		(2,2);

-- ***********************Consulta 25

INSERT INTO ciudad (cod_ciu,nombre)
VALUES 	(1,'Laferrere'),
		(2,'Zarate');

INSERT INTO proveedor (cod_prov,nombre,domicilio,cod_ciu,fecha_alta)
VALUES 	(1,'Hitler','Calle Falsa 123',1,'2000-01-01'),
		(2,'Cell','paqquieressabereso 12',2,'2000-01-01'),
		(3,'noDeberiaAparecer','noMeVeas',2,'2000-01-01'),
		(4,'ahoraSiSalgo','toldYou',1,'2000-01-01');

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(2,'Lana'),
		(3,'Madera');

INSERT INTO provisto_por (cod_mat,cod_prov)
VALUES 	(1,2),
		(2,2),
		(3,2),
		(3,4);

-- ***********************Consulta 26

INSERT INTO almacen (nro,nombre,responsable)
VALUES	(1,'esteNoSeVe','kheNo'),
		(2,'esteSiSeVe','kheSi'),
		(3,'mePaQueNo','Tampoco'),
		(4,'NoSalgo','deNada');

INSERT INTO articulo (cod_art,descripcion,precio)
VALUES 	(1,'articuloCaro',2000),
		(2,'articuloBarato',444),
		(3,'otroQueSirve',100),
		(4,'justForTest',60);

INSERT INTO material (cod_mat,descripcion)
VALUES 	(1,'Pasto'),
		(123,'elQuePide');

INSERT INTO compuesto_por (cod_art,cod_mat)
VALUES 	(1,1),
		(2,123),
		(3,123),
		(4,1);

INSERT INTO contiene (nro,cod_art)-- solo el 2 se tiene q ver
VALUES 	(1,1),
		(2,1),
		(2,2),
		(2,3),
		(1,2),
		(1,4);
