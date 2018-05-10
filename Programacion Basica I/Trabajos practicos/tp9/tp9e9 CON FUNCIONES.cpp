#include<stdio.h>
#include<conio.h>
#include<string.h>

char cadena1[50],cadena2[50];

int palabra(int valor,char cadena1[],char cadena2[]);
void mayor(int valor);

int main()
{
	int valor=0;	
	valor=palabra(valor,cadena1,cadena2);
	mayor(valor);
	getch();
	return 0;
}

int palabra(int valor,char cadena1[],char cadena2[])

	{
		printf("Ingrese una palabra: ");
		gets(cadena1);
		printf("Ingrese otra palabra: ");
		gets(cadena2);
		valor=strcmp(cadena1,cadena2);	
		return valor;	
	}	

void mayor(int valor)
	
	{
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
	}	
	


