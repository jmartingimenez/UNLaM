/*		(enunciado)

Confeccionar un programa que calcule la sumatoria de los elementos que se encuentran
en las posiciones par y que ademas encuentre de ellos cual es el mayor elemento
Mostrar los resultados obtenidos	

//////////////////////////////

	Programa: Hacer lo de arriba xD
		
			
	i= variable contador
	suma= variable que va guardando la suma de los numeros pares
	max= variable que guarda el numero mas alto
	re= variable que guarda el resultado del calculo del resto
	A[MAX]= array de 10 posiciones
	
***Explicacion..

	-Se comprueba que el resto de i (la posicion actual) sea impar. COMO LOS VECTORES
COMIENZAN EN 0 LO QUE VEMOS EN PANTALLA COMO POSICION IMPAR, EN REALIDAD ES PAR

	Ej. 'Ingrese un numero en la posicion 1: ' (el 1 es impar, pero la verdadera posicion
del vector es 0 -el 1 se muestra por el 'i+1')	
	-Si i=0 (si es la primera vez que se inicia el bucle), se setea como numero mas
alto el primer numero ingresado. Si esto no se hace, y en mi vector solo cargara numeros
negativos, la variable max seguiria valiendo 0 (ya que es mayor a cualquier numero negativo)
	-El 'else' siguiente es simplemente para que en las repeticiones siguientes ya se
pueda comparar el numero ingresado con el que se encuentra guardado en 'max'
	
*/

#include<stdio.h>
#include<conio.h>
#define MAX 10

main()

{
int i=0,suma=0,max=0,re=0,A[MAX];
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
		re=i%2;
		if(re==1)
			{
				suma+=A[i];
			}
		if(i==0)
			{
				max=A[i];
			}	
		else
			{
				if(A[i]>max)
					{
						max=A[i];
					}
			}	
	}	
printf("--\n\nLa suma de las posiciones pares del vector es: %d",suma);
printf("\nEl numero mas grande es: %d",max);	
getch();
return(1);	
}
