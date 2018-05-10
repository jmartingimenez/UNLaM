-- No hay DDL, solo ejercicios

/*1.Realiza una consulta que permita devolver en tres columnas
separadas el año, mes y el día de la fecha de ingreso del
empleado y el legajo.
Aclaración: La consulta debe basarse en el uso de funciones
de manejo de fechas.*/
SELECT	Legajo AS 'Número de legajo',
		YEAR(Fecha_Ingreso) AS 'Año',
		MONTH(Fecha_Ingreso) AS 'Mes',
		DAY(Fecha_Ingreso) AS 'Día'
FROM Empleado;

/*2.Realiza una consulta que devuelva el nombre y apellido
y la edad de cada empleado. 
Aclaración: La consulta debe basarse en el uso de funciones
de manejo de fechas.*/
SELECT	Nombre_Apellido,
		DATEDIFF(YEAR,Fecha_Nacimiento,getDate()) AS 'Edad'
FROM Empleado;

/*3.Realizar una consulta que devuelva el nombre y apellido 
y fecha de ingreso del empleado más antiguo de la empresa.*/
SELECT	Nombre_Apellido AS 'Nombre',
		Fecha_Ingreso AS 'Fecha de ingreso'
FROM Empleado
WHERE Fecha_Ingreso=(
	SELECT MIN(Fecha_Ingreso)
	FROM Empleado
);

/*4.Realizar una consulta que devuelva los empleados que
están asignados a algún Departamento.
Indicar legajo, nombre y apellido y descripción del
departamento al que pertenecen.*/
SELECT	E.Legajo,
		E.Nombre_Apellido AS 'Nombre y Apellido',
		D.Descripcion
FROM Empleado AS E
	JOIN Departamento AS D ON E.ID_Depto=D.ID_Depto; 

/*5.Realizar una consulta que devuelva los empleados que no
están asignados a ningún proyecto. Indicar legajo,
nombre y apellido de los empleados.*/
SELECT	E.Legajo,
		E.Nombre_Apellido AS 'Nombre y Apellido'
FROM Empleado AS E
WHERE NOT EXISTS(
	SELECT 1
	FROM Proyecto_Empleados AS PE
	WHERE E.Legajo=PE.Legajo
);			

/*6.Realizar una consulta que devuelva los empleados que
están asignados a algún proyecto. Indicar legajo, nombre
y apellido de los empleados*/
-- ESTA HECHA A MEDIAS, HAY UN TEMA CON LA TABLA 'Proyecto'
SELECT	E.Legajo,
		E.Nombre_Apellido AS 'Nombre y Apellido'
FROM Empleado AS E
	JOIN Proyecto_Empleados AS PE ON E.Legajo=Pe.Legajo;

/*7.Escribir una sentencia SQL que agregue como valor
predeterminado la fecha del día actual para el campo
Fecha_Ingreso de la tabla empleado.*/
ALTER TABLE Empleado ADD DEFAULT getDate() FOR Fecha_Ingreso;

/*8.Escribir una sentencia SQL que agregue una condición
de manera que el campo Fecha_Nacimiento de la tabla Empleado
no pueda ser anterior al 01/01/1900.*/
ALTER TABLE Empleado ADD CHECK (Fecha_Nacimiento >= '1990-01-01');

/*9.Qué diferencia existe entre las siguientes dos vistas
----a)
CREATE VIEW v_departamento
AS
SELECT * FROM Departamento
WHERE Descripcion IS NOT NULL
----b)
CREATE VIEW v_departamento
AS
SELECT * FROM Departamento
WHERE Descripcion IS NOT NULL WITH CHECK OPTION
----RTA=	La primer vista 'trae' solo las filas donde
			el campo Descripcion no esta vacio/no es nulo.
			La segunda vista actua como la primera, con la
			diferencia de que no permite insertar/alterar
			datos donde la clausula WHERE de la vista sea
			violada (ej, un insert donde el campo descripcion
			sea nulo, cosa que no se valida en la primer vista)
*/

/*10.Qué hace el siguiente código?
Dar un ejemplo de uso de lo que se está creando...

CREATE TYPE dbo.DireccionMail FROM varchar (50) NULL

RTA==Se esta creando un alias para un varchar(50) con valor
NULL por defecto

Ejemplo en creación de tabla:
	- En lugar de poner..
		'correo_electronico VARCHAR(50) NULL'
	- Se puede poner..
		'correo_electronico DireccionMail'	
*/





