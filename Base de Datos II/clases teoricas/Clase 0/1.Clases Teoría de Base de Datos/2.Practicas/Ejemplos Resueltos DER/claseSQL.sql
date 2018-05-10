/* Creación de Tablas*/

CREATE TABLE Autor ( 
	Id INT NOT NULL,
	datosAutor VARCHAR(50))
;

CREATE TABLE CategoriaLibro ( 
	Id INT NOT NULL,
	datosCatLibro VARCHAR(50)
)
;

CREATE TABLE Editorial ( 
	Id INT NOT NULL,
	datosEditorial VARCHAR(50),
	idLocalidad INT NOT NULL
)
;

CREATE TABLE Libro ( 
	Id INT NOT NULL,
	datosLibro VARCHAR(50),
	idCategoriaLibro INT NOT NULL,
	idEditorial INT NOT NULL
)
;

CREATE TABLE Libro_Autor ( 
	idLibro INT NOT NULL,
	idAutor INT NOT NULL
)
;


CREATE TABLE Localidad ( 
	Id INT NOT NULL,
	datosLocalidad VARCHAR(50),
	idProvincia INT NOT NULL
)
;

CREATE TABLE Cliente ( 
	Id INT NOT NULL,
	datosCliente VARCHAR(50),
	idLocalidad INT NOT NULL
)
;

CREATE TABLE Provincia ( 
	Id INT NOT NULL,
	datosProvincia VARCHAR(50)
)
;

CREATE TABLE Prestamos ( 
	idLibro INT NOT NULL,
	idCliente INT NOT NULL,
	FechaPrestamos DATETIME,
	FechaDevolucion DATETIME
)
;

/*Creación de PK */
ALTER TABLE Autor ADD CONSTRAINT PK_Autor
	PRIMARY KEY (Id)
;

ALTER TABLE CategoriaLibro ADD CONSTRAINT PK_CategoriaLibro
	PRIMARY KEY (Id)
;


ALTER TABLE Editorial ADD CONSTRAINT PK_Editorial 
	PRIMARY KEY (Id)
;

ALTER TABLE Libro ADD CONSTRAINT PK_Libro 
	PRIMARY KEY (Id)
;

ALTER TABLE Libro_Autor ADD CONSTRAINT PK_Libro_Autor 
	PRIMARY KEY (idLibro, idAutor)
;

ALTER TABLE Localidad ADD CONSTRAINT PK_Localidad 
	PRIMARY KEY (Id)
;

ALTER TABLE Cliente ADD CONSTRAINT PK_Cliente 
	PRIMARY KEY (Id)
;

ALTER TABLE Provincia ADD CONSTRAINT PK_Provincia 
	PRIMARY KEY (Id)
;

ALTER TABLE Prestamos ADD CONSTRAINT PK_Prestamos
	PRIMARY KEY (idLibro,	idCliente);

ALTER TABLE Editorial ADD CONSTRAINT FK_Editorial_Localidad 
	FOREIGN KEY (idLocalidad) REFERENCES Localidad (Id)
;

ALTER TABLE Libro ADD CONSTRAINT FK_Libro_CategoriaLibro 
	FOREIGN KEY (idCategoriaLibro) REFERENCES CategoriaLibro (Id)
;

ALTER TABLE Libro ADD CONSTRAINT FK_Libro_Editorial 
	FOREIGN KEY (idEditorial) REFERENCES Editorial (Id)
;

ALTER TABLE Libro_Autor ADD CONSTRAINT FK_Libro_Autor_Autor 
	FOREIGN KEY (idAutor) REFERENCES Autor (Id)
;

ALTER TABLE Libro_Autor ADD CONSTRAINT FK_Libro_Autor_Libro 
	FOREIGN KEY (idLibro) REFERENCES Libro (Id)
;

ALTER TABLE Localidad ADD CONSTRAINT FK_Localidad_Provincia 
	FOREIGN KEY (idProvincia) REFERENCES Provincia (Id)
;

ALTER TABLE Cliente ADD CONSTRAINT FK_Cliente_Localidad 
	FOREIGN KEY (idLocalidad) REFERENCES Localidad (Id)
;

ALTER TABLE Prestamos ADD CONSTRAINT PK_Prestamos_Libro
FOREIGN KEY (idLibro) REFERENCES Libro (Id)
;

ALTER TABLE Prestamos ADD CONSTRAINT PK_Prestamos_Cliente
FOREIGN KEY (idCliente) REFERENCES Cliente (Id)
;


/* Crear con sentencia todo en uno */

CREATE TABLE TablaA ( 
	Id INT NOT NULL CONSTRAINT  PK_TablaA PRIMARY KEY,
	datosA VARCHAR(50)
);

CREATE TABLE TablaB ( 
	Id INT NOT NULL CONSTRAINT  PK_TablaB PRIMARY KEY,
	datosB VARCHAR(50),
	IdA INT NOT NULL  CONSTRAINT FK_TablaA_TablaB FOREIGN KEY 
							REFERENCES TablaA (Id)
)
;