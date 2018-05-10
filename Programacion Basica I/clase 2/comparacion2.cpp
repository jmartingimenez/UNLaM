#include<stdio.h>
#include<conio.h>
int main()
{
	int a=0,b=0;
	printf("ingrese un numero A: ");
	scanf("%d",&a);
	printf("ingrese un numero B: ");
	scanf("%d",&b);
	if(a==b)
	{
		printf("Los numeros son iguales.");
	}
	else
	{
		if(a<b)
		{
			printf("El numero B es mayor.");
		}
		else
		{
			printf("El numero A es mayor.");
		}
	}
	getch();
	return(1);
}
