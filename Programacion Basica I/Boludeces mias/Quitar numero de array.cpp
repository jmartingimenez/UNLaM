/*						(ejercicio inventado por mi)
											
Programa: 

	-Realizar un array de 5 elementos y cargarle numeros enteros. 
	-Mostrar los numeros ingresados de forma ordenada (menor a mayor) y la suma de estos
	(con excepcion de un elemento que debe ser seleccionado)
	-Se debe mostrar el numero de coincidencias entre el numero seleccionado y la cantidad
de veces que este aparece en el array
	-Si el numero ingresado no se encuentra en el array, se debe volver a pedir otro
numero.

	ej.: A={2,1,5,3,4}	<---- Se elige el 3, se debe mostrar: 1 2 4 5. La suma debe
dar 12 (1+2+4+5).
											
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

main()

{
int i=0,j=0,temp=0,num=0,suma=0,coinc=0,A[MAX];
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		A[j]=0;
		j++;
	}	
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
	}	
system("cls");	
while(coinc<1)
	{
		printf("Ingrese un numero a 'eliminar' del array: ");
		scanf("%d",&num);
		for(i=0;i<MAX;i++)
			{
				if(num==A[i])
					{
						coinc++;
					}
			}
		if(coinc<1)
			{
				system("cls");
				printf("Error!!: El numero no se encuentra en el array\n");
			}				
	}
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-1;j++)
			{
				if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
			}
	}
system("cls");
printf("Se ha removido de la lista %d coincidencia/s con el numero %d\n\n\nOrden: ",coinc,num);
for(i=0;i<MAX;i++)
	{
		if(A[i]!=num)
			{
				suma+=A[i];
				printf("%d ",A[i]);
			}
	}
printf("\n\nLa suma de los numeros del array es: %d",suma);	
getch();
return(1);	
}
