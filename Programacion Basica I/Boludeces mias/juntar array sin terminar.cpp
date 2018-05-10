/*
	Programa: 
		-Ingresar 1 array de 5 numeros y ordenarlos de menor a mayor
		-Ingresar otro array de 5 numeros y ordenarlos de mayor a menor
		-Juntar ambos array en 1 solo y ordenarlos de menor a mayor
			
		
	***Nota: Con 1 array solo se podria hacer lo que pide el programa, pero la gracia
es poder juntar los vectores :P

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
#define TOTALMAX 10

main()

{
int i=0,j=0,k=0,temp=0,A[MAX],A2[MAX],A3[TOTALMAX];
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		A2[i]=0;
	}
for(i=0;i<TOTALMAX;i++)
	{
		A3[i]=0;
	}	
printf("Primer Array\n-----------------\n");
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
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
printf("\n\n\nSegundo Array\n----------------\n");
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A2[i]);
	}	
for(i=0;i<MAX;i++)
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
for(i=0;i<TOTALMAX;i++)
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
//system("cls");
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
printf("\n\n\nArrays juntados, ordenado de menor a mayor\n---------------\n");
for(i=0;i<TOTALMAX;i++)
	{
		printf("%d ",A3[i]);
	}	
	
getch();
return(1);	
}
