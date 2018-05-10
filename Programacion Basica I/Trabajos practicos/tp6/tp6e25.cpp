#include<stdio.h>
#include<conio.h>
#define FC 4

main()

{
int i=0,j=0,x=0,y=0,temp=0,mat[FC][FC];
for(i=0;i<FC;i++)
	{
		for(j=0;j<FC;j++)
			{
				mat[i][j]=0;
				printf("Ingrese un numero en %d,%d: ",i,j);
				scanf("%d",&mat[i][j]);
			}
	}	
printf("\n\nMatriz ingresada\n---------------\n\n");
for(i=0;i<FC;i++)
	{
		printf("\n");
		for(j=0;j<FC;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}	
printf("\n\nMatriz ordenada\n---------------\n\n");	
for(i=0;i<FC;i++)
	{
		for(j=0;j<FC;j++)
			{
				for(x=0;x<FC;x++)
					{
						for(y=0;y<FC;y++)
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
for(i=0;i<FC;i++)
	{
		printf("\n");
		for(j=0;j<FC;j++)
			{
				printf("%d ",mat[i][j]);
			}
	}	
	
getch();
return(1);	
}
