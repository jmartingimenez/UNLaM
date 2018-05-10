-- Borrar esto luego
USE bddDePrueba;

-- Creacion de la base de datos
DROP DATABASE clase1Biblioteca;
CREATE DATABASE clase1Biblioteca;
USE clase1Biblioteca;

-- Creacion de tablas
CREATE TABLE Provincias(
	ID_Provincia SMALLINT PRIMARY KEY,
	descripcion VARCHAR(20)
);

CREATE TABLE Localidades(
	ID_Localidad SMALLINT PRIMARY KEY,
	descripcion VARCHAR(20),
	ID_Provincia SMALLINT,
	FOREIGN KEY (ID_Provincia)
		REFERENCES Provincias (ID_Provincia) 
);

CREATE TABLE Categorias(
	ID_Categoria SMALLINT PRIMARY KEY,
	descripcion VARCHAR(20)
);

CREATE TABLE Editoriales(
	ID_Editorial SMALLINT PRIMARY KEY,
	nombre VARCHAR(20),
	direccion VARCHAR(20),
	telefono VARCHAR(15),
	ID_Localidad SMALLINT,
	FOREIGN KEY (ID_Localidad)
		REFERENCES Localidades (ID_Localidad)
);

CREATE TABLE Libros(
	ID_Libro SMALLINT PRIMARY KEY,
	titulo VARCHAR(30),
	descripcion VARCHAR(30),
	ID_Editorial SMALLINT,
	ID_Categoria SMALLINT,
	FOREIGN KEY (ID_Editorial)
		REFERENCES Editoriales (ID_Editorial),
	FOREIGN KEY (ID_Categoria)
		REFERENCES Categorias (ID_Categoria)
);

CREATE TABLE Personas(
	ID_Persona SMALLINT PRIMARY KEY,
	nombre VARCHAR(15),
	apellido VARCHAR(15),
	direccion VARCHAR(25),
	telefono VARCHAR(15),
	ID_Localidad SMALLINT,
	FOREIGN KEY (ID_Localidad)
		REFERENCES Localidades (ID_Localidad)
);

CREATE TABLE Autores(
	ID_Persona SMALLINT PRIMARY KEY,
	referencia VARCHAR(15),
	FOREIGN KEY (ID_Persona)
		REFERENCES Personas (ID_Persona)
);

CREATE TABLE Alumnos(
	ID_Persona SMALLINT PRIMARY KEY,
	anio_ingreso SMALLINT,
	anio_cursa SMALLINT,
	turno VARCHAR(15),
	division CHAR(1),
	FOREIGN KEY (ID_Persona)
		REFERENCES Personas (ID_Persona)
);

CREATE TABLE Docentes(
	ID_Persona SMALLINT PRIMARY KEY,
	anio_ingreso SMALLINT,
	titulo VARCHAR(30),
	FOREIGN KEY (ID_Persona)
		REFERENCES Personas (ID_Persona)	
);

CREATE TABLE Autores_Libros(
	ID_Persona SMALLINT,
	ID_Libro SMALLINT,
	PRIMARY KEY (ID_Persona,ID_Libro),
	FOREIGN KEY (ID_Persona)
		REFERENCES Personas (ID_Persona),
	FOREIGN KEY (ID_Libro)
		REFERENCES Libros (ID_Libro) 
);

CREATE TABLE Prestamos(
	ID_Persona SMALLINT,
	ID_Libro SMALLINT,
	fecha_prestamo DATE,
	fecha_devolucion DATE,
	PRIMARY KEY (ID_Persona,ID_Libro),
	FOREIGN KEY (ID_Persona)
		REFERENCES Personas (ID_Persona),
	FOREIGN KEY (ID_Libro)
		REFERENCES Libros (ID_Libro) 
);

-- Inserts de prueba

INSERT INTO Provincias(ID_Provincia, Descripcion)
VALUES(1,'Mendoza'),
	(2,'Buenos Aires'),
	(3,'Santa Fe'),
	(4,'Cordoba');
	
INSERT INTO Localidades(ID_Localidad,descripcion,ID_Provincia)
VALUES(1,'Laferrere',2),
		(2,'San Justo',2),
		(3,'algunaDeCordoba',4),
		(4,'algunaDeMendoza',1),
		(5,'otraDeCordoba',4),
		(6,'algunaDeSantaFe',3);

INSERT INTO Categorias(ID_Categoria,descripcion)
VALUES (1,'Categoria 1'),
		(2,'Categoria 2'),
		(3,'Categoria 3'),
		(4,'Categoria 4'),
		(5,'Categoria 5');

