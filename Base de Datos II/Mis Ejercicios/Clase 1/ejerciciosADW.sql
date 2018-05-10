USE AdventureWorks_Data;

/*1.Listar los códigos y descripciones de todos los productos*/
SELECT P.ProductID AS 'Cod Producto',
	D.Description AS 'Descripcion'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID;

/*2.Listar los datos de la subcategoría número 17*/
SELECT *
FROM Production.ProductSubcategory
WHERE ProductSubcategoryID=17;

/*3.Listar los productos cuya descripción comience con D*/
SELECT P.Name AS 'Nombre'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID
WHERE D.Description LIKE 'D%';	

/*4.Listar las descripciones de los productos cuyo
número finalice con 8
ASUMO QUE EL NUMERO ES DE 'ProductNumber'*/
SELECT D.Description AS 'Descripcion'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID
WHERE P.ProductNumber LIKE '%8';

/*5.Listar aquellos productos que posean un color asignado.
Se deberán excluir todos aquellos que no posean ningún valor*/
SELECT *
FROM Production.Product
WHERE Color IS NOT NULL;

/*6.Listar el código y descripción de los productos de color Black
(Negro) y que posean el nivel de stock en 500.*/
SELECT P.ProductID AS 'ID',D.Description AS 'Descripcion'
FROM Production.Product AS P	
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID
WHERE P.Color='Black'
	AND P.SafetyStockLevel=500;	

/*7.Listar los productos que sean de color Black (Negro)
ó Silver (Plateado)*/
SELECT *
FROM Production.Product
WHERE Color='Black'
	OR Color='Silver';

/*8.Listar los diferentes colores que posean asignados
los productos. Sólo se deben listar los colores*/
SELECT DISTINCT Color
FROM Production.Product
WHERE Color IS NOT NULL;	

/*9.Contar la cantidad de categorías que se encuentren
cargadas en la base.*/
SELECT COUNT(*) AS 'Categorias'
FROM Production.ProductCategory;	

/*10.Contar la cantidad de subcategorías que posee
asignada la categoría 2.*/
SELECT COUNT(*) AS 'Subcategorias de la Categoria 2'
FROM Production.ProductSubcategory
WHERE ProductCategoryID=2;

/*11.Listar la cantidad de productos que existan por cada
uno de los colores*/
SELECT Color, COUNT(*) AS 'Cantidad de productos'
FROM Production.Product
WHERE Color IS NOT NULL
GROUP BY Color;

/*12.Sumar todos los niveles de stocks aceptables que
deben existir para los productos con color Black*/
SELECT SUM(SafetyStockLevel) AS 'Suma de Stocks de color negro'
FROM Production.Product
WHERE Color='Black';

/*13.Calcular el promedio de stock que se debe tener de todos
los productos cuyo código se encuentre entre el 316 y 320.*/
SELECT AVG(SafetyStockLevel) AS 'Promedio de Stock'
FROM Production.Product
WHERE ProductID BETWEEN 316 AND 320;

/*14.Listar el nombre del producto y descripción de la
subcategoría que posea asignada.*/
SELECT P.Name AS 'Producto',S.Name AS 'SubCategoria'
FROM Production.Product AS P
	JOIN Production.ProductSubcategory AS S 
	ON P.ProductID=S.ProductCategoryID;
	
/*15.Listar todas las categorías que poseen asignado al menos
una subcategoría. Se deberán excluir aquellas que no posean
ninguna.*/	
SELECT C.Name AS 'Categoria'
FROM Production.ProductCategory AS C
WHERE EXISTS
	(
		SELECT 1
		FROM Production.ProductSubcategory AS S
		WHERE C.ProductCategoryID=S.ProductCategoryID
	);
/*16.Listar el código y descripción de los productos que posean
fotos asignadas*/
SELECT P.ProductID AS 'Cod Producto',
	D.Description AS 'Descripcion'
FROM Production.Product AS P
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID
WHERE EXISTS
	(
		SELECT 1
		FROM Production.ProductProductPhoto AS PF
		WHERE P.ProductID=PF.ProductID
	);	

/*17.Listar la cantidad de productos que existan por cada
una de las Clases*/
SELECT Class AS 'Clase',COUNT(*) AS 'Productos'
FROM Production.Product
WHERE Class IS NOT NULL
GROUP BY Class;

/*18.Listar la descripción de los productos y su respectivo color.
Sólo nos interesa caracterizar al color con los
valores: Black, Silver u Otro. 
Por lo cual si no es ni silver ni black se debe indicar Otro.*/
SELECT D.Description AS 'Descripcion',CASE P.Color
	WHEN 'Black' THEN 'Black'
	WHEN 'Silver' THEN 'Silver'
	ELSE 'Otro'	
END AS 'Color'
FROM Production.ProductDescription AS D
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON D.ProductDescriptionID=MDC.ProductDescriptionID
	JOIN Production.ProductModel AS M
	ON MDC.ProductModelID=M.ProductModelID
	JOIN Production.Product AS P
	ON M.ProductModelID=P.ProductModelID
GROUP BY D.Description,P.Color;	

/*19.Listar el nombre de la categoría, el nombre de la subcategoría
y la descripción del producto*/
SELECT C.Name AS 'Categoria',
	S.Name AS 'SubCategoria',
	D.Description AS 'Descripcion'
FROM Production.ProductCategory AS C
	JOIN Production.ProductSubcategory AS S
	ON C.ProductCategoryID=S.ProductCategoryID
	JOIN Production.Product	AS P
	ON S.ProductCategoryID=P.ProductSubcategoryID		
	JOIN Production.ProductModel AS M
	ON P.ProductModelID=M.ProductModelID
	JOIN Production.ProductModelProductDescriptionCulture AS MDC
	ON M.ProductModelID=MDC.ProductModelID
	JOIN Production.ProductDescription AS D
	ON MDC.ProductDescriptionID=D.ProductDescriptionID;		

/*20.Listar la cantidad de subcategorías que posean asignado
los productos.*/

SELECT COUNT(DISTINCT ProductSubcategoryID) AS 'SubCategorias'
FROM Production.Product
WHERE ProductSubcategoryID IS NOT NULL;