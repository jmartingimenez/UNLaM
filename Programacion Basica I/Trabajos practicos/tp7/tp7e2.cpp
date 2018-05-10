/*

	Programa: Calcular el area de un circulo

*/

#include<stdio.h>
#include<conio.h>
#define PI 3.1416

float area(float r);

int main()

{
	float r=0,a=0;
	printf("Ingrese el radio del circulo: ");
	scanf("%f",&r);
	a=area(r);
	printf("El area del circulo es %.2f",a);
	getch();
	return 0;
}

float area(float r)

{
	return PI*r*r;
}
