/*Base de datos para el TP de Prog Web II - Spotify*/

DROP DATABASE IF EXISTS negrify;
CREATE DATABASE IF NOT EXISTS negrify;
USE negrify;

CREATE TABLE Privilegio( 
	id TINYINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(255) DEFAULT 'Usuario'
);

CREATE TABLE Usuario(
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(255) UNIQUE NOT NULL,
    contrasenia VARCHAR(255) NOT NULL,
    mail VARCHAR(255) UNIQUE NOT NULL,
    fecha_registro TIMESTAMP NOT NULL,
    fecha_modificado TIMESTAMP NOT NULL,
    cod_activacion VARCHAR(255) NOT NULL,
    ban BOOLEAN DEFAULT FALSE NOT NULL,
    pais VARCHAR(255) NOT NULL,
    pais_coordenada VARCHAR(255) NOT NULL,
	privilegio_id TINYINT UNSIGNED NOT NULL,
	FOREIGN KEY (privilegio_id)
		REFERENCES Privilegio (id)
);

CREATE TABLE Seguir(
	seguidor_id INT UNSIGNED,
    seguido_id INT UNSIGNED,
    estado BOOL DEFAULT FALSE,
    PRIMARY KEY (seguidor_id,seguido_id),
    FOREIGN KEY (seguidor_id)
		REFERENCES Usuario (id),
    FOREIGN KEY (seguido_id)
		REFERENCES Usuario (id)
);

CREATE TABLE Genero(
	id TINYINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(255)
);

CREATE TABLE Playlist(
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(255) NOT NULL,
    foto VARCHAR(255) NOT NULL,
    color CHAR(7) NOT NULL,
    reproducciones INT UNSIGNED NOT NULL DEFAULT 0,
    fecha_creacion TIMESTAMP NOT NULL,
	estado CHAR(10) NOT NULL,
	creador_id INT UNSIGNED,
	genero_id TINYINT UNSIGNED, 
	FOREIGN KEY (creador_id)
		REFERENCES Usuario (id),
	FOREIGN	KEY (genero_id)
		REFERENCES Genero (id)
);

CREATE TABLE Cancion(
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(255) NOT NULL,
    duracion TIME NOT NULL,
    album VARCHAR(255) NOT NULL,
    artista VARCHAR(255) NOT NULL,
    genero_id TINYINT UNSIGNED NOT NULL,
    FOREIGN KEY (genero_id)
		REFERENCES Genero (id)
);

CREATE TABLE Playlist_Cancion(
	cancion_id INT UNSIGNED,
    playlist_id INT UNSIGNED,
    PRIMARY KEY (cancion_id,playlist_id),
    FOREIGN KEY (cancion_id)
		REFERENCES Cancion (id),
	FOREIGN KEY (playlist_id)
		REFERENCES Playlist (id)
);

CREATE TABLE Favoritos(
	usuario_id INT UNSIGNED, 
    playlist_id INT UNSIGNED,
    PRIMARY KEY (usuario_id,playlist_id),
    FOREIGN KEY (usuario_id)
		REFERENCES Usuario (id),
	FOREIGN KEY (playlist_id)
		REFERENCES Playlist (id)
);

CREATE TABLE Reportes(
	usuario_id INT UNSIGNED, 
    playlist_id INT UNSIGNED,
    PRIMARY KEY (usuario_id,playlist_id),
    FOREIGN KEY (usuario_id)
		REFERENCES Usuario (id),
	FOREIGN KEY (playlist_id)
		REFERENCES Playlist (id)
);

CREATE TABLE Me_Gusta(
	usuario_id INT UNSIGNED, 
    playlist_id INT UNSIGNED,
    fecha TIMESTAMP NOT NULL,
    PRIMARY KEY (usuario_id,playlist_id),
    FOREIGN KEY (usuario_id)
		REFERENCES Usuario (id),
	FOREIGN KEY (playlist_id)
		REFERENCES Playlist (id)	
);

CREATE TABLE Voto(
	usuario_id INT UNSIGNED, 
    playlist_id INT UNSIGNED,
    fecha TIMESTAMP NOT NULL,
    PRIMARY KEY (usuario_id,playlist_id),
    FOREIGN KEY (usuario_id)
		REFERENCES Usuario (id),
	FOREIGN KEY (playlist_id)
		REFERENCES Playlist (id)	
);

/*		
-- INSERTS Y CONSULTAS SIMPLES PARA VER QUE FUNCIONA

INSERT INTO Privilegio(	id,nombre)
VALUES (DEFAULT,DEFAULT);

INSERT INTO Usuario(	id,	nombre, contrasenia,
                        mail, fecha_registro, fecha_modificado,
                        cod_activacion, ban, pais,
                        pais_coordenada, privilegio_id
                        )
VALUES
	(DEFAULT,'pepe','abc123','hola@test.com',
		DEFAULT,DEFAULT,'xzxzzxzxzca',DEFAULT,'Argentina','asdf',1),
	(DEFAULT,'jose','mmm123','chau@test.com',
		DEFAULT,DEFAULT,'xxbbzzccaax',DEFAULT,'Argentina','qwer',1);
            
INSERT INTO Genero (id,nombre)
VALUES (DEFAULT,'Cuartetotronic');

INSERT INTO Playlist(
						id, nombre, foto,
                        color, reproducciones, fecha_creacion,
                        estado, creador_id, genero_id
					)
VALUES (DEFAULT,'Poxyclub','c:\windows\system32\foto.jpg.exe',
		'#FFFF23',DEFAULT,DEFAULT,'Solo yo',2,1);                    

    
SELECT * FROM Usuario;
SELECT * FROM Playlist;  
SELECT 	U.nombre AS 'Autor de Playlist',
		P.nombre AS 'Nombre de Playlist',
        G.nombre AS 'Genero de Playlist'
FROM Usuario AS U
	JOIN Playlist AS P ON U.id=P.creador_id
    JOIN Genero AS G ON P.genero_id=G.id;
*/    