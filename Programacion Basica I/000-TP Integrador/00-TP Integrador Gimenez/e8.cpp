/*
8)	Se solicita se desarrolle un programa que dada un cadena de caracteres ingresada en un array de char, la
misma se muestre en orden inverso al ingresado. Utilizando para su desarrollo una función y punteros para su
solución.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void ingreso(char *ptr);
void reversa(char *ptr_rev,int tam);//la consigna dice 'usando punteros', asi que hice 2 (?)

int main()

{
	int i=0,tam=0;
	char palabra[20],*ptr=NULL,*ptr_rev=NULL;
	ptr=palabra;
	ingreso(ptr);
	tam=strlen(palabra)-1;
	ptr_rev=&palabra[tam];//o hacer ptr=&palabra[tam] para usar un puntero solo
	reversa(ptr_rev,tam);
	getch();
	return 0;
}

void ingreso(char *ptr)

{
	printf("Ingrese una palabra: ");
	gets(ptr);
}

void reversa(char *ptr_rev,int tam)

{
	int i=0;
	for(i=0;i<=tam;i++)
		{
			printf("%c",*(ptr_rev-i));
		}
}


