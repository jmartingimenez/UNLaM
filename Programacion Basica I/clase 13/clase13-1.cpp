#include<stdio.h>
#include<conio.h>
#define MAX 10
main()

{
int i=0,j=0,A[MAX],temp=0;
for(i=0;i<MAX;i++)
	{
		A[i]=0;
	}	
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&A[i]);
	}	
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-1;j++)
			{
				if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
			}
	}	
printf("\nOrden: ");
for(i=0;i<MAX;i++)
	{
		printf("%d ",A[i]);
	}	
	
getch();
return(1);	
}
