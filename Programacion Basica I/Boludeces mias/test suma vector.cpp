#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//para usar system("cls")

main()

{
/*Declaracion variables*/
short int i=0,suma=0,vector[5];
/*Asegurarse que todas las posiciones del vector sean 0*/
for(i=0;i<5;i++);//Notese que en el for va <5 y no <=5 (da cualquier cosa sino)
	{
		vector[i]=0;
	}	
i=0;//volver i a 0 (ya que en el ultimo bucle valia 5
/*Agregar numeros al vector, i indica en que posicion del vector se agregara*/
for(i=0;i<5;i++)
	{
		system("cls");
		printf("Ingrese un numero en la posicion %hd: ",i+1);
		scanf("%hd",&vector[i]);
		suma+=vector[i];
	}	
printf("\n\nEl resultado de la suma es: %hd",suma);	
getch();
return(1);	
}
