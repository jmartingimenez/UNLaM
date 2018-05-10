-- Consultas

/* Consulta 1
Listar el nombre de todos los empleados
*/

SELECT E.nombre
FROM Empleado AS E;

/* Consulta 2
Listar nombre y numero de todos los empleados
*/

SELECT E.nombre,E.nro
FROM Empleado AS E;

/* Consulta 3
Mostrar los datos de todos los empleados
*/

SELECT *
FROM Empleado;

/* Consulta 4
Indicar nombre de empleados ordenados por sueldo
*/

SELECT E.nombre
FROM Empleado AS E
ORDER BY E.sueldo;

/* Consulta 5
Listar nombre de empleados ordenados por sueldo y para mismo
sueldo, por antiguedad mostrando los mas nuevos primero
*/

SELECT E.nombre
FROM Empleado AS E
ORDER BY E.sueldo,E.F_ingreso DESC;

/* Consulta 6
Indicar nombre de empleados con sueldo mayor a $2000
*/

SELECT E.nombre
FROM Empleado AS E
WHERE E.sueldo>2000;

/* Consulta 7
¿Cual es el nombre y fecha de ingreso de los empleados que
ganan $5000 o menos cuyo nombre es N2?
*/

SELECT E.nombre,E.f_ingreso
FROM Empleado AS E
WHERE (E.nombre='N2')
	AND (E.sueldo <= 5000);

/* Consulta 8
Indicar nombre de aquellos empleados que ingresaron en el año 2012
*/

SELECT E.nombre
FROM Empleado AS E
WHERE (E.f_ingreso >= '2012-01-01' AND E.f_ingreso <= '2012-12-31');

/* Consulta 9
¿Cual es el nombre de los empleados sin jefe?
*/

SELECT E.nombre
FROM Empleado AS E
WHERE E.nro_jefe IS NULL;

/* Consulta 10
Listar numero y nombre de empleados que comienzan con la letra 'A'
*/

SELECT E.nro,E.nombre
FROM Empleado AS E
WHERE E.nombre LIKE 'A%';

/* Consulta 11
Indique nombre y sueldo de empleados de numero 1,2,5,7 y 9
*/

SELECT E.nombre,E.sueldo
FROM Empleado AS E
WHERE E.nro IN (1,2,5,7,9);

/* Consulta 12
Listar el numero de empleados que son jefe (La ID)
*/

SELECT DISTINCT E.nro_jefe
FROM Empleado AS E
WHERE E.nro_jefe IS NOT NULL;

/* Consulta 13
Indique nombre y descripcion de especialidad de todos los empleados
*/

SELECT EM.nombre,ES.descripcion
FROM Empleado AS EM
	JOIN Especialidad AS ES ON EM.cod_esp=ES.cod_esp;

/* Consulta 14
Listar el nombre de empleados que trabajan en el area de codigo 1
*/

SELECT E.nombre
FROM Empleado AS E
	JOIN Trabaja AS T ON E.nro=T.nro_emp
WHERE T.cod_area=1;

/* Consulta 15
Listar nombre y descripcion de especialidad de empleados que
trabajan en el area llamada 'A1' y cobran mas de $2000
*/

SELECT DISTINCT EM.nombre,ES.descripcion
FROM Empleado AS EM
	JOIN Especialidad AS ES ON EM.cod_esp=ES.cod_esp
	JOIN Trabaja AS TR ON EM.nro=TR.nro_emp
	JOIN Area AS AR ON TR.cod_area=AR.cod_area
WHERE (AR.descripcion='A1')
	AND EM.sueldo>2000;

/* Consulta 16
Indique nombre, sueldo y descripcion de especialidad de
empleados que trabajan en areas que contienen la palabra
'Ventas', cobran mas de $2000, ingresaron en enero del 2013
y tienen jefe
*/

SELECT DISTINCT EM.nombre,EM.sueldo,ES.descripcion
FROM Empleado AS EM
	JOIN Especialidad AS ES ON EM.cod_esp=ES.cod_esp
	JOIN Trabaja AS TR ON EM.nro=TR.nro_emp
	JOIN Area AS AR ON TR.cod_area=AR.cod_area
WHERE (EM.sueldo>2000)
	AND (EM.f_ingreso >= '2013-01-01' AND EM.f_ingreso <= '2013-01-31')
	AND (EM.nro_jefe IS NOT NULL)
	AND AR.descripcion LIKE '%Ventas%';

/* Consulta 17
Listar el nombre de todos los empleados junto al de su jefe
*/

SELECT E.nombre AS Empleado,J.nombre AS Jefe
FROM Empleado AS E
	JOIN Empleado AS J ON E.nro_jefe=J.nro;

/* Consulta 18
Listar nombre y sueldo de empleados que trabajan en las areas
'A1', 'A2' o 'A3' y cuyo jefe se llama 'Juan', y tiene la
especialidad 'Contador'
*/

SELECT EM.nombre,EM.sueldo
FROM Empleado AS EM
	JOIN Empleado AS JE ON EM.nro_jefe=JE.nro
	JOIN Especialidad AS ES ON JE.cod_esp=ES.cod_esp
	JOIN Trabaja AS TR ON EM.nro=TR.nro_emp
	JOIN Area AS AR ON TR.cod_area=AR.cod_area
