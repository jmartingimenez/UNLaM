/*			(enunciado)

Dado el vector vector1 de tamaño n. Si el tamaño es par, se desea que el programa 
permita invertir y mostrar los elementos de la mitad de los elementos, tanto la mitad
inferior del vector como así también la superior. Esto debe aplicarse a cualquier tamaño
con cantidad elementos pares.

Ejemplo:   vector1[]={1,2,3,4,5,6}  		vector_invertido[]={3,1,2,6,5,4}

*/

//************************************************************************************

/*			(mi descripcion)

	Programa: Hacer lo que dice arriba xD
		
	i= variable contador para el for y las posiciones del array
	n= numero ingresado que define cuantas posiciones tendra el array
	re= para calcular el resto y decidir que hacer 
	A= array (vector)
		
	-1er for= pide los numeros y los almacena en el vector
	-2do for= muestra los numeros ingresados	
	-3er for= muestra los numeros de la mitad del vector en posicion invertida
(si el vector tiene 10 posiciones, se muestran los primeros 5 numeros al reves)
	-4to for= muestra los numeros de la segunda mitad del vector en posicion invertida
(si el vector tiene 10 posiciones, se muestran los segundos 5 numeros al reves)

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()

{

int i=0,n=0,re=0;
printf("Ingrese el tamanio del vector: ");
scanf("%d",&n);	
re=n%2;
if(re==1)//Chau programa :D
	{
		printf("El tamanio del vector es impar. No es que podamos hacer mucho :)");
	}
else//A laburar
	{
		int A[n];
		for(i=0;i<n;i++)//pidiendo numeros
			{
				printf("Ingrese un numero: ");
				scanf("%d",&A[i]);
			}
		system("cls");
		printf("Numeros ingresados\n------------------\n");
		for(i=0;i<n;i++)//mostrando los numeros que pusiste
			{
				printf("%d ",A[i]);
			}	
		printf("\n\n\nNumeros ingresados invertidos por cada mitad del vector\n---------------\n");
		for(i=(n-1)/2;i>=0;i--)//primera mitad de los numeros invertida
			{
				printf("%d " ,A[i]);
			}	
		for(i=n-1;i>=n/2;i--)//segunda mitad de los numeros invertida
			{
				printf("%d ",A[i]);
			}			
	}	
getch();
return(1);	
}
