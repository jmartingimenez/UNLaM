/*1.1 - Crear la Base de datos 'GestionClientes'*/
USE MASTER;
DROP DATABASE GestionClientes;
CREATE DATABASE GestionClientes;
USE GestionClientes;

/*1.2 - Crear el siguiente esquema relacional*/
CREATE SCHEMA Facturacion AUTHORIZATION dbo
GO
CREATE TABLE Facturacion.Tipo_Producto(
Cod_Tipo_Producto smallint NOT NULL,
Descricpion varchar(100) NULL,
CONSTRAINT PK_Tipo_Producto PRIMARY KEY CLUSTERED (Cod_Tipo_Producto ASC)
)
GO
CREATE TABLE Facturacion.Cliente(
Nro_Cliente int IDENTITY(1,1) NOT NULL,
Razon_Social varchar(100) NULL,
Domicilio varchar(100) NULL,
CUIT bigint NULL,
CONSTRAINT PK_Cliente PRIMARY KEY CLUSTERED (Nro_Cliente ASC)
)
GO
CREATE TABLE Facturacion.Factura(
Nro_Factura int IDENTITY(1,1) NOT NULL,
Nro_Cliente int NOT NULL,
Fecha smalldatetime NULL CONSTRAINT DF__Factura__Fecha__182C9B23 DEFAULT (getdate()),
Importe_Total numeric(10, 2) NULL,
CONSTRAINT PK_Factura PRIMARY KEY CLUSTERED (Nro_Factura ASC),
CONSTRAINT FK_Factura_Nro_Cli FOREIGN KEY(Nro_Cliente) REFERENCES Facturacion.Cliente (Nro_Cliente)
)
GO
CREATE TABLE Facturacion.Producto(
Nro_Producto int NOT NULL,
Descripcion varchar(100) NOT NULL,
Cod_Tipo_Producto smallint NULL,
Precio numeric(10, 2) NULL DEFAULT ((0)),
CONSTRAINT PK_Producto PRIMARY KEY CLUSTERED (Nro_Producto ASC) ,
CONSTRAINT FK_Producto_Tipo_Producto FOREIGN KEY(Cod_Tipo_Producto) REFERENCES Facturacion.Tipo_Producto (Cod_Tipo_Producto)
)
GO
CREATE TABLE Facturacion.ItemFactura(
Nro_Factura int NOT NULL,
Nro_Item smallint NOT NULL,
Nro_Producto int NULL,
Cantidad int NULL,
CONSTRAINT PK_ItemFactura PRIMARY KEY CLUSTERED (Nro_Factura ASC, Nro_Item ASC),
CONSTRAINT FK__ItemFactu FOREIGN KEY(Nro_Factura) REFERENCES Facturacion.Factura (Nro_Factura),
CONSTRAINT FK_Producto FOREIGN KEY(Nro_Producto) REFERENCES Facturacion.Producto (Nro_Producto)
)
GO

		/*
		--Si es necesario borrarlo, seguir el siguiente orden:
		DROP TABLE Facturacion.ItemFactura
		DROP TABLE Facturacion.Producto
		DROP TABLE Facturacion.Tipo_Producto
		DROP TABLE Facturacion.Factura
		DROP TABLE Facturacion.Cliente
		DROP SCHEMA Facturacion
		*/
		
/*2.1 - Agregar el campo Fecha_Baja en la tabla clientes.*/	
ALTER TABLE Facturacion.Cliente ADD Fecha_Baja DATETIME;

/*3.1 - Agregar al menos 3 facturas dentro del modelo de
datos creado con sus respectivas relaciones. Tener en
cuenta el orden de inserción.*/
INSERT INTO Facturacion.Cliente(Razon_Social,Domicilio,
								CUIT,Fecha_Baja)
VALUES	('rs1','calle1',12345,'2015-03-02'),
		('rs2','calle2',23456,'2016-05-08'),
		('rs3','calle3',34567,'2017-02-01'),
		('rs4','calle4',45678,'2012-09-07');
INSERT INTO Facturacion.Factura(Nro_Cliente,Fecha,Importe_Total)
VALUES	(1,'2013-01-06',300),
		(2,'2014-11-09',400),
		(3,GETDATE(),500);
