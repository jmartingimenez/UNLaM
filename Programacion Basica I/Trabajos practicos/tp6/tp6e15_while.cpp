/*	(enunciado)
Una empresa de omnibus registra una ficha por cada uno de los viajes de sus 30 unidades la siguiente informacion
	-Numero de omnibus (de 1 a 30)
	-Recaudacion
	-Km recorridos
			
=============

Nota: La recaudacion la voy a calcular (km*100)	

N° omnibus | Recaudacion | Km recorridos
----------------------------------------
    XX				XX			XX
*/

#include<stdio.h>
#include<conio.h>
#define FI 30
#define CO 2

main()

{
	int i=0,j=0,temp=0,num_omnibus=0,km=0,recaudacion=0,omnibus[FI],estadisticas[FI][CO];
	for(i=0;i<FI;i++)
		{
			omnibus[i]=0;//Limpieza del vector
			for(j=0;j<CO;j++)
				{
					estadisticas[i][j]=0;//Limpieza de la matriz
				}
		}	
	printf("Ingreso de viajes -Finaliza con 999-\n-------------------------\n\n");
	while(num_omnibus!=999)
		{
			printf("Ingrese el numero de omnibus: ");
			scanf("%d",&num_omnibus);
			if(num_omnibus==999)
				{
					break;
				}
			else
				{
					if((num_omnibus<1)||(num_omnibus>30))
						{
							printf("\n\t\tERROR!!: El numero de omnibus solo puede ser entre 1 y 30.\n");
						}
					else
						{
							omnibus[num_omnibus-1]=num_omnibus;
							printf("Ingrese la cantidad de Kilometros recorridos: ");
							scanf("%d",&km);
							recaudacion=km*100;
							estadisticas[num_omnibus-1][j]+=recaudacion;
							estadisticas[num_omnibus-1][j+1]+=km;
						}				
				}	
	
		}
	printf("\nListado de viajes\n---\n");
	printf("Num Omnibus\tRecaudacion\tKm recorridos\n---------------------------------------------\n\n");
	for(i=0;i<FI;i++)
		{
			if(omnibus[i]>0)
				{
					printf("%d\t\t$%d\t\t%d Kms\n",omnibus[i],estadisticas[i][j],estadisticas[i][j+1]);
				}
			
		}
			
	
	
	
	getch();
	return(1);
}
