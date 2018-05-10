#include<stdio.h>
#include<conio.h>
#define FI 2
#define CO 3

main()

{
int i=0,j=0,x=0,y=0,temp=0,mat[FI][CO];
for(i=0;i<FI;i++)
	{
		for(j=0;j<CO;j++)
			{
				mat[i][j]=0;
				printf("Ingrese un numero en %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
			}
	}	
printf("\n\nMatriz\n-----------\n");
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}	
printf("\n\nMatriz ordenada\n---------------");
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
