/*Alumno: Gimenez Jonatan (Turno noche)

---NO TENGO LOS EJERCICIOS, PERO EL PARCIAL MAS O MENOS CONSISTIA EN LAS SIGUIENTES PARTES...

PRIMERO: CREAR UNA BASE DE DATOS LLAMADA 'Alumnos Unlam' DESDE EL WIZARD DEL MANAGMENT STUDIO

SEGUNDO: UN ENUNCIADO EN EL QUE EN BASE A EL MISMO TENIAS QUE CREAR LAS TABLAS (NO PEDIA EL DER)

TERCERO (b,c): ALTERAR LA BASE PARA AGREGAR RESTRICCIONES

CUARTO (d): AGREGAR LOS INSERTS NECESARIOS PARA PODER PROBAR LAS 4 CONSULTAS SIGUIENTES

QUINTO (e): RESOLVER 4 CONSULTAS (LOS ENUNCIADOS DE ESTAS QUE PUSE ABAJO LAS ESCRIBI MEDIO DE MEMORIA,
			QUIZAS NO ERAN EXACTAMENTE IGUALES)

NOTA: 9 (Nueve). SUPONGO QUE ME DESCONTO PUNTOS POR HABER QUITADO EL 'USE Alumnos Unlam' Y PORQUE EN
		LA RESTRICCION DE LA MAYORIA DE EDAD, EN EL CHECK HABIA PUESTO (edad > 17) EN VEZ DE (edad >= 18)

DATO: HACIA MUCHO INCAPIE EN EL USO DE CONSTRAINTS, NO OLVIDAR..		
*/

/*Creacion de la base*/
CREATE TABLE condicion(
	codigo TINYINT IDENTITY (1,1) NOT NULL,
	descripcion VARCHAR(50) NOT NULL,
	CONSTRAINT PK_codigo PRIMARY KEY (codigo)
)

CREATE TABLE alumnos(
	legajo INT IDENTITY (1,1) NOT NULL,
	tipo_doc TINYINT NOT NULL,
	num_doc INT NOT NULL,
	nombre VARCHAR(50) NOT NULL,
	apellido VARCHAR(50) NOT NULL,
	edad TINYINT NOT NULL,
	email VARCHAR(50) NOT NULL,
	condicion TINYINT NOT NULL,
	CONSTRAINT PK_legajo PRIMARY KEY (legajo),
	CONSTRAINT FK_condicion FOREIGN KEY (condicion) REFERENCES condicion (codigo)
)

CREATE TABLE cursadas(
	cod_cursada INT IDENTITY (1,1) NOT NULL,
	descripcion VARCHAR(50) NOT NULL,
	fecha_inicio DATE NOT NULL,
	fecha_fin DATE NOT NULL,
	observacion VARCHAR(50) NOT NULL,
	tipo VARCHAR(50) NOT NULL,
	CONSTRAINT PK_cod_cursada PRIMARY KEY (cod_cursada)
)

CREATE TABLE materias(
	codigo INT IDENTITY (1,1) NOT NULL,
	descripcion VARCHAR(50) NOT NULL,
	cod_cursada INT NOT NULL,
	CONSTRAINT PK_codigo_mat PRIMARY KEY (codigo),
	CONSTRAINT FK_cod_cursada FOREIGN KEY (cod_cursada) REFERENCES cursadas (cod_cursada)
)

CREATE TABLE alumno_materia(
	alumno_legajo INT,
	materia_codigo INT,
	CONSTRAINT PK_alumno_materia PRIMARY KEY (alumno_legajo,materia_codigo),
	CONSTRAINT FK_alumno FOREIGN KEY (alumno_legajo) REFERENCES alumnos (legajo),
	CONSTRAINT FK_materia FOREIGN KEY (materia_codigo) REFERENCES materias (codigo)

)

/*Punto b: Alterar la tabla alumnos para que los alumnos deban ser mayores de edad*/
ALTER TABLE alumnos ADD CONSTRAINT CH_edad CHECK (edad >= 18)

