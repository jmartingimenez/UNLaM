#include<stdio.h>
#include<conio.h>
#define MAX 5

main()

{
int i=0,A[MAX],max=0,min=0;
for(i=0;i<MAX;i++)
	{
		A[i]=0;
	}
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d:\t ",i+1);
		scanf("%d",&A[i]);
		if(i==0)
			{
				max=A[i];
				min=A[i];
			}
		if(A[i]>max)
			{
				max=A[i];
			}	
		if(A[i]<min)
			{
				min=A[i];
			}			
	}	
printf("------------------\n\n\nEl numero mas alto es %d y el numero mas bajo es %d.",max,min);	
getch();
return(1);	
}