INSERT INTO Facturacion.Factura(Nro_Cliente,Fecha,Importe_Total)
VALUES	(1,'2013-01-06',50);		
INSERT INTO Facturacion.Tipo_Producto(Cod_Tipo_Producto,Descricpion)
VALUES	(1,'tipoProducto1'),
		(2,'tipoProducto2'),
		(3,'tipoProducto3');	
INSERT INTO Facturacion.Producto(Nro_Producto,Descripcion,
								Cod_Tipo_Producto,Precio)
VALUES	(1,'producto1',3,125),
		(2,'producto2',2,250),
		(3,'producto3',1,375);	
INSERT INTO Facturacion.Producto(Nro_Producto,Descripcion,
								Cod_Tipo_Producto,Precio)
VALUES(4,'Para el 4.7',2,89);			
INSERT INTO Facturacion.ItemFactura(Nro_Factura,Nro_Item,
									Nro_Producto,Cantidad)
VALUES	(1,1,1,10),
		(2,3,2,20),
		(3,2,3,30);	
		
		/*
		-- Para comprobar los inserts
		SELECT * FROM Facturacion.ItemFactura
		SELECT * FROM Facturacion.Producto
		SELECT * FROM Facturacion.Tipo_Producto
		SELECT * FROM Facturacion.Factura
		SELECT * FROM Facturacion.Cliente	
		*/

/*4.1 - f_ultimodia(@mes,@año): Crear una función que nos
devuelva el último día de cada mes/año.
===TOMAR CON PINZAS. EN EL PRIMER DATEADD ESTOY
===AGREGANDO UN MES MAS AL ACTUAL, DESPUES RESTO
=== UN DIA PARA QUEDAR EN EL ULTIMO DIA DEL MES ACTUAL.
===EN EL SEGUNDO, SUMO UN ANIO AL ACTUAL Y RESTO UN
DIA PARA QUEDAR EN EL ULTIMO DIA DEL ANIO*/
CREATE FUNCTION f_ultimodia (@mes INT,@anio INT)
RETURNS TABLE
AS
RETURN(
	SELECT	DAY(DATEADD(MONTH, @mes, -1)) 
				AS 'Ultimo dia del mes dado',
			DAY(DATEADD(YEAR,DATEDIFF(YEAR,@anio,GETDATE())+1,-1))
				AS 'Ultimo dia del anio dado'	
);

	--SELECT * FROM dbo.f_ultimodia(4,2012);

/*4.2 - f_ultimafactura(): Crear una función que devuelva
el próximo número de factura a asignar. Se tendrá en cuenta
para los números de factura son incrementales.*/
CREATE FUNCTION f_ultimafactura()
RETURNS INT
AS
BEGIN
	DECLARE @numero INT
	SET @numero=(
		SELECT MAX(Nro_Factura) + 1
		FROM Facturacion.Factura)
	RETURN @numero
END;

	--SELECT dbo.f_ultimafactura() AS 'Proximo numero de factura';

/*4.3 - f_cuit(@cuit): Crear una función que reciba un número
de cuit numérico y devuelva un cuit formateado con guiones.
===NO FUNCIONA EN SQL SERVER 2008 EL FORMAT*/

	--FORMAT NO CORRE EN SQL 2008, LO DEJE SIN HACER
	
