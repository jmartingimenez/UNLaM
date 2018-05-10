/*	(enunciado)
Calcular el mayor valor de un vector utilizando el pasaje del vector a una funcion
*/

#include<stdio.h>
#include<conio.h>

int i=0,v[10],*ptr=NULL;

void leer(int *ptr);
void mayor(int *ptr);

main()

{
	ptr=v;
	leer(ptr);
	mayor(ptr);
	getch();
	return 0;
}

void leer(int *ptr)

{
	for(i=0;i<10;i++)
		{
			printf("Ingrese un numero: ");
			scanf("%d",ptr+i);
		}
}

void mayor(int *ptr)

{
	int mayor=*ptr;
	for(i=0;i<10;i++)
		{
			if(*ptr>mayor)
				{
					mayor=*ptr;
				}
			ptr++;//Para que vaya a la direccion siguiente para seguir comparando				
		}
	printf("El numero mas grande es %d.",mayor);	
}

