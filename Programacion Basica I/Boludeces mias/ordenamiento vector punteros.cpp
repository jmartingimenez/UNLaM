#include<stdio.h>
#include<conio.h>

void ingreso(int *ptr);
void ordenamiento(int *ptr);
void mostrar(int *ptr);
int main()

{
	int A[5],*ptr=NULL;
	ptr=A;
	ingreso(ptr);
	ordenamiento(ptr);
	mostrar(ptr);
	getch();
	return 0;
		
}

void ingreso(int *ptr)

{
	int i=0;
	for(i=0;i<5;i++)
		{
			printf("Ingrese un numero en la posicion %d: ",i);
			scanf("%d",ptr+i);
		}
}

void ordenamiento(int *ptr)

{
	int i=0,j=0,temp=0;
	for(i=0;i<5;i++)
		{
			for(j=0;j<5-i;j++)
				{
					if(ptr[j]>ptr[j+1])
						{
							temp=ptr[j];
							ptr[j]=ptr[j+1];
							ptr[j+1]=temp;
						}
				}
		}
}

void mostrar(int *ptr)

{
	int i=0;
	for(i=0;i<5;i++)
		{
			printf("%d ",ptr[i]);
		}
}

