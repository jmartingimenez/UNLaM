/*

	i= variable contador para los bucles y las posiciones del vector
	A= Array (vector)
	MAX= constante para el limite de numeros ingresados (lo deje en 5 a proposito)

***Explicacion del ultimo for por las dudas: 
				for(i=MAX-1;i>=0;i--)
		- Comienza en la posicion maxima-1 (ya que debe bajar a 0) -los array inician en 0-	
		- Se ejecuta mientras i>=0
		- Se resta un valor de i (entonces va bajando la posicion), Ej.: A[29],A[28]...A[0]		

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5//El ejercicio pide 100, lo deje asi para probarlo rapido

main()

{

int i=0,A[MAX];
for(i=0;i<MAX;i++)//Limpiando basura
	{
		A[i]=0;
	}	
for(i=0;i<MAX;i++)//Pedido de numeros, se asignan en la posicion que indica i
	{
		printf("Ingrese un numero: ");
		scanf("%d",&A[i]);
	}	
system("cls");
printf("Numeros segun su orden de ingreso\n---------------------\n");
for(i=0;i<MAX;i++)//muestra los numeros ingresados en orden
	{
		printf("%d ",A[i]);
	}	
printf("\n\nNumeros en el orden inverso\n---------------------\n");
for(i=MAX-1;i>=0;i--)//muestra los numeros en orden inverso
	{
		printf("%d ",A[i]);
	}	
getch();
return(1);	
}
