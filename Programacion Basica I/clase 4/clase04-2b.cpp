#include<stdio.h>
#include<conio.h>
#define CAFE 20
#define LECHE 10
#define CONIAC 20
#define MLUNA 10
int main()
{//inicio

int cod=0,cant=0,precio=0,preciototal=0,pickprincipal=0,pick=0;
printf("\nCafe:1.\nTe:2.\nChocolate:3.");
printf("\nIngrese el codigo correspondiente: ");
scanf("%d",&pickprincipal);
if(pickprincipal==1)
{
	printf("\nLeche:1.\nConiac:2.\nLeche y Coniac:3.\nNinguno:4 ");
printf("\nIngrese el codigo correspondiente: ");
scanf("%d",&cod);
switch(cod)
{
	case 1: 
	precio=(CAFE+LECHE);
	printf("\nEl precio es de %d",precio);
	break;
case 2: 
	precio=(CAFE+CONIAC);
	printf("\nEl precio es de %d",precio);
	break;
case 3: 
	precio=(CAFE+LECHE+CONIAC);
	printf("\nEl precio es de %d",precio);
	break;
case 4: 
	precio=CAFE;
	printf("\nEl precio es de %d",precio);
	break;
}
printf("\n¿Queres medialunas?.\nSi=1.\nNo=2.\nSeleccionar: ");
scanf("%d",&pick);
if(pick==1)
{
	printf("\n¿Cuantas medialunas?: ");
	scanf("%d",&cant);
	preciototal=precio+(MLUNA*cant);
	printf("El precio total es de %d",preciototal);
}
else
{
	printf("el precio total es de %d",precio);
}
}
else
if(pickprincipal==2)
{
}
getch();
return(1);
}
