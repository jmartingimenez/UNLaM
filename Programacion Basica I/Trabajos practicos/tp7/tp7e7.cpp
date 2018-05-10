/*

	Programa: Escribir una funcion que calcule el cubo de un numero entero
	

*/
#include<stdio.h>
#include<conio.h>

int cubo(int n);

int main()

{
	int n=0,c;
	printf("Ingrese un numero: ");
	scanf("%d",&n);
	c=cubo(n);
	printf("El cubo de %d es %d.",n,c);
	getch();
	return 0;
}

int cubo(int n)

{
	return n*n*n;
}
