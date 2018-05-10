DROP DATABASE IF EXISTS ejercicio3;
CREATE DATABASE IF NOT EXISTS ejercicio3;
USE ejercicio3;

CREATE TABLE Proveedor
	(
		id_proveedor INT UNSIGNED NOT NULL PRIMARY KEY,
		nombre VARCHAR(15),
		cuit INT
	);

CREATE TABLE Cliente
	(
		id_cliente INT UNSIGNED NOT NULL PRIMARY KEY,
		nombre VARCHAR(15)
	);

CREATE TABLE Vendedor
	(
		id_vendedor INT UNSIGNED NOT NULL PRIMARY KEY,
		nombre VARCHAR(15),
		apellido VARCHAR(15),
		dni INT UNSIGNED
	);

CREATE TABLE Producto
	(
		id_producto INT UNSIGNED NOT NULL PRIMARY KEY,
		descripcion VARCHAR(30),
		estado CHAR(10),
		id_proveedor INT UNSIGNED NOT NULL,
		CONSTRAINT Proveedor_FK
		FOREIGN KEY (id_proveedor)
			REFERENCES Proveedor (id_proveedor)
	);

CREATE TABLE Venta
	(
		nro_factura INT UNSIGNED NOT NULL PRIMARY KEY,
		id_cliente INT UNSIGNED NOT NULL,
		fecha DATE,
		id_vendedor INT UNSIGNED NOT NULL,
		CONSTRAINT Cliente_FK
		FOREIGN KEY (id_cliente)
			REFERENCES Cliente (id_cliente),
		CONSTRAINT Vendedor_FK
		FOREIGN KEY (id_vendedor)
			REFERENCES Vendedor (id_vendedor)
	);

CREATE TABLE Detalle_Venta
	(
		nro_factura INT UNSIGNED NOT NULL,
		nro_detalle INT UNSIGNED,
		id_producto INT UNSIGNED NOT NULL,
		cantidad INT UNSIGNED,
		precio_unitario DECIMAL,
		PRIMARY KEY (nro_factura,nro_detalle),
		CONSTRAINT Venta_FK
		FOREIGN KEY (nro_factura)
			REFERENCES Venta (nro_factura),
		CONSTRAINT Producto_FK
		FOREIGN KEY (id_producto)
			REFERENCES Producto (id_producto)
	);