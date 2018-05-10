#include<stdio.h>
#include<conio.h>
#define FI 3
#define CO 3

main()
{
	int mat[FI][CO],j=0,i=0;
	
	for(i=0;i<FI;i++)
	{
		for(j=0;j<FI;j++)
		{
			mat[i][j]=0;
		}
		
	}
	
i=0;
j=0;
for(i=0;i<FI;i++)
{
printf("\n");
for(j=0;j<FI;j++)
{
printf("ingrese en Fila %d,columna %d   ",i+1,j+1);
scanf("%d",&mat[i][j]);
}
}
for(i=0;i<FI;i++)
	{
		printf("\n");
		for(j=0;j<CO;j++)
			{
				printf("%d\t",mat[i][j]);
			}
	}
getch();
}


