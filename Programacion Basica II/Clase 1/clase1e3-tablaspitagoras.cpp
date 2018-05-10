#include<stdio.h>
#include<conio.h>
int tabla[10][9];

void func_limpiar();
void func_carga();
void func_tabla();

int main()

{
	func_limpiar();
	func_carga();
	func_tabla();
 	getch();
	return 0;
}

void func_limpiar()

{
	for(int i=0;i<10;i++)
		{
			for(int j=0;j<9;j++)
				{
					tabla[i][j]=0;	
				}
		}
}

void func_carga()

{
	for(int i=0;i<10;i++)
		{
			for(int j=0;j<9;j++)
				{
					tabla[i][j]=(i+1)*(j+1);
				}
		}			
}

void func_tabla()

				 	
{
	printf("\t\t\t\tTabla Pitagorica\n\t\t\t\t================\n\n");
	printf("X|\t1\t2\t3\t4\t5\t6\t7\t8\t9\n==========================================================================");
	for(int i=0;i<10;i++)
		{
			printf("\n%d|\t",i+1);
			for(int j=0;j<9;j++)
				{
					printf("%d\t",tabla[i][j]);
				}
		}		
}
