#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/*

Programa: Calcular la potencia o raiz cuadrada de un numero.

	math.h es la libreria para poder usar el pow(comando para calcular potencia)
y sqrt (square root/raiz cuadrada)
	num guarda el numero ingresado, exp el exponente y res muestra el resultado.

***Explicacion del uso..
	res=pow(num,exp)
	El resultado(res) es igual a la potencia(pow) de (num) elevado a (exp)
	sqrt(num) <----- raiz cuadrada del numero ingresado.

*/

main()

{
	
float num,exp,res;
printf("Calcule la potencia de un numero.\n");
printf("- El resultado mostrara los primeros 4 decimales. -\n");
printf("Ingrese un numero: ");
scanf("%f",&num);
printf("\nIngrese un exponente: ");
scanf("%f",&exp);
res=pow(num,exp);
printf("\nResultado: %.4f",res);
printf("\n-----------------------------");
printf("\nCalculando raiz cuadrada..");
printf("\nIngrese el radical: ");
scanf("%f",&num);
res=sqrt(num);
printf("\nResultado: %.4f",res);
getch();
return(1);
}

