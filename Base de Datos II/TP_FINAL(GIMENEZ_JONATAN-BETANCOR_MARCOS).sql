/*================	CREACION DE BDD DONDE ESTARAN LAS TABLAS	================*/
USE MASTER

IF EXISTS(select * from sys.databases where name='TP_FINAL')
	DROP DATABASE TP_FINAL
GO

CREATE DATABASE TP_FINAL
GO	
USE TP_FINAL
GO

/*================	ESQUEMAS PARA TESTEO	================*/

CREATE SCHEMA TP
GO
CREATE SCHEMA Test
GO

/*================	TABLAS PARA TESTEO	================*/
CREATE TABLE Test.sinPKFK(
	campo1 CHAR(1),
	campo2 CHAR(1)
)

CREATE TABLE Test.conPKNOFK(
	pkSimple CHAR(2),
	CONSTRAINT PK_simple PRIMARY KEY (pkSimple)
)

CREATE TABLE Test.conFKNOPK(
	fkSimple CHAR(2),
	CONSTRAINT FK_simple FOREIGN KEY (fkSimple) REFERENCES Test.conPKNOFK (pkSimple)
) 

CREATE TABLE Test.conPKFK(
	pkSimple2 CHAR(2),
	fkSimple2 CHAR(2),
	CONSTRAINT PK_simple2 PRIMARY KEY (pkSimple2),
	CONSTRAINT FK_simple2 FOREIGN KEY (fkSimple2) REFERENCES Test.conPKFK (pkSimple2)
)

CREATE TABLE Test.conPKCompuesta(
	pkc1 CHAR(3),
	pkc2 CHAR(3),
	CONSTRAINT PK_Compuesta PRIMARY KEY (pkc1,pkc2)
)

CREATE TABLE Test.conPKFKCompuesta(
	campoA CHAR(3),
	campoB CHAR(3),
	refCampoA CHAR(3),
	refCampoB CHAR(3),
	CONSTRAINT PK_testFKCompuesta PRIMARY KEY (campoA,campoB),
	CONSTRAINT FK_Compuesta FOREIGN KEY (refCampoA,refCampoB) 
		REFERENCES Test.conPKFKCompuesta (campoA,campoB)
) 

INSERT INTO Test.sinPKFK VALUES('a','A'),('b','B'),('c','C')
INSERT INTO Test.conPKNOFK VALUES ('PS')
INSERT INTO Test.conFKNOPK VALUES ('PS')
INSERT INTO Test.conPKFK VALUES('PK','PK')
INSERT INTO Test.conPKCompuesta VALUES ('PKC','PKC')
INSERT INTO Test.conPKFKCompuesta VALUES ('FKC','FKC','FKC','FKC')
GO

/*================	VISTA PARA TESTEO	================*/

CREATE VIEW Test.v_test AS SELECT * FROM Test.sinPKFK
GO

/*================	FUNCIONES PARA TESTEO	================*/

CREATE FUNCTION Test.f_noParam()
RETURNS CHAR(1)
AS
BEGIN
	RETURN 'f1'
END
GO

CREATE FUNCTION Test.f_siParam(@parametroRandom INT)
RETURNS @miTabla TABLE(
	campoRandom1 TINYINT,
	campoRandom2 TINYINT
)
AS
BEGIN
	INSERT INTO @miTabla SELECT 1,2
	RETURN 
END	
GO

/*================	PROCEDIMIENTOS PARA TESTEO	================*/

CREATE PROCEDURE Test.p_sinParametros AS SELECT 1
GO

CREATE PROCEDURE Test.p_conParametros @id CHAR(1) AS SELECT 1
GO

/*================	INDICE PARA TESTEO	================*/

CREATE INDEX idx_campoRandom ON Test.sinPKFK (campo2)
GO

/*================	TRIGGERS PARA TESTEO	================*/

CREATE TRIGGER Test.t_esAfter ON Test.sinPKFK AFTER INSERT
AS
BEGIN
	SELECT 1
END
GO

CREATE TRIGGER Test.t_esInstead ON Test.sinPKFK INSTEAD OF UPDATE
AS
BEGIN
	SELECT 1
END
GO

CREATE TRIGGER t_noEsDML ON DATABASE FOR DROP_TABLE 
AS
BEGIN
	PRINT 'Mensaje Random'
