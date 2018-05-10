/*

	Programa: Ingresar numeros a una matriz
	i y j= variables contadores necesarias
	mat[FI][CO]= matriz que tiene 'FI' cantidad de filas y 'CO' cantidad de columnas
(ver los define)
***Posiciones en matriz (en el print de la linea 35 se puede agregar i+1 y j+1 para evitar
los ceros)
-------
	0.0		0.1		0.2	
	1.0		1.1		1.2
	2.0		2.1		2.2	
-------
***Despues de limpiar la matriz i y j deben volver a setearse en 0 de nuevo, sino quedan
con los valores de FI y CO

*/

#include<stdio.h>
#include<conio.h>
#define FI 3
#define CO 3

main()

{
int i=0,j=0,mat[FI][CO];//En la matriz el primer numero indica la fila y el segundo la columna
for(i=0;i<FI;i++)//Limpieza de matriz
	{
		for(j=0;j<CO;j++)//pasa por 0,0... 0,1... 0,2... despues 1,0... 1,1... 1,2....etc....
			{
				mat[i][j]=0;
			}
	}	
i=0;j=0;//Si no los vuelvo a 0, quedan en 3 los 2 (comprobado)
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				printf("Ingrese valor en %d,%d: ",i,j);//pide en el mismos sentido que limpia
				scanf("%d",&mat[i][j]);
			}
	}	
for(i=0;i<FI;i++)
	{
		printf("\n");//Si no agrego esto, salen los 9 numeros en fila
		for(j=0;j<CO;j++)
			{
				printf("%d\t",mat[i][j]);//va mostrando las posiciones
			}
	}	
getch();
return(1);	
}
