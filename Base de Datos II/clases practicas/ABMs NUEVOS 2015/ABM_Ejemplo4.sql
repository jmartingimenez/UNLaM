----------------------------------------------------------------------------------------------------------------------------------------------
---EJEMPLO 4:ABM CON manejo de errores, TABLA DE LOG y CON VALIDACIONES BASICAS-----------------------------------------------------------------------------
---En el script se crea la tabla, el SP y al final hay ejemplos de llamadas
---Al indicar RAISERROR en el try catch se lanza error a capa superior. Los RAISERROR del cuerpo
---ppal se los trata en el catch.
---Es importante probar el SP comentando
---y descomentando RAISERROR asi identifican la diferencia.
---Ademas inserta los errores en una tabla de log de errores. Es importante ver bien el significado
---de los campos que se insertan en esta tabla.
----------------------------------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------------------------------
--Creación de tabla Empleado 
----------------------------------------------------------------------------------------------------------------------------------------------
DROP TABLE [dbo].[EMPLEADO]
GO
use master
go
CREATE TABLE [dbo].[EMPLEADO](
	[ID] NUMERIC(18, 0) NOT NULL, 
	[NOMBRE] VARCHAR(100) NOT NULL, 
	[APELLIDO] VARCHAR(100) NOT NULL, 
	[FECHA_NAC] DATETIME NOT NULL, 
	[EDAD] SMALLINT NOT NULL, 
	[DNI] INT NOT NULL, 
 CONSTRAINT [PK_EMPLEADO] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
DROP TABLE [dbo].[LOGERRORES]
GO
CREATE TABLE [dbo].[LOGERRORES](
	[ID] [numeric](18, 0) IDENTITY(1,1) NOT NULL,
	[DESCRIPCION] [varchar](max) NULL,
	[ERROR] [int] NULL,
	[FILA] [int] NULL,
	[ERROR_LINE] [int] NULL,
	[ERROR_MESSAGE] [nvarchar](2048) NULL,
	[ERROR_PROCEDURE] [nvarchar](126) NULL,
	[ERROR_NUMBER] [int] NULL,
	[ERROR_SEVERITY] [int] NULL,
	[ERROR_STATE] [int] NULL,
	[FECALT] [datetime] NULL,
	[USERID] [varchar](255) NULL
 CONSTRAINT [PK_LOGERRORES] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
-- =====================================================================
-- Autor:		Cintia Gioia	
-- Fecha de creación: 4/10/2015
-- Descripción:	ABM de Empleados
-- =====================================================================
CREATE PROCEDURE [dbo].[SP_EMPLEADOS_ABM_Ejemplo4]    
	@ACCION CHAR(1)='A',   
	@ID NUMERIC(18, 0), 
	@NOMBRE VARCHAR(100)='NOMBRE', 
	@APELLIDO VARCHAR(100), 
	@FECHA_NAC DATETIME, 
	@EDAD SMALLINT, 
	@DNI INT
AS
BEGIN
	
SET NOCOUNT ON /*Evita que se devuelva el mensaje que muestra el recuento del número de filas
afectadas por una instrucción o un procedimiento almacenado de Transact-SQL
como parte del conjunto de resultados.*/

DECLARE @DESCRIPCIONERROR VARCHAR(MAX)

BEGIN TRY
	

	SELECT @ACCION = UPPER(@ACCION)

	SELECT @DESCRIPCIONERROR = 'Id Inválido'
	IF @ID IS NULL OR @ID<=0
	BEGIN
		 RAISERROR (@DESCRIPCIONERROR,16,1) 
		 --Lanza error de validacion. LANZA ERROR AL CATCH, PORQUE EL SP TIENE TRY CATCH
	END	
	
	IF @ACCION = 'A' 
	BEGIN
		SELECT @DESCRIPCIONERROR = 'Id ya existente'
		IF EXISTS (SELECT 1 FROM EMPLEADO WHERE ID =@ID)
		BEGIN
		 RAISERROR (@DESCRIPCIONERROR,16,1)
		 --Lanza error de validacion. LANZA ERROR AL CATCH, PORQUE EL SP TIENE TRY CATCH
		END
	
	END
	
	IF @ACCION = 'B' OR @ACCION = 'M'
	BEGIN
	
		SELECT @DESCRIPCIONERROR = 'Id inexistente '
		IF NOT EXISTS (SELECT 1 FROM EMPLEADO WHERE ID =@ID)
		BEGIN
		 RAISERROR (@DESCRIPCIONERROR,16,1)
		END	
	END
	
	IF @ACCION = 'A' OR @ACCION = 'M'
	BEGIN
		SELECT @DESCRIPCIONERROR = 'Nombre inválido'
		IF @NOMBRE IS NULL OR LTRIM(RTRIM(@NOMBRE))=''
		BEGIN
		 RAISERROR (@DESCRIPCIONERROR,16,1)
		END	
	END
		
	IF @ACCION ='A' 
		BEGIN
			SELECT @DESCRIPCIONERROR = 'Error al insertar EMPLEADO '

			INSERT INTO dbo.EMPLEADO
			(ID, NOMBRE, APELLIDO, FECHA_NAC, EDAD, DNI) 
			VALUES 
			(@ID,@NOMBRE, @APELLIDO, @FECHA_NAC, @EDAD, @DNI) 			

			SELECT 'Cantidad de Filas insertadas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 

	IF @ACCION ='B'
		BEGIN	

		    SELECT @DESCRIPCIONERROR = 'Error al eliminar EMPLEADO - ID: '	 + CAST(@ID AS VARCHAR(20))  
		
			DELETE dbo.EMPLEADO			
			WHERE ID = @ID
			
			SELECT 'Cantidad de Filas borradas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 

	IF @ACCION ='M' 
		BEGIN

			SELECT @DESCRIPCIONERROR = 'Error al actualizar EMPLEADO - ID: '	 + CAST(@ID AS VARCHAR(20)) 

			UPDATE dbo.EMPLEADO	
			SET NOMBRE=@NOMBRE,
			APELLIDO=@APELLIDO, 
			FECHA_NAC=@FECHA_NAC,
			EDAD=@EDAD,
			DNI=@DNI
			WHERE ID = @ID
			
			SELECT 'Cantidad de Filas modificadas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 		
		
END TRY

BEGIN CATCH
 
    INSERT INTO LOGERRORES 
	(DESCRIPCION, ERROR, FILA, 
	ERROR_LINE, ERROR_MESSAGE, ERROR_PROCEDURE, 
	ERROR_NUMBER, ERROR_SEVERITY, ERROR_STATE, FECALT, USERID
	)  
	VALUES (@DESCRIPCIONERROR,  
	@@ERROR, @@ROWCOUNT, --estas 2 variables de entorno se pisan con cada sentencia ejecutada en el SP, por lo cual en este paso siempre van a devolver cero
	ERROR_LINE(), ERROR_MESSAGE(), ERROR_PROCEDURE(), 
	ERROR_NUMBER(), ERROR_SEVERITY(),ERROR_STATE(),
	GETDATE(),SYSTEM_USER )       
	
	RAISERROR (@DESCRIPCIONERROR,16,1)  --Al indicar RAISERROR se lanza error a capa superior

END CATCH

END
GO
----------------------------------------------------------------------------------------------------------------------------------------------
--Ejemplo llamadas: 
----------------------------------------------------------------------------------------------------------------------------------------------
--Inserto un registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 1, 'Andrea', 'Perez', '19991123', 15, 36789890
--Si quiero insertar el mismo registro da un error CONTROLADO ya que el sp tiene manejo de errores 
--(si se deja RAISERROR ademas lanza errores a la capa superior). Graba error en tabla de log siempre que suceda 
--un error. Como se valida id existente no intenta insertar. El error es lanzado por el raiserror 
--en la validacion
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 1, 'Andrea', 'Perez', '19991123', 15, 36789890
SELECT * FROM dbo.LOGERRORES
--inserto otro registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 2, 'Carlos', 'Gonzalez', '20051002', 10, 45678345
--modifico el registro 2:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'M', 2, 'Pedro', 'Gonzalez', '20031002', 12, 46789204
--si modifico uno inexistente se lanza error por vaildacion, no se modifica ningun registro y graba en tabla de log:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'M', 3, 'Pedro', 'Gonzalez', '20031002', 12, 46789204
--elimino el registro 2: (solo basta con indicar B y el ID, el resto de los campos no importa el contenido
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'B', 2, '', '', '', 0, 0
--si elimino uno inexistente da error por validacion, no se elimina ningun registro, se graba en tabla:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'B', 3, '', '', '', 0, 0

--Ejemplo de intentar insertar id invalido, lanza error de validacion y graba tabla de log
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 0, 'SILVANA', 'Perez', '19991123', 15, 36789890
--Ejemplo de intentar insertar id invalido, lanza error de validacion y graba tabla de log
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', NULL, 'SILVANA', 'Perez', '19991123', 15, 36789890
--Ejemplo de intentar insertar nombre invalido, lanza error de validacion y graba tabla de log
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 4, '', 'Perez', '19991123', 15, 36789890
--Ejemplo de intentar insertar nombre invalido, lanza error de validacion y graba tabla de log
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo4 'A', 4, NULL, 'Perez', '19991123', 15, 36789890

SELECT * FROM dbo.EMPLEADO
SELECT * FROM dbo.LOGERRORES
