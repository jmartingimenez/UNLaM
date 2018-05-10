/*

	Programa: Escribir una funcion que calcule el cuadrado de un numero entero
	

*/
#include<stdio.h>
#include<conio.h>

int cuadrado(int n);

int main()

{
	int n=0,c;
	printf("Ingrese un numero: ");
	scanf("%d",&n);
	c=cuadrado(n);
	printf("El cuadrado de %d es %d.",n,c);
	getch();
	return 0;
}

int cuadrado(int n)

{
	return n*n;
}
