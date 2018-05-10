/*		(enunciado)
Realizar 5 funciones e invocarlas
a.	Que lea un vector de enteros de 10 elementos
b.	Que ordene el vector
c. 	Que copie un vector en otro
d.	Que seleccione el mayor elemento
e.	Que imprima el vector

===========================================================

Nota 1:	void leer(int A[],int);	<---------Aparentemente asi se declara la funcion si no se va usar punteros.
***el segundo int tiene que ver con el tamaño del array (pero si pongo 'int MAX' en el segundo paramentro, me
da error :(. Asi que tampoco lo entiendo bien)

Nota2: Me pasa algo raro en el ordenamiento
***Normalmente lo hago con 2 for y seria algo como...
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-i;j++)//El '-i' no es obligatorio
			{
				if(blabla...)
			}
	}
***Pero si lo hago asi parece que me agarra posiciones raras por que me salen ceros. Entonces el segundo
for lo tuve que poner como	'for(j=0;j<MAX-1-i;j++)'	<---Restarle 1 al maximo. No entiendo el por que...	

*/
#include<stdio.h>
#include<conio.h>
#define MAX 10

int A[MAX];//Creo que se debe poner aca...

void leer(int A[]);//el segundo int es para indicar APARENTEMENTE el tamaño
void ordenar(int A[]);
void copiar(int A[]);
int max(int A[]);
void mostrar(int A[]);

int main()

{
int i=0,m;
for(i=0;i<MAX;i++)
	{
		A[i]=0;
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&A[i]);
	}		
leer(A);
ordenar(A);
copiar(A);
m=max(A);//Para variar entre tantos voids :3
printf("El numero mas alto es:\t%d",m);
mostrar(A);	
getch();
return 0;	
}

void leer(int A[])

{
	int i=0;
	printf("\n");
	for(i=0;i<MAX;i++)
		{
			printf("%d ",A[i]);
		}
	
	printf("\nVector leido\n----------\n\n");
}
void ordenar(int A[])

{
	int i=0,j=0,temp=0;
	for(i=0;i<MAX;i++)
		{
			for(j=0;j<MAX-1-i;j++)//No entiendo por que aca tengo que restarle uno al maximo
				{				  //el '-i' es intencional, normalmente pondria=>	j=0;j<MAX-i;j++	
					if(A[j]>A[j+1])
						{
							temp=A[j];
							A[j]=A[j+1];
							A[j+1]=temp;
						}
				}
		}
	printf("\nVector ordenado\n--------------\n\n");	
}
void copiar(int A[])

{
	int i=0,B[MAX];
	for(i=0;i<MAX;i++)
		{
			B[i]=0;
			B[i]=A[i];
		}
	printf("\nVector B: ");
	for(i=0;i<MAX;i++)
		{
			printf("%d ",B[i]);
		}		
	printf("\nVector copiado\n------------\n\n");	
}

int max(int A[])

{
	int i=0,max=0;
	max=A[0];
	for(i=0;i<MAX;i++)
		{
			if(A[i]>max)
				{
					max=A[i];
				}
		}
	return max;	
}

void mostrar(int A[])

{
	int i=0;
	printf("\n\nVector Ordenado: ");
	for(i=0;i<MAX;i++)
		{
			printf("%d ",A[i]);
		}
}

