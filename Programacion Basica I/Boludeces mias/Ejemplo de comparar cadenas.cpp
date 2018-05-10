#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//para usar el system("cls")/fflush(stdin)..
#include<string.h>//para usar el strcmp, gets..

/*

***Programa de Ejemplo para comparar cadenas. (pag 163 del libro esta todo esto)

	system("cls")  <---- clear screen/limpiar pantalla.
	fflush(stdin)  <---- limpiar memoria del teclado.
	!=  <--- distinto.
	cad1[50] y cad2[50] son variables de tipo char que pueden almacenar hasta
49 caracteres (para 50 se deberia poner 51, el numero faltante corresponde a lo
que marca el final de la cadena -ver fotocopia del libro-
	gets() <---- Similar al scanf pero para cadenas. El problema con usar el 
scanf es que si uno escribe "Hola como estas", solo agarraria el "Hola", (no toma
despues de los espacios).

***Explicacion de como comparar las cadenas.
	El comando que se encarga de comparar las cadenas es el 'strcmp'
(string compare/comparar cadenas). En parentesis, separados por comas van
los nombres de las variables que se van a comparar.

	***ESTA COMPARACION DA UN VALOR NUMERICO (cada letra tiene un valor y aca
se comprueba la suma de cada una si no me equivoco xD) -ver libro-.

Basicamente, si son iguales las dos cadenas, el valor que debe dar, DEBE SER CERO!
	Ese valor se almacena en la variable del tipo entero 'c'.
		Por eso el  c=strcmp(cad1,cad2)
		
	La variable entera c es la que se usa con el while, mientras sea distinta
a 0. Se te obliga a volver a escribir..

*/

main()

{
	int c;
	printf("Programa para comparar cadenas.");
	while(c!=0)
		{
			fflush(stdin);
			char cad1[50],cad2[50];
			printf("\nIngrese una palabra o frase: ");
			gets(cad1);
			system("cls");
			printf("Ingrese una segunda palabra o frase: ");
			gets(cad2);
			c=strcmp(cad1,cad2);//el compare da un valor numerico(0 son iguales)
			if(c!=0)
				{
					system("cls");
					printf("Las frases son diferentes. Vuelve a intentarlo!!");
				}
		}
	
	printf("\nLas frases son iguales.");

getch();
return(1);
}
