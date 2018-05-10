#include<stdio.h>
#include<conio.h>

main()

{
	
int i=1,n=1,p=1,j=0;
printf("\nEste programa mostrara la tabla de un numero entero seleccionado.");
printf("\nIngrese un numero: ");
scanf("%d",&n);
for(i=1;i<=10;i++)
	{
		for(j=0;j<=n;j++)
			{
				p=i*j;	
			}
		printf("\n%dx%d=%d",n,i,p);
		p=1;	
	}

getch();
return(1);	
}
