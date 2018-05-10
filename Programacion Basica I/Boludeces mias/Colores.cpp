#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Libreria requerida

/*

	Programa: Ver como ingresar colores.

***Requiere la libreria stdlib.h

	Se utiliza el comando --->	'system("color XX")'
(Las 2 'X' corresponden a un codigo de color especifico)
	*El primer valor indica el color del fondo	
	*El segundo valor indica el color del texto

	En el ejemplo se usa 'system("Color 2f")'. Donde 2(verde) es el color
del fondo y f(Blanco brillante) es el color del texto.

***Si se quita un valor del codigo solo cambiara el color del texto.
***Si se agregan mas valores, se compilara pero se mostrara la ayuda oficial
que explica como usar el comando.

*/

main()

{
system("color 2f");
printf("Este es un programa que muestra los codigos de colores.");
printf("\n-------------------------------------------------------\n");
printf("\n0-Negro\n1-Azul\n2-Verde\n3-Celeste\n4-Rojo\n5-Violeta\n6-Amarillo");
printf("\n7-Blanco\n8-Gris\n9-Azul claro\nA-Verde claro\nB-Celeste claro");
printf("\nC-Rojo claro\nD-Violeta claro\nE-Amarillo claro\nF-Blanco brillante\n\n");
printf("Para este programa se utilizaron 2 codigos juntos.\n");
printf("El primero corresponde al fondo y el segundo al color del texto.\n");
printf("-color 2f- Es el comando utilizado en este caso.\n");
printf("\t\tVER ARCHIVO .CPP PARA VER COMO SE ESCRIBE");
getch();
return(1);	
}
