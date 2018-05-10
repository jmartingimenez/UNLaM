/*
	
	Programa: Ingresar un numero y mostrar el factorial del mismo
		
	n= variable que guarda el numero ingresado
	f= variable que llama a la funcion 'factorial' y toma el valor retornado por la misma
	i= variable contador para el for
	
*/

#include<stdio.h>
#include<conio.h>

int factorial(int n);//Declaracion de funcion de tipo entera

int main()

{
	int n=0,f;//Declaracion de variables
	printf("Ingrese un numero para ver su factorial: ");//Pedido de numero
	scanf("%d",&n);
	f=factorial(n);//'f' llama a la funcion factorial y toma el valor retornado por la misma
	printf("!%d: %d",n,f);//Se muestra el resultado
	getch();
	return 0;
}

//********************funcion factorial*********************

int factorial(int n)

{
	int i=0;//Variable para contador
	for(i=n-1;i>=1;i--)//Calculo del factorial, creo que ya no hace falta explicarlo..
		{
			n=n*i;
		}
	return n;//Se retorna el valor de 'n', que lo tomara 'f'	
}