/*Punto c: Alterar la tabla alumnos para que el dni sea unico (no se tenia que normalizar esto)*/
ALTER TABLE alumnos ADD CONSTRAINT UQ_dni UNIQUE (num_doc,tipo_doc)

/*Punto d: Hacer las inserciones necesarias para poder probar las consultas del siguiente punto*/
INSERT INTO condicion (descripcion) VALUES ('Regular'),('Libre'),('Graduado');

INSERT INTO alumnos (tipo_doc,num_doc,nombre,apellido,edad,email,condicion)
VALUES	(1,11111111,'alumno1','apellido1',20,'hola@gg.com',1),
		(1,22222222,'alumno2','apellido2',25,'chau@gg.com',2),
		(1,33333333,'alumno3','apellido3',30,'user@unlam.edu.ar',3),
		(1,44444444,'alumno4','apellido4',26,'blablabla@gg.com',1);

INSERT INTO alumnos (tipo_doc,num_doc,nombre,apellido,edad,email,condicion)
VALUES	(1,55555555,'alumno5','apellido5',36,'al5@gg.com',2)

INSERT INTO cursadas (descripcion,fecha_inicio,fecha_fin,observacion,tipo)
VALUES	('cursada1','2015-03-08','2015-06-24','observacion1','cuatrimestral'),
		('cursada2','2016-01-10','2016-06-20','observacion2','cuatrimestral'),
		('cursada3','2016-01-15','2016-11-20','observacion3','cuatrimestral')

INSERT INTO cursadas (descripcion,fecha_inicio,fecha_fin,observacion,tipo)
VALUES	('cursada4','2017-03-08','2015-06-24','observacion4','cuatrimestral')

INSERT INTO materias (descripcion,cod_cursada)
VALUES	('materia1',1),
		('materia2',2),
		('materia3',3);

INSERT INTO materias (descripcion,cod_cursada)
VALUES ('materia4',4)

INSERT INTO alumno_materia(alumno_legajo,materia_codigo)
VALUES	(1,1),
		(2,2),
		(3,3),
		(4,3)

INSERT INTO alumno_materia(alumno_legajo,materia_codigo)
VALUES (2,4)

/*Punto e: Consultas*/

--1 * Mostrar por alumno, la cantidad de materias que curso/cursa desde el ultimo anio calendario
SELECT A.apellido AS 'Alumno',COUNT(*) AS 'Materias'
FROM alumnos A 
	JOIN alumno_materia AM ON A.legajo=AM.alumno_legajo
	JOIN materias M ON AM.materia_codigo=M.codigo
	JOIN cursadas C ON M.cod_cursada=C.cod_cursada	
WHERE DATEDIFF(DAY,C.fecha_inicio,GETDATE()) <= 365
GROUP BY A.apellido

--2 * Mostrar la informacion de alumnos regulares entre 20 y 30 años, inscriptos desde 2016 y que sean regulares
SELECT * 
FROM alumnos A
	JOIN condicion C ON A.condicion=C.codigo
	JOIN alumno_materia AM ON A.legajo=AM.alumno_legajo
	JOIN materias M ON AM.materia_codigo=M.codigo
	JOIN cursadas CU ON M.cod_cursada=CU.cod_cursada
WHERE (A.edad >= 20 AND A.edad <= 30)
	AND C.descripcion = 'Regular' 
	AND CU.fecha_inicio >= '2016-01-01'

--3 * Mostrar por cada condicion (regular,libre, graduado) el promedio de edad de alumnos de cada uno
SELECT C.descripcion AS 'Condicion', AVG(A.edad) AS 'Promedio de edad'
FROM alumnos A JOIN condicion C ON A.condicion=C.codigo
GROUP BY  C.codigo,C.descripcion

--4 * Mostrar nombre, apellido e email de los alumnos que no tienen en su mail el dominio de la unlam
--  * (Si bien con un LIKE basta, pedia usar funciones de manejo de cadenas)
SELECT A.nombre, A.apellido, A.email
FROM alumnos A
WHERE SUBSTRING(email,CHARINDEX('@',email) +1,LEN(email)) <> 'unlam.edu.ar'


