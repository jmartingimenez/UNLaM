//itoa, convierte entero a char		(requiere stdlib)
//atoi, convierte char a entero
#include<stdio.h>
#include<conio.h>
#include<string.h>

void palindromo(char *ptr,int tam_real);

int main()

{
	int tam_real=0;
	char cadena[50],*ptr=NULL;
	printf("Ingrese una palabra: ");
	gets(cadena);
	ptr=cadena;
	tam_real=strlen(cadena)-1;
	palindromo(ptr,tam_real);
	getch();
	return 0;
}

void palindromo(char *ptr,int tam_real)

{
	int i=0;
	for(i=0;i<=tam_real;i++)
		{
			*(ptr+i)=*(ptr+i)-32;			
			printf("%c",*(ptr+i));

		}	
}
