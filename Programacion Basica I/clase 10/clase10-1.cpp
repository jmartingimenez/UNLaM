#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
	Programa: Ingresar numero y tiempo de autos, marcar 1er y 2do tiempos
mas rapidos y ultimo y anteultimos tiempos (los 2 mas lentos)
	
	numauto: guarda el numero de auto ingresado
	cauto: contador de autos ingresados(para sacar el promedio)
	autorap: Guarda el numero del auto mas rapido (menos tiempo)
	auto2rap: guarda el numero del segundo auto mas rapido
	autolen: guarda el numero del auto mas lento (mas tiempo)
	auto2len: guarda el numero del segundo auto mas lento
	stiempo: para sumar todos los tiempos
	tiempo: guarda el tiempo del auto ingresado
	tiemporap: guarda el tiempo mas rapido
	tiempo2rap: guarda el segundo tiempo mas rapido
	tiempolen: guarda el tiempo mas lento
	tiempo2len: guarda el segundo tiempo mas lento
	
**** (este if es para dar valores iniciales (si no, el que valgan 0 hasta los if da problemas). 
Solo funcionara en el primer bucle.
		if(cauto==1)
		{
			tiemporap=tiempo;
			tiempo2rap=tiempo;
			tiempolen=tiempo;
			tiempo2len=tiempo;
			autorap=numauto;
			auto2rap=numauto;
			autolen=numauto;
			auto2len=numauto;
		}
(Este if hace que el primer auto/tiempo ingresado tome todos esos valores)
	(Sin esto hay cosas que solo se guardarian si serian menores a 0)	

***Para 1er,2do, ultimo y anteultimo auto/tiempo ver mas abajo...
	
*/
main()

{
int numauto=0,cauto=0,autorap=0,auto2rap=0,autolen=0,auto2len=0,stiempo=0,tiemporap=0,tiempo2rap=0,tiempolen=0,tiempo2len=0,tiempo=0;
float promedio=0;
while(numauto!=999)
{
	//system("cls");//Quitado para ver que cuenta bien los numeros.
	cauto++;
	printf("Ingrese el numero de auto: ");
	scanf("%d",&numauto);
	if(numauto!=999)
	{
		printf("Ingrese el tiempo de este auto: ");
		scanf("%d",&tiempo);
		if(cauto==1)//ver arriba sobre este if
		{
			tiemporap=tiempo;
			tiempo2rap=tiempo;
			tiempolen=tiempo;
			tiempo2len=tiempo;
			autorap=numauto;
			auto2rap=numauto;
			autolen=numauto;
			auto2len=numauto;
		}
//Explicacion de los if para 1er/2do mayor/menor tiempo (los 2 de abajo)
/*
(explicacion de asignar 1er y 2do menor -mejor- tiempo)
Primero se comprueba si el tiempo ingresado es menor al segundo menor
tiempo. Si esto se cumple, se repregunta si el tiempo ingresado es menor
al mejor tiempo de todos. Si se cumplen las 2 cosas, el mejor tiempo anterior
pasara a ser el segundo mejor tiempo y el tiempo ingresado pasara a ser
el mejor tiempo de todos. Lo mismo con el numero de auto.
Si solo se cumple lo primero (es menor que el segundo mejor tiempo guardado
anteriormente, pero no es el mejor tiempo de todos)
Solo se almacenara los datos como segundo menor/mejor tiempo.

***(Para el tema de mayor tiempo es lo mismo pero al reves nomas)

*/	
		if((tiempo>tiempo2len)&&(tiempo!=0))
		{
			if(tiempo>tiempolen)
			{
				tiempo2len=tiempolen;
				tiempolen=tiempo;
				auto2len=autolen;
				autolen=numauto;
			}
			else
			{
				tiempo2len=tiempo;
				auto2len=numauto;				
			}
		}
		if((tiempo<tiempo2rap)&&(tiempo!=0))
		{
			if(tiempo<tiemporap)
			{
				tiempo2rap=tiemporap;
				tiemporap=tiempo;
				auto2rap=autorap;
				autorap=numauto;
			}
			else
			{
				tiempo2rap=tiempo;
				auto2rap=numauto;				
			}
		}
		stiempo=stiempo+tiempo;
		promedio=(float)stiempo/(float)cauto;		
	}
	
}
//system("cls");//Quitado para ver que cuenta bien los numeros.
printf("-------------------------------------------\n");
printf("El tiempo promedio es de %.2f",promedio);
printf("\n---");
printf("\nEl tiempo mas rapido es el del auto %d: %d segundos.",autorap,tiemporap);	
printf("\nEl segundo tiempo mas rapido es el del auto %d: %d segundos.",auto2rap,tiempo2rap);
printf("\n---");
printf("\nEl tiempo mas lento es el del auto %d: %d segundos.",autolen,tiempolen);	
printf("\nEl anteultimo tiempo es el del auto %d: %d segundos.",auto2len,tiempo2len);
printf("\nEl tiempo sumado de todos los autos es de: %d segundos.",stiempo);	
getch();
return(1);	
}
