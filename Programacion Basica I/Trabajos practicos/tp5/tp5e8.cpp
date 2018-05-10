#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*

**Ejercicio: Trabajo practico 5, ejercicio 8**

Programa: Realizar una tabulacion despues de escribir '\t'.

	\t <--- realiza una tabulacion.
	palabra[4] es una variable que almacena hasta 3 caracteres(Se suele poner
un valor mas del necesario -ver fotocopia del libro-
	escrito[50] es el mismo tipo de variable que palabra, solo que esta guardara
la palabra ingresada.
	\\t <----Doble barra para evitar la tabulacion. (Si se escribe solo
\t, toma la tabulacion en vez de la palabra, poner la doble barra hace que la
variable se guarde como '\t'.

	gets()  <---- Reemplazo del scanf para cadenas. Scanf sirve pero tiene un
problema (si se escribe con espacios solo toma la primer palabra). Si uno escribe
'\t asdadadasd' lo va a dar como correcto. (entre parentesis la variable
donde se asignara el valor del printf).

***Explicacion de como comparar las cadenas.
	El comando que se encarga de comparar las cadenas es el 'strcmp'
(string compare/comparar cadenas). En parentesis, separados por comas van
los nombres de las variables que se van a comparar.

	***ESTA COMPARACION DA UN VALOR NUMERICO (cada letra tiene un valor y aca
se comprueba la suma de cada una si no me equivoco xD) -ver libro-.

Basicamente, si son iguales las dos cadenas, el valor que debe dar, DEBE SER CERO!
	Ese valor se almacena en la variable del tipo entero 'c'.
	Por eso el  c=strcmp(palabra,escrito)
		
	La variable entera c es la que se usa con el while, mientras sea distinta
a 0. Se te obliga a volver a escribir..

*/
 
main()
{
   int c=0;
   char palabra[4]="\\t";
   char escrito[50];
   printf("Escribe el comando de tabulacion: ");
   gets(escrito);
   c=strcmp(palabra,escrito);
     while(c!=0)
   		{
			system("cls");//limpiar pantalla
			fflush(stdin);//liberar memoria del teclado
			printf("\nError!!: Comando incorrecto.\n\n");
			printf("\nPor favor, escribe el comando de tabulacion: ");
			gets(escrito);
			c=strcmp(palabra,escrito);
		}

	printf("\n\n\tLo lograste!!.");   
  
      
getch(); 
return (1);
}
