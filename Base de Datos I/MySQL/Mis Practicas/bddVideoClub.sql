-- Base de datos
DROP DATABASE IF EXISTS videoclub;
CREATE DATABASE IF NOT EXISTS videoclub;
USE videoclub;

CREATE TABLE Especialidad(
	cod_esp INT PRIMARY KEY,
	descripcion VARCHAR(15)
);

CREATE TABLE Area(
	cod_area INT PRIMARY KEY,
	descripcion VARCHAR(15)
);

CREATE TABLE Empleado(
	nro INT PRIMARY KEY,
	nombre VARCHAR(15),
	cod_esp INT,
	nro_jefe INT,
	sueldo DECIMAL,
	f_ingreso DATE,
	FOREIGN KEY (cod_esp)
		REFERENCES Especialidad (cod_esp),
	FOREIGN KEY (nro_jefe)
		REFERENCES Empleado (nro)
);

CREATE TABLE Trabaja(
	nro_emp INT,
	cod_area INT,
	PRIMARY KEY (nro_emp,cod_area),
	FOREIGN KEY (nro_emp)
		REFERENCES Empleado (nro),
	FOREIGN KEY (cod_area)
		REFERENCES Area (cod_area)
);