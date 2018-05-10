#include <stdio.h>
#include <conio.h>
/*
chom (cantidad de hombres)
cmuj (cantidad de mujeres)
porh (porcentaje de hombres)
porm (porcentaje de mujeres)
*/
int main()
{
	int chom=0,cmuj=0,porh=0,porm=0;
	printf("Ingrese la cantidad de hombres: ");
	scanf("%d",&chom);
	printf("Ingrese la cantidad de mujeres: ");
	scanf("%d",&cmuj);
	porh=(chom*100)/(chom+cmuj);
	porm=(cmuj*100)/(chom+cmuj);
	printf("--------------------------------------------");
	printf("\nLos %d hombres representan el %d porciento.\nLas %d mujeres representan el %d porciento.",chom,porh,cmuj,porm);
	printf("\n--------------------------------------------");
	getch();
	return(1);
}

