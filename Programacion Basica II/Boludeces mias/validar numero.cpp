#include<stdio.h>

int pedirnumero();

int main()

	{
		int num=pedirnumero();
		printf("\n\nEl numero es %d",num);
		return 0;
	}

int pedirnumero()

	{
		int num;
		do
			{
				fflush(stdin);
				printf("Ingrese un numero: ");
			}while(scanf("%d",&num)==0);
		return num;					
	}
