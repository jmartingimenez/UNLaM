/* Consulta 1
Listar la cantidad de productos que tiene la empresa. 
*/

SELECT COUNT(*) AS 'Total de Productos'
FROM Producto;

/* Consulta 2
Listar la descripción de productos en estado 'en stock' que
tiene la empresa
*/

SELECT P.descripcion AS 'Descripcion'
FROM Producto AS P
WHERE P.estado='En stock';

/* Consulta 3
Listar los productos que nunca fueron vendidos
*/

SELECT P.descripcion
FROM Producto AS P
	LEFT JOIN Detalle_Venta AS DV ON P.id_producto=DV.id_producto
WHERE DV.id_producto IS NULL;

/* Consulta 4
Listar la cantidad total de unidades que fueron vendidas de cada
producto (descripción).
*/
-- No se mostrar cuando uno tiene 0 ventas
SELECT P.descripcion AS 'Descripcion',COUNT(*) AS 'Unidades X Producto'
FROM Producto AS P
	JOIN Detalle_Venta AS DV ON P.id_producto=DV.id_producto
GROUP BY P.id_producto,P.descripcion;

/* Consulta 5
Listar el nombre de cada vendedor y la cantidad de ventas
realizadas en el año 2015
*/

SELECT VD.nombre,COUNT(*) AS 'Ventas'
FROM Vendedor AS VD
	JOIN Venta AS VT ON VD.id_vendedor=VT.id_vendedor
WHERE VT.fecha >= '2015-01-01'
	AND VT.fecha <= '2015-12-31'
GROUP BY VD.id_vendedor,VD.nombre;

/* Consulta 6
Listar el monto total vendido por cada cliente (nombre) 
*/

SELECT C.nombre,SUM(DV.precio_unitario) AS 'Monto x Cliente $'
FROM Cliente AS C
	JOIN Venta AS V ON C.id_cliente=V.id_cliente
	JOIN Detalle_Venta AS DV ON V.nro_factura=DV.nro_factura
GROUP BY C.id_cliente,C.nombre;

/* Consulta 7
Listar la descripción de aquellos productos en estado ‘sin stock’
que se hayan vendido en el mes de Enero de 2015 
*/

SELECT P.descripcion
FROM Producto AS P
WHERE P.estado='Sin stock'
	AND P.id_producto IN
	(
		SELECT DV.id_producto
		FROM Detalle_Venta AS DV
			JOIN Venta AS VT ON DV.nro_factura=VT.nro_factura
		WHERE VT.fecha >= '2015-01-01'
			AND VT.fecha <= '2015-01-31'
	);
