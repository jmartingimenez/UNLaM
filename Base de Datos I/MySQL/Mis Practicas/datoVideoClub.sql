-- Datos
INSERT INTO Especialidad(cod_esp,descripcion)
VALUES (1,'Gerente'),(2,'Operario');

INSERT INTO Area(cod_area,descripcion)
VALUES (1,'A1'),(2,'A2');

INSERT INTO Empleado(nro,nombre,cod_esp,nro_jefe,sueldo,f_ingreso)
VALUES				(1,'N1',1,NULL,10000,'2012-07-01'),
					(2,'N2',2,1,2000,'2013-10-01'),
					(3,'N3',2,1,1000,'2015-07-03');

INSERT INTO Trabaja(nro_emp,cod_area)
VALUES	(1,1),
		(1,2),
		(2,1),
		(3,2);