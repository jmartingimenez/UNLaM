/*

	Programa: Mostrar la inversa de 1.
	
*** Inverso multiplicativo de n=1/n
*** Inverso aditivo de n=n*(-1) 	

*/

#include<stdio.h>
#include<conio.h>

int aditivo(int n);
float multiplicativo(float n);

int main()

{
	int seleccion=0,n=0,a;
	float m=0;
	printf("Ingrese 1 para calcular el inverso aditivo de un numero.\n");
	printf("Ingrese otro numero para calcular el inverso multiplicativo.\n");
	printf("Seleccion: ");
	scanf("%d",&seleccion);
	if(seleccion==1)
		{
			printf("Ingrese un numero para saber su inverso aditivo: ");
			scanf("%d",&n);
			a=aditivo(n);
			printf("El inverso aditivo de %d es %d.",n,a);
		}
	else
		{
			printf("Ingrese un numero para saber su inverso multiplicativo: ");
			scanf("%d",&n);
			m=multiplicativo(n);
			printf("El inverso multiplicativo de %d es %.2f.",n,m);
		}
	getch();
	return 0;		
	
}

//****************funcion aditivo***********

int aditivo(int n)

{
	return n*(-1);
}

//*****************funcion multiplicativo********

float multiplicativo(float n)

{
	return (1/n);
}
