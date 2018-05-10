#include<stdio.h>
#include<conio.h>
#define FI 3
#define CO 3

int mat[FI][CO];
void func_llenar();
void func_mostrar();
void func_mostrarinv();

int main()

{	
	func_llenar();
	func_mostrar();
	func_mostrarinv();
	getch();
	return 0;
}

void func_llenar()

{
	int i=0,j=0;
	for(i=0;i<FI;i++)
		{
			for(j=0;j<CO;j++)
				{
					printf("Ingrese un numero en la posicion %d,%d: ",i,j);
					scanf("%d",&mat[i][j]);
				}
		}
}

void func_mostrar()

{
	int i=0,j=0;
	for(i=0;i<FI;i++)
		{
			printf("\n");
			for(j=0;j<CO;j++)
				{
					printf("%d ",mat[i][j]);
				}
		}
}

void func_mostrarinv()

{
	printf("\n\nMatriz invertida mostrando\nsolo la diagonal principal\n--------------------------\n\n");
	int i=0,j=0;
	for(i=FI-1;i>=0;i--)
		{
			printf("\n");
			for(j=CO-1;j>=0;j--)
				{
					if(i==j)
						{
							printf("%d ",mat[i][j]);
						}
					else
						{
							printf(" ");
						}	
					
				}
		}
}

