#include<stdio.h>
#include<conio.h>

/*

	ct= Contador total, El bucle va 10 veces xq el interior va 5 (5*10)
Siempre al final resetea suma5.
	suma5=Guarda el resultado de las sumas de los 5 numeros del for interno. Al salir de ese bucle se vuelve a igualar a 0.
	num=Guarda el numero ingresado.
	Suma=La suma de todos los numeros.
	cn= Contador parcial, regula el bucle interno para que solo corra 5 veces, antes de salir para resetearse 'suma5'.	

*/
main()

{
	
	int cn=1,ct=1,num=0,suma5=0,suma=0;
for(ct=1;ct<=10;ct++)
	{
		for(cn=1;cn<=5;cn++)
			{
				printf("\nIngrese un numero: ");
				scanf("%d",&num);
				suma5=suma5+num;
		
			}
printf("\n--------------------");
printf("\nLa suma de los 5 numeros anteriores es %d.",suma5);	
printf("\n--------------------");
suma=suma+suma5;
suma5=0;		
	}
printf("\nLa suma de todos los numeros es de %d.",suma);
printf("\n--------------------");	
	
getch();
return(1);	
}
