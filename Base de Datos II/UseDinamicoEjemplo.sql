--CREAMOS 2 BASES DE DATOS PARA EL EJEMPLO
CREATE DATABASE quickTest
GO

CREATE DATABASE quickTest2
GO

USE quickTest2
GO

--CREAMOS UNA TABLA RANDOM EN LA BDD 'quickTest2'
CREATE TABLE tablaEnLaBDD_quickTest2(id INT)
GO

--AHORA VAMOS A LA BDD 'quickTest' QUE NO TIENE NINGUNA TABLA
USE quickTest
GO

--PROCEDIMIENTO CREADO Y EJECUTADO EN LA BDD 'quickTest'
CREATE PROCEDURE EJEMPLO @BDD_DADA VARCHAR(MAX)
AS
BEGIN
	DECLARE @useBDD VARCHAR(MAX)				--El USE @BDD
	DECLARE @sql NVARCHAR(MAX)					--Tu consulta
	DECLARE @FilasResultantes INT				--Para capturar filas devueltas
	
	SET @useBDD='USE '+@BDD_DADA+'; '
	
	--Esta query devolvera la cantidad de tablas en la bdd pasada por parametro
	SET @sql=@useBDD + 'SELECT @FilasResultantes=COUNT(*) 
						FROM sys.objects 
						WHERE type_desc=''USER_TABLE'''
	
	/*LO MAS UTIL PARA VER SI LA QUERY DINAMICA LA ESTAS ESCRIBIENDO BIEN ES EL PRINT.
	SI LO DESCOMENTAS VAS A PODER VER COMO QUEDO LA CONSULTA QUE SE VA A EJECUTAR.
	SI EL PRINT NO SE MUESTRA AL DESCOMENTARLO, COMENTA EL 'EXECUTE SP_EXECUTESQL'*/
	--PRINT @sql	
	
	EXECUTE SP_EXECUTESQL	@sql,
							N'@FilasResultantes INT OUTPUT',
							@FilasResultantes=@FilasResultantes OUTPUT
	
	SELECT @FilasResultantes AS 'Muestro cantidad de tablas en ''quickTest2'' sin estar en esa BDD'						
END

EXECUTE EJEMPLO 'quickTest2'	--POR PARAMETRO EL NOMBRE DE LA BDD