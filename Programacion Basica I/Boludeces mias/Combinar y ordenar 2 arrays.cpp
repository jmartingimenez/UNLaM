/*
	Programa: 
		-Ingresar 1 array de 5 numeros y ordenarlos de menor a mayor
		-Ingresar otro array de 5 numeros y ordenarlos de mayor a menor
		-Juntar ambos array en 1 solo y ordenarlos de menor a mayor
			
		
	***Nota: Con 1 array solo se podria hacer lo que pide el programa, pero la gracia
es poder juntar los vectores :P

	i= variable contador para los for y las posiciones
	j= variable contador extra para utilizar el metodo burbuja
	k= variable contador exclusiva para el array de 10 (evita problemas)
	temp= variable temporal (metodo burbuja)
	A= primer array que ordena de menor a mayor
	A2= segundo array que ordena de mayor a menor
	A3= array de 10 posiciones que combina los 2 anteriores
	MAX= constante para definiir tamaño de los 2 primeros arrays (5 posiciones)
	TOTALMAX= constante para definir tamaño del array combinado (10 posiciones)
	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
#define TOTALMAX 10

main()

{
int i=0,j=0,k=0,temp=0,A[MAX],A2[MAX],A3[TOTALMAX];
for(i=0;i<MAX;i++)//Limpiando basura
	{
		A[i]=0;
		A2[i]=0;
	}
for(i=0;i<TOTALMAX;i++)//Limpiando basura
	{
		A3[i]=0;
	}	
printf("Primer Array\n-----------------\n");//Pidiendo numeros para el primer array
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
		A3[k]=A[i];//Ademas se guarda en A3.
		k++;//Subiendo el valor de k para las posiciones de A3.
	}
for(i=0;i<MAX;i++)//Burbuja para ordenar de menor a mayor
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
printf("Segundo Array\n----------------\n");//Pidiendo numeros para el segundo array
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A2[i]);
		A3[k]=A2[i];//Se sigue guardando en A3.
		k++;//Sigue subiendo, no arranca de 0, por que ya trae el valor anterior.
	}	
for(i=0;i<MAX;i++)//Burbuja segundo array para ordenar de mayor a menor
	{
		for(j=0;j<MAX-1;j++)
			{
				if(A2[j]<A2[j+1])
					{
						temp=A2[j];
						A2[j]=A2[j+1];
						A2[j+1]=temp;
					}
			}
	}		
for(i=0;i<TOTALMAX;i++)//Burbuja para las 10 posiciones del tercer array
	{
		for(j=0;j<TOTALMAX-1;j++)
			{
				if(A3[j]>A3[j+1])
					{
						temp=A3[j];
						A3[j]=A3[j+1];
						A3[j+1]=temp;
					}
			}
	}	
system("cls");
printf("Primer Array, ordenado de menor a mayor\n---------------\n");
for(i=0;i<MAX;i++)
	{
		printf("%d ",A[i]);
	}
printf("\n\n\nSegundo Array, ordenado de mayor a menor\n---------------\n");
for(i=0;i<MAX;i++)
	{
		printf("%d ",A2[i]);
	}
printf("\n\n\nArrays juntados, ordenados de menor a mayor\n---------------\n");
for(i=0;i<TOTALMAX;i++)
	{
		printf("%d ",A3[i]);
	}	
	
getch();
return(1);	
}
