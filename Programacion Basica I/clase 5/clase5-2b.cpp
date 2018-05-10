#include<stdio.h>
#include<conio.h>

/*
Programa: Clasificacion de numeros en ceros, positivos y negativos.


La variable i controla que sean 20 opciones.
La variable num controla los numeros ingresados.
cc,cp,cn son variables para clasificar los numeros entre
positivos, negativos y ceros.
*/ 

main()

{
	
	int cc=0,cp=0,cn=0,num=0;
	float i=0;
	for(i=0;i<20;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%i",&num);
		if(num==0)
			{
			cc++;//agrega el valor ingresado a esta variable.
			}
		else
		{
			if(num>0)
			{
				cp++;//agrega el valor ingresado a esta variable.
			}
			else
			{
				if(num<0)				
				{
					cn++;//agrega el valor ingresado a esta variable.
				}
			}
		}




		}
	
printf("\nLa cantidad de ceros es de %d.",cc);
printf("\nLa cantidad de numeros positivos es de %d.",cp);
printf("\nLa cantidad de numeros negativos es de %d.",cn);

getch();
return(1);	
}
