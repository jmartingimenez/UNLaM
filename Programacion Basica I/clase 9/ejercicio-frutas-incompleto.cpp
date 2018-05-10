#include <stdio.h>
#include <conio.h>
#define ZAPA 20
#define BATA 15
#define NARA 30
#define MANZA 25
#define BANA 20

int main(){
	int art=0, cant=0, total=0, stotal=0, myimpt=0, menorcantidad=0, smi=0, mnimpt=0, ord=0, myimptart=0, mnimprart=0;
	float iva=0, bruto=0, totalfinal=0;
	printf ("Ingrese el numero de articulo: ");
	scanf("%i",&art);
	while (art != 986){
		fflush(stdin);
			printf("Ingrese la cantidad que desea comprar: ");
			scanf("%i",&cant);
			ord++;
		switch(art){
			case 1: total=cant*ZAPA;
			printf("Usted acaba de comprar $%d en ZAPALLO\n\n", total);
			break;
			case 2: total=cant*BATA;
			printf("Usted acaba de comprar $%d en BATATA\n\n", total);
			break;
			case 3: total=cant*NARA;
			printf("Usted acaba de comprar $%d en NARANJA\n\n", total);
			break;
			case 4: total=cant*MANZA;
			printf("Usted acaba de comprar $%d en MANZANA\n\n", total);
			break;
			case 5: total=cant*BANA;
			printf("Usted acaba de comprar $%d en BANANA\n\n", total);
			break;
			default:printf("Error, articulo invalido");	}
			if (ord==1)
			   {myimpt=total;
			    myimptart=art;
				mnimpt=total;
				mnimprart=art;}
			if (myimpt<total)
			   {myimpt=total;
			    myimptart=art;}
			if (mnimpt>total)
			   {mnimpt=total;
				mnimprart=art;}

			stotal=stotal+total;
			printf("Ingrese el numero de articulo: ");
			scanf("%i",&art);
		
	}
	printf("El total es %d \n", stotal);
	iva=(stotal*10.86)/100;
	bruto= (stotal*6)/100;
	totalfinal= stotal+iva+bruto;
	printf("El total a pagar es: %.2f\n",totalfinal);
	printf("El mayor importes es %d\n",myimpt);
	printf("El menor importe es %d\n",mnimpt);
	printf("El articulo de menor importe comprado es %d",mnimprart);

	
	getch();
	return(1);
}
