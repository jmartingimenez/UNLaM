/*
2)	Desarrollar un programa que posea una función denominada copiarArray() que reciba dos arrays y el tamaño
de los mismos (deben de ser del mismo tamaño) y que consiga copiar en el segundo array el contenido del primero
*/

#include<stdio.h>
#include<conio.h>

int i=0;
void ingreso(int *ptr);
void copiararray(int *ptr,int *ptr2);
void mostrar(int *ptr,int *ptr2);


int main()

{
	int v1[5],v2[5],*ptr,*ptr2;
	ptr=v1;
	ptr2=v2;
	ingreso(ptr);
	copiararray(ptr,ptr2);
	mostrar(ptr,ptr2);
	getch();
	return 0;
}

void ingreso(int *ptr)

{
	for(i=0;i<5;i++)
		{
			printf("Ingrese un numero en la posicion %d: ",i);
			scanf("%d",ptr+i);
		}
}

void copiararray(int *ptr,int *ptr2)

{
	for(i=0;i<5;i++)
		{
			*(ptr2+i)=*(ptr+i);
		}
}

void mostrar(int *ptr,int *ptr2)

{
	printf("\ncargado\t\t\t\tcopiado\n---------------------------------------\n\n");
	for(i=0;i<5;i++)
		{
			printf("%d\t\t\t\t%d\n",*(ptr+i),*(ptr2+i));
		}
}

