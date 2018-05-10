#include <stdio.h>  //input-output
#include <conio.h>  //para el getch

int main() //int(integer/entero)
{  //Suma
	int val1=0,val2=0,suma=0;
	printf("Ingrese un numero: ");
	scanf("%d",&val1);
	printf("Ingrese otro numero: ");
	scanf("%d",&val2);
	suma=val1+val2;
	printf("La suma da como resultado: %d",suma);
	getch();
	return(1);
		
}
