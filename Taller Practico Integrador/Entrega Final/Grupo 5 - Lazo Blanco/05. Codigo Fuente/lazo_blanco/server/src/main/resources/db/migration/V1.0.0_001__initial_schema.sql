CREATE TABLE `license` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `code` varchar(255) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `institution` varchar(255) DEFAULT NULL,
  `expedition_date` datetime DEFAULT NULL,
  `expiration_date` datetime DEFAULT NULL,
  PRIMARY KEY (`uuid`),
  UNIQUE KEY `UK_license__code` (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `location` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `zip_code` int(11) NOT NULL,
  `address_number` int(11) NOT NULL,
  `address_street` varchar(255) NOT NULL,
  `city` varchar(255) NOT NULL,
  `province` varchar(255) NOT NULL,
  `apartment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `permission` (
	`uuid` varchar(255) NOT NULL,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,
	`updated_by` varchar(255) NOT NULL,
	`name` varchar(255) NOT NULL,
	PRIMARY KEY (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `public_entity` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `phone_number` varchar(255) DEFAULT NULL,
  `type` varchar(255) DEFAULT NULL,
  `location_uuid` varchar(255) NOT NULL,
  PRIMARY KEY (`uuid`),
  KEY `FK_public_entity__location` (`location_uuid`),
  CONSTRAINT `FK_public_entity__location` FOREIGN KEY (`location_uuid`) REFERENCES `location` (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `user` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `email_confirmed` tinyint(1) NOT NULL DEFAULT '0',
  `password` varchar(255) NOT NULL,
  `role` varchar(255) NOT NULL DEFAULT 'VICTIM',
  `status` varchar(255) NOT NULL DEFAULT 'PENDING',
  `first_name` varchar(255) NOT NULL,
  `valid` tinyint(1) NOT NULL DEFAULT '0',
  `id_number` varchar(255) DEFAULT NULL,
  `sex` varchar(255) DEFAULT NULL,
  `last_name` varchar(255) DEFAULT NULL,
  `birth_date` datetime DEFAULT NULL,
  `phone_number` varchar(255) DEFAULT NULL,
  `secondary_email` varchar(255) DEFAULT NULL,
  `license_uuid` varchar(255) DEFAULT NULL,
  `location_uuid` varchar(255) DEFAULT NULL,
  `password_token` varchar(255) DEFAULT NULL,
  `token_expiration_date` datetime DEFAULT NULL,
  PRIMARY KEY (`uuid`),
  UNIQUE KEY `UK_user__email` (`email`),
  UNIQUE KEY `UK_user__id_number` (`id_number`),
  KEY `FK_user__license` (`license_uuid`),
  KEY `FK_user__location` (`location_uuid`),
  CONSTRAINT `FK_user__license` FOREIGN KEY (`license_uuid`) REFERENCES `license` (`uuid`),
  CONSTRAINT `FK_user__location` FOREIGN KEY (`location_uuid`) REFERENCES `location` (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `user_permission`;
CREATE TABLE `user_permission` (
  `user_uuid` varchar(255) NOT NULL,
  `permission_uuid` varchar(255) NOT NULL,
  KEY `FK_user_permission__user` (`user_uuid`),
  KEY `FK_user_permission__permission` (`permission_uuid`),
  CONSTRAINT `FK_user_permission__user` FOREIGN KEY (`user_uuid`) REFERENCES `user` (`uuid`),
  CONSTRAINT `FK_user_permission__permission` FOREIGN KEY (`permission_uuid`) REFERENCES `permission` (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;