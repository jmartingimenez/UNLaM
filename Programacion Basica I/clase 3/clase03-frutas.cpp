#include<stdio.h>
#include<conio.h>
#define MANDA 5
#define PERA 15
#define UVA 20
#define MANZA 10
#define KIWI 22
#define FRUTI 50
#define MANGO 35

int main()

{
	int cod=0,cant=0,precio=0;
	printf("\n--------------");
	printf("\n1-Mandarinas.\n2-Peras.\n3-Uvas.\n4-Manzanas.\n5-Kiwis.\n6-Frutillas.\n7-Mangos.");
	printf("\n-------------------------------------------------------------");
	printf("\nIngrese el codigo correspondiente al producto seleccionado: ");
	scanf("%d",&cod);
	printf("Seleccione la cantidad: ");
	scanf("%d",&cant);
	switch(cod)
	{
		case 1:printf("\nHa seleccionado %d mandarina/s.",cant);
		precio=(MANDA*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 2:printf("\nHa seleccionado %d pera/s.",cant);
		precio=(PERA*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 3:printf("\nHa seleccionado %d uva/s.",cant);
		precio=(UVA*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 4:printf("\nHa seleccionado %d manzana/s.",cant);
		precio=(MANZA*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 5:printf("\nHa seleccionado %d kiwi/s.",cant);
		precio=(KIWI*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 6:printf("\nHa seleccionado $%d frutilla/s.",cant);
		precio=(FRUTI*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
		case 7:printf("\nHa seleccionado %d mango/s.",cant);
		precio=(MANGO*cant);
		printf("\nEl total es de: $%d.",precio);
		break;
	}
	getch();
	return(1);
}
