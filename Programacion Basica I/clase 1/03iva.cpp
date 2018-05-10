#include <stdio.h>
#include <conio.h>
#define IVA 0.21
/*
prec (Precio del articulo)
cant (Cantidad de articulos)
tot (Precio a pagar sin iva)
tiva (Valor IVA)
totiva (Precio a pagar con iva)
*/
int main()
{
	int cant=0;
	float prec=0,tot=0,tiva=0,totiva=0;
	printf("Ingrese un precio: ");
	scanf("%f",&prec);
	printf("Ingrese la cantidad de productos: ");
	scanf("%d",&cant);
	tot=prec*cant;
	tiva=tot*IVA;
	totiva=tot+tiva;
	printf("--------------------------------------------");
	printf("\nEl precio correspondiente es de $%.2f.",tot);
	printf("\nEl impuesto correspondiente al IVA es de $%.2f.",tiva);
	printf("\nEl precio final es de $%.2f.",totiva);
	printf("\n--------------------------------------------");
	getch();
	return(1);
	
}
