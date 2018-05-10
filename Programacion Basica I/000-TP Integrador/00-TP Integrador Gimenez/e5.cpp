/*
5)	Desarrollar un programa en código C que dado el ingreso de un numero realice tres acciones posibles:

a.	Que calcule el factorial del número mediante una función
b.	Que calcule la potencia del número (dando como dato adicional a que número se lo desea elevar. Desarrollar
otra función
c.	Una función que muestre el menú de las opciones que contemple la opción salir

*/

#include<stdio.h>
#include<conio.h>

int menu(int num);
void fact(int num);
void pot(int num);

int main()

{
	int m=0,num=0;
	while(m!=3)
		{
			printf("Ingrese un numero: ");
			scanf("%d",&num);
			m=menu(num);
			switch(m)
				{
					case 1:
						fact(num);
						break;
					case 2:
						pot(num);
						break;
					case 3:
						break;
					default:
						printf("ERROR!!: Codigo incorrecto.");
						break;		
				}
		}
	getch();
	return 0;
}

int menu(int num)

{
	int seleccion=0;
	printf("Seleccione que desea hacer con el numero %d\n-----------------\n\n",num);
	printf("1-Calcular el factorial de %d",num);
	printf("\n2-Calcular una potencia de %d",num);
	printf("\n3-Salir\n\nSeleccion: ");
	scanf("%d",&seleccion);
	return seleccion;	
}

void fact(int num)

{
	int i=0,resu=num;
	for(i=num-1;i>=1;i--)
		{
			resu*=i;
		}
	printf("El factorial de %d es: %d\n\n\n",num,resu);	
	
}

void pot(int num)//falta algo para que cuando se eleve a 0 de 1.

{
	int i=0,p=0,resu=num;
	printf("\nSeleccione el exponente para elevar el numero %d: ",num);
	scanf("%d",&p);
	for(i=1;i<p;i++)
		{
			resu*=num;
		}
	printf("El resultado es: %d\n\n\n",resu);	
}
