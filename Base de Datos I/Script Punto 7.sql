-- ----------------------------------------------------------------------------------------------------------- --
-- PUNTO 7: Obtener el veterinario que ha realizado la mayor cantidad de asistencias (atenciones de mascotas). --
-- ----------------------------------------------------------------------------------------------------------- --
SELECT nombre_vet as NOMBRE, apellido_vet as APELLIDO, max(visita) as CANTIDAD_DE_ASISTENCIAS FROM(SELECT count(dni_vet) as visita FROM visita GROUP BY dni_vet) as tabla, visita, veterinario;