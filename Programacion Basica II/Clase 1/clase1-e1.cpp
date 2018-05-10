#include<stdio.h>
#include<conio.h>

int matriz[3][3];

void func_limpiar();
void func_cargar();
void func_mostrar();

int main()

{
	func_limpiar();
	func_cargar();
	func_mostrar();
	getch();
	return 0;
}

void func_limpiar()

{
	for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				{
					matriz[i][j]=0;
				}
		}
}

void func_cargar()

{
	for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				{
					printf("Ingrese un numero en pos %d,%d:\t ",i,j);
					scanf("%d",&matriz[i][j]);
				}
		}	
}

void func_mostrar()

{
	for(int i=0;i<3;i++)
		{
			printf("\n");
			for(int j=0;j<3;j++)
				{
					printf("%d ",matriz[i][j]);
				}
		}	
}