INSERT INTO Editoriales(ID_Editorial,nombre,direccion,telefono,
	ID_Localidad)
VALUES (1,'editorial1','calle e 22','0303456',1),
		(2,'editorial2','calle palo 11345','12444',2),
		(3,'editorial3','calle m 83','77777',3),
		(4,'editorial4','calle av agua 200','33333',3),
		(5,'editorial5','calle a 907','44444',6);	

INSERT INTO Libros(ID_Libro,titulo,descripcion,ID_Editorial,
	ID_Categoria)
VALUES(1,'Harry Potter','DESC1',2,5),
		(2,'El principito','DESC2',3,4),
		(3,'Aprendiendo SQL','DESC3',4,3),
		(4,'Mercadotecnia I','DESC4',1,2),
		(5,'Mercadotecnia II','DESC5',1,1),
		(6,'Diccionario','DESC6',1,3),
		(7,'Libro de Bolos','DESC7',5,2),
		(8,'Libro sin nombre','DESC8',4,4);
			
INSERT INTO Personas(ID_Persona,nombre,apellido,direccion,
	telefono,ID_Localidad)
VALUES(1,'Pepe','Pompin','Calle a 123','12345678',1),
		(2,'toto','Momo','Calle a 128','44557788',2),
		(3,'Juan','Matos','Calle f 13','16780009',3),
		(4,'Juan','Roma','Calle z 3000','15431991',4),
		(5,'Jose','Illo','Calle g 242','38996127',5),
		(6,'Hola','Chau','Calle l 620','55658809',6),
		(7,'Buen','Dia','Calle f 378','45678901',2),
		(8,'Aloho','Mora','Calle go 12311','44990000',1);	

INSERT INTO Autores(ID_Persona,referencia)
VALUES(1,'noSeQueEs'),(2,'noSeQueEs'),(3,'noSeQueEs'),
		(4,'noSeQueEs'),(5,'noSeQueEs'),(6,'noSeQueEs');


INSERT INTO Autores_Libros(ID_Persona,ID_Libro)
VALUES (1,1),(2,2),(3,4),(4,3),(5,6),(6,6),(8,7),(3,8),(6,5);

INSERT INTO Docentes(ID_Persona,anio_ingreso,titulo)
VALUES (4,1994,'Matematica'),
		(5,2007,'Geografia'),
		(6,2000,'Arte'),
		(8,1995,'Lengua');
		
INSERT INTO Alumnos(ID_Persona,anio_ingreso,anio_cursa,
	turno,division)
VALUES (1,2015,2016,'Maniana','A'),
		(2,2015,2017,'Tarde','B'),
		(3,2013,2014,'Noche','C');		

-- Ejercicios

/*a.Listar todas las personas que viven en Buenos Aires.
Ordenar por nombre de persona.*/

SELECT PE.nombre AS 'Nombre'
FROM Personas AS PE
	JOIN Localidades AS LO ON PE.ID_Localidad=LO.ID_Localidad
	JOIN Provincias AS PR ON LO.ID_Provincia=PR.ID_Provincia
WHERE PR.descripcion='Buenos Aires'
ORDER BY PE.nombre

/*b.Listar los libros, con sus respectivos autores
(para el caso de autor mostrar datos de persona y autor).
Ordenar por nombre de libro.*/

SELECT L.titulo AS 'Titulo',P.nombre AS 'Autor Nombre',P.apellido
	AS 'Autor Apellido'
FROM Libros AS L
	JOIN Autores_Libros AS AL ON L.ID_Libro=AL.ID_Libro
	JOIN Autores AS A ON AL.ID_Persona=A.ID_Persona
	JOIN Personas AS P ON P.ID_Persona=A.ID_Persona

/*c.Listar todas las personas (de cualquier tipo) que
viven en Buenos Aires. Mostrar solo los datos generales de
personas. Ordenar por nombre de persona.*/

SELECT PE.nombre AS 'Nombre',PE.apellido AS 'Apellido',
	PE.direccion AS 'Direccion', PE.telefono AS 'Telefono',
	LO.descripcion AS 'Localidad'
FROM Personas AS PE
	JOIN Localidades AS LO ON PE.ID_Localidad=LO.ID_Localidad
	JOIN Provincias AS PR ON LO.ID_Provincia=PR.ID_Provincia
WHERE PR.descripcion='Buenos Aires'
ORDER BY PE.nombre

/*d.Listar todas las personas y segun su tipo los datos
correspondientes (Autor, docente o alumno).
Ordenar por nombre de persona. */

