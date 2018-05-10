//itoa, convierte entero a char		(requiere stdlib)
//atoi, convierte char a entero
#include<stdio.h>
#include<conio.h>
#include<string.h>

main()

{
	int i=0,tam_real=0;
	char cadena[50];
	printf("Ingrese una palabra: ");
	gets(cadena);
	tam_real=strlen(cadena)-1;
	for(i=0;i<=tam_real;i++)
		{
			cadena[i]=cadena[i]-32;			
			printf("%c",cadena[i]);

		}
	getch();
	return 0;
}
