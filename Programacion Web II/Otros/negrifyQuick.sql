-- phpMyAdmin SQL Dump
-- version 4.5.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 14, 2016 at 07:48 
-- Server version: 10.1.13-MariaDB
-- PHP Version: 5.5.37

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `negrify`
--

-- --------------------------------------------------------

--
-- Table structure for table `cancion`
--

CREATE TABLE `cancion` (
  `id` int(10) UNSIGNED NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `duracion` time NOT NULL,
  `album` varchar(255) NOT NULL,
  `artista` varchar(255) NOT NULL,
  `genero_id` tinyint(3) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `cancion`
--

INSERT INTO `cancion` (`id`, `nombre`, `duracion`, `album`, `artista`, `genero_id`) VALUES
(1, 'prueba1', '00:00:00', 'albumdeprueba', 'prueba2', 1),
(2, 'otacann', '00:00:00', 'albumdeprueba', 'oqoqoq', 1),
(3, 'xxxxxx', '00:00:00', 'zzzzzz', 'yyyyyy', 1),
(4, 'eeeeeee', '00:00:00', 'ttttttttt', 'rrrrrrrrrrr', 1),
(5, 'hhhhhhhhhhh', '00:00:00', 'kkkkkkkkkkkk', 'jjjjjjjjjjjjjj', 1),
(6, 'ttttttttttttt', '00:00:00', 'ttttttttttt', 'ttttttttttttt', 1),
(7, 'ooooooooooooooo', '00:00:00', 'oooooooo', 'ooooooooooo', 1),
(8, 'qqqqq', '00:00:00', 'qqqqq', 'qqqqq', 1),
(9, 'qqqqqq', '00:00:00', 'ttttttttt', 'qqqqq', 1),
(10, 'Want you bad', '00:00:00', 'Conspiracy of One', 'The Offspring', 1),
(11, 'Want you bad', '00:00:00', 'Conspiracy of One', 'The Offspring', 1),
(12, 'Original Prankster', '00:00:00', 'Conspiracy of One', 'The Offspring', 1),
(13, 'Millon Miles Away', '00:00:00', 'Conspiracy of One', 'The Offspring', 1),
(14, 'Walla Walla', '00:00:00', 'Americana', 'The Offspring', 1),
(15, 'Come out and play', '00:00:00', 'Smash', 'The Offspring', 1),
(16, 'Nitro', '00:00:00', 'Smash', 'The Offspring', 1),
(17, 'Americana', '00:00:00', 'Americana', 'The Offspring', 1),
(18, 'aa bb', '00:00:00', 'zz xx', 'qq ww', 1);

-- --------------------------------------------------------

--
-- Table structure for table `favoritos`
--

CREATE TABLE `favoritos` (
  `usuario_id` int(10) UNSIGNED NOT NULL,
  `playlist_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `genero`
--

CREATE TABLE `genero` (
  `id` tinyint(3) UNSIGNED NOT NULL,
  `nombre` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `genero`
--

INSERT INTO `genero` (`id`, `nombre`) VALUES
(1, 'random');

-- --------------------------------------------------------

--
-- Table structure for table `me_gusta`
--

CREATE TABLE `me_gusta` (
  `usuario_id` int(10) UNSIGNED NOT NULL,
  `playlist_id` int(10) UNSIGNED NOT NULL,
  `fecha` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `playlist`
--

CREATE TABLE `playlist` (
  `id` int(10) UNSIGNED NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `foto` varchar(255) NOT NULL,
  `color` char(7) NOT NULL,
  `reproducciones` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `fecha_creacion` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `estado` char(10) NOT NULL,
  `creador_id` int(10) UNSIGNED DEFAULT NULL,
  `genero_id` tinyint(3) UNSIGNED DEFAULT NULL,
  `ban` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `playlist`
--

INSERT INTO `playlist` (`id`, `nombre`, `foto`, `color`, `reproducciones`, `fecha_creacion`, `estado`, `creador_id`, `genero_id`, `ban`) VALUES
(1, 'dePrueba', 'dePrueba.jpg', '', 0, '2016-08-25 18:24:42', 'publica', 2, 1, 0),
(2, 'dePrueba2', 'dePrueba2.jpg', '', 0, '2016-10-25 18:33:32', 'publica', 2, 1, 0),
(3, 'aloha', 'aloha.jpg', '', 0, '2016-10-26 18:54:31', 'publica', 2, 1, 0),
(4, 'xxxaa', 'xxxaa.jpg', '', 0, '2016-10-26 18:57:10', 'publica', 2, 1, 0),
(5, 'funca', 'funca.jpg', '', 0, '2016-10-26 19:04:31', 'publica', 2, 1, 0),
(6, 'funca2', 'funca2.jpg', '', 0, '2016-10-26 19:07:34', 'publica', 2, 1, 0),
(7, 'funca3', 'funca3.jpg', '', 0, '2016-10-26 19:08:13', 'publica', 2, 1, 0),
(8, 'vvvvv', 'vvvvv.jpg', '', 0, '2016-10-26 19:34:50', 'publica', 2, 1, 0),
(9, 'kkkkk', 'kkkkk.jpg', '', 0, '2016-10-26 19:37:48', 'publica', 2, 1, 0),
(10, 'hhhh', 'hhhh.jpg', '', 0, '2016-10-26 19:39:23', 'publica', 2, 1, 0),
(11, 'wwwwwwww', 'wwwwwwww.jpg', '', 0, '2016-11-06 18:41:04', 'publica', 2, 1, 0),
(12, 'uuuuuuu', 'uuuuuuu.jpg', '', 0, '2016-11-07 17:32:10', 'publica', 2, 1, 1),
(13, 'nuevotest', 'nuevotest.jpg', '', 0, '2016-10-27 02:18:31', 'publica', 2, 1, 0),
(14, 'previosend', 'previosend.jpg', '', 0, '2016-11-07 16:43:18', 'publica', 2, 1, 1),
(15, 'sinExtension', 'sinExtension.jpg', '', 0, '2016-11-06 21:18:28', 'publica', 2, 1, 1),
(16, 'conExtension', 'conExtension.jpg', '', 0, '2016-10-27 23:46:22', 'publica', 2, 1, 0),
(17, 'sinLaExtension', 'sinLaExtension.jpg', '', 0, '2016-11-06 20:42:27', 'publica', 2, 1, 1),
(18, 'conLaExtension', 'conLaExtension.jpg', '', 0, '2016-11-06 21:18:30', 'publica', 2, 1, 1),
(19, 'guardaLaExtension', 'guardaLaExtension.jpg', '', 0, '2016-11-06 21:18:31', 'publica', 2, 1, 1),
(20, 'conNuevoNombre', 'conNuevoNombre.jpg', '', 0, '2016-11-06 21:18:33', 'publica', 2, 1, 1),
(21, 'Conspiracy', 'Conspiracy.jpg', '', 0, '2016-11-11 18:31:22', 'publica', 2, 1, 0),
(22, 'Americana', 'Americana.jpg', '', 0, '2016-11-11 18:38:30', 'publica', 2, 1, 0),
(23, 'ixn1', 'ixn1.jpg', '', 0, '2016-11-11 19:13:39', 'publica', 2, 1, 0),
(24, 'ixn2', 'ixn2.jpg', '', 0, '2016-11-11 19:15:12', 'publica', 2, 1, 0),
(25, 'Ixnay on the Hombre', 'Ixnay_on_the_Hombre.jpg', '', 0, '2016-11-11 20:35:01', 'publica', 2, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `playlist_cancion`
--

CREATE TABLE `playlist_cancion` (
  `id` int(10) UNSIGNED NOT NULL,
  `cancion_id` int(10) UNSIGNED NOT NULL,
  `playlist_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `privilegio`
--

CREATE TABLE `privilegio` (
  `id` tinyint(3) UNSIGNED NOT NULL,
  `nombre` varchar(255) DEFAULT 'Usuario'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `privilegio`
--

INSERT INTO `privilegio` (`id`, `nombre`) VALUES
(1, 'Administrador'),
(2, 'Usuario');

-- --------------------------------------------------------

--
-- Table structure for table `reportes_playlist`
--

CREATE TABLE `reportes_playlist` (
  `id` int(10) UNSIGNED NOT NULL,
  `usuario_id` int(10) UNSIGNED NOT NULL,
  `playlist_id` int(10) UNSIGNED NOT NULL,
  `confirmacion` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reportes_playlist`
--

INSERT INTO `reportes_playlist` (`id`, `usuario_id`, `playlist_id`, `confirmacion`) VALUES
(11, 3, 12, 1),
(14, 3, 14, 1),
(15, 3, 15, 1),
(17, 3, 17, 1),
(18, 3, 18, 1),
(19, 3, 19, 1),
(20, 3, 20, 1);

-- --------------------------------------------------------

--
-- Table structure for table `reportes_usuario`
--

CREATE TABLE `reportes_usuario` (
  `id` int(10) UNSIGNED NOT NULL,
  `usuario_denunciado` int(10) UNSIGNED NOT NULL,
  `usuario_denunciante` int(10) UNSIGNED NOT NULL,
  `confirmacion` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reportes_usuario`
--

INSERT INTO `reportes_usuario` (`id`, `usuario_denunciado`, `usuario_denunciante`, `confirmacion`) VALUES
(3, 3, 2, 0);

-- --------------------------------------------------------

--
-- Table structure for table `seguir`
--

CREATE TABLE `seguir` (
  `seguidor_id` int(10) UNSIGNED NOT NULL,
  `seguido_id` int(10) UNSIGNED NOT NULL,
  `estado` tinyint(1) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `usuario`
--

CREATE TABLE `usuario` (
  `id` int(10) UNSIGNED NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `apellido` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `contrasenia` varchar(255) NOT NULL,
  `mail` varchar(255) NOT NULL,
  `fecha_registro` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `fecha_modificado` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `cod_activacion` varchar(255) NOT NULL,
  `ban` tinyint(1) NOT NULL DEFAULT '0',
  `pais` varchar(255) NOT NULL,
  `pais_coordenada` varchar(255) NOT NULL,
  `privilegio_id` tinyint(3) UNSIGNED NOT NULL DEFAULT '2',
  `estado_activacion` tinyint(3) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `usuario`
--

INSERT INTO `usuario` (`id`, `nombre`, `apellido`, `username`, `contrasenia`, `mail`, `fecha_registro`, `fecha_modificado`, `cod_activacion`, `ban`, `pais`, `pais_coordenada`, `privilegio_id`, `estado_activacion`) VALUES
(2, 'pepe', 'pompin', 'usuario1', '122b738600a0f74f7c331c0ef59bc34c', 'usuario1@hotmail.com', '2016-10-30 20:46:55', '0000-00-00 00:00:00', '1bb91f73e9d31ea2830a5e73ce3ed328', 0, '', '', 1, 0),
(3, 'aloha', 'kepota', 'usuario2', 'nene', 'nene@blabla.com', '2016-11-11 18:07:36', '0000-00-00 00:00:00', '27', 0, 'Argentina', 'xasdad', 2, 1);

-- --------------------------------------------------------

--
-- Table structure for table `voto`
--

CREATE TABLE `voto` (
  `id` int(10) UNSIGNED NOT NULL,
  `cancion_id` int(10) UNSIGNED NOT NULL,
  `playlist_id` int(10) UNSIGNED NOT NULL,
  `fecha` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cancion`
--
ALTER TABLE `cancion`
  ADD PRIMARY KEY (`id`),
  ADD KEY `genero_id` (`genero_id`);

--
-- Indexes for table `favoritos`
--
ALTER TABLE `favoritos`
  ADD PRIMARY KEY (`usuario_id`,`playlist_id`),
  ADD KEY `playlist_id` (`playlist_id`);

--
-- Indexes for table `genero`
--
ALTER TABLE `genero`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `me_gusta`
--
ALTER TABLE `me_gusta`
  ADD PRIMARY KEY (`usuario_id`,`playlist_id`),
  ADD KEY `playlist_id` (`playlist_id`);

--
-- Indexes for table `playlist`
--
ALTER TABLE `playlist`
  ADD PRIMARY KEY (`id`),
  ADD KEY `creador_id` (`creador_id`),
  ADD KEY `genero_id` (`genero_id`);

--
-- Indexes for table `playlist_cancion`
--
ALTER TABLE `playlist_cancion`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `cancion_id` (`cancion_id`,`playlist_id`),
  ADD KEY `playlist_id` (`playlist_id`);

--
-- Indexes for table `privilegio`
--
ALTER TABLE `privilegio`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `reportes_playlist`
--
ALTER TABLE `reportes_playlist`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `usuario_id` (`usuario_id`,`playlist_id`),
  ADD KEY `playlist_id` (`playlist_id`);

--
-- Indexes for table `reportes_usuario`
--
ALTER TABLE `reportes_usuario`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `usuario_denunciado` (`usuario_denunciado`,`usuario_denunciante`),
  ADD KEY `usuario_denunciante` (`usuario_denunciante`);

--
-- Indexes for table `seguir`
--
ALTER TABLE `seguir`
  ADD PRIMARY KEY (`seguidor_id`,`seguido_id`),
  ADD KEY `seguido_id` (`seguido_id`);

--
-- Indexes for table `usuario`
--
ALTER TABLE `usuario`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`),
  ADD UNIQUE KEY `mail` (`mail`),
  ADD KEY `privilegio_id` (`privilegio_id`);

--
-- Indexes for table `voto`
--
ALTER TABLE `voto`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `cancion_id` (`cancion_id`,`playlist_id`),
  ADD KEY `playlist_id` (`playlist_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cancion`
--
ALTER TABLE `cancion`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
--
-- AUTO_INCREMENT for table `genero`
--
ALTER TABLE `genero`
  MODIFY `id` tinyint(3) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `playlist`
--
ALTER TABLE `playlist`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;
--
-- AUTO_INCREMENT for table `playlist_cancion`
--
ALTER TABLE `playlist_cancion`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `privilegio`
--
ALTER TABLE `privilegio`
  MODIFY `id` tinyint(3) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `reportes_playlist`
--
ALTER TABLE `reportes_playlist`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
--
-- AUTO_INCREMENT for table `reportes_usuario`
--
ALTER TABLE `reportes_usuario`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `usuario`
--
ALTER TABLE `usuario`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `voto`
--
ALTER TABLE `voto`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `cancion`
--
ALTER TABLE `cancion`
  ADD CONSTRAINT `cancion_ibfk_1` FOREIGN KEY (`genero_id`) REFERENCES `genero` (`id`);

--
-- Constraints for table `favoritos`
--
ALTER TABLE `favoritos`
  ADD CONSTRAINT `favoritos_ibfk_1` FOREIGN KEY (`usuario_id`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `favoritos_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlist` (`id`);

--
-- Constraints for table `me_gusta`
--
ALTER TABLE `me_gusta`
  ADD CONSTRAINT `me_gusta_ibfk_1` FOREIGN KEY (`usuario_id`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `me_gusta_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlist` (`id`);

--
-- Constraints for table `playlist`
--
ALTER TABLE `playlist`
  ADD CONSTRAINT `playlist_ibfk_1` FOREIGN KEY (`creador_id`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `playlist_ibfk_2` FOREIGN KEY (`genero_id`) REFERENCES `genero` (`id`);

--
-- Constraints for table `playlist_cancion`
--
ALTER TABLE `playlist_cancion`
  ADD CONSTRAINT `playlist_cancion_ibfk_1` FOREIGN KEY (`cancion_id`) REFERENCES `cancion` (`id`),
  ADD CONSTRAINT `playlist_cancion_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlist` (`id`);

--
-- Constraints for table `reportes_playlist`
--
ALTER TABLE `reportes_playlist`
  ADD CONSTRAINT `reportes_playlist_ibfk_1` FOREIGN KEY (`usuario_id`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `reportes_playlist_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlist` (`id`);

--
-- Constraints for table `reportes_usuario`
--
ALTER TABLE `reportes_usuario`
  ADD CONSTRAINT `reportes_usuario_ibfk_1` FOREIGN KEY (`usuario_denunciado`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `reportes_usuario_ibfk_2` FOREIGN KEY (`usuario_denunciante`) REFERENCES `usuario` (`id`);

--
-- Constraints for table `seguir`
--
ALTER TABLE `seguir`
  ADD CONSTRAINT `seguir_ibfk_1` FOREIGN KEY (`seguidor_id`) REFERENCES `usuario` (`id`),
  ADD CONSTRAINT `seguir_ibfk_2` FOREIGN KEY (`seguido_id`) REFERENCES `usuario` (`id`);

--
-- Constraints for table `usuario`
--
ALTER TABLE `usuario`
  ADD CONSTRAINT `usuario_ibfk_1` FOREIGN KEY (`privilegio_id`) REFERENCES `privilegio` (`id`);

--
-- Constraints for table `voto`
--
ALTER TABLE `voto`
  ADD CONSTRAINT `voto_ibfk_1` FOREIGN KEY (`cancion_id`) REFERENCES `cancion` (`id`),
  ADD CONSTRAINT `voto_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlist` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
