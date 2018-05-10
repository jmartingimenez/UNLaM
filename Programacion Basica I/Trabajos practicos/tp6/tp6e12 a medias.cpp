/*								(enunciado)
	
	Realizar la carga por teclado de 10 elementos cuyo tipo de dato es entero largo,
almacenar los mismos en un array unidimensonal. General dos nuevos array del mismo
tamaño:

	a. El primero mostrara el 45% del valor inicial cargado
	b. El segundo numero se mostrara en forma ordenada ascendente

*/

//////////////////////////////////////////////////////////////////////////////////////

/*								(mi descripcion)

	Programa: Hacer lo de arriba xD
			
***Nota: No entiendo el punto a, asi que lo hago suponiendo que tengo que sumar todos
los numeros que meta al vector y mostrar el 45% de ese resultado. Lo hice con un vector
solo. (por fiaca)	

*/

#include<stdio.h>
#include<conio.h>
#define MAX 10

main()

{
long int i=0,j=0,temp=0,A[MAX];
float suma=0;	
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		A[j]=0;
		j++;
	}
for(i=0;i<MAX;i++)
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);		
		scanf("%d",&A[i]);
		suma+=(float)A[i];
	}
suma*=0.45;	
printf("El 45%% de la suma de todas las posiciones es de: %.2f",suma);
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-1;j++)
			{
				if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
			}
	}
printf("\n\nOrden de menor a mayor\n--------------\n\n\n");
for(i=0;i<MAX;i++)
	{
		printf("%d ",A[i]);
	}	
getch();
return(1);	
}
