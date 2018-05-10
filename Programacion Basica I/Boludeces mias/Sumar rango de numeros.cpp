#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

	Programa: Mostrar el rango entre 2 numeros ingresados y sumarlos.
	
	'reset' es la variable que te permite volver al principio.
	'a' y 'b' guardan los dos numeros ingresados.
	'cont' es la variable del for que ira subiendo 'a' hasta llegar a 'b'.
	'suma' ira sumando los nuevos valores de 'a' entre si.
	
***Hice que te obligue a que 'b' sea mas grande que 'a'. Con rebuscarselas
un poco esto no es necesario, pero me daba fiaca seguir.	

*/

main()

{
system("color 0e");
int reset=1;
while(reset==1)
	{
		int a=0,b=0,cont=0,suma=0;
		system("cls");
		printf("Este programa muestra y suma los numeros que comprenden un rango seleccionado.");
		printf("\n-----------------------------------------------------------------------------");
		printf("\n\nIngrese un numero: ");
		scanf("%d",&a);
		printf("Ingrese otro numero: ");
		scanf("%d",&b);	
		while(b<=a)
			{
				system("cls");
				printf("\nERROR!!: El segundo numero debe ser mayor al primero que es %d.",a);
				printf("\n\nIngrese otro numero: ");
				scanf("%d",&b);	
			}
		system("cls");
		printf("Rango: [ ");
		for(cont=a;cont<=b;cont++)
			{
				printf("%d ",cont);
				suma=suma+cont;
			}	
		printf("]");
		printf("\n\nLa suma de los numeros del rango es de: %d.",suma);	
		printf("\n-------------------------------------------");
		printf("\n\n\n\n\n\n\n\t\tDesea continuar?\n\nPulse 1 para si\t\t\tCualquier Otra tecla para finalizar.");
		printf("\n\n\nSeleccion: ");
		scanf("%d",&reset);
	}
getch();
return(1);	
}
