/*

	Programa: Comprobar si un numero ingresado se encuentra en un vector
	
	i= variable contador para el for y para las posiciones del vector
	num= guarda el numero ingresado a comparar
	cnum= si existe coincidencia, se sube 1 (para contar cuantas veces aparece)
	V= vector
	MAX= constante para definir el maximo de posiciones

*/

#include<stdio.h>
#include<conio.h>
#define MAX 4

main()

{
int i=0,num=0,cnum=0,V[MAX];
for(i=0;i<MAX;i++)//Limpiando basura
	{
		V[i]=0;
	}
for(i=0;i<MAX;i++)//Pidiendo numeros para el vector
	{
		printf("Ingrese un numero en la posicion %d: ",i+1);
		scanf("%d",&V[i]);
	}
printf("Ingrese otro numero: ");//Pidiendo el numero para comparar
scanf("%d",&num);
for(i=0;i<MAX;i++)//Buscando comparaciones
	{
		if(num==V[i])
			{
				cnum++;//Se agrega al contador de coincidencias
			}
	}	
if(cnum==0)
	{
		printf("El numero ingresado no se encuentra en el vector.");
	}	
else
	{
		printf("El numero ingresado %d se encuentra %d veces en el vector",num,cnum);
	}	
getch();
return(1);	
}
