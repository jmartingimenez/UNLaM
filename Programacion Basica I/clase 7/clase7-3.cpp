#include<stdio.h>
#include<conio.h>

/*

Programa: Mostrar codigo ascii desde un rango determinado
(ejemplo, entre rango 10 y 15 mostrara alt+10,alt+11,alt+12,alt+13,alt+14,alt+15.

	ri(varialble que define el rango inicial)
	rf(variable que define el rango final)
	val es una variable de caracter(para utilizar la letra ingresada)
	fflush(stdin) <----Limpia memoria del teclado.
	El while hace q se muestre desde el rango inicial y por cada bucle
aumentara en 1 (val++) hasta llegar al rango final.

*/

main()

{
int ri=0,rf=0;
printf("Ingrese un rango inicial: ");
scanf("%d",&ri);
printf("Ingrese un rango final: ");
scanf("%d",&rf);
char val;
val=ri;
while(val<=rf)
	{
	fflush(stdin);
	printf("\n%c",val);
	val++;
	}
	
getch();
return 0;	
}
