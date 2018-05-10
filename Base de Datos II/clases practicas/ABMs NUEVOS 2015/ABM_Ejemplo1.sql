----------------------------------------------------------------------------------------------------------------------------------------------
---EJEMPLO 1:ABM Simple, sin manejo de errores y sin validaciones-----------------------------------------------------------------------------
---En el script se crea la tabla, el SP y al final hay ejemplos de llamadas
----------------------------------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------------------------------
--Creación de tabla Empleado 
----------------------------------------------------------------------------------------------------------------------------------------------
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
-- =====================================================================
-- Autor:		Cintia Gioia	
-- Fecha de creación: 4/10/2015
-- Descripción:	ABM de Empleados
-- =====================================================================
CREATE PROCEDURE [dbo].[SP_EMPLEADOS_ABM_Ejemplo1] 
	@ACCION CHAR(1),   
	@ID NUMERIC(18, 0), 
	@NOMBRE VARCHAR(100), 
	@APELLIDO VARCHAR(100), 
	@FECHA_NAC DATETIME, 
	@EDAD SMALLINT, 
	@DNI INT
AS
BEGIN
	
SET NOCOUNT ON /*Evita que se devuelva el mensaje que muestra el recuento del número de filas
 afectadas por una instrucción o un procedimiento almacenado de Transact-SQL
 como parte del conjunto de resultados.*/

SELECT @ACCION = UPPER(@ACCION)
	
	IF @ACCION ='A' 
		BEGIN
			INSERT INTO dbo.EMPLEADO
			(ID, NOMBRE, APELLIDO, FECHA_NAC, EDAD, DNI) 
			VALUES 
			(@ID,@NOMBRE, @APELLIDO, @FECHA_NAC, @EDAD, @DNI) 			

			SELECT 'Cantidad de Filas insertadas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 

	IF @ACCION ='B'
		BEGIN			
			DELETE dbo.EMPLEADO			
			WHERE ID = @ID
			
			SELECT 'Cantidad de Filas borradas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 

	IF @ACCION ='M' 
		BEGIN
			UPDATE dbo.EMPLEADO	
			SET NOMBRE=@NOMBRE,
			APELLIDO=@APELLIDO, 
			FECHA_NAC=@FECHA_NAC,
			EDAD=@EDAD,
			DNI=@DNI
			WHERE ID = @ID
			
			SELECT 'Cantidad de Filas modificadas: ' + CONVERT(VARCHAR(10),@@ROWCOUNT)
		END 		

END

----------------------------------------------------------------------------------------------------------------------------------------------
--Ejemplo llamadas: 
----------------------------------------------------------------------------------------------------------------------------------------------
--Inserto un registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'A', 1, 'Andrea', 'Perez', '19991123', 15, 36789890
--si quiero insertar el mismo da un error no controlado ya que el sp no tiene manejo de errores:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'A', 1, 'Andrea', 'Perez', '19991123', 15, 36789890
--inerto otro registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'A', 2, 'Carlos', 'Gonzalez', '20051002', 10, 45678345
--modifico el registro 2:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'M', 2, 'Pedro', 'Gonzalez', '20031002', 12, 46789204
--si modifico uno inexistente no da error, pero no se modifica ningun registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'M', 3, 'Pedro', 'Gonzalez', '20031002', 12, 46789204
--elimino el registro 2: (solo basta con indicar B y el ID, el resto de los campos no importa el contenido
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'B', 2, '', '', '', 0, 0
--si elimino uno inexistente no da error, pero no se elimina ningun registro:
EXEC dbo.SP_EMPLEADOS_ABM_Ejemplo1 'B', 3, '', '', '', 0, 0

SELECT * FROM dbo.EMPLEADO