/*4.4 - f_sololetras(@texto): Crear una función que quite
todo caracter que no sea letra del texto.
===SI ENTIENDO BIEN, EL PATRON '%[^a-Z]%' AL TENER
===EL '^' ADELANTE EN VEZ DE COMPROBAR SI UN CARACTER
===ES PERMITIDO, COMPRUEBA SI ESE CARACTER NO LO ES.
===COMO PATINDEX DEVUELVE LA POSICION DONDE SE ENCUENTRA
===ESE PATRON, MIENTRAS SEA MAYOR A 0 ES QUE QUEDAN
===CARACTERES POR REEMPLAZAR. UNA VEZ DENTRO DEL BUCLE,
===SE RENOMBRA '@texto' UTILIZANDO UN STUFF (EL PATRON
===SERIA LA PROPIA CADENA, LA POSICION INICIAL DONDE
===NO ENCUENTRA COINCIDENCIA, 1 PARA NO MOVERSE DE AHI Y
===FINALMENTE UN CARACTER EN BLANCO PARA ELIMINAR ESE
===CARACTER QUE NO DEBE ESTAR)*/
CREATE FUNCTION f_sololetras(@texto VARCHAR(MAX))
RETURNS VARCHAR(MAX)
AS
BEGIN
	DECLARE @patron VARCHAR(MAX)
	SET @patron='%[^a-Z]%'
	WHILE PATINDEX(@patron,@texto)>0
		BEGIN
			SET @texto=STUFF(@texto,PATINDEX(@patron,@texto),1,'')
		END
	RETURN @texto	
END;

		--SELECT dbo.f_sololetras('/avErSi23''fuNciona12');

/*4.5 - f_quitarespacios(@texto): Crear una función que
quite todos los espacios contenidos en un texto.*/
CREATE FUNCTION f_quitarespacios(@texto VARCHAR(MAX))
RETURNS VARCHAR(MAX)
AS
BEGIN
	SET @texto=REPLACE(@texto,' ','')
RETURN @texto
END;

	--SELECT dbo.f_quitarespacios(' un texto de prueba  x  1 ');

/*4.6 - f_quitarespaciosv2(@texto,@caracter): Generalizar la 
función anterior indicando qué caracter se quiere quitar.*/	
CREATE FUNCTION f_quitarespaciosv2(@texto VARCHAR(MAX),
									@caracter VARCHAR(MAX))
RETURNS VARCHAR(MAX)
AS
BEGIN
	SET @texto=REPLACE(@texto,@caracter,'')
RETURN @texto
END;

	--SELECT dbo.f_quitarespaciosv2('abcdefg','e');
	
/*4.7 - f_menorcosto(): Realizar una función de devuelva
los productos que posean menor costo por cada tipo de
producto. Se desea conocer, el código del tipo de producto,
su descripción. el producto con el menor costo y su precio.*/
CREATE FUNCTION f_menorcosto()
RETURNS @miTabla TABLE(
	Codigo_Tipo_Producto INT,
	Descripcion_Tipo_Producto VARCHAR(MAX),
	Producto VARCHAR(MAX),
	Precio NUMERIC(10,2)
)
AS
BEGIN
	INSERT INTO @miTabla(	Codigo_Tipo_Producto,
							Descripcion_Tipo_Producto,
							Producto,
							Precio)
	SELECT	P.Cod_Tipo_Producto AS 'test',
			T.Descricpion AS 'test2',
			P.Descripcion AS 'test3',
			P.Precio AS 'test4'
	FROM Facturacion.Producto P
		JOIN Facturacion.Tipo_Producto T
		ON P.Cod_Tipo_Producto=T.Cod_Tipo_Producto
	WHERE Precio=(
		SELECT MIN(Precio)
		FROM Facturacion.Producto PP
		WHERE P.Cod_Tipo_Producto=PP.Cod_Tipo_Producto
	)
RETURN	
END;

			--DROP FUNCTION f_menorcosto
			--SELECT * FROM dbo.f_menorcosto()
			
/*5.1 - tg_importe: Generar un trigger que actualice el
importe siempre que se inserte o modifique un item
de la factura.*/
CREATE TRIGGER tg_importe ON Facturacion.ItemFactura
AFTER INSERT,UPDATE
AS
BEGIN
	DECLARE @operacion CHAR(1)
	SET @operacion='I'
	IF EXISTS(SELECT 1 FROM DELETED)
		BEGIN
			SET @operacion='U'
		END
	UPDATE Facturacion.Factura
	SET Importe_Total=Importe_Total + 
		(
			SELECT TOP 1 P.Precio
			FROM INSERTED I
				JOIN Facturacion.ItemFactura F
				ON I.Nro_Factura=F.Nro_Factura
				JOIN Facturacion.Producto P
				ON F.Nro_Producto=P.Nro_Producto
		)
	WHERE Nro_Factura=(
		CASE WHEN @operacion='I'
			THEN (SELECT TOP 1 I.Nro_Factura 
				  FROM INSERTED I
				  WHERE Nro_Factura=I.Nro_Factura )
			ELSE (SELECT TOP 1 D.Nro_Factura 
				  FROM DELETED D
				  WHERE Nro_Factura=D.Nro_Factura )	  
		END		
	)		
