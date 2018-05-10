#include<stdio.h>
#include<conio.h>

main()

{
int i=0,j=0,k=0,temp=0,n=3,A[n];

/*Es hora de sacar la basura*/

for(i=0;i<n;i++)
	{
		A[i]=0;
	}
for(j=0;j<n;j++)
	{
		A[j]=0;
	}
for(k=0;k<n;k++)
	{
		A[k]=0;
	}

/*Aca viene el camion :3*/
	
for(i=0;i<n;i++)
	{
		printf("\nIngrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
	}
for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
			{
				if(A[j]<A[j+1])
					{
						temp=A[j+1];
						A[j+1]=A[j];
						A[j]=temp;
					}
			}
	}	
printf("\n\n\nOrden: ");
for(k=0;k<n;k++)
	{
		printf("%d ",A[k]);
	}	
getch();
return(1);	
}
