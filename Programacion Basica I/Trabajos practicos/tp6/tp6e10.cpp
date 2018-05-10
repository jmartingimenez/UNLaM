/*			(enunciado)

***Dada una mtriz cuadrada invertir su diagonal principal e informar; tanto para
matrices de 2x2, de 3x3 y de 4x4

-------------------

	Programa: Hacer lo de arriba xD
		
	i y j= contadores necesarios
	mat= matriz que tiene 'FI' cantidad de filas y 'CO' cantidad de columnas (ver define)
	
	Explicacion de la diagonal invertida...
			
	-Los for del final simplemente estan configurados para mostrar todo en el sentido
contrario al que se ingreso (invierte todo, no solo la diagonal principal)
	- Suponiendo que es una matriz de 2x2, al entrar al primer for, i=FI-1 (osea 1), luego
entra al segundo for donde 'j' ira desde 'CO-1' hasta 0. Cuando el if encuentre una igualdad
entre las posiciones de 'i' y 'j' (cuando 'j' tambien valga 1) mostrara el numero ingresado.
En el segundo recorrido de 'j' (i=1 y j=0) no se mostrara nada. Luego de salir del segundo
for se reiniciara el primero (salto de linea mediante) ahora i=0 y el segundo for se iniciara
nuevamente (como 'j' en un principio vale 1, al no haber coincidencia no se mostrara nada),
en el segundo recorrido del for interno (ya con 'j' valiendo 0), si habra coincidencia y se
mostrara el numero ingresado en la cuarta posicion...

Ejemplo... ('n' indica un numero mostrado -donde hubo coincidencia- y 'X' donde no la hubo)

				n	X
				X	n		
				
***Notese que las posiciones donde hay coincidencia son (0,0) y (1,1), coinciden 'i' y 'j'
que es lo que busca el if				

*/

#include<stdio.h>
#include<conio.h>
#define FI 3
#define CO 3

main()

{
int i=0,j=0,mat[FI][CO];
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
			}
	}	
i=0;j=0;
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				printf("Ingrese un numero en la posicion %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
			}
	}	
printf("\n\nMatriz en el orden ingresado\n-----\n\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d\t",mat[i][j]);
			}
	}	
printf("\n\nMatriz con la diagonal principal invertida\n------\n\n");	
for(i=FI-1;i>=0;i--)
	{
		printf("\n");
		for(j=CO-1;j>=0;j--)
			{
				if(mat[i]==mat[j])
					{
						printf("%d \t", mat[i][j]);							
					}
				else
					{
						printf("\t");//Solo muestra la diagonal principal
					}	
			}
	}		
	
getch();
return(1);	
}

