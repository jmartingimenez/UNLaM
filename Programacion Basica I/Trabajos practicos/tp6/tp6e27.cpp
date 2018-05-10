#include<stdio.h>
#include<conio.h>
#include<string.h>
#define TAM 50


main()

{
	int i=0,tam_real=0,pal=0;
	char palabra[50];
	printf("Ingrese una palabra sin espacios y que no supere los 50 caracteres:\n");
	scanf("%s",&palabra);//Si es una palabra sola, los espacios no cuentan, usar el gets es al dope^^
	tam_real=strlen(palabra);//Quitando los espacios vacios
	printf("\n\t\t\tTamanio real: %d caracteres\n\n",tam_real);//Mostrando el tamaño de la palabra	
	for(i=0;i<tam_real;i++)//Desde la primer letra hasta la ultima
		{
			/*
			printf("\n\t\t\ttest posicion reversa, comienzo: %c",palabra[tam_real-1-i]);	
			Con lo de arriba se ve como va comparando letra por letra
			*/		
			if(palabra[i]!=palabra[tam_real-1-i])
				{
					pal++;
				}
		}
	if(pal==0)
		{
			printf("\n\nLa palabra %s es palindroma",palabra);
		}
	else
		{
			printf("\n\nLa palabra %s no es palindroma",palabra);
		}	
	getch();
	return(1);
}