WHERE (JE.nombre='Juan')
	AND (ES.descripcion='Contador')
	AND AR.descripcion IN ('A1','A2','A3');

/* Consulta 19
Mostrar nombre de los empleados que ganan mas que sus jefes
*/

SELECT E.nombre
FROM Empleado AS E
	JOIN Empleado AS J ON E.nro_jefe=J.nro
WHERE E.sueldo > J.sueldo;

/* Consulta 20
Indicar la cantidad de empleados de la compañía
*/

SELECT COUNT(*)
FROM Empleado;

/* Consulta 21
Indicar cantidad de empleados y sueldo maximo
*/

SELECT COUNT(*) AS 'Cantidad de empleados',MAX(sueldo) AS 'Sueldo maximo'
FROM Empleado AS E;

/* Consulta 22
¿Cuantos empleados ganan mas de $2000?
*/

SELECT COUNT(*)
FROM Empleado AS EM
WHERE EM.sueldo>2000;

/* Consulta 23
Contar cantidad de empleados por codigo de area
*/

SELECT T.cod_area,COUNT(*)
FROM Trabaja AS T
GROUP BY T.cod_area;

/* Consulta 24
Contar cantidad de empleados por codigo de area que tienen sueldos
promedios menores a 5000
*/

SELECT T.cod_area,COUNT(*)
FROM Trabaja AS T
	JOIN Empleado AS E ON T.nro_emp=E.nro
GROUP BY T.cod_area
HAVING AVG(E.sueldo)<5000;

/* Consulta 25
Mostrar nombre de los jefes y cantidad de empleados a su cargo
*/

SELECT JE.nombre,COUNT(*)
FROM Empleado AS JE
	JOIN Empleado AS EM ON JE.nro=EM.nro_jefe
GROUP BY JE.nro,JE.nombre;

/* Consulta 26
Mostrar nombre de los jefes y cantidad de empleados a su cargo.
Solo considerando jefes de especialidad 'Gerente' que tengan
mas de 5 empleados a su cargo
*/

SELECT JE.nombre,COUNT(*)
FROM Empleado AS JE
	JOIN Empleado AS EM ON JE.nro=EM.nro_jefe
	JOIN Especialidad AS ES ON JE.cod_esp=ES.cod_esp
WHERE ES.descripcion='Gerente'
GROUP BY JE.nro,JE.nombre
HAVING COUNT(*) > 5;

/* Consulta 27
¿Cuantos jefes hay?
*/

SELECT COUNT(DISTINCT nro_jefe)
FROM Empleado 
WHERE nro_jefe IS NOT NULL;

/* Consulta 28
Listar nombre y sueldo de empleados que trabajan en dos o mas areas
*/

SELECT E.nombre,E.sueldo
FROM Empleado AS E
	JOIN Trabaja AS T ON E.nro=T.nro_emp
GROUP BY E.nro
HAVING COUNT(*) >= 2;

/* Consulta 29
Listar nombres de empleados que trabajan en algun area que comienza
con A
*/

SELECT E.nombre
FROM Empleado AS E
WHERE EXISTS
	(
		SELECT 1
		FROM Trabaja AS T
			JOIN Area AS A ON T.cod_area=A.cod_area
		WHERE A.descripcion LIKE 'A%'
			AND T.nro_emp=E.nro
	);

/* Consulta 30
¿Cual es el nombre y sueldo de los empleados que ganan el sueldo maximo?
*/

SELECT E1.nombre,E1.sueldo
FROM Empleado AS E1
WHERE E1.sueldo=
	(
		SELECT MAX(E2.sueldo)
		FROM Empleado AS E2
	);

/* Consulta 31
Indicar la descripcion de areas sin empleados asignados
*/

SELECT A.descripcion
FROM Area AS A
	LEFT JOIN Trabaja AS T ON A.cod_area=T.cod_area
WHERE T.nro_emp IS NULL;

SELECT A.descripcion
FROM Area AS A
WHERE NOT EXISTS
	(
		SELECT 1
		FROM Trabaja AS T
		WHERE A.cod_area=T.cod_area
	);

/* Consulta 32
Mostrar el nombre de los empleados que trabajan en todas las areas
*/

SELECT E.nombre
FROM Empleado AS E
WHERE NOT EXISTS
	(
		SELECT 1
		FROM Area AS A
		WHERE NOT EXISTS
			(
				SELECT 1
				FROM Trabaja AS T
				WHERE (T.nro_emp=E.nro AND T.cod_area=A.cod_area)
			)
	);

/* Consulta 33
Mostrar nombre de empleados que trabajan en todas las areas que terminan
con 'S'
*/
-- El LIKE parece no funcionar, pero esta bien ubicado
SELECT E.nombre
FROM Empleado AS E
WHERE NOT EXISTS
	(
		SELECT 1
		FROM Area AS A
		WHERE A.descripcion LIKE '%s'
			AND NOT EXISTS
				(
					SELECT 1
					FROM Trabaja AS T
					WHERE T.nro_emp=E.nro 
						AND T.cod_area=A.cod_area
				)
	);

