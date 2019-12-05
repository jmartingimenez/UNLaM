-- Insert permissions
INSERT INTO `permission` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`) VALUES
('029c5454-d1ee-4656-9f37-c656e648bb94', NOW(), NOW(), 'initial-data', 'administrator'),
('43b364a3-0f89-4f11-a9ad-2e44598ccefd', NOW(), NOW(), 'initial-data', 'professional'),
('17416f42-93a4-4437-b0ee-1e734b62df8b', NOW(), NOW(), 'initial-data', 'victim');

-- Insert initial users
INSERT INTO `user` (`uuid`, `created_at`, `updated_at`, `updated_by`, `email`, `email_confirmed`, `password`, `role`, `status`, `first_name`, `valid`, `id_number`, `sex`, `last_name`, `birth_date`, `phone_number`, `secondary_email`, `license_uuid`, `location_uuid`, `password_token`, `token_expiration_date`) VALUES
('4710e585-0642-42d0-9cee-f868b9c3abeb', NOW(), NOW(), 'initial-data', 'admin@lazoblanco.com.ar', 1, '123456', 'ADMINISTRATOR', 'ACTIVE', 'Lazo', 0, null , null, 'Blanco', null, null, null, null, null, null, null),
('0d350362-7681-4c6e-84b9-f7e52ede25bf', NOW(), NOW(), 'initial-data', 'randreoli@lazoblanco.com.ar', 1, '123456', 'PROFESSIONAL', 'ACTIVE', 'Rodrigo', 0, '38425148', 'MALE', 'Andreoli', null, null, null, null, null, null, null),
('df179c6f-fc3c-4975-a395-af239edcafd6', NOW(), NOW(), 'initial-data', 'mledesma@lazoblanco.com.ar', 1, '123456', 'VICTIM', 'ACTIVE', 'Mauro', 0, '40391692', 'MALE', 'Ledesma', null, null, null, null, null, null, null),
('62c06bfe-7dfb-46a1-94c3-eb0e25aa2ed5', NOW(), NOW(), 'initial-data', 'jmurano@lazoblanco.com.ar', 1, '123456', 'PROFESSIONAL', 'ACTIVE', 'Juan', 0, '38258356', 'MALE', 'Murano', null, null, null, null, null, null, null),
('b09d3881-e11f-4085-abac-5edc4ad11246', NOW(), NOW(), 'initial-data', 'sares@lazoblanco.com.ar', 1, '123456', 'VICTIM', 'ACTIVE', 'Santiago', 0, '38398639', 'MALE', 'Quintana', null, null, null, null, null, null, null);

-- Insert permissions for users
INSERT INTO `user_permission` (`user_uuid`, `permission_uuid`) VALUES
('4710e585-0642-42d0-9cee-f868b9c3abeb', '029c5454-d1ee-4656-9f37-c656e648bb94'),
('0d350362-7681-4c6e-84b9-f7e52ede25bf', '43b364a3-0f89-4f11-a9ad-2e44598ccefd'),
('df179c6f-fc3c-4975-a395-af239edcafd6', '17416f42-93a4-4437-b0ee-1e734b62df8b'),
('62c06bfe-7dfb-46a1-94c3-eb0e25aa2ed5', '43b364a3-0f89-4f11-a9ad-2e44598ccefd'),
('b09d3881-e11f-4085-abac-5edc4ad11246', '17416f42-93a4-4437-b0ee-1e734b62df8b');

-- Insert public entities with their own location
-- -- Police
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('af728021-42b1-4fcf-a7ad-2796b9bc9afd', NOW(), NOW(), 'initial-data', 4139 , 2343, 'Av. Lisandro de la Torre', 'Mataderos', 'Buenos Aires', null),
('ba68ed5f-445b-4a1e-8352-dd6767d3fa13', NOW(), NOW(), 'initial-data', 1408 , 165, 'Basualdo', 'Villa Luro', 'Buenos Aires', null),
('81aff444-5c77-4efc-98df-72369e8261b7', NOW(), NOW(), 'initial-data', 1407 , 3748, 'Remedios', 'Parque Avellaneda', 'Buenos Aires', null),
('fa854a8b-a5c0-4dba-85a6-afca8acacc16', NOW(), NOW(), 'initial-data', 1407 , 453, 'Chivilcoy', 'Floresta', 'Buenos Aires', null),
('1564e79d-ca1e-4ae2-8ec0-e8d1e4ec7501', NOW(), NOW(), 'initial-data', 1406 , 258, 'Cnel. Esteban Bonorino', 'Flores', 'Buenos Aires', null),
('28397479-c1b6-4133-a0d6-b689a9de7b3d', NOW(), NOW(), 'initial-data', 1406 , 1454, 'Valle', 'Caballito', 'Buenos Aires', null),
('35a1a7ed-2e33-47dd-b466-c3a81feaa4cc', NOW(), NOW(), 'initial-data', 1406 , 1548, 'Av. Avellaneda', 'Caballito', 'Buenos Aires', null),
('607077a6-117c-4495-88df-8e694c6fb8c1', NOW(), NOW(), 'initial-data', 1419 , 4254, 'Av. Nazca', 'Villa Pueyrredón', 'Buenos Aires', null),
('905d0339-0750-4688-b0c1-e8177efb8d9e', NOW(), NOW(), 'initial-data', 1264 , 2724, 'Av. Caseros', 'Parque Patricios', 'Buenos Aires', null),
('acbb7b4c-fbd8-4ebc-b44e-bd11d7580ffb', NOW(), NOW(), 'initial-data', 1174 , 471, 'Billinghurst', 'Almagro', 'Buenos Aires', null),
('b6e40606-ded4-4bef-81aa-0fc4d7f53223', NOW(), NOW(), 'initial-data', 1425 , 4000, 'Av. Santa Fe', 'Palermo', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('61cfbe84-99d9-4501-b75d-e01f641757c5', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría Comunal 9', '011 4635-2011', 'POLICE', 'af728021-42b1-4fcf-a7ad-2796b9bc9afd'),
('e43aab9d-2d5c-498f-a674-94367479d71e', NOW(), NOW(), 'initial-data', 'Comisaría Vecinal 10C Policía de La Ciudad', '011 4635-2011	', 'POLICE', 'ba68ed5f-445b-4a1e-8352-dd6767d3fa13'),
('a01c97fd-317f-40cb-9a5b-522ac0519e5c', NOW(), NOW(), 'initial-data', 'Comisaría Vecinal 9B - 9C Policía de La Ciudad', '011 4671-3333', 'POLICE', '81aff444-5c77-4efc-98df-72369e8261b7'),
('0fd3592d-4348-4020-b286-be55eb656c79', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría Vecinal 10A', '011 4671-2209', 'POLICE', 'fa854a8b-a5c0-4dba-85a6-afca8acacc16'),
('dbd71db9-38a5-4e00-be3b-92c130d81532', NOW(), NOW(), 'initial-data', 'Comisaría Policía de La Ciudad 38', '011 4631-3333', 'POLICE', '1564e79d-ca1e-4ae2-8ec0-e8d1e4ec7501'),
('613a4f7b-cee2-4c85-a298-f8f6f748bcf4', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad - Comisaría Vecinal 7B', '011 4432-3922', 'POLICE', '28397479-c1b6-4133-a0d6-b689a9de7b3d'),
('4cf9ebfd-6f75-4250-ac3f-79a7cce5aa61', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría Comunal 6B', '011 4632-9129', 'POLICE', '35a1a7ed-2e33-47dd-b466-c3a81feaa4cc'),
('252054e3-0551-43cc-9afe-a511c185c84a', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría Vecinal 11B Anexo', '011 4572-4547', 'POLICE', '607077a6-117c-4495-88df-8e694c6fb8c1'),
('51379547-a0cf-4eb9-80cb-30137805efcd', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría 32', '011 4911-6416', 'POLICE', '905d0339-0750-4688-b0c1-e8177efb8d9e'),
('5edb1bc8-198a-4c57-b9d4-2bde4cff797d', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría Comunal 5', '011 4861-5507', 'POLICE', 'acbb7b4c-fbd8-4ebc-b44e-bd11d7580ffb'),
('eee06341-c6d4-45e4-8176-b96e79cb77b8', NOW(), NOW(), 'initial-data', 'Policía de La Ciudad Comisaría 23', '011 4832-5260', 'POLICE', 'b6e40606-ded4-4bef-81aa-0fc4d7f53223');

-- -- Womens Police
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('653f5d24-14d2-440a-b799-52a68a2ab28e', NOW(), NOW(), 'initial-data', 1852, 98, 'Olegario V. Andrade', 'Burzaco', 'Buenos Aires', null),
('fc184c0b-bcf5-4361-b5b8-233618d0e22f', NOW(), NOW(), 'initial-data', 1876, 68, 'Pilcomayo', 'Don Bosco', 'Buenos Aires', null),
('f71846d8-a500-48f2-ac2f-36576b7b119f', NOW(), NOW(), 'initial-data', 1635, 3045, 'Tomás Espora', 'Olivos', 'Buenos Aires', null),
('33118930-989a-4eb8-82c7-fdfe846d9cd9', NOW(), NOW(), 'initial-data', 1806, 105, 'Antonio Fariña', 'San Justo', 'Buenos Aires', null),
('638641c1-0b54-4e97-b440-2d71a60dc3be', NOW(), NOW(), 'initial-data', 1615, 158, 'Av. del Sesquicentenario', 'Grand Bourg', 'Buenos Aires', null),
('dcd4a5b4-eb6b-4dfa-9b15-f44c17e34912', NOW(), NOW(), 'initial-dataa', 1814, 1262, 'Calle Libertad', 'Cañuelas', 'Buenos Aires', null),
('d93c69db-5427-4633-b285-30e3c8ce4d50', NOW(), NOW(), 'initial-data', 1763, 4625, 'Gullermo Miller', 'Virrey del Pino', 'Buenos Aires', null),
('d3168ef6-747b-4fe8-8730-029bc96dcbab', NOW(), NOW(), 'initial-data', 2800, 1086, 'Pacheco', 'Zarate', 'Buenos Aires', null),
('0c146ea7-5fff-4fb7-9262-2efd30fb3331', NOW(), NOW(), 'initial-data', 1864, 210, 'Av. Pres. Hipólito Yrigoyen', 'Alejandro Korn', 'Buenos Aires', null),
('b5cda9cd-e185-41cf-95b7-da80edb5e67e', NOW(), NOW(), 'initial-data', 1744, 118, 'Zeballos', 'Moreno', 'Buenos Aires', null),
('d3978b80-6f38-4512-acda-18443324bc1a', NOW(), NOW(), 'initial-dataa', 1836, 348, '25 de Mayo', 'Temperley', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('ccf4ac4d-77f6-4593-a1df-66c097300f8d', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia de Almirante Brown', '011 4238-8555', 'WOMENSPOLICE', '653f5d24-14d2-440a-b799-52a68a2ab28e'),
('e1e8ea24-c240-405c-a8d0-e3b9df960a71', NOW(), NOW(), 'initial-data', 'Comisaría mujer de Quilmes', '011 4252-6006', 'WOMENSPOLICE', 'fc184c0b-bcf5-4361-b5b8-233618d0e22f'),
('9960d0b1-e6c8-440e-9248-047c3b7330f5', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer de Vte Lopez', '011 4711-7887', 'WOMENSPOLICE', 'f71846d8-a500-48f2-ac2f-36576b7b119f'),
('943c37b3-0bf3-4979-9a31-08ae174cb25b', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia', '011 4234-3566', 'WOMENSPOLICE', '33118930-989a-4eb8-82c7-fdfe846d9cd9'),
('980b71fd-9315-49c3-84c4-3b99280a6113', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer de Malvinas Argentinas', '02320 42-3193', 'WOMENSPOLICE', '638641c1-0b54-4e97-b440-2d71a60dc3be'),
('c9bcf37b-2367-44ac-9046-5215648af138', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia', '02226 43-1535', 'WOMENSPOLICE', 'dcd4a5b4-eb6b-4dfa-9b15-f44c17e34912'),
('04151091-0134-4a4e-bd38-c4470cb124c0', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer de Oro Verde', '02202 49-7000', 'WOMENSPOLICE', 'd93c69db-5427-4633-b285-30e3c8ce4d50'),
('22a3dd1a-62c7-40f7-b31f-507c6404dc8f', NOW(), NOW(), 'initial-data', 'Policía Comisaría de la mujer y la familia', '03487 54-9005', 'WOMENSPOLICE', 'd3168ef6-747b-4fe8-8730-029bc96dcbab'),
('ff4e3e53-e07a-4cbb-9078-d32238e83c15', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia', '02225 42-6238', 'WOMENSPOLICE', '0c146ea7-5fff-4fb7-9262-2efd30fb3331'),
('594d3eba-6cfd-42b6-a23f-3ec4a4b15fd1', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia de Moreno', '0237 460-1567', 'WOMENSPOLICE', 'b5cda9cd-e185-41cf-95b7-da80edb5e67e'),
('614ddb71-6030-4053-9f11-7887d38e58f9', NOW(), NOW(), 'initial-data', 'Comisaría de la mujer y la familia de Lomas De Zamora', '011 4244-1474', 'WOMENSPOLICE', 'd3978b80-6f38-4512-acda-18443324bc1a');
 
-- -- Assistance Center
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('0d6c94b9-8624-48fb-a799-0ffdbcc59cf6', NOW(), NOW(), 'initial-data', 1177, 765, 'Jerónimo Salguero', 'Almagro', 'Buenos Aires', null),
('db782c8d-3c42-4af0-b6e1-f89a9be8e6b1', NOW(), NOW(), 'initial-data', 1114, 1022, 'Pres. José Evaristo Uriburu', 'Recoleta', 'Buenos Aires', null),
('5ba871d1-d20a-445a-8069-f62fd6d87ae8', NOW(), NOW(), 'initial-data', 1429, 4583, 'Zapiola', 'Saavedra', 'Buenos Aires', null),
('67762c6c-826c-4b94-8a3a-7ef27784d221', NOW(), NOW(), 'initial-data', 1636, 3137, 'Juan de Garay', 'Olivos', 'Buenos Aires', null),
('fac22ff7-9edd-4d45-8c8a-286f7cc47ade', NOW(), NOW(), 'initial-data', 1884, 3146, 'Av. 14', 'Berazategui', 'Buenos Aires', null),
('130472a0-0657-4b77-8b46-8c5f2ce0610b', NOW(), NOW(), 'initial-data', 1832, 75, 'República Árabe de Siria', 'Lomas de Zamora', 'Buenos Aires', null),
('18bc4b9c-253b-4e93-ad19-f03cb1a44e64', NOW(), NOW(), 'initial-data', 1048, 1250, 'Lavalle', 'Centro', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('04c1c1f8-2144-483a-a347-351f9d8b56bf', NOW(), NOW(), 'initial-data', 'Centro Integral de la mujer Elvira Rawson', '0800-666-8537', 'ASSISTANCE', '0d6c94b9-8624-48fb-a799-0ffdbcc59cf6'),
('e1402fe1-002a-46ff-9113-4deab664eb80', NOW(), NOW(), 'initial-data', 'Centro Integral de la mujer Alicia Moreau', '011 4823-1165', 'ASSISTANCE', 'db782c8d-3c42-4af0-b6e1-f89a9be8e6b1'),
('33e611d2-b94e-4397-b62c-fb1437c24a95', NOW(), NOW(), 'initial-data', 'Centro Integral de la mujer', '011 2108-5782', 'ASSISTANCE', '5ba871d1-d20a-445a-8069-f62fd6d87ae8'),
('80611448-019a-42f8-8f81-f27afebf77dc', NOW(), NOW(), 'initial-data', 'Centro Municipal de la mujer y Políticas de Género', '080044468537', 'ASSISTANCE', '67762c6c-826c-4b94-8a3a-7ef27784d221'),
('bf7ae51f-faaa-48d5-bdfa-d0f40cf6c067', NOW(), NOW(), 'initial-data', 'CIPAV Centro Integral de Prevención y Asistencia a las Violencias', '011 4256-7207', 'ASSISTANCE', 'fac22ff7-9edd-4d45-8c8a-286f7cc47ade'),
('617b9e35-6a91-4536-9320-8fbd57d886ce', NOW(), NOW(), 'initial-data', 'Dirección Municipal de Derechos de las Mujeres y Equidad de Género', '011 4239-9634', 'ASSISTANCE', '130472a0-0657-4b77-8b46-8c5f2ce0610b'),
('9bee6573-2469-4209-8c6a-3c539e6ba95d', NOW(), NOW(), 'initial-data', 'Casa-Refugio Mariquita Sanchez', '0800-666-8537', 'ASSISTANCE', '18bc4b9c-253b-4e93-ad19-f03cb1a44e64');

-- -- Hospitals
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('81ba4be9-dbf2-4fa7-90a4-69eb5fe2233a', NOW(), NOW(), 'initial-data', 1212, 4214, 'Av. Hipólito Yrigoyen', 'Almagro', 'Buenos Aires', null),
('623f83af-8d8b-4c8f-b278-9edcf24eda89', NOW(), NOW(), 'initial-data', 1407, 1550, 'Pedro Calderón de la Barca', 'Monte Castro', 'Buenos Aires', null),
('cefb3d9f-ab6e-4716-8a71-8884a849d511', NOW(), NOW(), 'initial-data', 1426, 2680, 'Palpa', 'Colegiales', 'Buenos Aires', null),
('80a3ebd1-d920-4e7c-ad5f-575d1932bf5f', NOW(), NOW(), 'initial-data', 1406, 2701, 'Dr. Juan Felipe Aranguren', 'Flores', 'Buenos Aires', null),
('0c0473be-24a8-41f9-9c86-4435d42dd348', NOW(), NOW(), 'initial-data', 1437, 406, 'Avenida Almafuerte', 'Parque Patricios', 'Buenos Aires', null),
('8290e990-8511-4665-a2eb-bc8fd03d2682', NOW(), NOW(), 'initial-data', 1428, 3555, 'Av. Monroe', 'Coghlan', 'Buenos Aires', null),
('c59c8827-d62c-4507-b9f5-17314dce806b', NOW(), NOW(), 'initial-data', 1221, 609, 'Gral. Urquiza', 'Balvanera', 'Buenos Aires', null),
('4e87161a-df9a-42e6-9fb9-c9ca9f3e512f', NOW(), NOW(), 'initial-data', 1155, 750, 'Pi y Margall ', 'Almte Brown', 'Buenos Aires', null),
('7c51ef50-1e4c-4787-be20-92853166558e', NOW(), NOW(), 'initial-data', 1684, 386, 'Avenida Presidente Arturo U. Illia s/n y Marconi Morón', 'El Palomar', 'Buenos Aires', null),
('a56657ae-89a2-4c87-8bec-8a00791b914d', NOW(), NOW(), 'initial-data', 2005, 575, 'Av. Puccio', 'Alberdi', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('b431e880-e190-4e00-b7bc-42154bd340e7', NOW(), NOW(), 'initial-data', 'Emergencias', '0800-888-3637', 'HOSPITAL', '81ba4be9-dbf2-4fa7-90a4-69eb5fe2233a'),
('0c56fa13-0551-471f-874b-addac556f945', NOW(), NOW(), 'initial-data', 'Hospital General de Agudos D. Vélez Sarsfield', '011 4639-8700', 'HOSPITAL', '623f83af-8d8b-4c8f-b278-9edcf24eda89'),
('bf84221b-1456-4357-a093-4e9f1285c4b7', NOW(), NOW(), 'initial-data', 'Hospital Italiano Centro Traumatológico', '011 4959-0610', 'HOSPITAL', 'cefb3d9f-ab6e-4716-8a71-8884a849d511'),
('1dccc451-8829-4d7a-8439-a5977e1ec877', NOW(), NOW(), 'initial-data', 'Hospital General de Agudos Dr. Teodoro Álvarez', '0011 4630-2900', 'HOSPITAL', '80a3ebd1-d920-4e7c-ad5f-575d1932bf5f'),
('42f2c17b-bca5-47f5-9eb4-ff688f2d8042', NOW(), NOW(), 'initial-data', 'Hospital Penna', '0011 4911-5555', 'HOSPITAL', '0c0473be-24a8-41f9-9c86-4435d42dd348'),
('06eeb1e2-95ee-4683-8b94-c21138ab93b1', NOW(), NOW(), 'initial-data', 'Hospital Pirovano', '011 4546-4300', 'HOSPITAL', '8290e990-8511-4665-a2eb-bc8fd03d2682'),
('46798413-08ed-4d80-ac3d-b913bdb738cb', NOW(), NOW(), 'initial-data', 'Hospital General de Agudos José María Ramos Mejía', '011 4931-1884', 'HOSPITAL', 'c59c8827-d62c-4507-b9f5-17314dce806b'),
('7379bbe6-b0ad-4c26-bb8f-8ae85d073ded', NOW(), NOW(), 'initial-data', 'Hospital General de Agudos Dr. Cosme Argerich', '011 4121-0700', 'HOSPITAL', '4e87161a-df9a-42e6-9fb9-c9ca9f3e512f'),
('a70de949-8b42-4f86-bd14-b83af8a64047', NOW(), NOW(), 'initial-data', 'Hospital Posadas El Palomar', '011 4469-9300', 'HOSPITAL', '7c51ef50-1e4c-4787-be20-92853166558e'),
('20c71cdf-1652-42f5-89a9-c2f7967061a4', NOW(), NOW(), 'initial-data', 'Hospital Alberdi', '0341 480-6177', 'HOSPITAL', 'a56657ae-89a2-4c87-8bec-8a00791b914d');

-- -- Psicology Center
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('e4349c90-6203-4892-b1f4-5dbd3c5fb2a3', NOW(), NOW(), 'initial-data', 1704, 337, 'Saavedra', 'Ramos Mejia', 'Buenos Aires', null),
('f83c2e01-bc61-4aad-87ad-11498ac5cb24', NOW(), NOW(), 'initial-data', 1704, 456, 'Álvarez Jonte', 'Ramos Mejia', 'Buenos Aires', null),
('2096f942-86bf-4efd-836a-aa67016d18eb', NOW(), NOW(), 'initial-data', 1406, 6747, 'Av. Rivadavia', 'Flores', 'Buenos Aires', null),
('b7237fd8-e35d-4db8-989c-9fff43f3fcef', NOW(), NOW(), 'initial-data', 1427, 1118, 'Plaza', 'Villa Ortúzar', 'Buenos Aires', null),
('d6ba1af4-8446-441b-8284-2a93b4090167', NOW(), NOW(), 'initial-data', 1613, 1432, 'Paunero', 'San Miguel', 'Buenos Aires', null),
('ee82329f-7e6e-4fd8-a829-94311a9843ee', NOW(), NOW(), 'initial-data', 1439, 3321, 'Oliden', 'Villa Lugano', 'Buenos Aires', null),
('7d99e9f9-092e-434e-a8a6-2e9502e1eb62', NOW(), NOW(), 'initial-data', 1706, 16217, 'Av. Rivadavia', 'Haedo', 'Buenos Aires', null),
('13aa6181-f00b-461a-8bac-da26b220266f', NOW(), NOW(), 'initial-data', 1110, 660, 'Pres. Luis Sáenz Peña', 'Monserrat', 'Buenos Aires', null),
('76a55146-2712-41c4-ac75-f59fbbc745cc', NOW(), NOW(), 'initial-data', 1629, 501, 'Mayor Vergani', 'Caballito', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('7ab0aa91-130c-4618-a84c-6d95a875d552', NOW(), NOW(), 'initial-data', 'Centro Integral de Asistencia Psicológica', '011 4656-3093', 'PSICOLOGY', 'e4349c90-6203-4892-b1f4-5dbd3c5fb2a3'),
('a483b1c8-a8f5-410e-bd27-d63889cd240f', NOW(), NOW(), 'initial-data', 'Centro Psicológico Comunitario (Fund. Capac.)', '011 4658-5441', 'PSICOLOGY', 'f83c2e01-bc61-4aad-87ad-11498ac5cb24'),
('19c2f5af-96f8-41ab-b40b-8caeb1ce13f0', NOW(), NOW(), 'initial-data', 'Centro de Atencion Psicologica de Flores', '011 4631-7953', 'PSICOLOGY', '2096f942-86bf-4efd-836a-aa67016d18eb'),
('689a6fb9-8ad6-4972-8535-e5d035c5b8c6', NOW(), NOW(), 'initial-data', 'Centro Psicológico Plaza. Diagnóstico y Tratamiento.', '11 2067-7393', 'PSICOLOGY', 'b7237fd8-e35d-4db8-989c-9fff43f3fcef'),
('26c50faf-21c4-4a7d-98af-f61cd9435200', NOW(), NOW(), 'initial-data', 'Centro Psicológico San Miguel', '011 4667-1444', 'PSICOLOGY', 'd6ba1af4-8446-441b-8284-2a93b4090167'),
('471b74bb-04b7-4ae8-8902-59c903529f7e', NOW(), NOW(), 'initial-data', 'Lumos - Centro Integral de Asistencia Psicológica y Psicopedagógica', '011 3980-2220', 'PSICOLOGY', 'ee82329f-7e6e-4fd8-a829-94311a9843ee'),
('0f3c91d1-a6e9-410f-af1c-518a7f10abbe', NOW(), NOW(), 'initial-data', 'CASA - Centro de Asistencia Psicológica y Psicodrama', '011 4659-7954', 'PSICOLOGY', '7d99e9f9-092e-434e-a8a6-2e9502e1eb62'),
('e0512448-1f18-432d-9d79-f90a169b4bd1', NOW(), NOW(), 'initial-data', 'CAP - Centro de Atención Psicológica Uthgra', '011 5708-5207', 'PSICOLOGY', '13aa6181-f00b-461a-8bac-da26b220266f'),
('5a8a7efa-c3de-4c2f-905c-37679a3e3f72', NOW(), NOW(), 'initial-data', 'Atención Psicológica Clínica - Pilar/Caballito', '011 15-3457-4323', 'PSICOLOGY', '76a55146-2712-41c4-ac75-f59fbbc745cc');

-- -- Attorney Center
INSERT INTO `location` (`uuid`, `created_at`, `updated_at`, `updated_by`, `zip_code`, `address_number`, `address_street`, `city`, `province`, `apartment`) VALUES
('66fd6ed3-d8a5-47cf-91d4-ba5af2cd8482', NOW(), NOW(), 'initial-data', 1406, 2763, 'Av Corrientes', 'Balvanera', 'Buenos Aires', null),
('24033559-9691-4633-a038-5d12dc0fd7d1', NOW(), NOW(), 'initial-data', 1440, 5795, 'Av. Juan Bautista Alberdi', 'Mataderos', 'Buenos Aires', null),
('bcd02eed-70cf-4364-9d70-955945cbebe9', NOW(), NOW(), 'initial-data', 1440, 1202, 'Martiniano Leguizamón', 'Mataderos', 'Buenos Aires', null),
('ad188366-93cc-45c9-9ea1-1dea46abf60d', NOW(), NOW(), 'initial-data', 1785, 1896, 'José Alico', 'Aldo Bonzi', 'Buenos Aires', null),
('585ef313-cce7-4ad1-b67e-390bc81fe09d', NOW(), NOW(), 'initial-data', 1205, 4243, 'Av. Rivadavia', 'Almagro', 'Buenos Aires', 'Piso 2 Oficina A'),
('136dc79f-f104-4db4-bf36-5ee25c5a942e', NOW(), NOW(), 'initial-data', 1055, 736, 'Rodríguez Peña', 'Centro', 'Buenos Aires', null),
('e6e6aae3-3ba1-4460-be92-61c67ceb9919', NOW(), NOW(), 'initial-data', 1123, 1868, 'Av. Santa Fe', 'Recoleta', 'Buenos Aires', null),
('40413d27-2763-46d0-9c39-32a9dadc5ee2', NOW(), NOW(), 'initial-data', 1407, 1231, 'Av. Lope de Vega', 'Vélez Sársfield', 'Buenos Aires', null),
('a57a44f2-a48f-421f-b74f-61ea0abeea0b', NOW(), NOW(), 'initial-data', 1408, 1149, 'Av. Lisandro de la Torre', 'Liniers', 'Buenos Aires', null),
('7a9e8ce8-fbfd-4e98-afcd-a54f6e934bc2', NOW(), NOW(), 'initial-data', 1001, 651, 'Av. Leandro N. Alem', 'Centro', 'Buenos Aires', null);

INSERT INTO `public_entity` (`uuid`, `created_at`, `updated_at`, `updated_by`, `name`, `phone_number`, `type`, `location_uuid`) VALUES
('f65f25b8-8290-4636-ae61-d5b6b88c749d', NOW(), NOW(), 'initial-data', 'Estudio Jurídico Ina', '011 4964-0507', 'ATTORNEY', '66fd6ed3-d8a5-47cf-91d4-ba5af2cd8482'),
('39e896da-0025-4c08-a173-57c773b97f64', NOW(), NOW(), 'initial-data', 'Estudio Jurídico del Rincón', '011 4682-2344', 'ATTORNEY', '24033559-9691-4633-a038-5d12dc0fd7d1'),
('97d8036e-6960-42e6-a772-c92b94f2d83f', NOW(), NOW(), 'initial-data', 'Estudio Zani', '011 4687-1777', 'ATTORNEY', 'bcd02eed-70cf-4364-9d70-955945cbebe9'),
('98647726-b7d4-4fda-933c-e624938a1880', NOW(), NOW(), 'initial-data', 'Estudio Jurídico Dr. Bareiro', '011 4643-9444', 'ATTORNEY', 'ad188366-93cc-45c9-9ea1-1dea46abf60d'),
('4d8710ca-0a8f-4b39-ab65-9a67a651cb47', NOW(), NOW(), 'initial-data', 'Abogados OnLine 24hs', '011 5910-2190', 'ATTORNEY', '585ef313-cce7-4ad1-b67e-390bc81fe09d'),
('cfbb9593-c258-442e-9b60-d189f5b27a54', NOW(), NOW(), 'initial-data', 'Estudio Jurídico Marsan & Asociados', '011 4815-4644', 'ATTORNEY', '136dc79f-f104-4db4-bf36-5ee25c5a942e'),
('60e8fb0c-73d0-42ed-a961-7991ab572255', NOW(), NOW(), 'initial-data', 'Estudios Jurídicos', '011 4775-1544', 'ATTORNEY', 'e6e6aae3-3ba1-4460-be92-61c67ceb9919'),
('dab4a5e6-4e3e-4561-8e11-a06df0ed453b', NOW(), NOW(), 'initial-data', 'Estudio Jurídico Norberto Luis Fornasari y N. Fabio Fornasari', '011 4639-6565', 'ATTORNEY', '40413d27-2763-46d0-9c39-32a9dadc5ee2'),
('808842fc-d8a4-427a-b090-1cae327de54d', NOW(), NOW(), 'initial-data', 'Estudio Jurídico Dra. Valeria Barvosa & Asociados', '011 2065-3344', 'ATTORNEY', 'a57a44f2-a48f-421f-b74f-61ea0abeea0b'),
('90c752a6-94bd-411f-b466-8eea71c7cbd2', NOW(), NOW(), 'initial-data', 'Estudio Juridico Gallo & Asociados', '011 4314-6699', 'ATTORNEY', '7a9e8ce8-fbfd-4e98-afcd-a54f6e934bc2');
