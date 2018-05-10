#include<stdio.h>
#include<conio.h>
#include<string.h>

void func_cadenas(char *ptr,char *ptr2);
void func_compare(char *ptr,char *ptr2);

int main()

{
	int tam=0;
	char cad1[20],cad2[20],*ptr=cad1,*ptr2=cad2;
	func_cadenas(ptr,ptr2);
	tam=strlen(ptr);
	func_compare(ptr,ptr2);
	getch();
	return 0;
}

void func_cadenas(char *ptr,char *ptr2)

{
	printf("Ingrese una palabra: ");
	gets(ptr);
	printf("Ingrese otra palabra: ");
	gets(ptr2);
}

void func_compare(char *ptr,char *ptr2)

{
	int c=strcmp(ptr,ptr2);
	if(c==0)
		{
			printf("Las palabras son iguales.");
		}	
	else
		{
			printf("Las palabras no son iguales.");
		}
}

