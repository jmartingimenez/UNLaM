/* Consulta 1
Listar los números de artículos cuyo precio se encuentre entre
$100 y $1000 y su descripción comience con la letra A. 
*/

SELECT cod_art AS 'Codigo de articulo'
FROM articulo
WHERE precio BETWEEN 100 AND 1000
	AND descripcion LIKE 'A%';

/* Consulta 2
Listar todos los datos de todos los proveedores.
*/

SELECT *
FROM proveedor;

/* Consulta 3
Listar la descripción de los materiales de código 1,3,6,9 y 18. 
*/

SELECT descripcion
FROM material
WHERE cod_mat IN (1,3,6,9,18);

/* Consulta 4
Listar código y nombre de proveedores de la calle Suipacha, que
hayan sido dados de alta en el año 2001.
*/

SELECT cod_prov AS 'Codigo de proveedor',nombre
FROM proveedor
WHERE domicilio LIKE 'suipacha%'
	AND fecha_alta >= '2001-01-01';

/* Consulta 5
Listar nombre de todos los proveedores y de su ciudad. 
*/

SELECT P.nombre AS Nombre, C.nombre AS Ciudad
FROM proveedor AS P JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu;

/* Consulta 6
Listar los nombres de los proveedores de la ciudad de La Plata. 
*/

SELECT P.nombre AS Nombre
FROM proveedor AS P JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu
WHERE C.nombre='La Plata';

/* Consulta 7
Listar los números de almacenes que almacenan el artículo
de descripción A.
*/

SELECT ALM.nro
FROM almacen AS ALM JOIN contiene ON ALM.nro=contiene.nro
		JOIN articulo AS ART ON contiene.cod_art=ART.cod_art
WHERE ART.descripcion='A';

/* Consulta 8
Listar los materiales (código y descripción) provistos por
proveedores de la ciudad de Rosario. 
*/

SELECT M.cod_mat, M.descripcion
FROM material AS M JOIN provisto_por AS PP ON M.cod_mat=PP.cod_mat
			JOIN proveedor AS P ON PP.cod_prov=P.cod_prov
			JOIN ciudad AS C ON C.cod_ciu=P.cod_ciu
WHERE C.nombre='Rosario';

/* Consulta 9
Listar los nombres de los proveedores que proveen materiales
para artículos ubicados en almacenes que Martín Gómez
tiene a su cargo.
*/

SELECT PR.nombre
FROM proveedor AS PR JOIN provisto_por AS PP ON PR.cod_prov=PP.cod_prov
	JOIN material AS MA ON PP.cod_mat=MA.cod_mat
	JOIN compuesto_por AS CP ON MA.cod_mat=CP.cod_mat
	JOIN articulo AS AR ON CP.cod_art=AR.cod_art
	JOIN contiene AS CO ON AR.cod_art=CO.cod_art
	JOIN almacen AS AL ON CO.nro=AL.nro
WHERE AL.responsable='Martin Gomez';

/* Consulta 10
Mover los artículos almacenados en el almacén de número 10
al de número 20. 
*/

UPDATE almacen
SET nro=20
WHERE nro=10;

/* Consulta 11
Eliminar a los proveedores que contengan la palabra ABC
en su nombre 
*/

DELETE FROM proveedor
WHERE nombre LIKE '%ABC%';

/* Consulta 12
Indicar la cantidad de proveedores que comienzan con la letra F.
*/

-- Tmb sirve count(*), pero como lo puse ignora nulos
SELECT COUNT(nombre) 
FROM proveedor
WHERE proveedor.nombre LIKE 'F%';

/* Consulta 13
Listar el promedio de precios de los artículos
por cada almacén (nombre) 
*/

SELECT ALM.nombre AS 'Nombre', AVG(ART.precio) AS 'Promedio'
FROM almacen AS ALM 
	JOIN contiene ON ALM.nro=contiene.nro
	JOIN articulo AS ART ON contiene.cod_art=ART.cod_art
GROUP BY ALM.nombre;

/* Consulta 14
Listar la descripción de artículos compuestos
por al menos 2 materiales. 
*/

-- Para usar una cantidad como condicion, esto funciona
-- en lugar del WHERE (Poniendo el COUNT en el WHERE da error)
SELECT A.descripcion
FROM articulo AS A
	JOIN compuesto_por AS C ON A.cod_art=C.cod_art
	JOIN material AS M ON C.cod_mat=M.cod_mat
HAVING COUNT(A.descripcion)>1;

