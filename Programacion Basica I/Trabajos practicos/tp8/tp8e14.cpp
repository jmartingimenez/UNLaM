#include<stdio.h>
#include<conio.h>
#define MAX 5

void limpiar(int *ptr);
void llenar(int *ptr);
int contar_pares(int *ptr);
int contar_impares(int *ptr);

int main()

{
	int *ptr=NULL,A[MAX],p,i;
	ptr=A;
	limpiar(ptr);
	llenar(ptr);
	p=contar_pares(ptr);
	i=contar_impares(ptr);
	printf("\n\nTotal de numeros pares: %d\nTotal de numeros impares: %d",p,i);
	getch();
	return 0;
}

void limpiar(int *ptr)

{
	int i=0;
	for(i=0;i<MAX;i++)
		{
			ptr[i]=0;
		}
}

void llenar(int *ptr)

{
	int i=0;
	for(i=0;i<MAX;i++)
		{
			printf("Ingrese un numero en la posicion %d: ",i);
			scanf("%d",ptr+i);
		}
}

int contar_pares(int *ptr)

{
	int i=0,pares=0;
	for(i=0;i<MAX;i++)
		{
			if(*(ptr+i)%2==0)
				{
					pares++;
				}
		}
	return pares;	
}

int contar_impares(int *ptr)

{
	int i=0,impares=0;
	for(i=0;i<MAX;i++)
		{
			if(ptr[i]%2==1)
				{
					impares++;
				}
		}
	return impares;	
}


