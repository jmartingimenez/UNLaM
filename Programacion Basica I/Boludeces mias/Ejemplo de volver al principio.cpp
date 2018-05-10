#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//para usar el system("cls") <---- Limpiar pantalla

/*

Ejemplo creado por mi para volver al inicio al final de un programa.

	opcion es la variable que controla la pregunta final sobre si se desea
volver al principio. Si la opcion es 1 se vuelve al principio del ciclo.

	num1 y num2 son las variables que guardan los numeros ingresados.
	suma se encarga de sumar los 2 numeros ingresados.

*/

main()

{
	int opcion=1;
	float num1=0,num2=0,suma=0;
	while(opcion==1)	
	{
		printf("Programa de suma simple (Se admiten decimales, solo se mostraran 2 al final).");
		printf("\n-------------------");
		printf("\nEscribe el primer numero :\t ");
		scanf("%f",&num1);
		system("cls");
		printf("\nEscribe el segundo numero:\t ");
		scanf("%f",&num2);
		system("cls");
		suma=num1+num2;
		printf(" %.2f\n+\n %.2f\n-----------------\n %.2f",num1,num2,suma);
		printf("\n\nEl resultado es %.2f",suma);
		printf("\nTodos los decimales fueron tomados en cuenta en la operacion.");
		printf("\n\n\n\tDeseas escribir otro numero?");
		printf("\n\n\tSI=1\tNO=Cualquier otra tecla:\t ");
		scanf("%d",&opcion);
		system("cls");//limpiar pantalla
	}
printf("\nBye Bye..");
getch();
return(1);
}

