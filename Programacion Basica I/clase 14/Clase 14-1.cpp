/*
	-Ingresar cliente[1-5], termina con 999
	-Articulos[10-14]
	-Cantidad
			
***Mostrar el cuadro

Cliente			Art(10)		Art(11)		Art(12)		Art(13)		Art(14)
1				XX			XX			XX			XX			XX
2				XX			XX			XX			XX			XX
3				XX			XX			XX			XX			XX
4				XX			XX			XX			XX			XX
5				XX			XX			XX			XX			XX

(Lo hice de manera que se pueda ingresar cualquier numero de cliente, son 5 como maximo
pero los numeros pueden ser cualquiera)
==============================================================================

	i,j,k= contadores, el 'k' creo que esta al pedo.
	ncliente= guarda el numero de cliente ingresado
(Esta variable es para comprobar si el numero es 999, si es distinto, recien ahi va al vector)
	art= guarda el codigo del articulo seleccionado
	MAX= constante para limitar a 5 filas/columnas de matriz y cantidad de clientes	
	mayorcant= guarda la cantidad mas alta ingresada
	clientemayor= guarda el numero de cliente que compro la cantidad mas alta
(El if comprueba si la cantidad es la mayor ingresada, si esto se cumple, la variable
guarda el numero de cliente)
	A= vector que guarda los numeros de clientes ingresados (que son distintos de 999)
	tot= matriz que guarda las cantidades seleccionadas
	
************************
NOTA: No sabia bien como combinar el for con el while, asi que use un while y 2 if en la
parte del pedido de cliente/articulo/cantidad.
			
	-El primero comprueba que el articulo este entre [10,14]. Si se cumple, se pide
la cantidad. Se agrega el numero de cliente al vector y se aumenta 'k' (el contador)
	-El segundo comprueba si el contador ya alcanzo a MAX, si es verdadero con el break
se sale del while aunque no se haya puesto como cliente el 999.

************************
NOTA 2: Explicacion de esto...		tot[k][art-10]

	-k corresponde al cliente actual (si es el primero, segundo, tercero..)
	[art-10]: La fila tiene 5 posiciones (0,1,2,3,4), sin embargo, las posiciones del
articulo serian (10,11,12,13,14). Restandole 10 hago que quede en la posicion de la
matriz que corresponde.

(Si es el primer cliente y la articulo que elije es 11, la cantidad ingresada -ej. 5-
se guardaria en la posicion [0,(11-10)]=[0,1])

La primer fila se veria algo asi..
Cliente			Art(10)		Art(11)		Art(12)		Art(13)		Art(14)
1				XX			5			XX			XX			XX
Posicion:		(0,0)		(0,1)		(0,2)		(0,3)		(0,4)

************************
NOTA 3: Queda pendiente...
	-Que en el cuadro final, no se muestren siempre 5 filas si los clientes
son menos (si se escribe 999 antes).
	-Algo que me permita aumentar la cantidad (si ingreso 2 veces el mismo numero de cliente)
		

*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Para limpiar pantalla con el 'system("cls")'
#define MAX 5

main()

{
int i=0,j=0,k=0,ncliente=0,art=0,mayorcant=0,clientemayor=0,A[MAX],tot[MAX][MAX];
for(i=0;i<MAX;i++)//Limpiando el vector
	{
		A[i]=0;
	}
for(i=0;i<MAX;i++)//Limpiando la matriz
	{
		for(j=0;j<MAX;j++)
			{
				tot[i][j]=0;
			}
	}	
printf("Ingrese numero de cliente: ");
scanf("%d",&ncliente);
while(ncliente!=999)//Pedido de cliente/articulo/cantidad
	{
		printf("Ingrese el codigo del articulo seleccionado. Entre 10 y 14: ");
		scanf("%d",&art);
		if((art>=10)&&(art<=14))//Solo si el articulo esta en el rango se ve lo siguiente
			{
				printf("Ingrese la cantidad del articulo %d: ",art);
				scanf("%d",&tot[k][art-10]);//Ver NOTA 2
				A[k]=ncliente;//El vector guarda el numero de cliente
				k++;//Aumenta el contador del vector -ver NOTA-
			}
		else
			{
				printf("ERROR!!: Codigo incorrecto. Debe estar entre 10 y 14.\n");
			}	
		if(k==MAX)//Con esto salimos del while -ver NOTA-
			{
				break;
			}
		else
			{
				system("cls");
				printf("Ingrese numero de cliente: ");
				scanf("%d",&ncliente);					
			}			

	}
system("cls");
printf("****************************************************\n");
printf("Cliente\t\t\tCodigo de Articulo\n");	
printf("****************************************************\n");
printf("\n\t\t10\t11\t12\t13\t14\n");
printf("****************************************************\n");
for(i=0;i<MAX;i++)//Mostrando el cuadro
	{
		printf("\n%d\t-\t",A[i]);//Se muestra el numero de cliente guardado en A
		for(j=0;j<MAX;j++)
			{
				if(tot[i][j]>0)//Si la cantidad es mayor a 0
					{
						printf("%d",tot[i][j]);//Se muestra la cantidad
						if(tot[i][j]>mayorcant)//La cantidad es la mas alta?
							{
								mayorcant=tot[i][j];//La variable toma el valor de la cantidad
								clientemayor=A[i];//Se guarda el numero de cliente
							}
						
					}
				else//Si la cantidad no es mayor a 0
					{
						printf("\t");//Se tabula, sino hago esto, todo quedaria abajo del art10
					}	
			}
	}
printf("\n\nEl cliente que mas productos llevo fue el %d.",clientemayor);	
getch();
return(1);	
}
