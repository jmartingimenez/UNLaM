/*
Alumno: Jonatan Gimenez
DNI: 35137586

NOTA: 10 (Diez)
*/



/*CONSIGNA: COPIO LO QUE ME ACUERDO 
Generar un SP que funcione como un ABM de una tabla cualquiera elegida de AdventureWorks. Este SP realiza operaciones de ABM.
Tiene que tener manejo de errores. Si existe fallo en la operacion, realizar una insercion en la tabla Log_Errores con los datos
correspondientes (Aca venian los campos, pero abajo esta la definicion de la tabla, no lo voy a repetir). Si la operacion se
realizo con exito, insertar en una tabla de auditoria(trigger after) la operacion que se realizo(La declaracion de la tabla esta abajo).
Antes de las operaciones ABM comprobar a traves de una funcion que exista la id(o campo que sea PK) dada 

En la ejecucion no debe ser obligatorio pasar algun valor en cada parametro(podes mandar string vacios si la tabla elegida lo permite)
*/




USE AdventureWorks --AdventureWorks_Data quizas tambien, ver el nombre. En la pc de la facu era 'AdventureWorks' nomas
GO
/*TABLA USADA: Production.Culture*/
--SELECT * FROM Production.Culture

CREATE TABLE Log_Errores(
	ID NUMERIC(18,0) IDENTITY(1,1) NOT NULL,
	ERROR_LINE INT NULL,
	ERROR_MESSAGE NVARCHAR(2048) NULL,
	ERROR_PROCEDURE NVARCHAR(126) NULL,
	ERROR_NUMBER INT NULL,
	ERROR_SEVERITY INT NULL,
	ERROR_STATE INT NULL,
	FECTRANS DATETIME NULL,
	USERID VARCHAR(255) NULL
)

CREATE TABLE Auditoria(
	Usuario VARCHAR(MAX),
	Fecha DATETIME,
	Accion CHAR(12)
)
GO

CREATE FUNCTION F_COMPROBAR_ID(@ID_A_COMPROBAR CHAR(2)) --Pidio hacer la comprobacion con una funcion
RETURNS INT
AS
BEGIN
	DECLARE @RESPUESTA TINYINT
	IF EXISTS(SELECT 1 FROM Production.Culture WHERE CultureID=@ID_A_COMPROBAR)
		SET @RESPUESTA=1
	ELSE SET @RESPUESTA=0
	RETURN @RESPUESTA
END

--DROP FUNCTION dbo.F_COMPROBAR_ID

GO
CREATE PROCEDURE ABM_PARCIAL	@ACCION CHAR(1),
								@ID CHAR(2),
								@NOMBRE VARCHAR(MAX),
								@FECHA_MODIFICACION DATETIME
AS
BEGIN
	SET NOCOUNT ON
	BEGIN TRY
		IF(@ACCION NOT IN('A','B','M')) RAISERROR('ERROR!!: Accion incorrecta',16,1)

		DECLARE @COMPROBACION TINYINT
		SELECT @COMPROBACION=dbo.F_COMPROBAR_ID(@ID)
		
		IF(@ACCION='A') 
		BEGIN
			IF(@COMPROBACION=1) RAISERROR('ERROR!!: Ya existe la id dada.',16,1)
			ELSE INSERT INTO Production.Culture VALUES (@ID,@NOMBRE,@FECHA_MODIFICACION)
		END		
				
		IF(@ACCION='B')
			BEGIN
				IF(@COMPROBACION=0) RAISERROR('ERROR!!: No se encuentra la id para la baja.',16,1)
				ELSE DELETE FROM Production.Culture WHERE CultureID=@ID
			END

		IF(@ACCION='M')
			BEGIN
				IF(@COMPROBACION=0) RAISERROR('ERROR!!: No se encuentra la id para la modificacion.',16,1)
				ELSE UPDATE Production.Culture
					 SET Name=@NOMBRE, ModifiedDate=@FECHA_MODIFICACION
					 WHERE CultureID=@ID
			END
	END TRY
	BEGIN CATCH
		INSERT INTO Log_Errores(ERROR_LINE,ERROR_MESSAGE,ERROR_PROCEDURE,ERROR_NUMBER,ERROR_SEVERITY,ERROR_STATE,FECTRANS,USERID)
		VALUES(ERROR_LINE(),ERROR_MESSAGE(),ERROR_PROCEDURE(),ERROR_NUMBER(),ERROR_SEVERITY(),ERROR_STATE(),GETDATE(),USER)
		PRINT 'Consulta con errores. Revise la tabla Log_Errores: ' + ERROR_MESSAGE()	
	END CATCH
END


--DROP PROCEDURE ABM_PARCIAL

GO
CREATE TRIGGER T_ABM_PARCIAL ON Production.Culture AFTER INSERT,DELETE,UPDATE
AS
BEGIN
	IF EXISTS(SELECT 1 FROM DELETED)
		BEGIN
			IF EXISTS(SELECT 1 FROM INSERTED) INSERT INTO Auditoria VALUES(SYSTEM_USER,GETDATE(),'MODIFICACION')
			ELSE INSERT INTO Auditoria VALUES(SYSTEM_USER,GETDATE(),'BAJA')
		END
	ELSE  INSERT INTO Auditoria VALUES(SYSTEM_USER,GETDATE(),'INSERCION')
	
END

GO
EXECUTE ABM_PARCIAL 'A','ar','Argentina','20170203'		--Da error
EXECUTE ABM_PARCIAL 'A','br','Brasil','20170203'		--Funciona

EXECUTE ABM_PARCIAL 'B','br','',''						--Funciona si se hizo la insercion anterior
EXECUTE ABM_PARCIAL 'B','pe','',''						--Da error

EXECUTE ABM_PARCIAL 'M','ar','Argentina','20000506'		--Funciona
EXECUTE ABM_PARCIAL 'M','pe','',''						--No funciona


SELECT * FROM Production.Culture
SELECT * FROM Log_Errores
SELECT * FROM Auditoria









