/*	(enunciado)
Usando punteros leer e imprimir un vector de 10 elementos enteros
*/
#include<stdio.h>
#include<conio.h>

int v[10],*ptr=NULL,i=0;

void leer(int *ptr);
void mostrar(int *ptr);

main()

{
	ptr=v;//ptr=&v[0]	<---Es lo mismo
	leer(ptr);
	mostrar(ptr);
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

void mostrar(int *ptr)

{
	for(i=0;i<10;i++)
		{
			printf("Pos %d: %d\n",i,v[i]);
		}		
}
