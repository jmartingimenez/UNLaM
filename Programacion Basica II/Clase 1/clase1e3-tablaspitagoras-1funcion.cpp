#include<stdio.h>
#include<conio.h>

void func_tabla();

int main()

{
	func_tabla();
 	getch();
	return 0;
}

void func_tabla()

{
	int tabla[10][9];	
	printf("\t\t\t\tTabla Pitagorica\n\t\t\t\t================\n\n");
	printf("X|\t1\t2\t3\t4\t5\t6\t7\t8\t9\n==========================================================================");	
	for(int i=0;i<10;i++)
		{
			printf("\n%d|\t",i+1);//Pasando a la siguiente fila							
			for(int j=0;j<9;j++)
				{
					tabla[i][j]=(i+1)*(j+1);//Llenando la matriz, sin `limpiar'
					printf("%d\t",tabla[i][j]);//Mostrando las posiciones											
				}
		}
}


