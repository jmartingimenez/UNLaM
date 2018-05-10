/* Consulta 1
Listar el nombre y ciudad de todas las personas que trabajan en
la   empresa “Banelco”. 
*/

SELECT P.nombre,P.ciudad
FROM Persona AS P
	JOIN Trabaja AS T ON P.nro_persona=T.nro_persona
	JOIN Empresa AS E ON T.nro_empresa=E.nro_empresa
WHERE E.nombre='Banelco';