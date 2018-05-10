/*
1)	Desarrollar un programa en lenguaje C que cargue un array de enteros de 20 posiciones y por medio de dos
funciones realice e informe como resultado:
a.	La carga de un vector con los elementos pares
b.	La carga de otro vector con los elementos impares
*/

#include<stdio.h>
#include<conio.h>

int i=0;

void limpiar(int *ptr);
void pares(int *ptr);
void impares(int *ptr);
void mostrar(int *ptr);

int main()

{
	int v[20],*ptr;
	ptr=v;
	limpiar(ptr);
	pares(ptr);
	impares(ptr);
	mostrar(ptr);
	getch();
	return 0;
}

void limpiar(int *ptr)

{
	for(i=0;i<20;i++)
	{
		*(ptr+i)=0;
	}
}

void pares(int *ptr)

{
	printf("Llenando posiciones pares\n--------------------------------\n\n");
	for(i=0;i<20;i++)
		{
			if(i%2==0)
				{
					printf("Ingrese un numero en la posicion %d: ",i);
					scanf("%d",ptr+i);
				}
		}
}

void impares(int *ptr)

{
	printf("\n\nLlenando posiciones impares\n--------------------------------\n\n");
	for(i=0;i<20;i++)
		{
			if(i%2==1)
				{
					printf("Ingrese un numero en la posicion %d: ",i);
					scanf("%d",ptr+i);
				}
		}
}

void mostrar(int *ptr)

{
	for(i=0;i<20;i++)
		{
			printf("%d ",*(ptr+i));
		}
}
