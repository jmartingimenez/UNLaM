#include<stdio.h>
#include<conio.h>

/*
Programa: Clasificar numeros entre 1 y 5.

La variable i controla que sean 10 opciones.
El cod clasifica que el valor ingresado este en el rango deseado.
n1, n2, n3, n4 y n5 son variables para clasificar los numeros.
*/
main()

{//inicio

int i=0,cod=0,n1=0,n2=0,n3=0,n4=0,n5=0;
for(i=0;i<10;i++)
	{
		printf("Ingrese un numero entre 1 y 5: ");
		scanf("%d",&cod);
		if((cod>=1)&&(cod<=5))
		{
		
		switch(cod)
			{
				case 1:if(cod==1)
					{
					n1++;//agrega el valor ingresado a esta variable.
					break;	
					}
				case 2:if(cod==2)
					{
					n2++;//agrega el valor ingresado a esta variable.
					break;	
					}
				case 3:if(cod==3)
					{
					n3++;
					break;//agrega el valor ingresado a esta variable.	
					}
				case 4:if(cod==4)
					{
					n4++;//agrega el valor ingresado a esta variable.
					break;	
					}
				case 5:if(cod==5)
					{
					n5++;//agrega el valor ingresado a esta variable.
					break;	
					}
			}
			}
			else
			{
				printf("ERROR!!: Solo se permiten numeros entre 1 y 5.\n");
				i--;//Resta un valor en el contador para que se pueda llegar a 10 ingresos.		
			}
	}
printf("\nLa cantidad de unos es de %d.",n1);
printf("\nLa cantidad de dos es de %d.",n2);
printf("\nLa cantidad de tres es de %d.",n3);
printf("\nLa cantidad de cuatros es de %d.",n4);
printf("\nLa cantidad de cincos es de %d.",n5);

getch();
return(1);
}//inicio
