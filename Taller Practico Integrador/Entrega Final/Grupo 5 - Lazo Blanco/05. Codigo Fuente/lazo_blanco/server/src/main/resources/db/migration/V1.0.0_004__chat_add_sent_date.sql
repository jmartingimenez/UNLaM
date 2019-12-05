ALTER TABLE `chat_message`
ADD COLUMN `sent_at` datetime NOT NULL AFTER `content`;