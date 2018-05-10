/*

	Programa: Sumar matrices 2x2
		
	i,j= contadores
	mat,mat2= matrices con 'FI' cantidad de filas y 'CO' cantidad de columnas (estas 2 se suman)
	matresu= matriz con 'FI' cantidad de filsa y 'CO' cantidad de columnas (para el resultado)
	
***Como se suma...

matresu[i][j]=mat[i][j]+mat2[i][j];   <---Suponiendo que i=0 y j=0. (posicion 0,0)
matresu[0][0] guarda el resultado  en la posicion 0,0 de la suma de los valores que estan
en mat[0][0] y mat2[0][0]
	

*/

#include<stdio.h>
#include<conio.h>
#define FI 2
#define CO 2

main()

{
int i=0,j=0,mat[FI][CO],mat2[FI][CO],matresu[FI][CO];
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				matresu[i][j]=0;
			}
	}
printf("Primera matriz\n-----\n");
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
				printf("Ingrese un numero en la posicion %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
			}
	}
printf("\n\nSegunda matriz\n-----\n");
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				mat2[i][j]=0;
				printf("Ingrese un numero en la posicion %d,%d: ",i,j);
				scanf("%d",&mat2[i][j]);
			}
	}		
printf("\nMatriz 1\n-------\n\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}	
printf("\n\nMatriz 2\n-------\n\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat2[i][j]);
			}
	}		
for(i=0;i<FI;i++)//Llenando la matriz de resultados
	{
		for(j=0;j<CO;j++)
			{
				matresu[i][j]=mat[i][j]+mat2[i][j];
			}
	}	
printf("\n\nResultado\n---------\n\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",matresu[i][j]);
			}
	}	
getch();
return(1);	
}

