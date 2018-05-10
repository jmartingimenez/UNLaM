#include<stdio.h>
#include<conio.h>
#define BATA 5.0//batata
#define CEBO 7.0//cebolla
#define NARA 10.0//naranja
#define MANZA 15.0//manzana
#define RECARGO 0.1
#define DESCUENTO 0.9
int main()

{//inicio

int cod=0,cant=0;
float art=0,pick=0,preciob=0,preciof=0,precargo=0,trecargo=0,desc=0;
printf("\n--------------");
printf("\n1-Batatas.\n2-Cebollas.\n3-Naranjas.\n4-Manzanas.");
printf("\n-------------------------------------------------------------");
printf("\ningrese un numero: ");
scanf("%d",&cod);
printf("\ningrese la cantidad: ");
scanf("%d",&cant);
switch(cod)
{//inicio cod
	case 1:printf("\nHa seleccionado %d batata/s.",cant);
	pick=BATA;
	break;
	case 2:printf("\nHa seleccionado %d cebolla/s.",cant);
	pick=CEBO;
	break;
	case 3:printf("\nHa seleccionado %d naranja/s.",cant);
	pick=NARA;
	break;
	case 4:printf("\nHa seleccionado %d manzana/s.",cant);
	pick=MANZA;
	break;
}//final cod 
preciob=(pick*cant);
printf("\nEl precio del producto es de: $%.2f.",preciob);
if(cant<10)
{//cant <10
precargo=(pick*RECARGO);
trecargo=(preciob+precargo);
printf("\nEl precio final es de %.2f.",trecargo);
}//cant <10
else
if((cant>10)&&(cant<99))
{//if 10-99
printf("\nEl precio final es de %.2f.",preciob);
}//if 10-99
else
if(cant>99)
{//if 99
desc=(preciob*0.9);
printf("\nEl precio final es de %.2f.",desc);
}//if 99

getch();
return(1);
}//inicio
