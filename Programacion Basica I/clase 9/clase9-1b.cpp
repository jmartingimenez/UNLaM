#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ZAPA 20
#define BATA 15
#define NARA 30
#define MANZA 25
#define BANA 20
#define IVA 0.1086
#define INGBRUT 0.06

main()

{
int seleccion=0,art1=0,art2=0,art3=0,art4=0,art5=0;
float total=0,totalind=0,totaliva=0,totalbrut;
while(seleccion!=986)
	{
		system("cls");
		printf("\n1-Zapallo:\t20\n2-Batana:\t15\n3-Naranja:\t30\n4-Manzana:\t25\n5-Banana:\t20\n");
		printf("\nIngrese el codigo correspondiente al articulo seleccionado: ");
		scanf("%d",&seleccion);
		switch(seleccion)
		{
			case 1:
				art1++;
				total=total+ZAPA;
				break;
			case 2:
				art2++;
				total=total+BATA;
				break;
			case 3:
				art3++;
				total=total+NARA;
				break;
			case 4:
				art4++;
				total=total+MANZA;
				break;
			case 5:
				art5++;
				total=total+BANA;
				break;
			default:
				if(seleccion!=986)
				{
					printf("\n\n\t\tERROR!!: Codigo Incorrecto.");
					break;					
				}

		}
		
	}	
system("cls");
/*Precios individuales*/
if(art1>0)
	{
		totalind=ZAPA*art1;
		printf("\nLlevaste %d Zapallo/s con un precio de $%.2f",art1,totalind);
	}
if(art2>0)
	{
		totalind=BATA*art2;
		printf("\nLlevaste %d Batata/s con un precio de $%.2f",art2,totalind);
	}
if(art3>0)
	{
		totalind=NARA*art3;
		printf("\nLlevaste %d Naranja/s con un precio de $%.2f",art3,totalind);
	}
if(art4>0)
	{
		totalind=MANZA*art4;
		printf("\nLlevaste %d Manzana/s con un precio de $%.2f",art4,totalind);	
	}
if(art5>0)
	{
		totalind=BANA*art5;
		printf("\nLlevaste %d Banana/s con un precio de $%.2f",art5,totalind);
	}
/*Precios finales*/		
printf("\n---------------------------------------------------------------\n\n\n");
printf("\nEl total de los productos llevados es de: $%.2f",total);
totaliva=total*IVA;
printf("\nEl impuesto correspondiente al IVA es de: $%.2f",totaliva);	
totalbrut=total*INGBRUT;
printf("\nEl impuesto correspondiente a los ingresos brutos es de: $%.2f",totalbrut);
total=total+totaliva+totalbrut;
printf("\n---------------------------------------------------------------\n\n\n");
printf("\nEl precio final es de: $%.2f",total);	
getch();
return(1);	
}
