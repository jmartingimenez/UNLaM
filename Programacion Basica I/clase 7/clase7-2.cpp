#include<stdio.h>
#include<conio.h>

/*

Programa: Contar vocales y consonantes ingresadas y mostrar al final.

	a,e,i,o,u,cons son variables que guardan las vocales/consonantes ingresadas.
	letra es una variable de caracter
	fflush(stdin) <------Limpiar memoria de teclado..
	!=   <-----Distinto
	Los caracteres van entre ''.
	El programa almacena la letra ingresada y la guarda en la variable
correspondiente. El while dura hasta que se pulza '?'. El ++ dentro del
switch es para que cada vez que se pulse una tecla se aumente en 1 el valor
de la variable correspondiente (va sumando cuantas teclas de tal tipo
se apretaron..)

*/

main()

{

int a=0,e=0,i=0,o=0,u=0,cons=0;
char letra;
printf("Ingrese una letra: ");
scanf("%c",&letra);
while(letra!='?')
	{
		
		fflush(stdin);
		switch(letra)
			{
				case 'a':a++;
				break; 
				case 'e':e++;
				break; 
				case 'i':i++;
				break; 
				case 'o':o++;
				break; 
				case 'u':u++;
				break; 
				default:cons++;
				break; 
			}
		printf("Ingrese una letra: ");
		scanf("%c",&letra);	
	}	
	
printf("\n------------------------");
printf("\nCantidad de 'a': %d.",a);
printf("\nCantidad de 'e': %d.",e);
printf("\nCantidad de 'i': %d.",i);
printf("\nCantidad de 'o': %d.",o);
printf("\nCantidad de 'u': %d.",u);
printf("\nCantidad de consonantes: %d.",cons);
printf("\n------------------------");

getch();
return(1);	
}
