#include<stdio.h>
#include<conio.h>
#define IVA 0.21
#define PIVA 1.21

main()

{//inicio

int citem=0,item=0,cod=0,i=0,precio=0;
float total=0.0,psoloiva=0.0;
printf("ingrese la cantidad de items: ");
scanf("%d",&citem);
printf("\nArticulo		Precio		Denominacion");
printf("\n01			15		Boligrafo");
printf("\n02			10		Goma de borrar");
printf("\n03			30		Cuad. 48 hojas");
printf("\n04			15		Cuad. 24 hojas");
printf("\n05			20		Vaso de plastico");
printf("\n06			25		Plato");
printf("\n07			80		Jabon en polvo");
printf("\n08			15		Jabon en pan");
printf("\n09			20		Detergente 1 litro"); 
printf("\n10			30		Balde 10 litros");
for(i=1;i<=citem;i++)
	{
printf("\n\nIngrese el codigo correspondiente al producto seleccionado: ");
scanf("%d",&cod);
switch(cod)
	{
	case 1: printf("Selecciono un boligrafo, el precio es de $15.");
			precio=precio+15;
			break;
	case 2: printf("Selecciono un goma de borrar, el precio es de $10.");
			precio=precio+10;
			break;
	case 3: printf("Selecciono un cuaderno de 48 hojas, el precio es de $30.");
			precio=precio+30;
			break;
	case 4: printf("Selecciono un cuaderno de 24 hojas, el precio es de $15.");
			precio=precio+15;
			break;
	case 5: printf("Selecciono un vaso de plastico, el precio es de $20.");
			precio=precio+20;
			break;
	case 6: printf("Selecciono un plato, el precio es de $25.");
			precio=precio+25;
			break;
	case 7: printf("Selecciono un jabon en polvo, el precio es de $80.");
			precio=precio+80;
			break;
	case 8: printf("Selecciono un jabon en pan, el precio es de $15.");
			precio=precio+15;
			break;
	case 9: printf("Selecciono un detergente de 1 litro, el precio es de $20.");
			precio=precio+20;
			break;
	case 10: printf("Selecciono un balde de 10 litros, el precio es de $30.");
			precio=precio+30;
			break;
	default: printf("ERROR!!: Codigo incorrecto.");
			i--;
			break; 		
	}


}
	
printf("\n\nLlevaste %d productos y el precio es de $%d.",citem,precio);
psoloiva=(float)precio*IVA;
printf("\nEl iva es %.2f.",psoloiva);
total=(float)precio*PIVA;
printf("\nEl precio total %.2f",total);
if(total>500)
	{
		total=total*0.75;
		printf("\n\nTenes un descuento del 25 porciento.");
		printf("\nEl precio final con descuento es de %.2f.",total);
	}
	else
	{
		if(total>200)
		{
		total=total*0.8;
		printf("\n\nTenes un descuento del 20 porciento.");
		printf("\nEl precio final con descuento es de %.2f.",total);			
		}
		else
		{
		if(total>100)
		{
		total=total*0.85;
		printf("\n\nTenes un descuento del 15 porciento.");
		printf("\nEl precio final con descuento es de %.2f.",total);			
		}
		else
		{
			if(total>50)
			{
		total=total*0.9;
		printf("\n\nTenes un descuento del 10 porciento.");
		printf("\nEl precio final con descuento es de %.2f.",total);				
			}
		else
		{
		total=total*0.95;
		printf("\n\nTenes un descuento del 5 porciento.");
		printf("\nEl precio final con descuento es de %.2f.",total);	
		}
		}			
		}

	}
	

getch();
return(1);	
}//inicio
