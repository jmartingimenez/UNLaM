//ENUNCIADO:	Cargar una matriz usando punteros, mostrar sus datos y direcciones de memoria

#include<stdio.h>
#include<conio.h>

void func_limpiar(int *p);
void func_cargar(int *p);
void func_vervalor(int *p);
void func_verdir(int *p);

int main()

{
	int mat[2][3],*p=&mat[0][0];
	func_limpiar(p);
	func_cargar(p);
	func_vervalor(p);
	func_verdir(p);
	getch();
	return 0;
}

void func_limpiar(int *p)

{
	for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
				{
					*(p+i*3+j)=0;
				}				
		}						
}								

void func_cargar(int *p)

{
	for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
				{
					printf("Ingrese un numero en la posicion %d,%d:\t",i,j);
					scanf("%d",(p+i*3+j));
				}
		}
}

void func_vervalor(int *p)

{
	printf("\n\nMostrando los datos cargados en la matriz\n=========================================\n");
	for(int i=0;i<2;i++)
		{
			printf("\n\t\t");
			for(int j=0;j<3;j++)
				{
					printf("%d ",*(p+i*3+j));
				}
		}
}

void func_verdir(int *p)

{
	printf("\n\nMostrando las direcciones de memoria de la matriz\n=================================================\n");	
	for(int i=0;i<2;i++)
		{
			printf("\n\t");
			for(int j=0;j<3;j++)
				{
					printf("%d ",(p+i*3+j));
				}
		}	
}
