/*			(enunciado)
Programa que imprima si un # es par o impar de una matriz 3 * 3. Mostrar la matriz ordenada.
*/

#include<stdio.h>
#include<conio.h>
#define FI 3
#define CO 3

main()

{
int i=0,j=0,x=0,y=0,temp=0,re=0,mat[FI][CO];
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
				printf("Ingrese un numero en %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
				re=mat[i][j]%2;
				if(re==0)
					{
						printf("\t\t\t\t\tEl numero %d es par\n",mat[i][j]);
					}
				else
					{
						printf("\t\t\t\t\tEl numero %d es impar\n",mat[i][j]);
					}	
			}
	}
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				for(x=0;x<FI;x++)
					{
						for(y=0;y<CO;y++)
							{
								if(mat[i][j]<mat[x][y])
									{
										temp=mat[i][j];
										mat[i][j]=mat[x][y];
										mat[x][y]=temp;
									}
							}
					}
			}
	}
printf("\n\nMatriz ordenada\n-----------\n\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}
	
	
getch();
return(1);	
}
