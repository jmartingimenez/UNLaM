INSERT INTO Proveedor(id_proveedor,nombre)
VALUES (1,'Pepe');

INSERT INTO Producto(id_producto,descripcion,estado,id_proveedor)
VALUES 	(1,'Pan','Sin stock',1),
		(2,'Empanada','En stock',1),
		(3,'Papas','Sin stock',1);

INSERT Cliente(id_cliente,nombre)
VALUES 	(1,'hola'),
		(2,'chau');

INSERT INTO Vendedor(id_vendedor,nombre)
VALUES 	(1,'Vendedor1'),
		(2,'Vendedor2'),
		(3,'Vendedor3');

INSERT INTO Venta(nro_factura,id_cliente,fecha,id_vendedor)
VALUES	(1,2,'2014-01-25',3),
		(2,1,'2015-01-01',2),
		(3,2,'2015-06-12',1),
		(4,2,'2015-03-17',1),
		(5,1,'2015-01-09',3);

INSERT INTO Detalle_Venta(nro_factura,nro_detalle,id_producto,precio_unitario)
VALUES	(1,443,2,444),
		(5,879,3,555),
		(4,123,3,666);