/*Creacion de tabla*/
CREATE TABLE empTest1 ( 
empId INT, 
empNombre VARCHAR(1000));

/*Prueba de que no tiene indices*/
SELECT OBJECT_NAME(i.id) AS Tabla,
	i.name AS iName, i.indid AS iId
FROM SYSINDEXES AS i 
WHERE i.indid=0; --Solo trae tablas sin indice

/*Inserts*/
INSERT INTO empTest1 VALUES(4, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(6, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(1, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(3, REPLICATE ('a', 1000));

/*Los datos vuelven en el orden en que fueorn insertados*/
SELECT empID FROM empTest1;

/*Ver que páginas para guardar datos tiene asociada una tabla
(En este caso, 'empTest1')*/
DBCC TRACEON(3604)-- imprimir la salida en la ventana de consulta
GO
DECLARE @DBID Int, @TableID Int
SELECT @DBID = DB_ID(), @TableID = OBJECT_ID('empTest1')
DBCC ind(@DBID, @TableID, -1);

/*Ver los datos, esto comprueba que las filas estan en el orden
insertado, reemplazar 121 por algún numero de página devuelto
por la consulta anterior (columna 'PagePID')*/
DBCC TRACEON (3604)
GO
Declare @DBID Int
Select @DBID = db_id()
DBCC page(@DBID, 1, 121, 3)-- Cambiar el 121, leer arriba
GO

/*Creacion de un índice nonclustered*/
CREATE UNIQUE NONCLUSTERED INDEX empTest1_empId
ON empTest1(empId);

/*Comprobacion del cambio*/
DBCC TRACEON (3604) 
GO
Declare @DBID Int, @TableID Int
Select @DBID = db_id(), @TableID = object_id('empTest1')
DBCC ind(@DBID, @TableID, -1);

DBCC TRACEON (3604)
GO
Declare @DBID Int
Select @DBID = db_id()
DBCC page(@DBID, 1, 165, 3);

/*Mas Inserts*/
INSERT INTO empTest1 VALUES(8, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(7, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(2, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(10, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(5, REPLICATE ('a', 1000));
INSERT INTO empTest1 VALUES(9, REPLICATE ('a', 1000));

/*Añanadiendo un campo y generando un clustered index*/
ALTER TABLE empTest1 ADD EmpIndex Int IDENTITY(1,1);
CREATE UNIQUE CLUSTERED INDEX clust_emp ON empTest1 (EmpIndex);

/*Ver cambio de PagePID, el SELECT ya devuelve ordenado*/
DBCC TRACEON (3604) 
GO
Declare @DBID Int, @TableID Int
Select @DBID = db_id(), @TableID = object_id('empTest1')
DBCC ind(@DBID, @TableID, -1);

/*Creacion de otra tabla con sus inserts*/
CREATE TABLE empTest2 (
    EmpId INT,
    EmpName VARCHAR(1000));

INSERT INTO empTest2 VALUES (4, REPLICATE('a', 10));
INSERT INTO empTest2 VALUES (6, REPLICATE('a', 10));
INSERT INTO empTest2 VALUES (1, REPLICATE('a', 10));
INSERT INTO empTest2 VALUES (3, REPLICATE('a', 10));

/*Observaciones*/
DBCC TRACEON (3604)
GO
Declare @DBID Int, @TableID Int
Select @DBID = db_id(), @TableID = object_id('empTest2')
DBCC ind(@DBID, @TableID, -1);

--El 278 depende del PagePID de la consulta anterior
DBCC TRACEON (3604)
GO
Declare @DBID Int
Select @DBID = db_id()
DBCC page(@DBID, 1, 278, 3);

/*Creacion de un UNIQUE CLUSTERED INDEX
Aca ya saldran ordenados si se ejecuta las 2 consultas de antes*/
CREATE UNIQUE CLUSTERED INDEX empTest2_EmpIndex
ON empTest2 (EmpId);