END
GO

CREATE TRIGGER t_otroInstead ON Test.sinPKFK INSTEAD OF DELETE
AS
BEGIN
	SELECT 1
END
GO

/*====================================================================================
********************FIN PARA LAS COSAS DE EJEMPLO, COMIENZO DEL TP*******************
=====================================================================================*/


/*================	DEFINICION DE LAS TABLAS DEL TP	================*/
CREATE TABLE TP.Lista_Objetos(
	Esquema VARCHAR(MAX) NOT NULL,			
	Base VARCHAR(MAX) NOT NULL,
	Objecto VARCHAR(MAX) NOT NULL, 
	Tipo_Objecto VARCHAR(MAX) NOT NULL,
	Parametros CHAR(2),
	Retorno_Funcion VARCHAR(MAX),
	PK CHAR(2),
	PK_Compuesta CHAR(2),
	FK CHAR(2),
	FK_Compuesta CHAR(2),
	Indice CHAR(2),
	Tipo_Trigger CHAR(10)			
) 

CREATE TABLE TP.Auditoria(			
	Esquema VARCHAR(MAX) NOT NULL,			
	Base VARCHAR(MAX) NOT NULL,
	Fecha DATETIME DEFAULT GETDATE() NOT NULL,
	Usuario VARCHAR(MAX) NOT NULL	
)

CREATE TABLE TP.Log_Errores(		
	Id INT IDENTITY(1,1) NOT NULL,
	Descripcion VARCHAR(MAX),				
	Linea_Excepcion INT,					
	Numero_Error INT,						
	Severidad TINYINT,						
	Estado TINYINT,							
	Fecha DATETIME DEFAULT GETDATE(),
	Usuario VARCHAR(MAX)						
)
GO

