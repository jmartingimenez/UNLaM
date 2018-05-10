#include<stdio.h>
#include<conio.h>

int numero(int num);

int main()

{
	int num=0,n;
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	n=numero(num);
	if(n==0)
		{
			printf("El numero es %d",num);
		}
	else
		{
			if(n>0)
				{
					printf("El numero %d es positivo",num);
				}
			else
				{
					printf("El numero %d es negativo",num);
				}	
		}	
	getch();
	return 0;
}

int numero(int num)

{
	if(num==0)
		{
			return 0;
		}
	else
		{
			if(num>0)
				{
					return 1;
				}
			else
				{
					return -1;
				}	
		}	
}
