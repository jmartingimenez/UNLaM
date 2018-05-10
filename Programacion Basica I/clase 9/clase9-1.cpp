#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ZAPALLO 20
#define BATATA 15
#define NARANJA 30
#define MANZANA 25
#define BANANA 20
#define IVA 1.1086
#define INGBRUT 0.06

main()

{
int cod=0,seleccion=0,tot=0,art1=0,art2=0,art3=0,art4=0,art5=0,codmayor=0,codmenor=0,menorimp=0;
float totiva=0,totbrut=0,totfin=0,mayorimp=0;	
while(cod!=986)
{
	system("cls");
	printf("\n1-Zapallo\t$20\n");
	printf("\n2-Batata\t$15\n");
	printf("\n3-Naranja\t$30\n");
	printf("\n4-Manzana\t$25\n");
	printf("\n5-Banana\t$20\n");
	printf("\nIngrese el codigo del producto seleccionado: ");
	scanf("%d",&cod);
	switch(cod)
		{
			case 1:
					tot=tot+ZAPALLO;
					art1++;
					break;
			case 2:
					tot=tot+BATATA;
					art2++;
					break;
			case 3:
					tot=tot+NARANJA;
					art3++;
					break;
			case 4:
					seleccion=MANZANA;
					art4++;
					break;
			case 5:
					tot=tot+BANANA;
					art5++;					
					break;
			default: 	
					if(cod!=986)
					{
						printf("ERROR!!: Codigo incorrecto.");
					}
					
					break;
		}

}
system("cls");
art1=ZAPALLO*art1;
codmayor=1;
codmenor=1;
mayorimp=art1;
menorimp=art1;
art2=BATATA*art2;
if(art2>mayorimp)
	{
		mayorimp=art2;
		codmayor=2;
	}
art3=NARANJA*art3;
if(art3>mayorimp)
	{
		mayorimp=art3;
		codmayor=3;
	}
art4=MANZANA*art4;
if(art4>mayorimp)
	{
		mayorimp=art4;
		codmayor=4;
	}
art5=BANANA*art5;
if(art5>mayorimp)
	{
		mayorimp=art5;
		codmayor=5;
	}
//aca menor	
if(art2<menorimp)
	{
		menorimp=art2;
		codmenor=2;
	}
art3=NARANJA*art3;
if(art3<menorimp)
	{
		menorimp=art3;
		codmenor=3;
	}
art4=MANZANA*art4;
if(art4<menorimp)
	{
		menorimp=art4;
		codmenor=4;
	}
art5=BANANA*art5;
if(art5<menorimp)
	{
		menorimp=art5;
		codmenor=5;
	}
printf("Precio de zapallo/s -c/u $20:\t$%d\n",art1);
printf("Precio de Batata/s -c/u $15:\t$%d\n",art2);	
printf("Precio de Naranja/s -c/u $30:\t$%d\n",art3);	
printf("Precio de Manzana/s -c/u $25:\t$%d\n",art4);	
printf("Precio de Banana/s -c/u $20:\t$%d\n",art5);
printf("\n\nTotal: $%d\n",tot);	
totiva=tot*IVA;
totbrut=tot*INGBRUT;
printf("Total con IVA: $%.2f\n",totiva);												
printf("Total con Ingresos brutos: $%.2f\n",totbrut);
totfin=totiva+totbrut;
printf("El total final es de: $%.2f.",totfin);	
printf("\n------------------------------\n\n");
printf("\n\nEl importe mas alto es: %.2f y corresponde al producto de codigo %d.\n",mayorimp,codmayor);
printf("\n\nEl importe mas bajo es: %.2f y corresponde al producto de codigo %d.\n",menorimp,codmenor);

getch();
return(1);	
}
