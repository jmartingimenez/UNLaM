/*
6)	Desarrollar un programa que te permita cargar un vector de 20 posiciones. El ingreso de los mismos será
por medio del ingreso del menor valor incrementándose el mismo hasta completar el vector.
a.	En una función realizar la carga anterior mente mencionada
b.	En otra función realizar el cálculo de la media de los valores ingresados e informar
*/

#include<stdio.h>
#include<conio.h>
#define MAX 20

void carga(int *ptr);
void calculo(int *ptr);

int main()

{
	int i=0,v[MAX],*ptr;
	ptr=v;
	carga(ptr);
	calculo(ptr);	
	getch();
	return 0;
}

void carga(int *ptr)

{
	int i=0;
	for(i=0;i<MAX;i++)
		{
			*(ptr+i)=0;//Limpieza
			printf("Ingrese un numero en la posicion %d: ",i+1);
			scanf("%d",ptr+i);
			if((i>0)&&(*(ptr+i)<=*(ptr+i-1)))
				{	/*						
					-Solo si no es el primer numero se compara el ingresado con el anterior
					-Se esta comparando a donde apunta y la posicion anterior (el -1)*/
					printf("\t\tERROR!!: El numero ingresado debe ser mayor al anterior (%d)\n",*(ptr+i-1));
					i--;//Para que siga pidiendo en la misma posicion donde se genero el error	
				}		//Si o si van a ser 5 numeros, uno mayor que el anterior
		}
}

void calculo(int *ptr)

{
	int i=0;
	float promedio=0;
	for(i=0;i<MAX;i++)
		{
			promedio+=((float)*(ptr+i));//Sumando los numeros
		}
	promedio/=MAX;//Dividiendolos por la cantidad
	printf("La media de los valores ingresados es: %.2f",promedio);
		
}
