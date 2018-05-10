#include<stdio.h>
#include<conio.h>

int amasb(int a, int b);//Declaracion de funcion que retornara algun valor
void cmasd(int c, int d);//Declaracion de funcion que no retornara ningun valor

int main()

{
	int a=0,b=0,c=0,d=0,suma_ab;//declaracion de variables
/*Variable 'suma_ab' tomara el valor retornado por la funcion 'amasb'*/	
	printf("Ingrese un numero a: ");//Pedido de numero
	scanf("%d",&a);
	printf("Ingrese un numero b: ");//Pedido de numero
	scanf("%d",&b);
	printf("Ingrese un numero c: ");//Pedido de numero
	scanf("%d",&c);
	printf("Ingrese un numero d: ");//Pedido de numero
	scanf("%d",&d);
	printf("La suma de todos los numeros es: %d",a+b+c+d);//Suma de numeros (dentro de main)
	suma_ab=amasb(a,b);//Se llama a la funcion 'amasb'
	//'suma_ab' toma el valor retornado por la funcion 'amasb'
	printf("\nLa suma de a y b da %d",suma_ab);//Se muestra el resultado de la suma
	cmasd(c,d);//Se llama a la funcion 'cmasd' que no retornara ningun valor
	getch();
	return 0;
}

int amasb(int a, int b)//Funcion 'amasb'

{
	return a+b;//La funcion retorna la suma de a+b
}

void cmasd(int c, int d)//Funcion 'cmasd'

{
	printf("\nLa suma de c y d da %d",c+d);//Se ve el resultado, esta funcion no retorna nada
}
