/*
7)	Realizar un programa que dado el ingreso de una fecha, el programa debe validar
si se trata de una fecha válida, de lo contrario pedirá nuevamente su ingreso o termina.
----------------------------------------------------------------------------------------
Por si alguien quiere hacerlo como corresponde...

Wikipedia dice: Un año es bisiesto si es divisible entre 4, excepto aquellos divisibles entre 100
pero no entre 400.

***NOTA:El mio solo se basa en el 2015, por lo que solo pide mes y dia
En el vector..
[0]Ene= 31
[1]Feb= 28
[2]Mar= 31
[3]Abr= 30
[4]May= 31
[5]Jun= 30
[6]Jul= 31
[7]Ago= 31
[8]Sep= 30
[9]Oct= 31
[10]Nov= 30
[11]Dic= 31
*/

#include<stdio.h>
#include<conio.h>

int funcion_meses();
int funcion_dia();
void mensaje(int dia,int mes,int *ptr);

int main()

{
	int dia=0,mes=0,meses[12]={31,28,31,30,31,30,31,31,30,31,30,31},*ptr;
	mes=funcion_meses();
	dia=funcion_dia();
	ptr=&meses[mes-1];
	mensaje(dia,mes,ptr);	
	getch();
	return 0;
}

int funcion_meses()

{
	int mes=0;
	while((mes<1)||(mes>12))
		{
			printf("Ingrese el numero de mes\n-----------------\n\n");
			printf("1-Enero\n2-Febrero\n3-Marzo\n4-Abril\n5-Mayo\n6-Junio\n");
			printf("7-Julio\n8-Agosto\n9-Septiembre\n10-Octubre\n11-Noviembre\n12-Diciembre\n\nSeleccion: ");
			scanf("%d",&mes);
			if((mes<1)||(mes>12))	
				{
					printf("ERROR!!: Codigo de mes incorrecto.");
				}
		}
	return mes;	
}

int funcion_dia()

{
	int dia=0;
	printf("Ingrese el dia: ");
	scanf("%d",&dia);
	return dia;

}

void mensaje(int dia,int mes,int *ptr)

{
	if((dia>*(ptr)||(dia<1)))
		{
			printf("La fecha %d/%d/2015 no existe.",dia,mes);
		}
	else
		{
			printf("La fecha %d/%d/2015 existe.",dia,mes);
		}	
	printf("\nEl mes %d tiene %d dias.",mes,*(ptr));		
}
