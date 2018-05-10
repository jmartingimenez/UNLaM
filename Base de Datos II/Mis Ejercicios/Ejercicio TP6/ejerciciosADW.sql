USE AdventureWorks_Data;

/*1.p_InsCulture(id,name,date): Este sp debe permitir dar de alta
un nuevo registro en la tabla Production.Culture. Los tipos de
datos de los parámetros deben corresponderse con la tabla.*/
CREATE PROCEDURE p_InsCulture	@ID CHAR(2),
								@NAME VARCHAR(MAX)
AS
DECLARE @ACTUALDATE DATETIME
SET @ACTUALDATE=GETDATE()
INSERT INTO Production.Culture(CultureID,Name,ModifiedDate)
VALUES(@ID,@NAME,@ACTUALDATE);

--EXECUTE p_InsCulture 'XX','E6E1';		

/*2.p_SelCulture(id): Este sp devolverá el registro completo
según el id enviado.*/
CREATE PROCEDURE p_SelCulture @ID CHAR(2)
AS
SELECT * FROM Production.Culture WHERE CultureID=@ID;

--EXECUTE p_SelCulture 'XX'

/*3.p_DelCulture(id): Este sp debe borrar el id enviado por
parámetro de la tabla Production.Culture.*/
CREATE PROCEDURE p_DelCulture @ID CHAR(2)
AS
DELETE FROM Production.Culture
WHERE CultureID=@ID;

--EXECUTE p_DelCulture 'XX'

/*4.p_UpdCulture(id): Dado un id debe permitirme cambiar el
campo name del registro.*/
CREATE PROCEDURE p_UpdCulture @ID CHAR(2),@NUEVONOMBRE VARCHAR(MAX)
AS
UPDATE Production.Culture
SET Name=@NUEVONOMBRE
WHERE CultureID=@ID;

--EXECUTE p_UpdCulture 'th','ThaiX';

/*5.sp_CantCulture (cant out): Realizar un sp que devuelva la
cantidad de registros en Culture. El resultado deberá colocarlo
en una variable de salida.*/
CREATE PROCEDURE sp_CantCulture
AS
DECLARE @CANTIDAD INT
SELECT @CANTIDAD=COUNT(*)
FROM Production.Culture
PRINT 'Cantidad de culturas: ' + CAST(@CANTIDAD AS VARCHAR(MAX));

--EXECUTE sp_CantCulture;

		/*VERSION CON OUTPUT*/
		CREATE PROCEDURE sp_CantCulture @CANTIDAD INT OUTPUT
		AS
		SELECT @CANTIDAD=COUNT(*)
		FROM Production.Culture;

		--DECLARE @CANTIDAD INT
		--EXECUTE sp_CantCulture @CANTIDAD OUTPUT
		--PRINT 'Cantidad de culturas: ' + CAST(@CANTIDAD AS VARCHAR(MAX)); 

/*6.sp_CultureAsignadas : Realizar un sp que devuelva solamente
las Culture’s que estén siendo utilizadas en las tablas
(Verificar qué tabla/s la están referenciando).
Sólo debemos devolver id y nombre de la Cultura.*/	
CREATE PROCEDURE sp_CultureAsignadas
AS
SELECT P.CultureID,P.Name 
FROM Production.Culture P
WHERE EXISTS(
	SELECT 1
	FROM Production.ProductModelProductDescriptionCulture PM
	WHERE P.CultureID=PM.CultureID
);

--EXECUTE sp_CultureAsignadas;

/*7.p_ValCulture(id,name,date,operación, valida out):
Este sp permitirá validar los datos enviados por parámetro.
En el caso que el registro sea válido devolverá un 1 en el
parámetro de salida valida ó 0 en caso contrario.
El parámetro operación puede ser “U” (Update), “I” (Insert)
ó “D” (Delete).
Lo que se debe validar es:
- Si se está insertando no se podrá agregar un registro con un id
  existente, ya que arrojará un error.
- Tampoco se puede agregar dos registros Cultura con el mismo Name,
  ya que el campo Name es un unique index.
- Ninguno de los campos debería estar vacío.
- La fecha ingresada no puede ser menor a la fecha actual.*/	
CREATE PROCEDURE p_ValCulture	@ID CHAR(2), @NAME  VARCHAR(MAX),
								@DATE DATETIME, @OPERACION CHAR(1)
AS 
BEGIN
	DECLARE	@VALIDA INT,@FECHA_ACTUAL DATETIME,
			@CAMPOS_EXISTENTES INT
	SET @VALIDA=0
	SET @FECHA_ACTUAL=GETDATE()
	SET @CAMPOS_EXISTENTES=(
		SELECT COUNT(*)
		FROM Production.Culture
		WHERE Name=@NAME OR CultureID=@ID)
	IF (@ID IS NOT NULL AND LEN(LTRIM(RTRIM(@ID)))>0 AND
		@NAME IS NOT NULL AND LEN(LTRIM(RTRIM(@NAME)))>0 AND
		@DATE IS NOT NULL AND LEN(LTRIM(RTRIM(@DATE)))>0 AND
		(@OPERACION='U' OR @OPERACION='I' OR @OPERACION='D') AND
		@DATE>=@FECHA_ACTUAL AND @CAMPOS_EXISTENTES=0)
		BEGIN
			SET @VALIDA=1
		END
	PRINT 'Validacion: '+ CAST(@VALIDA AS CHAR(1))
END;	

--DECLARE @miFecha DATETIME
--SET @miFecha='20180201'
--EXEC p_ValCulture 'ar','nuevo',@miFecha,'D'	