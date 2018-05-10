/*								(enunciado)
	Despues de haber realizado la carga de dos matrices de diferentes tamaños, cuyas 
matrices idenficaremos como R y S mostrar los elementos comunes de R en S

/////////////////////////////////////////////////

	Programa: Hacer lo de arriba ^^
	
	i,j,k,l= contadores, los ultimos 2 los tuve que agregar para buscar coincidencias
al final, no se si son necesarios, pero de esta manera me salio.
	fc1 y fc2= variables para guardar la cantidad de filas y columnas de la 1er y 2da matriz
			(suponiendo que las filas y columnas son iguales en cada matriz)
	R y S= matrices que tienen 'fc1' y 'fc2' cantidad de filas/columnas		
	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Solo para limpiar la pantalla cuando se muestran los numeros

main()

{
int i=0,j=0,k=0,l=0,fc1=0,fc2=0;
printf("Ingrese la cantidad de columnas y filas de la primera matriz: ");
scanf("%d",&fc1);
printf("Ingrese la cantidad de columnas y filas de la segunda matriz: ");
scanf("%d",&fc2);
int R[fc1][fc1],S[fc2][fc2];//Declaracion de matrices
for(i=0;i<fc1;i++)//Limpieza de la primera matriz
	{
		for(j=0;j<fc1;j++)
			{
				R[i][j]=0;
			}
	}	
for(i=0;i<fc2;i++)//Limpieza de la segunda matriz
	{
		for(j=0;j<fc2;j++)
			{
				S[i][j]=0;
			}
	}	
printf("\n--Primera matriz\n----------\n\n");
for(i=0;i<fc1;i++)//Pedido de numeros para la primera matriz
	{
		for(j=0;j<fc1;j++)
			{
				printf("Ingrese un numero en %d,%d: ",i,j);
				scanf("%d",&R[i][j]);
			}
	}	
printf("\n--Segunda matriz\n----------\n\n");
for(i=0;i<fc2;i++)//Pedido de numeros para la segunda matriz
	{
		for(j=0;j<fc2;j++)
			{
				printf("Ingrese un numero en %d,%d: ",i,j);
				scanf("%d",&S[i][j]);
			}
	}
system("cls");//Solo para limpiar la pantalla cuando se muestran los numeros
printf("--\nPrimera matriz\n--------\n");//Mostrando los numeros ingresados en R
for(i=0;i<fc1;i++)
	{
		printf("\n");
		for(j=0;j<fc1;j++)
			{
				printf("%d\t",R[i][j]);
			}
	}	
printf("\n\n--\nSegunda matriz\n--------\n");//Mostrando los numeros ingresados en S
for(i=0;i<fc2;i++)
	{
		printf("\n");
		for(j=0;j<fc2;j++)
			{
				printf("%d\t",S[i][j]);
			}
	}		
printf("\n\n--\nCoincidencias entre las 2 matrices\n----------------\n\n");
for(i=0;i<fc1;i++)//Si hay una manera mas simple, me gustaria saberla :D
	{
		for(j=0;j<fc1;j++)
			{
				for(k=0;k<fc2;k++)
					{
						for(l=0;l<fc2;l++)
							{
								if(R[i][j]==S[k][l])
									{
										printf("%d ",R[i][j]);
									}
							}
					}
			}
	}
	
getch();
return(1);	
}
