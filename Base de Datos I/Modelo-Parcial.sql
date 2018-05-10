drop database if exists modeloparcial;

create database if not exists modeloparcial;

use modeloparcial;

create table espectaculo 	(id_espectaculo int,
							descripcion char(20),
							precio int,
                            primary key (id_espectaculo)
                            );
                            
create table ciudad 	(id_ciudad int,
						nombre char (20),
                        primary key (id_ciudad));
                        
create table cliente 	(id_cliente int,
						nombre char(20),
                        telefono int,
                        id_ciudad int,
                        primary key (id_cliente),
                        foreign key (id_ciudad) references ciudad(id_ciudad)
						);
                        
create table  boleteria 	(id_boleteria int,
							nombre char(20),
                            direccion char(20),
                            id_ciudad int,
                            primary key (id_boleteria),
                            foreign key (id_ciudad) references ciudad(id_ciudad)
                            );
                            
create table entrada 	(id_cliente int,
						id_espectaculo int,
                        id_boleteria int,
                        fecha date,
                        primary key (id_cliente,id_espectaculo,id_boleteria),
                        foreign key (id_cliente)references cliente(id_cliente),
                        foreign key (id_espectaculo)references espectaculo(id_espectaculo),
                        foreign key (id_boleteria)references boleteria(id_boleteria)
                        );
					
-- *******************************************

insert into espectaculo (id_espectaculo,descripcion,precio)
values(1,'dracula',3000),
	   (2,'toc toc',1500),
       (3,'Piñon',700);


insert into ciudad(id_ciudad,nombre)
values(1,'Ramos Mejia'),
	   (2,'San Justo');
       
insert into cliente (id_cliente,nombre,telefono,id_ciudad)
values(1,'pepe',1111,1),
		(2,'carlos',2222,2),
        (3,'juancito',3333,1);

insert into boleteria(id_boleteria,nombre,direccion,id_ciudad)
values(1,'hoyts','calle falsa',1),
	   (2,'cinemark','calle true',2),
       (3,'showcase','haedo',2),
       (4,'village','caballito',2);

insert into entrada (id_cliente, id_espectaculo, id_boleteria,fecha)
values(1,3,1,'2013-01-04'),
	   (2,1,2,'2012-01-02'),
       (3,3,3,'2011-01-01'),
       (1,2,2,'2013-01-04'),
       (1,1,3,'2013-01-04'),
       (1,2,1,'2013-01-04'),
       (1,3,2,'2013-01-04');