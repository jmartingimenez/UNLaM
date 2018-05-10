SELECT 	cod_art
	FROM articulo
	WHERE precio BETWEEN 100 AND 1000
		AND descripcion LIKE 'A%';

SELECT *
	FROM proveedor;

SELECT descripcion
	FROM material
	WHERE cod_mat IN (1, 3, 6, 9, 18);

SELECT cod_prov AS codigo, nombre
	FROM proveedor
	WHERE domicilio LIKE 'suipacha%'
		AND fecha_alta >= '2001-01-01';

SELECT P.nombre AS Nombre, C.nombre AS Ciudad
FROM proveedor AS P JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu;

-- 6

SELECT P.nombre AS Nombre
FROM proveedor AS P JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu
WHERE C.nombre='la plata';

-- 7
/*
Listar los números de almacenes que almacenan el artículo de descripción A.
*/

SELECT ALM.nro
FROM almacen AS ALM JOIN contiene ON ALM.nro=contiene.nro
                    JOIN articulo AS ART ON ART.cod_art=contiene.cod_art
WHERE ART.descripcion='A'; 


-- 8

SELECT M.cod_mat, M.descripcion
	FROM material AS M JOIN provisto_por ON M.cod_mat=provisto_por.cod_mat
				JOIN proveedor AS P ON P.cod_prov=provisto_por.cod_prov
				JOIN ciudad AS C ON C.cod_ciu=P.cod_ciu
	WHERE C.nombre='rosario';
 

-- 9

SELECT P.nombre
	FROM proveedor AS P JOIN provisto_por ON P.cod_prov=provisto_por.cod_prov
			JOIN material AS M ON M.cod_mat=provisto_por.cod_mat
			JOIN compuesto_por AS COMP ON COMP.cod_mat=M.cod_mat
			JOIN articulo AS AR ON AR.cod_art=COMP.cod_art
			JOIN contiene ON contiene.cod_art=AR.cod_art
			JOIN almacen AS AL ON AL.nro=contiene.nro
	WHERE AL.responsable='martin gomez';

-- 10

UPDATE contiene
	SET nro=20
	WHERE nro=10;

-- 11

DELETE FROM proveedor 
	WHERE nombre LIKE '%abc%';
				