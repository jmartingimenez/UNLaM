USE AdventureWorks_Data;

/*1.Realizar una consulta que permita devolver la fecha
y hora actual*/
SELECT	CONVERT(date,getDate()) AS 'Fecha',
		CONVERT(time,getDate()) AS 'Hora Actual';

/*2.Realizar una consulta que permita devolver únicamente
el año y mes actual:*/
SELECT YEAR(getDate()) AS 'Año', MONTH(getDate()) AS 'Mes';

/*3.Realizar una consulta que permita saber cuántos días
faltan para el día de la primavera (21-Sep)*/
SELECT DATEDIFF(DAY,getDate(),'2017-21-09') AS 'Días para primavera';

/*4.Realizar una consulta que permita redondear el
número 385,86 con únicamente 1 decimal.*/
SELECT ROUND(385.86,1);
SELECT ROUND(CONVERT(DOUBLE PRECISION, 385.86),1);

/*5.Realizar una consulta permita saber cuánto es el mes
actual al cuadrado. Por ejemplo, si estamos
en Junio, sería 6^2*/
SELECT POWER(MONTH(getDate()),2) AS 'Mes actual al cuadrado';

/*6.Devolver cuál es el usuario que se encuentra conectado
a la base de datos*/
SELECT SYSTEM_USER AS 'Usuario actual';

/*7.Realizar una consulta que permita conocer la edad
de cada empleado (Ayuda: HumanResources.Employee)*/
SELECT EmployeeID AS 'ID de Empleado',
	DATEDIFF(YEAR,BirthDate,getDate()) AS 'Edad'
FROM HumanResources.Employee;

/*8.Realizar una consulta que retorne la longitud de
cada apellido de los Contactos, ordenados por apellido.
En el caso que se repita el apellido devolver únicamente
uno de ellos.*/
SELECT DISTINCT C.LastName AS 'Apellido',
	LEN(C.LastName) AS 'Longitud'
FROM Person.Contact AS C
ORDER BY C.LastName;

/*9.Realizar una consulta que permita encontrar el
apellido con mayor longitud*/
SELECT DISTINCT LastName AS 'Apellido'
FROM Person.Contact
WHERE LEN(LastName)=(
	SELECT MAX(LEN(LastName))
	FROM Person.Contact 
);

/*10.Realizar una consulta que devuelva los nombres y apellidos
de los contactos que hayan sido modificados en los últimos
3 años.
===LA FECHA MAXIMA DE MODIFICACION EN EL ADVENTUREWORKS QUE TRAJE
===DE CLASE DATA DEL 2005, VA A DAR CERO FILAS (CAMBIAR 3 POR 12)
*/
SELECT FirstName AS 'Nombre',LastName AS 'Apellido'
FROM Person.Contact
WHERE DATEDIFF(YEAR,ModifiedDate,getDate()) <= 3;

/*11.Se quiere obtener los emails de todos los contactos, pero
en mayúscula*/
SELECT UPPER(EmailAddress)
FROM Person.Contact;

/*12.Realizar una consulta que permita particionar el mail de
cada contacto*/
SELECT ContactID AS 'IDContacto',
	EmailAddress AS 'Email',
	LEFT(EmailAddress,PATINDEX('%@%',EmailAddress) -1) AS 'Nombre',
	SUBSTRING(EmailAddress,PATINDEX('%@%',EmailAddress) +1,
		LEN(EmailAddress)) AS 'Dominio'
FROM Person.Contact;

SELECT ContactID AS 'IDContacto',
	EmailAddress AS 'Email',
	LEFT(EmailAddress,PATINDEX('%@%',EmailAddress) -1) AS 'Nombre',
	RIGHT(EmailAddress,PATINDEX('%@%',REVERSE(EmailAddress)) -1) AS 'Dominio'
FROM Person.Contact;

/*13.Devolver los últimos 3 dígitos del NationalIDNumber
de cada empleado*/
SELECT RIGHT(NationalIDNumber,3) AS 'NationalIDNumber - 3 ult'
FROM HumanResources.Employee;

/*14.Se desea enmascarar el NationalIDNumber de cada empleado,
de la siguiente forma ###-####-##*/
SELECT NationalIDNumber AS 'Telefono',
	CASE LEN(NationalIDNumber) WHEN 9 
		THEN
			SUBSTRING(NationalIDNumber,1,3) + '-' +
			SUBSTRING(NationalIDNumber,4,4) + '-' +
			SUBSTRING(NationalIDNumber,8,2)
		ELSE
			SUBSTRING(NationalIDNumber,1,3) + '-' +
			SUBSTRING(NationalIDNumber,4,LEN(NationalIDNumber))	
	END	AS 'Enmascarado' 
FROM HumanResources.Employee;	

/*15.Listar la dirección de cada empleado “supervisor” que
haya nacido hace más de 30 años. Listar todos los datos
en mayúscula. Los datos a visualizar son: nombre y apellido
del empleado, dirección y ciudad*/
SELECT	UPPER(P.FirstName) AS 'Nombre',
		UPPER(P.LastName) AS 'Apellido',
		UPPER(A.AddressLine1) AS 'Direccion',
		UPPER(A.City) AS 'Ciudad'
FROM HumanResources.Employee AS E
	JOIN Person.Contact AS P 
	ON P.ContactID=E.ContactID
	JOIN HumanResources.EmployeeAddress AS EA
	ON E.EmployeeID=EA.EmployeeID
	JOIN Person.Address AS A
	ON EA.AddressID=A.AddressID
WHERE E.EmployeeID IN(
	SELECT ManagerID
	FROM HumanResources.Employee)
	AND DATEDIFF(YEAR,E.BirthDate,getDate()) > 30;
	
/*16.Listar la cantidad de empleados hombres y mujeres*/
SELECT CASE Gender 
	WHEN 'M' THEN 'Masculino' ELSE 'Femenino'
	END AS 'Sexo',
	COUNT(*) AS 'Cantidad'
FROM HumanResources.Employee
GROUP BY Gender;

/*17.Categorizar a los empleados según la cantidad de horas
de vacaciones, según el siguiente formato:
Alto = más de 50 / medio= entre 20 y 50 / bajo = menos de 20*/
SELECT	C.FirstName + ' ' + C.LastName AS 'Nombre',
		CASE 
			WHEN E.VacationHours > 50 THEN 'Alto'
			WHEN E.VacationHours < 20 THEN 'Bajo'
				ELSE 'Medio' 
		END AS 'Horas'
FROM HumanResources.Employee AS E
	JOIN Person.Contact AS C
	ON E.ContactID=C.ContactID;