/* Consulta 15
Listar cantidad de materiales que provee cada proveedor
(código, nombre y domicilio) 
*/

SELECT 	P.cod_prov AS 'Cod',
		P.nombre AS 'Nombre de proveedor',
		P.domicilio AS 'Domicilio',
		COUNT(P.cod_prov) AS 'Cant. materiales'
FROM material AS M
	JOIN provisto_por AS PP ON M.cod_mat=PP.cod_mat
	JOIN proveedor AS P ON PP.cod_prov=P.cod_prov
GROUP BY P.cod_prov;

/* Consulta 16
Cuál es el precio máximo de los artículos que proveen los
proveedores de la ciudad de Zárate. 
*/

-- Mostrar el codigo de articulo lo puse pa q sea mas claro
SELECT A.cod_art AS 'Cod. Articulo',MAX(A.precio) AS 'Precio maximo'
FROM articulo AS A 
	JOIN compuesto_por AS CP ON A.cod_art=CP.cod_art
	JOIN material AS M ON CP.cod_mat=M.cod_mat
	JOIN provisto_por AS PP ON M.cod_mat=PP.cod_mat
	JOIN proveedor AS P ON PP.cod_prov=P.cod_prov
	JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu
WHERE C.nombre='Zarate';

/* Consulta 17
Listar los nombres de aquellos proveedores que
no proveen ningún material
*/

-- [INNER] JOIN Une una Tabla 'A' con una 'B'
-- con los registros que se corresponden
-- LEFT JOIN Trae todos los registros de la Tabla 'A'
-- tengan o no correspondencia con la Tabla 'B'
-- RIGHT JOIN Realiza lo inverso, trae todo de 'B'
-- tenga o no correspondencia con 'A'
SELECT DISTINCT P.nombre AS 'Nombre'
FROM proveedor AS P
	LEFT JOIN provisto_por AS PP ON PP.cod_prov=P.cod_prov
WHERE PP.cod_prov IS NULL;

/* Consulta 18
Listar los códigos de los materiales que provea el proveedor
10 y no los provea el proveedor 15.
*/

/* COMO CREO QUE ES LA LECTURA..
'Trame el codigo de material de la tabla 'material'
tal que ese codigo de material NO ESTE en un
registro de la tabla 'provisto_por' donde el codigo
del proveedor sea 15 y que ese codigo de material
SI ESTE en un registro de la tabla 'provisto_por'
donde el codigo de proveedor sea 10'
*/

SELECT MA.cod_mat AS 'Codigo de Material'
FROM material AS MA
WHERE MA.cod_mat NOT IN
	(
		SELECT cod_mat
		FROM provisto_por AS PP
		WHERE PP.cod_prov=15
	)
	AND MA.cod_mat IN
	(
		SELECT cod_mat
		FROM provisto_por AS PP
		WHERE PP.cod_prov=10
	);

/* Consulta 19
Listar número y nombre de almacenes que contienen los artículos
de descripción A y los de descripción B (ambos).
*/

-- *****************MI VERSION*****************

/* COMO CREO QUE ES LA LECTURA..
'Trame el numero y nombre de un almacen de la tabla 'almacen'
tal que exista 1 registro en la tabla 'articulo' donde la
descripcion de este sea 'A' y que el mismo se
encuentre en el almacen analizado (Las dos igualdades del
tercer select enlazan almacen con articulo, pudiendo ver
que articulo contiene X almacen) Y todo lo de antes pero
que la descripcion sea 'B' '
*/

SELECT AL.nro AS 'Nro Almacen', AL.nombre AS 'Nombre Almacen'
FROM almacen AS AL
WHERE EXISTS
	(
		SELECT 1
		FROM articulo AS AR
		WHERE AR.descripcion='A'
			AND EXISTS
				(
					SELECT 1
					FROM contiene AS CO
					WHERE CO.nro=AL.nro
						AND CO.cod_art=AR.cod_art
				)
	)
	AND EXISTS
	(
		SELECT 1
		FROM articulo AS AR
		WHERE AR.descripcion='B'
			AND EXISTS
				(
					SELECT 1
					FROM contiene AS CO
					WHERE CO.nro=AL.nro
						AND CO.cod_art=AR.cod_art
				)		
	);

-- ****************VERSION DE LA CLASE***************

/* COMO CREO QUE ES LA LECTURA..
'Traeme el numero y el nombre del almacen de la tabla 'almacen'
tal que exista un registro en la tabla generada por el JOIN
entre 'contiene' y 'articulo' donde un articulo tenga
por descripcion 'A' y se encuentre en el almacen analizado.
Lo mismo pero con 'B' '
*/

