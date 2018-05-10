/*			(enunciado)
Calcular el elemento maximo y minimo de una matriz guardando ademas los indices de los mismos
***********************************************
								
	Programa: Hacer lo de arriba ^^
				
	i,j= contadores
	mat= matriz de 'FI' cantidad de filas y 'CO' cantidad de columnas
	max= guarda el numero mas alto
	min= guarda el numero mas bajo 
					
	(Hay que setear como minimo el primer numero que se ingrese para despues comparar. Si yo
no hago esto, la unica forma de que la variable se modifique es que ingrese un numero mas bajo
de 0 -su valor inicial al ser declarada-)

	posmaxX y posmaxY= Guardan la coordenada del numero mas alto (valores de i y j)
	posminX y posminY= Guardan la coordenada del numero mas bajo (valores de i y j)
			
			
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Para limpiar la pantalla
#define FI 2//2 Por que se me canto
#define CO 3//3 Por que se me canto

main()

{
int i=0,j=0,mat[FI][CO],max=0,posmaxX=0,posmaxY,min=0,posminX=0,posminY=0;
for(i=0;i<FI;i++)//Limpiando matriz/Pidiendo numeros
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
				printf("Ingrese un numero en la posicion %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
				if((i==0)&&(j==0))//El primer numero va ser el minimo
					{
						min=mat[i][j];
						posminX=i;
						posminY=j;
					}
				else
					{
						if(mat[i][j]<min)//El numero es el menor de todos?
							{
								min=mat[i][j];//Se guarda el numero
								posminX=i;//Se guarda la fila
								posminY=j;//Se guarda la columna
							}
					}					
				if(mat[i][j]>max)//El numero es el mayor de todos?
					{
						max=mat[i][j];//Se guarda el numero
						posmaxX=i;//Se guarda la fila
						posmaxY=j;//Se guarda la columna						
					}
			}
	}	
system("cls");//Limpiando la pantalla
printf("Matriz generada\n-------------\n\n");//Mostrando la matriz
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}	
printf("\n\nEl numero maximo es %d y se encuentra en la posicion %d,%d.",max,posmaxX,posmaxY);
printf("\nEl numero minimo es %d y se encuentra en la posicion %d,%d.",min,posminX,posminY);	
	
	
getch();
return(1);	
}
