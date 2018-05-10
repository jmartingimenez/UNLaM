#include<stdio.h>
#include<conio.h>
#include<math.h>

/*
--------------------------------------------------------------------------
	Programa: Sacar la raiz de un numero.
--------------------------------------------------------------------------	


	Se puede ingresar radicando e indice. (funciona con decimales)

***Hecho con pow usando propiedades de la potenciacion/radicacion
	Ej.: (raiz cuadrada de 4 es igual a 4 elevado a 1/2)

	Uso float por que con int no me calculaba bien.
	
	o es la variable que controla la operacion
	rcand es la variable que guarda el radicando
	ind es la variable que guarda el indice

*/

main()

{
float o=0,rcand=0,ind=0;
printf("Este programa permite calcular la raiz de un numero seleccionado.\n");
printf("Ingrese un radicando: ");
scanf("%f",&rcand);	
printf("Ingrese un indice: ");
scanf("%f",&ind);
o=pow(rcand,1/ind);
printf("Resultado: %.2f",o);	
getch();
return(1);	
}
