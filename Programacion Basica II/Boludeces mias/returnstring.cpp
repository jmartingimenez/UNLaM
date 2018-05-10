#include<stdio.h>
#include<conio.h>
#include<string.h>

char *funcion();

int main()

	{
		char *p=funcion();
		printf("%s ",p);
		printf(" %s",p);
	}

char *funcion()

	{
		static char nombre[5]="hola";
		return nombre;
	}	
