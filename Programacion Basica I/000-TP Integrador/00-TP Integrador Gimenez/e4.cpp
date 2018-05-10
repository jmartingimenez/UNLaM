/*
4)	Desarrollar un programa en C que dado el ingreso de  2 vectores de números con decimales. 
El primero va a ingresar  la cantidad, mientras que el segundo va recibir el precio del producto. 
Desarrollar una función que genere un vector en el que se calcule y se informen los totales de
los 10 productos ingresados.
*/

#include<stdio.h>
#include<conio.h>

void ingreso_producto(float *ptr,float *ptr2);
void total(float *ptr,float *ptr2);

int main()

{
	int i=0;
	float cantidad[10],precio[10],*ptr,*ptr2;
	for(i=0;i<10;i++)
		{
			cantidad[i]=0;
			precio[i]=0;
		}
	ptr=cantidad;
	ptr2=precio;
	ingreso_producto(ptr,ptr2);	
	total(ptr,ptr2);
	getch();
	return 0;
}

void ingreso_producto(float *ptr,float *ptr2)

{
	int i=0;
	for(i=0;i<10;i++)
		{
			printf("Ingrese el precio del producto %d: ",i+1);
			scanf("%f",ptr+i);
			printf("Ingrese la cantidad llevada del producto %d: ",i+1);
			scanf("%f",ptr2+i);
		}
}

void total(float *ptr,float *ptr2)

{
	int i=0;
	float precio[10];
	printf("\nProducto\tPrecio\tCantidad\tPrecio Final\n-------------------------------------------------\n\n");
	for(i=0;i<10;i++)
		{
			precio[i]=(*(ptr+i)*(*(ptr2+i)));
			printf("%d\t\t$%.2f\t%.0f\t\t$%.2f\n",i+1,*(ptr+i),*(ptr2+i),precio[i]);
		}
}


