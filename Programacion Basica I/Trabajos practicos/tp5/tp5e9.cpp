#include<stdio.h>
#include<conio.h>

/*

Programa: Mostrar las primeras 4 potencias de los primeros 10 numeros enteros.

*** La tabla se muestra (numero,^1,^2,^3,^4). 

	resultado es la variable que guarda los resultados provisorios de 
las multiplicaciones.
	contadorexp es la variable que controla que el exponente llege hasta 4
(el for dura hasta q se multiplique 4 veces por si mismo)
	contadornum es la variable que controla que el numero avance desde 1 a 10.
(Tambien es el que se multiplica por si mismo)  

	resultado=resultado*contadornum <----- arranca en 1=1*1, el resultado de la
multiplicacion pasa a ser resultado, como es 1, la cuenta seria 4 veces iguales.

	ej.: con contadornum ya en 2 <-------- arranca en 1=1*2, despues pasa a ser
2=2*2, despues 4=4*2 y finalmente 8=8*2.
	
*/

main()

{

int resultado=1,contadorexp=1,contadornum=1;
printf("Numero\t\t^1\t\t^2\t\t^3\t\t^4\n");
printf("--------------------------------------------------------------------\n");
for(contadornum=1;contadornum<=10;contadornum++)

	{
		printf("%d",contadornum);//para la columna de los numeros.
		for(contadorexp=1;contadorexp<=4;contadorexp++)
			{
				resultado=resultado*contadornum;
				printf("\t\t %d",resultado);
			}
		printf("\n\n");
		resultado=1;//vuelve a 1 para que los resultados no sigan acumulandose.
		
	}
	
printf("\n\nAca se pueden ver las 4 primeras potencias de los 10 primeros numeros enteros.");
getch();
return(1);	
}
