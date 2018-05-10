USE AdventureWorks_Data

/*1.Listar los nombres de los productos y el nombre del
modelo que posee asignado. Solo listar aquellos
que tengan asignado algún modelo.*/
SELECT P.Name AS 'Producto',M.Name AS 'Modelo'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID;

/*2.Mostrar “todos” los productos junto con el modelo
que tenga asignado. En el caso que no tenga asignado
ningún modelo, mostrar su nulidad.*/
SELECT P.Name AS 'Producto',M.Name AS 'Modelo'
FROM Production.Product AS P
	LEFT JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID;

/*3.Ídem Ejercicio2, pero en lugar de mostrar nulidad,
mostrar la palabra “Sin Modelo” para indicar
que el producto no posee un modelo asignado.*/
SELECT P.Name AS 'Producto',
CASE 
	WHEN M.Name IS NULL THEN 'Sin Modelo' ELSE M.Name
END AS 'Modelo'
FROM Production.Product AS P
	LEFT JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID;

/*4.Contar la cantidad de Productos que poseen
asignado cada uno de los modelos.*/
SELECT ProductModelID AS 'ID Modelo',COUNT(*) AS 'Cant Productos'
FROM Production.Product
GROUP BY ProductModelID;

/*5.Contar la cantidad de Productos que poseen asignado
cada uno de los modelos, pero mostrar solo aquellos
modelos que posean asignados 2 o más productos.*/
SELECT ProductModelID AS 'ID Modelo',COUNT(*) AS 'Cant Productos'
FROM Production.Product
GROUP BY ProductModelID
HAVING COUNT(*)>2;

/*6.Contar la cantidad de Productos que poseen
asignado un modelo valido, es decir, que se encuentre
cargado en la tabla de modelos. Realizar este ejercicio
de 3 formas posibles: “exists” / “in” / “inner join”.*/

-- EXISTS
SELECT P.ProductModelID AS 'ID Modelo',COUNT(*) AS 'Cant Productos'
FROM Production.Product AS P
WHERE EXISTS
	(
		SELECT 1
		FROM Production.ProductModel AS M
		WHERE P.ProductModelID=M.ProductModelID
	)
GROUP BY P.ProductModelID;

-- IN
SELECT P.ProductModelID AS 'ID Modelo',COUNT(*) AS 'Cant Productos'
FROM Production.Product AS P
WHERE P.ProductModelID IN
	(
		SELECT M.ProductModelID
		FROM Production.ProductModel AS M
	)
GROUP BY P.ProductModelID;	

--JOIN
SELECT P.ProductModelID AS 'ID Modelo',COUNT(*) AS 'Cant Productos'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
GROUP BY P.ProductModelID;	

/*7.Contar cuantos productos poseen asignado cada uno
de los modelos, es decir, se quiere visualizar el nombre
del modelo y la cantidad de productos asignados.
Si algún modelo no posee asignado ningún producto,
se quiere visualizar 0 (cero).*/
-- NO ENTENDI BIEN ESTE, TODOS LOS MODELOS TIENEN ALGUN PRODUCTO
-- SEGUN ME DA (O LO ESTOY PENSANDO MAL DE ENTRADA)
SELECT M.Name AS 'Modelo',
CASE
	WHEN COUNT(*)IS NULL THEN '0' ELSE COUNT(*)
END AS 'Cant Productos'
FROM Production.Product AS P
	RIGHT JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
GROUP BY M.Name;

/*8.Se quiere visualizar, el nombre del producto, el nombre
modelo que posee asignado, la ilustración que posee asignada
y la fecha de ultima modificación de dicha ilustración
y el diagrama que tiene asignado la ilustración.
Solo nos interesan los productos que cuesten mas de $150
y que posean algún color asignado.
==PARA EL PRECIO NO SABIA SI USAR 'StandardCost' O 'ListPrice'.
==USE EL PRECIO ESTANDAR*/
SELECT P.Name AS 'Nombre de Producto',
	M.Name AS 'Nombre de Modelo',
	I.IllustrationID AS 'ID de Ilustracion',
	I.ModifiedDate AS 'Fecha de modificacion',
	I.Diagram AS 'Diagrama de Ilustracion'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelIllustration AS MI
	ON M.ProductModelID=MI.ProductModelID
	JOIN Production.Illustration AS I
	ON MI.IllustrationID=I.IllustrationID
WHERE P.StandardCost>150
	AND P.Color IS NOT NULL;

/*9.Mostrar aquellas culturas que no están asignadas a ningún
producto/modelo.
(Production.ProductModelProductDescriptionCulture)
==SI SE CORRIO EL PUNTO 18 ANTES NO DEBERIA SALIR NADA*/
SELECT Name AS 'Cultura' 
FROM Production.Culture
WHERE CultureID NOT IN(
	SELECT CultureID
	FROM Production.ProductModelProductDescriptionCulture
);

/*10.Agregar a la base de datos el tipo de contacto
“Ejecutivo de Cuentas” (Person.ContactType)*/
INSERT INTO Person.ContactType(Name)
VALUES('Ejecutivo de Cuentas');

/*11.Agregar la cultura llamada “nn” – “Cultura Moderna”.*/
INSERT INTO Production.Culture(CultureID,Name)
VALUES ('nn','Cultura Moderna');

/*12.Cambiar la fecha de modificación de las culturas
Spanish, French y Thai para indicar que fueron modificadas
hoy.*/
UPDATE Production.Culture
SET ModifiedDate=DEFAULT
WHERE Name IN ('Spanish','French','Thai');

/*13.En la tabla Production.CultureHis agregar todas
las culturas que fueron modificadas hoy. (Insert/Select).

RTA= No tengo esta tabla, y si la tabla era Production.Culture
ya estan, no entiendo bien la consigna
*/

/*14.Al contacto con ID 10 colocarle como nombre “Juan Perez”.*/
UPDATE Person.Contact
SET FirstName='Juan',LastName='Perez'
WHERE ContactID=10;

/*15.Agregar la moneda “Peso Argentino” con el código “PAR”
(Sales.Currency)*/
INSERT INTO Sales.Currency(CurrencyCode,Name)
VALUES ('PAR','Peso Argentino');

/*16.¿Qué sucede si tratamos de eliminar el código ARS
correspondiente al Peso Argentino? ¿Por qué?

RTA= No se puede ya que el codigo esta siendo utilizado
en otras tablas (Sales.CurrencyRate,Sales.CountryRegionCurrency)
*/

/*17.Realice los borrados necesarios para que nos permita
eliminar el registro de la moneda con código ARS.*/
DELETE FROM Sales.CurrencyRate
WHERE FromCurrencyCode='ARS'
	OR ToCurrencyCode='ARS';

DELETE FROM Sales.CountryRegionCurrency
WHERE CurrencyCode='ARS';

DELETE FROM Sales.Currency
WHERE CurrencyCode='ARS';

/*18.Eliminar aquellas culturas que no estén asignadas a ningún
producto (Production.ProductModelProductDescriptionCulture)*/
DELETE FROM Production.Culture
WHERE CultureID NOT IN(
	SELECT CultureID
	FROM Production.ProductModelProductDescriptionCulture
);