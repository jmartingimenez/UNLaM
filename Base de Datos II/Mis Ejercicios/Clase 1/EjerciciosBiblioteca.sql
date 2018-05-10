/*
a.Listar todas las personas que viven en Buenos Aires.
Ordenar por nombre de persona.
*/
USE clase1Biblioteca;

SELECT *
FROM Personas AS PE
JOIN Localidades AS LO ON PE.ID_Localidad=LO.ID_Localidad
JOIN Provincias AS PR ON LO.ID_Provincia=PR.ID_Provincia
WHERE PR.descripcion='Buenos Aires'
ORDER BY PE.nombre
