#include<stdio.h>
#include<conio.h>
#include<string.h>

main()
{
	int valor=0;
	char cadena1[50],cadena2[50];
	printf("Ingrese una palabra: ");
	gets(cadena1);
	printf("Ingrese otra palabra: ");
	gets(cadena2);
	valor=strcmp(cadena1,cadena2);
	if(valor>0)
		{
			printf("%s es la mayor cadena",cadena1);
		}
	else
		{
			if(valor==0)
				{
					printf("Las cadenas son iguales");
				}
			else
				{
					printf("%s es la mayor cadena",cadena2);
				}	
		}	
	
	
	
	getch();
	return 0;
}
