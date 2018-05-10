#include<stdio.h>
#include<conio.h>
#define MAX 50

main()

{
int i=0,j=0,temp=0,legajo[MAX],promedio[MAX];
for(i=0;i<MAX;i++)
	{
		legajo[i]=0;
		promedio[i]=0;		
	}
for(i=0;i<MAX;i++)
	{
		printf("Ingrese Numero de legajo: ");
		scanf("%d",&legajo[i]);
		printf("Ingrese el promedio del legajo numero %d: ",legajo[i]);
		scanf("%d",&promedio[i]);
	}
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-1;j++)
			{
				if(legajo[j]>legajo[j+1])
					{
						temp=legajo[j];
						legajo[j]=legajo[j+1];
						legajo[j+1]=temp;
						temp=promedio[j];
						promedio[j]=promedio[j+1];
						promedio[j+1]=temp;
					}
			}
	}	
printf("\n\nLista ordenada\n---\nLegajo\tPromedio\n-----------------\n");
for(i=0;i<MAX;i++)
	{
		printf("%d\t%d\n",legajo[i],promedio[i]);	
	}

getch();
return(1);	
}
