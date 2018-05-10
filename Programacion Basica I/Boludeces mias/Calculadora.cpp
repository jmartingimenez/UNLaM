#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

Programa: Calculadora basica.

	Tiene el retroceso hacia atras usando while, se puede buggear si escribis
letras.

*/

main()

{
int seleccion,volver;	
float val1,val2,operacion;
printf("Calculadora (Se aceptan decimales, solo se mostraran 2)\n");
printf("--------------------------------------\n\n");
while(seleccion>4 || seleccion <1)
	{
	printf("Elige la operacion que deseas realizar.\n");
	printf("1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n\nSeleccion: ");
	scanf("%d",&seleccion);	
	system("cls");
	switch(seleccion)
		{
			case 1:
				
					printf("Suma.\nIngrese un numero: ");
					scanf("%f",&val1);
					printf("\nIngrese otro numero: ");
					scanf("%f",&val2);
					operacion=val1+val2;
					printf("\nEl resultado es: %.2f",operacion);
					printf("\n\nDesea realizar otra operacion?");
					printf("\nPulse 1 para si, cualquier tecla para salir: ");
					scanf("%d",&volver);
					if(volver==1)
						{
							seleccion=5;
							system("cls");
						}
					break;

			case 2:
					printf("Resta.\nIngrese un numero: ");
					scanf("%f",&val1);
					printf("\nIngrese otro numero: ");
					scanf("%f",&val2);
					operacion=val1-val2;
					printf("\nEl resultado es: %.2f",operacion);
					printf("\n\nDesea realizar otra operacion?");
					printf("\nPulse 1 para si, cualquier tecla para salir: ");
					scanf("%d",&volver);
					if(volver==1)
						{
							seleccion=5;
							system("cls");
						}
					break;	
	
			case 3:
	
					printf("Multiplicacion.\nIngrese un numero: ");
					scanf("%f",&val1);
					printf("\nIngrese otro numero: ");
					scanf("%f",&val2);
					operacion=val1*val2;
					printf("\nEl resultado es: %.2f",operacion);
					printf("\n\nDesea realizar otra operacion?");
					printf("\nPulse 1 para si, cualquier tecla para salir: ");
					scanf("%d",&volver);
					if(volver==1)
						{
							seleccion=5;
							system("cls");
						}
					break;
	
			case 4:
					printf("Division.\nIngrese un numero: ");
					scanf("%f",&val1);
					printf("\nIngrese otro numero: ");
					scanf("%f",&val2);
					operacion=val1/val2;
					printf("\nEl resultado es: %.2f",operacion);
					printf("\n\nDesea realizar otra operacion?");
					printf("\nPulse 1 para si, cualquier tecla para salir: ");
					scanf("%d",&volver);
					if(volver==1)
						{
							seleccion=5;
							system("cls");
						}
					break;
	
			default:
					printf("\t\tERROR!!: Codigo erroneo.\n\n");
					break;
					
		}			
	}
printf("\n\t\tAdios!!.");	
getch();
return(1);	
}

