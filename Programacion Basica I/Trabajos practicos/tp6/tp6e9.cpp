/*		(enunciado)

Se tiene un arreglo de enteros:

	a. Determinar si un entero X pertenece o no a un arreglo.
	b. Si pertenece al arreglo cuantas veces esta en el
	
///////////////////////////////

	Programa: Hacer lo de arriba :D	

*/

#include<stdio.h>
#include<conio.h>
#define MAX 5

main()

{
int i=0,num=0,cont=0,A[MAX];
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
	}	
printf("Ingrese un numero a buscar en el vector: ");
scanf("%d",&num);
for(i=0;i<MAX;i++)
	{
		if(num==A[i])
			{
				cont++;
			}
	}	
if(cont>0)
	{
		if(cont==1)//Solo para que la frase final quede bien expresada
			{
				printf("El numero %d se encuentra 1 vez en el vector.",num);				
			}
		else
			{
				printf("El numero %d se encuentra %d veces en el vector.",num,cont);				
			}	

	}	
else
	{
		printf("El numero %d no se encuentra en el vector.",num);
	}	
getch();
return(1);	
}
