#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int  func_recu();
void func_a();
void func_b();

int main()

{
   	int pick,*p=&pick;
	pick=func_recu();
	printf("Tu eleccion es %d\t%d.",*p,pick);
	func_a();
	free(p);//requiere stdlib. Se supone que vacia el lugar al que apunta el puntero (p=NULL)
	getch();
	return 0;
      
}

int func_recu()

{
	int pick=0;
	while(pick!=3)
		{
			printf("Ingrese el numero 3: ");
			scanf("%d",&pick);
			if(pick!=3)
				{
					printf("Numero incorrecto\n");
					func_recu();
					break;//Parece quedar en un loop infinito, ni llegaria a esta linea aun poniendo el 3
				}
		}
	return 3;	
}

void func_a()

{
	printf("\nFuncion A");
	func_b();
}

void func_b()

{
	printf("\nFuncion B");
}
