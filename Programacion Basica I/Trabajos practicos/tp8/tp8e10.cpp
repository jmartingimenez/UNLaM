/*	(enunciado)
Ingresar un numero e imprimir asteriscos hasta el numero ingresado, ejemplo si ingreso un 3: en la primer linea
pongo un asterisco, en la segunda dos asteriscos y en la tercera 3. Asi hasta alcanzar el nummero ingresado
*/

#include<stdio.h>
#include<conio.h>

int *ptr=NULL;

void asterisco(int *ptr);

int main()

{
	int n=0;
	printf("Ingrese un numero: ");
	scanf("%d",&n);
	ptr=&n;
	asterisco(ptr);
	getch();
	return 0;
}

void asterisco(int *ptr)

{
	int i=0,j=0;	
	for(i=1;i<=*ptr;i++)
		{
			for(j=0;j<i;j++)
				{
					printf("*");
				}
			printf("\n");	
		}
}
