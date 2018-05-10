/*

	Programa: Leer un vector de números enteros de 100 elementos y sumar las posiciones pares
				
(Lo hice de manera de que sume los ingresos pares, en vez de las posiciones)***Ver nota
					
	i= variable contador para el for y las posiciones del array
	suma= variable que va guardando la suma de las posiciones pares <-----ver nota
	re= para guardar el valor del resto '0/1' <---ver nota
	MAX= constante para guardar el limite de posiciones del array
	A= array (vector)
				
***Nota: Cuando se calcula el resto da 2 posibles valores: 0 si es par y 1 si es impar.
La razon de que este usando 1 (impar) en el if tiene que ver con que las posiciones
en el vector no comienzan de 1, sino de 0. 
					
	Ej usando 0: A[0]=par,A[1]=impar,A[2]=par...
		(esto es lo correcto, el problema es que al comenzar de 0, para nosotros al abrir
el programa, la posicion 0 -par- seria el primer ingreso -impar-. SE SUMARIAN LAS
POSICIONES PARES DEL VECTOR, PERO ESTAS POSICIONES SERIAN LOS INGRESOS IMPARES!!.)
	Por esto agrege mostrar la posicion del numero a ingresar con el 'i+1'
	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10//El ejercicio pide 100, pero deje 10 para probar rapido el programa

main()

{
int i=0,suma=0,re=0,A[MAX];
for(i=0;i<MAX;i++)//Limpiando basura
	{
		A[i]=0;
	}	
for(i=0;i<MAX;i++)//Pidiendo ingresos
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
		re=i%2;
		if(re==1)//Guardamos las posiciones impares para sumar los ingresos pares (ver nota)
			{
				suma+=A[i];
			}
	}	
system("cls");
printf("La suma de las posiciones pares es: %d",suma);	
getch();
return(1);	
}
