/*
Sobre la cota: Un número es una cota inferior de un conjunto de números si es menor
o igual que todos los números del conjunto.

Ej.: A={5,6,7}<-----Cota inferior puede ser cualquier numero entre (-infinito,5]
   				(No me sale el simbolo de infinito aca :P)

*** Si entiendo bien el enunciado, una vez obtenidos los 30 valores, se debe mostrar la
cota inferior y el minimo.

--

	MAX= constante que guarda la maxima cantidad de posiciones del vector
	num= guarda el numero ingresado previo a agregarse al vector
	min= guarda el numero mas bajo ingresado
	pos= guarda la posicion del numero mas bajo ingresado
	i= actua como contador para los bucles y para las posiciones del vector
	A= array (vector)
	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 30

main()

{

int i=0,num=0,min=0,pos=0,A[MAX];
for(i=0;i<MAX;i++)//Sacando al basura
	{
		A[i]=0;
	}	
for(i=0;i<MAX;i++)//Bucle para pedido de numeros
	{
		printf("Ingrese un numero en la posicion %d:",i+1);
		scanf("%d",&num);
		if(num>0)//Viendo si es entero positivo
			{
				A[i]=num;
				if(i==0)//Solo corre la primera vez para setear el numero minimo
					{
						min=A[i];
						pos=i+1;
					}
				system("cls");						
			}
		else
			{
				system("cls");
				printf("\t\t\tERROR!!: Debe ser un numero entero positivo\n");
				i--;//Se resta uno en el bucle, para que si o si sean 30 numeros
			}
		if(num<min)//Buscando el numero mas bajo
			{
				min=A[i];
				pos=i+1;
			}	
	}	
system("cls");
printf("El numero mas bajo se encuentra en la posicion %d y es: %d",pos,min);	
printf("\nEl rango correspondiente a la cota inferior es (-inf,%d]",min);
getch();
return(1);	
}
