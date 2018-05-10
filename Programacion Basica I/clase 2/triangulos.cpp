#include <stdio.h>
#include <conio.h>
int main()
{
	int lado1=0,lado2=0,lado3=0;
	printf("Ingrese el valor del Lado 1: ");
	scanf("%d",&lado1);
	printf("Ingrese el valor del Lado 2: ");
	scanf("%d",&lado2);
	printf("Ingrese el valor del Lado 3: ");
	scanf("%d",&lado3);
	if(lado1==lado2)
	{
		if(lado1==lado3)
		{
			printf("El triangulo es equilatero.");
		}
		else
		{
			printf("El triangulo es isosceles.");
		}
	}
	else
	{
		if(lado1==lado3)
		{
			printf("El triangulo es isosceles.");
		}
		else
		{
			if(lado2==lado3)
			{
				printf("El triangulo es isosceles.");
			}
			else
			printf("El triangulo es escaleno.");
		}
	}
	getch();
	return(1);
}
