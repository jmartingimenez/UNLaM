#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()

{
	FILE *p_arch;
	int largo;
	char nombre[20],extension[5]=".txt";
	printf("Ingrese nombre: ");
	gets(nombre);
	strcat(nombre,extension);
	fopen(nombre,"w+");
	fclose(p_arch);
}
