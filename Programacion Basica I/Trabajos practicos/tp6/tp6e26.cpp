/*				(enunciado)

Sumar los elementos de cada una de las filas de una matriz y almacenar las sumas en un vector
//////////////////////////////////////////

	Programa: Hacer lo de arriba
				
	i,j= contadores
	suma= guarda el resultado de la suma de las filas
	A= vector que guarda resultados finales de la suma de una fila
	mat= matriz de 'FI' filas y 'CO' columnas
				
***Sobre el tercer define... ------------> '(FI*CO)-1'

	-Tomando la configuracion de ejemplo, con 2 filas y 3 columnas tendremos 6 numeros.
	-Para definir el tamaño del vector simplemente se multiplica filas*columnas
	-Esto daria A[6], pero seria un vector de 7 elementos ya que los vectores comienzan de
0. Por eso se le resta 1.			

*/
#include<stdio.h>
#include<conio.h>
#define FI 2
#define CO 3
#define VMAX (FI*CO)-1

main()

{
int i=0,j=0,suma=0,A[VMAX],mat[FI][CO];
for(i=0;i<FI;i++)//Limpieza de matriz
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
			}
	}	
for(i=0;i<VMAX;i++)//Limpieza de vector
	{
		A[i]=0;
	}	
for(i=0;i<FI;i++)//Pedido de numeros
	{
		suma=0;//En cada comienzo debe valer 0 para no acumular el valor de la fila anterior
		for(j=0;j<CO;j++)
			{
				printf("Ingrese un numero en la posicion %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
				suma+=mat[i][j];//Se va guardando el resultado de la suma entre cada posicion
			}
		A[i]=suma;//La posicion 'i' de 'A' toma el valor de la suma acumulada de la fila	
	}	
printf("\n\nMatriz\t\t\tSuma de la fila\n-----------------------------------------\n\n");
for(i=0;i<FI;i++)
	{
		printf("\t\t\t\t%d\n",A[i]);//Se muestra la suma
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat[i][j]);//Se muestra la matriz
			}
	}	
getch();
return(1);	
}
