CREATE TABLE `chat_room` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `victim_uuid` varchar(255) NOT NULL,
  `professional_uuid` varchar(255) NOT NULL,
  PRIMARY KEY (`uuid`),
  KEY `FK_chat_room__victim` (`victim_uuid`),
  KEY `FK_chat_room__professional` (`professional_uuid`),
  CONSTRAINT `FK_chat_room__victim` FOREIGN KEY (`victim_uuid`) REFERENCES `user` (`uuid`),
  CONSTRAINT `FK_chat_room__professional` FOREIGN KEY (`professional_uuid`) REFERENCES `user` (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `chat_message` (
  `uuid` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `updated_by` varchar(255) NOT NULL,
  `room_uuid` varchar(255) NOT NULL,
  `content` text NOT NULL,
  `sender` varchar(255) NOT NULL DEFAULT 'VICTIM',
  PRIMARY KEY (`uuid`),
  KEY `FK_chat_message__room` (`room_uuid`),
  CONSTRAINT `FK_chat_message__room` FOREIGN KEY (`room_uuid`) REFERENCES `chat_room` (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;