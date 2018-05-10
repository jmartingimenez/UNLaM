/*

	Programa: Decir si un numero es perfecto.
	
(Un numero es perfecto si la suma de sus divisores es igual al mismo. Ej.: 6 es un numero
perfecto por que sus divisores son 1,2 y 3 (1+2+3=6))	

	n= variable que guarda el numero ingresado
	p= variable que llama a la funcion 'perfecto' y toma el valor retornado por la misma
(si retorna 1, el numero es perfecto)
	i= variable contador para el for que hara las divisiones 'n/i' buscando el 'resto 0'
	divisores= variable que acumulara los valores de 'i' que generen un 'resto 0'
	re= variable que guardara el resto de 'n/i'
		
*/

#include<stdio.h>
#include<conio.h>

int perfecto(int n);//Declaracion de funcion

int main()

{
	int n=0,p;//Declaracion de variables
	printf("Ingrese un numero: ");//Pedido de numero
	scanf("%d",&n);
	p=perfecto(n);//'p' llama la funcion 'perfecto' y toma el valor retornado por esta
	if(p==1)//Si p es igual a 1...
		{
			printf("El numero %d es perfecto.",n);
		}
	else//De lo contrario..
		{
			printf("El numero %d no es perfecto.",n);
		}	
	getch();
	return 0;	
}

//*******************************(Funcion perfecto)*********************************

int perfecto(int n)

{
	int i=0,divisores=0,re=0;//Declaracion de variables locales
	for(i=1;i<=n/2;i++)//Se divide 'n/1, n/2... hasta llegar al valor de 'n'
		{
			re=n%i;//Se calcula el resto...
			if(re==0)//Si el resto es 0...
				{
					divisores+=i;//Se suma el valor de 'i' a la variable 'divisores'
				}
		}
	if(divisores==n)//Si la suma de los divisores es igual a 'n'
		{
			return 1;//'p' retorna 1
		}	
	else
		{
			return 0;//'p' retorna 0
		}	
}
