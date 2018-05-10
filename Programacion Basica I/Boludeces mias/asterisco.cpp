#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

	Programa: Armar una escalerita con asteriscos
	(Se ingresa el numero deseado y arranca desde 1 asterico hasta la cantidad
deseada)

	num es la variable que guarda el numero ingresado
	c es la variable contador que cuenta los bucles hasta el valor ingresado
(El primer bucle se encarga de las repeticiones)
	ast es la variable que imprime los asteriscos
(El segundo bucle se encarga de imprimir los asteriscos)
	reset controla la finalizacion del programa (while)

*/

main()

{
system("color 0f");
int num=0,ast=1,c=0,reset=0;
printf("Este programa crea una escalera de asteriscos.\n");
printf("Ingrese un numero entero mayor a 1 para ver el resultado.\n");
printf("----------------------------------------------------------\n\n\n");
while(num!=95)
	{
		fflush(stdin);
		printf("SI ESCRIBE 95 FINALIZARA EL PROGRAMA.\n");
		printf("Ingrese un numero: ");	
		scanf("%d",&num);
		system("cls");	
		if(num!=95)
		{
			for(c=1;c<=num;c++)
			{
				for(ast=1;ast<=c;ast++)
				{
					printf("*");
				}
				printf("\n");
			}
		}
		printf("\n\n");
	}
getch();
return(1);	
}
