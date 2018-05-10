#include<stdio.h>
#include<conio.h>

/*

	i= contador de numeros ingresados
	j= contador de posiciones del vector
	k= contador extra para resultados finales

***Explicacion del if

-Si el numero ubicado en la posicion actual en el vector A es mayor al numero ubicado
en la posicion siguiente. (entonces)...
	-La variable temporal guarda el valor de la posicion actual de j en el bucle
	-El vector toma como valor de la posicion actual el valor de la posicion siguiente
	-La posicion siguiente de j toma el valor guardado en la variable temporal
(estos 3 pasos realizan un intercambio de valores)
**Ej..
	Si... A[1]=3 y A[2]=1   <----- [1] seria j y [2] seria j+1
	temp=A[1];    <-----La variable temporal pasa a valer 3
	A[1]=A[1+1] <---- A[1] pasa a tener el valor de A[2] (osea, ahora vale 1)
	A[1+1]=temp <--- A[2] pasa a valer 3

***Estos 3 pasos dejarian... A[1]=1 y A[2]=3	

(No estoy seguro si es necesario una variable extra para el for final, pero no me da
problemas mostrando los resultdos)

*/	

main()
{
short int temp=0,i=0,j=0,k=0,n=3,A[n];
for(i=0;i<n;i++)
	{
		printf("Ingrese un numero en la posicion %hd: ",i+1);
		scanf("%hd",&A[i]);
	}
for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
			{
				if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
			}
	}	
	
printf("\n\n\nOrden: ");
for(k=0;k<n;k++)
	{
		printf("%hd ",A[k]);
	}
getch();
return(1);
}