SELECT AL.nro AS 'Nro Almacen', AL.nombre AS 'Nombre Almacen'
FROM almacen AS AL
WHERE EXISTS
	(
		SELECT 1
		FROM contiene AS CO JOIN articulo AS AR
			ON CO.cod_art=AR.cod_art
		WHERE AL.nro=CO.nro
			AND AR.descripcion='A'
	)
	AND EXISTS
		(
			SELECT 1
			FROM contiene AS CO JOIN articulo AS AR
				ON CO.cod_art=AR.cod_art
			WHERE AL.nro=CO.nro
				AND AR.descripcion='B'			
		);


/* Consulta 20
Listar la descripción de artículos compuestos por
todos los materiales. 
*/

SELECT AR.descripcion
FROM articulo AS AR
WHERE NOT EXISTS
	(
		SELECT 1
		FROM material AS MA
		WHERE NOT EXISTS
			(
				SELECT 1
				FROM compuesto_por AS CP
				WHERE CP.cod_art=AR.cod_art
					AND CP.cod_mat=MA.cod_mat
			)
	);

/* Consulta 21
Hallar los códigos y nombres de los proveedores que proveen
al menos un material que se usa en algún artículo
cuyo precio es mayor a $100.
*/

/* COMO CREO QUE ES LA LECTURA..
'Traeme el nombre y codigo de proveedores que proveen materiales
compuestos por articulos que salen mas de 100'
*/

SELECT DISTINCT P.nombre,P.cod_prov
FROM proveedor AS P
	JOIN provisto_por AS PP ON P.cod_prov=PP.cod_prov
	JOIN material AS MA ON PP.cod_mat=MA.cod_mat
	JOIN compuesto_por AS CP ON MA.cod_mat=CP.cod_mat
	JOIN articulo AS AR ON CP.cod_art=AR.cod_art
WHERE AR.precio>100;

/* Consulta 22
Listar la descripción de los artículos de mayor precio
*/

SELECT AR.descripcion
FROM articulo AS AR
WHERE AR.precio=
	(
		SELECT MAX(AR2.precio)
		FROM articulo AS AR2
	);

/* Consulta 23
Listar los nombres de proveedores de Capital Federal
que sean únicos proveedores de algún material.
*/

SELECT DISTINCT P.nombre
FROM proveedor P
	JOIN ciudad C ON C.cod_ciu=P.cod_ciu
	JOIN provisto_por PP ON P.cod_prov=PP.cod_prov
WHERE C.nombre='Capital Federal'
	AND PP.cod_mat IN
		(
			SELECT PP.cod_mat 
			FROM provisto_por PP			
			GROUP BY PP.cod_mat
			HAVING COUNT(*)=1
		);

/* Consulta 24
Listar los nombres de almacenes que almacenan la mayor
cantidad de artículos.
*/

SELECT AL.nombre
FROM almacen AS AL
	JOIN contiene AS CO ON AL.nro=CO.nro
GROUP BY AL.nro,AL.nombre
HAVING COUNT(*)=
	(
		SELECT MAX(nroAlm.cantArt)
		FROM 
			(
				SELECT COUNT(*) AS cantArt
				FROM contiene AS CO2
				GROUP BY CO2.nro
			) AS nroAlm
	);

/* Consulta 25
Listar la ciudades donde existan proveedores que proveen
todos los materiales. 
*/

SELECT DISTINCT C.nombre
FROM proveedor AS P
	JOIN ciudad AS C ON P.cod_ciu=C.cod_ciu
WHERE NOT EXISTS
	(
		SELECT 1
		FROM material AS MA
		WHERE NOT EXISTS
			(
				SELECT 1
				FROM provisto_por AS PP
				WHERE PP.cod_prov=P.cod_prov
					AND PP.cod_mat=MA.cod_mat
			)
	);

/* Consulta 26
Listar los números de almacenes que tienen todos los artículos
que incluyen el material con código 123.
*/

SELECT AL.nro
FROM almacen AS AL
WHERE NOT EXISTS
	(
		SELECT 1
		FROM articulo AS AR
			JOIN compuesto_por AS CP ON AR.cod_art=CP.cod_art
		WHERE CP.cod_mat=123
			AND NOT EXISTS
				(
					SELECT 1
					FROM contiene AS CO
					WHERE CO.nro=AL.nro
						AND CO.cod_art=AR.cod_art
				)
	)