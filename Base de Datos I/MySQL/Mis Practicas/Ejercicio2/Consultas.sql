/* Consulta 1
Hallar los números de vuelo desde el origen A
hasta el destino F.
*/

SELECT V.nro_vuelo
FROM vuelo AS V
WHERE desde='A' AND hasta='F';

/* Consulta 2
Hallar los nombres de pasajeros y números de vuelo para
aquellos pasajeros que viajan desde A a D. 
*/

SELECT V.nro_vuelo,P.nombre
FROM pasajero AS P
	JOIN vuelo AS V ON P.nro_vuelo=V.nro_vuelo
WHERE desde='A' AND hasta='D';

/* Consulta 3
Hallar los tipos de avión para vuelos que parten desde C. 
*/

SELECT DISTINCT A.tipo_avion
FROM avion AS A
	JOIN vuelo AS V ON A.nro_avion=V.nro_avion
WHERE V.desde='C';

/* Consulta 4
Listar los distintos tipo y nro. de avión que tienen
a H como destino.
*/

SELECT A.nro_avion,A.tipo_avion
FROM avion AS A
	JOIN vuelo AS V ON A.nro_avion=V.nro_avion
WHERE V.hasta='D'
GROUP BY A.nro_avion,A.tipo_avion;

/* Consulta 5
Mostrar por cada Avión (número y modelo) la cantidad de vuelos
en que se encuentra registrado.
*/

SELECT 	A.nro_avion AS 'Nro Avion',
		A.modelo_avion AS 'Modelo',
		COUNT(*) AS 'Cant Vuelos'
FROM avion AS A 
	JOIN vuelo AS V ON A.nro_avion=V.nro_avion
GROUP BY A.nro_avion,A.modelo_avion
ORDER BY COUNT(*) DESC;

/* Consulta 6
Cuántos pasajeros diferentes han volado
en un avión de modelo ‘B-­777’
*/

SELECT count(*) AS 'Usuarios B-777'
FROM pasajero AS P
	JOIN vuelo AS V ON P.nro_vuelo=V.nro_vuelo
	JOIN avion AS A ON V.nro_avion=A.nro_avion
WHERE A.modelo_avion='B-777';

/* Consulta 7
Listar la cantidad promedio de pasajeros transportados
por los aviones de la compañía, por tipo de avión. 
*/


/* Consulta 8
Hallar los tipos de avión que no son utilizados
en algún vuelo que pase por B
*/

SELECT DISTINCT A.tipo_avion AS 'Tipo Avion'
FROM avion AS A
	JOIN vuelo AS V ON A.nro_avion=V.nro_avion
WHERE V.desde <> 'B'
	AND V.hasta <> 'B';