END;

			--SELECT * FROM Facturacion.Factura
			--SELECT * FROM Facturacion.ItemFactura
			--SELECT * FROM Facturacion.Producto
			--DROP TRIGGER Facturacion.tg_importe	
			/*
			INSERT INTO Facturacion.ItemFactura(Nro_Factura,
				Nro_Item,Nro_Producto,Cantidad)
			VALUES	(4,3,2,9)
			*/
			/*
			UPDATE Facturacion.ItemFactura
			SET Nro_Producto=1
			WHERE Nro_Factura=4 
			*/
			
/*5.2 - tg_borrarcliente: Cada vez que se borre un cliente,
completar la fecha de baja con la fecha actual.
===ENTENDI QUE NO SE BORRA NADA, SOLO SE PONE LA
===FECHA DE BAJA*/
CREATE TRIGGER tg_borrarcliente ON Facturacion.Cliente
INSTEAD OF DELETE
AS
BEGIN
	UPDATE Facturacion.Cliente
	SET Fecha_Baja=GETDATE()
	WHERE Nro_Cliente=(SELECT Nro_Cliente FROM DELETED)
END;

		/*
		--SELECT * FROM Facturacion.Cliente
		--DELETE FROM Facturacion.Cliente WHERE Nro_Cliente=2
		--SELECT name,is_disabled,is_instead_of_trigger
		  FROM sys.triggers	
		--DROP TRIGGER Facturacion.tg_borrarcliente					
		*/

/*5.3 - tg_actualizaimporte: Generar un trigger que arroje
un mensaje de error cada vez que se quiera actualizar el
importe indicando que el import NO es actualizable.
El resto de los campos sí se podrían cambiar.
===PRIMERO SE DA UN ERROR SI SE INTENTA ACTUALIZAR EL IMPORTE,
===EN EL ELSE SE COMPRUEBA SI EL UPDATE ES PARA 'Nro_Cliente'
===O 'Fecha' Y SE HACE EL UPDATE CORRESPONDIENTE.
===INSERTED GUARDA LOS NUEVOS REGISTROS, DELETED LOS VIEJOS.
===EL 'TOP 1' ES PORQUE UN SELECT PUEDE DEVOLVER MAS DE UN
===REGISTRO (CUANDO HAY MAS DE UNO A MODIFICAR) Y ESO HACE
===FALLAR LA QUERY (AL USAR EL '=' NECESITO UN VALOR SOLO)*/
CREATE TRIGGER tg_actualizaimporte ON Facturacion.Factura
INSTEAD OF UPDATE
AS
BEGIN
SET NOCOUNT ON
	IF UPDATE(Importe_Total)
		BEGIN
			RAISERROR('No puede actualizarse el Importe',16,1)	
		END
	ELSE
		BEGIN IF UPDATE(Nro_Cliente)
			UPDATE Facturacion.Factura
			SET Nro_Cliente=(SELECT TOP 1 Nro_Cliente FROM INSERTED)
			WHERE Nro_Cliente=(SELECT TOP 1 Nro_Cliente FROM DELETED)
		END
		BEGIN IF UPDATE(Fecha)
			UPDATE Facturacion.Factura
			SET Fecha=(SELECT TOP 1 Fecha FROM INSERTED)
			WHERE Fecha=(SELECT TOP 1 Fecha FROM DELETED)		
		END
END;
		
		/*
		UPDATE Facturacion.Factura
		SET Nro_Cliente=2
		WHERE Nro_Cliente=3

		SELECT * FROM Facturacion.Factura

		DROP TRIGGER Facturacion.tg_actualizaimporte
		*/
		
/*===================FINAL===================*/		
-- Para ver la lista de triggers
SELECT name,is_disabled,is_instead_of_trigger
FROM sys.triggers