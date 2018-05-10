DROP DATABASE IF EXISTS ejercicio4;
CREATE DATABASE IF NOT EXISTS ejercicio4;
USE ejercicio4;

CREATE TABLE Persona(
	nro_persona INT UNSIGNED PRIMARY KEY,
	nombre VARCHAR(15),
	calle VARCHAR(15),
	ciudad VARCHAR(15),
	nro_supervisor INT UNSIGNED,
	CONSTRAINT Supervisor_FK
	FOREIGN KEY (nro_supervisor)
		REFERENCES Persona (nro_persona)
);

CREATE TABLE Empresa(
	nro_empresa INT UNSIGNED PRIMARY KEY,
	nombre VARCHAR(15),
	calle VARCHAR(15),
	ciudad VARCHAR(15)
);

CREATE TABLE Trabaja(
	nro_persona INT UNSIGNED,
	nro_empresa INT UNSIGNED,
	salario DECIMAL,
	fecha_ingreso DATE,
	PRIMARY KEY (nro_persona,nro_empresa),
	CONSTRAINT Persona_FK
	FOREIGN KEY (nro_persona)
		REFERENCES Persona (nro_persona),
	CONSTRAINT Empresa_FK
	FOREIGN KEY (nro_empresa)
		REFERENCES Empresa (nro_empresa)
);