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
#include<stdlib.h>//Para limpiar pantalla
#define FI 30
#define CO 2

main()

{
	int i=0,j=0,temp=0,menu=1,num_omnibus=0,km=0,recaudacion=0,omnibus[FI],estadisticas[FI][CO];
	for(i=0;i<FI;i++)
		{
			omnibus[i]=0;//Limpieza del vector
			for(j=0;j<CO;j++)
				{
					estadisticas[i][j]=0;//Limpieza de la matriz
				}
		}
	while((menu==1)||(menu==2))
		{
			printf("Seleccione la opcion correspondiente:");			
			printf("\n===INGRESANDO UN NUMERO DISTINTO FINALIZA EL PROGRAMA===");
			printf("\n\n1-Registrar Ficha\n2-Ver lista de recaudaciones");
			printf("\n\nSeleccion: ");
			scanf("%d",&menu);
			switch(menu)
				{
					case 1:
						printf("\n\nIngrese el numero de omnibus: ");
						scanf("%d",&num_omnibus);
						while((num_omnibus<1)||(num_omnibus>30))
							{
								printf("\n\t\tERROR!!: El numero de omnibus solo puede ser entre 1 y 30.\n");
								printf("Ingrese el numero de omnibus: ");
								scanf("%d",&num_omnibus);		
							}
						omnibus[num_omnibus-1]=num_omnibus;
						printf("Ingrese la cantidad de Kilometros recorridos: ");
						scanf("%d",&km);
						recaudacion=km*100;
						estadisticas[num_omnibus-1][j]+=recaudacion;
						estadisticas[num_omnibus-1][j+1]+=km;
						system("cls");//Limpiar pantalla					
						break;
					case 2:
						system("cls");//Limpiando pantalla
						printf("\nListado de viajes\n---\n");
						printf("Num Omnibus\tRecaudacion\tKm recorridos\n---------------------------------------------\n\n");
						for(i=0;i<FI;i++)
							{
								if(omnibus[i]>0)
									{
										printf("%d\t\t$%d\t\t%d Kms\n",omnibus[i],estadisticas[i][j],estadisticas[i][j+1]);
									}
								
							}
						printf("\n\n\n");//Para que cuando vuelva a pedir opcion, no quede tan pegado							
						break;
					default:
						break;		
				}	
		}
	getch();
	return(1);
}
