#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

Programa: Ejemplo de operaciones con array

	Los array llevan entre corchetes 1 valor mas del maximo.
	operacion guarda hasta 2 valores.
	operacion2 guarda hasta 5 valores al igual que operacion3.
	En operacion3 al principio los 5 valores son 0.	

*/

main()
{

int operacion[3]={10,15},suma=0,contarray=0;
int operacionv2[6]={5,10,15,20,25};
int operacionv3[6]={};

/* Suma basica */

printf("testeando array..\n");
suma=operacion[0]+operacion[1]+operacion[2];//array arranca de 0
//Si solo pongo operacion[1]+operacion[2], no se suma bien
printf("Primera suma: %d\n\n\n",suma);

/*Sumando los elementos del array con for*/

suma=0;
for(contarray=0;contarray<=5;contarray++)
	{
		suma=suma+operacionv2[contarray];
		printf("\n%d\t<---Suma parcial.",suma);
	}
printf("\nSegunda suma: %d\n\n\n",suma);

/*Guardando numeros ingresados en array y sumandolos con for*/
//Para ir guardando en el array creo que el for tiene q arrancar de 1.

suma=0;
contarray=1;
for(contarray=1;contarray<=5;contarray++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&operacionv3[contarray]);
		suma=suma+operacionv3[contarray];
	}

printf("\nTercera suma= %d",suma);	
	
	
	
	
getch();
return(1);	
}