CREATE PROCEDURE sp_GrabarObjetos @NOMBRE_BDD VARCHAR(MAX), @NOMBRE_ESQUEMA VARCHAR(MAX)
AS
BEGIN
	SET NOCOUNT ON
	BEGIN TRY		
		--SI NO EXISTE LA BDD SE DETIENE TODO ACA Y VA AL CATCH
		IF DB_ID(@NOMBRE_BDD) IS NULL RAISERROR('NO SE ENCUENTRA LA BDD',16,1)			  						  		
		
		--VARIABLE PARA CONSULTAS DINAMICAS
		DECLARE @sqlDinamico NVARCHAR(MAX)
		
		--COMPROBACION DINAMICA PARA VER SI EXISTE UN ESQUEMA 'X' PARA UNA BDD 'Y'		
		SET @sqlDinamico='IF NOT EXISTS(SELECT 1 FROM ' + @NOMBRE_BDD + '.sys.schemas 
										WHERE name='''+ @NOMBRE_ESQUEMA +''')
								RAISERROR(''NO SE ENCUENTRA EL ESQUEMA'',16,1)'		
		EXECUTE SP_EXECUTESQL @sqlDinamico
		
		BEGIN
			BEGIN TRAN
				/*DECLARACION DE VARIABLES PARA LA INSERCION Y DOS AUXILIARES*/
				DECLARE @Objeto VARCHAR(MAX),@Tipo_Objeto VARCHAR(MAX), @Parametros CHAR(2),
						@Retorno_Funcion VARCHAR(MAX), @PK CHAR(2), @PK_Compuesta CHAR(2),
						@FK CHAR(2), @FK_Compuesta CHAR(2), @Indice CHAR(2),@Tipo_Trigger CHAR(10),
						@CANTIDAD INT, @RESULTADO_DINAMICO VARCHAR(MAX)
							
				--CREANDO UNA TABLA TEMPORAL BASADA EN LA TABLA DEL LISTADO DE OBJETOS
				SELECT TOP 0 * INTO #TABLA_CURSOR FROM TP.Lista_Objetos
							
				--DECLARACION DINAMICA PARA EL CURSOR
				SET @sqlDinamico='DECLARE cursorObjetos CURSOR FOR
									(SELECT O.name,O.type
									 FROM ' + @NOMBRE_BDD + '.sys.objects O
									 WHERE EXISTS(
										SELECT 1
										FROM ' + @NOMBRE_BDD + '.sys.schemas S
										WHERE O.schema_id=S.schema_id
											AND S.name='''+ @NOMBRE_ESQUEMA +'''
										)
										AND O.type IN(''U'',''S'',''FN'',''TF'',''IF'',''V'',''P'',''TR'')
									  )'
				EXECUTE SP_EXECUTESQL @sqlDinamico
			COMMIT TRAN
			BEGIN TRAN
				DECLARE @CURSOR_NOMBRE_ACTUAL VARCHAR(MAX), @CURSOR_TIPO_ACTUAL CHAR(2)	
				OPEN cursorObjetos			
				FETCH NEXT FROM cursorObjetos INTO @CURSOR_NOMBRE_ACTUAL,@CURSOR_TIPO_ACTUAL
				WHILE @@FETCH_STATUS=0
					BEGIN	
						SET @Objeto='' SET @Tipo_Objeto='' SET @Parametros='' SET @Retorno_Funcion=''
						SET @PK='' SET @PK_Compuesta='' SET @FK='' SET @FK_Compuesta='' SET @Indice=''
						SET @Tipo_Trigger=''				
				
						SET @Objeto=@CURSOR_NOMBRE_ACTUAL
						IF(@CURSOR_TIPO_ACTUAL='U' OR @CURSOR_TIPO_ACTUAL='S')		
							BEGIN
								IF(@CURSOR_TIPO_ACTUAL='U') SET @Tipo_Objeto='TABLA'
								ELSE SET @Tipo_Objeto='TABLA DEL SISTEMA'
														
								--TIENE PK?
								SET @sqlDinamico='SELECT @CANT=COUNT(*)
												  FROM ' + @NOMBRE_BDD +'.INFORMATION_SCHEMA.TABLE_CONSTRAINTS
												  WHERE CONSTRAINT_TYPE=''PRIMARY KEY''
													AND TABLE_NAME='''+@CURSOR_NOMBRE_ACTUAL+''''
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
								IF(@CANTIDAD=0) 
									BEGIN
										SET @PK='NO'
										SET @PK_Compuesta='NO'
									END							
								ELSE
								BEGIN
									SET @PK='SI'
									--TIENE PK COMPUESTA?	
									SET @sqlDinamico='SELECT @CANT=COUNT(*)
													  FROM '+@NOMBRE_BDD+'.INFORMATION_SCHEMA.TABLE_CONSTRAINTS T
														JOIN '+@NOMBRE_BDD+'.INFORMATION_SCHEMA.CONSTRAINT_COLUMN_USAGE C
														ON C.CONSTRAINT_NAME=T.CONSTRAINT_NAME
															AND C.TABLE_NAME=T.TABLE_NAME
															AND T.CONSTRAINT_TYPE=''PRIMARY KEY''
													  WHERE C.TABLE_NAME='''+@CURSOR_NOMBRE_ACTUAL+'''
													  GROUP BY C.TABLE_NAME
													  HAVING COUNT(*)>1'
									EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
									IF(@CANTIDAD<=1) SET @PK_Compuesta='NO'
									ELSE SET @PK_Compuesta='SI'														
								END
														
								--TIENE FK?
								SET @sqlDinamico='SELECT @CANT=COUNT(*)
												  FROM ' + @NOMBRE_BDD +'.INFORMATION_SCHEMA.TABLE_CONSTRAINTS
												  WHERE CONSTRAINT_TYPE=''FOREIGN KEY''
													AND TABLE_NAME='''+@CURSOR_NOMBRE_ACTUAL+''''
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
								IF(@CANTIDAD=0) 
								BEGIN
									SET @FK='NO'
									SET @FK_Compuesta='NO'
								END							
								ELSE
								BEGIN
									SET @FK='SI'
									--TIENE FK COMPUESTA?	
									SET @sqlDinamico='SELECT @CANT=COUNT(*)
													  FROM '+@NOMBRE_BDD+'.INFORMATION_SCHEMA.TABLE_CONSTRAINTS T
														JOIN '+@NOMBRE_BDD+'.INFORMATION_SCHEMA.CONSTRAINT_COLUMN_USAGE C
														ON C.CONSTRAINT_NAME=T.CONSTRAINT_NAME
															AND C.TABLE_NAME=T.TABLE_NAME
															AND T.CONSTRAINT_TYPE=''FOREIGN KEY''
													  WHERE C.TABLE_NAME='''+@CURSOR_NOMBRE_ACTUAL+'''
													  GROUP BY C.TABLE_NAME
													  HAVING COUNT(*)>1'
									EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
									IF(@CANTIDAD<=1) SET @FK_Compuesta='NO'
									ELSE SET @FK_Compuesta='SI'									
								END 
														
								--TIENE INDICE?						
								SET @sqlDinamico='SELECT @CANT=COUNT(*)
												  FROM '+ @NOMBRE_BDD + '.sys.indexes
												  WHERE object_id=OBJECT_ID('''+@NOMBRE_ESQUEMA+'.'+@CURSOR_NOMBRE_ACTUAL+''')
													AND name IS NOT NULL
													AND is_primary_key=''false''
													AND is_unique=''false'''
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
								IF(@CANTIDAD=0) SET @Indice='NO'
								ELSE SET @Indice='SI'							 
							END
						ELSE IF(@CURSOR_TIPO_ACTUAL='FN' OR @CURSOR_TIPO_ACTUAL='TF' OR @CURSOR_TIPO_ACTUAL='IF')	
							BEGIN
								SET @Tipo_Objeto='FUNCION'
														
								-- QUE RETORNA?
								SET @sqlDinamico='SELECT @SEL=DATA_TYPE
												  FROM ' + @NOMBRE_BDD +'.INFORMATION_SCHEMA.ROUTINES
												  WHERE ROUTINE_TYPE=''FUNCTION'' 
													AND SPECIFIC_NAME=''' + @CURSOR_NOMBRE_ACTUAL +''''
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@SEL VARCHAR(MAX) OUTPUT',@SEL=@RESULTADO_DINAMICO OUTPUT							
								SET @Retorno_Funcion=UPPER(@RESULTADO_DINAMICO)						
							END
						ELSE IF(@CURSOR_TIPO_ACTUAL='V')		
							BEGIN
								SET @Tipo_Objeto='VISTA'
							END
						ELSE IF(@CURSOR_TIPO_ACTUAL='P')		
							BEGIN
								SET @Tipo_Objeto='PROCEDIMIENTO'						
							END
						ELSE IF(@CURSOR_TIPO_ACTUAL='TR')	
							BEGIN
								SET @Tipo_Objeto='TRIGGER'
							
								--ES AFTER O INSTEAD OF?
								SET @sqlDinamico='SELECT @CANT=COUNT(*)
												  FROM ' + @NOMBRE_BDD +'.sys.triggers 
												  WHERE name=''' + @CURSOR_NOMBRE_ACTUAL +'''
													AND is_instead_of_trigger=1'								
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
								IF(@CANTIDAD=0) SET @Tipo_Trigger='AFTER'
								ELSE SET @Tipo_Trigger='INSTEAD OF'
							END
					
						/*PONGO ESTE IF PARA AHORRAR LINEAS, LA CONSULTA ES LA MISMA
						EN AMBOS CASOS*/
						IF(@Tipo_Objeto='FUNCION' OR @Tipo_Objeto='PROCEDIMIENTO')
							BEGIN
								--TIENE PARAMETROS?
								SET @sqlDinamico='SELECT @CANT=COUNT(*)
												  FROM ' + @NOMBRE_BDD +'.sys.objects
												  WHERE name='''+ @CURSOR_NOMBRE_ACTUAL +'''
													AND object_id IN(
														SELECT object_id
														FROM sys.parameters
														WHERE name <> ''''
													)'
								EXECUTE SP_EXECUTESQL @sqlDinamico,N'@CANT INT OUTPUT',@CANT=@CANTIDAD OUTPUT
								IF(@CANTIDAD=0) SET @Parametros='NO'
								ELSE SET @Parametros='SI'						
							END	
						FETCH NEXT FROM cursorObjetos INTO @CURSOR_NOMBRE_ACTUAL,@CURSOR_TIPO_ACTUAL					

						INSERT INTO #TABLA_CURSOR VALUES(@NOMBRE_ESQUEMA,@NOMBRE_BDD,@Objeto,
														@Tipo_Objeto,@Parametros,@Retorno_Funcion,
														@PK,@PK_Compuesta,@FK,@FK_Compuesta,
														@Indice,@Tipo_Trigger)					
					END			
				CLOSE cursorObjetos
							
				DEALLOCATE cursorObjetos
			

				BEGIN			
					BEGIN TRAN
						INSERT INTO TP.Lista_Objetos SELECT * FROM #TABLA_CURSOR
					COMMIT TRAN
				END
				
				DROP TABLE #TABLA_CURSOR
				
			COMMIT TRAN
		END	

		-- TRATAMIENTO ERRORES EN TRANSACCIONES, SI ES MAYOR QUE CERO ES PORQUE UNA O MAS TRANSACCIONES NO SE EJECUTARON CORRECTAMENTE
		IF(@@TRANCOUNT > 0)
		BEGIN
			-- HACEMOS ROLLBACK DE TODAS LAS TRANSACCIONES ANTERIORES
			ROLLBACK TRAN

			DECLARE @ErrorMessage NVARCHAR(4000);
			DECLARE @ErrorSeverity INT;
			DECLARE @ErrorState INT;

			
		SELECT 
			@ErrorMessage = ERROR_MESSAGE(),
			@ErrorSeverity = ERROR_SEVERITY(),
			@ErrorState = ERROR_STATE();

			RAISERROR (@ErrorMessage, -- Message text.
				   16, -- Severity.
				   @ErrorState -- State.
				  );
		END		
	END TRY
	BEGIN CATCH
		--SI SE VIENE AL CATCH ANTES DE DROPEAR LA TABLA TEMPORAL...
		IF EXISTS(SELECT name FROM tempdb.sys.objects WHERE name LIKE '#TABLA_CURSOR%')
			DROP TABLE #TABLA_CURSOR 
					
		--SI SE VIENE AL CATCH ANTES DE LIBERAR LA MEMORIA DEL CURSOR
		IF((SELECT CURSOR_STATUS('global','cursorObjetos'))>=-1) DEALLOCATE cursorObjetos

		DECLARE @ErrorLine INT;
		DECLARE @ErrorNumber INT;
		DECLARE @SYSUSER NVARCHAR(200);
		DECLARE @FECHA DATETIME;
		
		SELECT 
			@ErrorMessage = ERROR_MESSAGE(),
			@ErrorSeverity = ERROR_SEVERITY(),
			@ErrorState = ERROR_STATE(),
			@ErrorLine = ERROR_LINE(),
			@ErrorNumber = ERROR_NUMBER(),
			@SysUser = SYSTEM_USER,
			@Fecha = GETDATE();

		INSERT INTO TP.Log_Errores(Descripcion,Linea_Excepcion, Numero_Error, Severidad, Estado, Fecha, Usuario)
		VALUES(@ErrorMessage,@ErrorLine, @ErrorNumber, @ErrorSeverity, @ErrorState, @Fecha, @SysUser)
		
		PRINT 'ERROR: Revise la tabla TP.Log_Errores. INFORMACION: ' + ERROR_MESSAGE()
	END CATCH
END
GO

/*================	TRIGGER PARA EL TP	================*/
CREATE TRIGGER TGI_InformeAuditoria ON TP.Lista_Objetos 
AFTER INSERT
AS
	BEGIN
		BEGIN TRY
			INSERT INTO TP.Auditoria SELECT TOP 1 Esquema, Base, GETDATE(), SYSTEM_USER FROM INSERTED		
		END TRY
		BEGIN CATCH
			PRINT 'ERROR: ' + ERROR_MESSAGE()
		END CATCH
	END
GO




/*================	EJECUCIONES DE EJEMPLO	================*/

/*
--DROP PROCEDURE sp_GrabarObjetos

EXECUTE sp_GrabarObjetos 'TP_FINAL','Test'
EXECUTE sp_GrabarObjetos 'TP_FINAL','TP' 

--ALGUNA DE LAS DOS VA A FALLAR, SEGUN EL NOMBRE QUE TENGA
EXECUTE sp_GrabarObjetos 'AdventureWorks','Production'		
EXECUTE sp_GrabarObjetos 'AdventureWorks_Data','Production' 

--VER LAS TABLAS
SELECT * FROM TP.Lista_Objetos
SELECT * FROM TP.Auditoria
SELECT * FROM TP.Log_Errores
*/
