#include<stdio.h>
#include<conio.h>

/*

Programa: Mostrar las primeras 6 potencias de los primeros 20 numeros enteros.

	***Supongo que se podria armar una tablita para que no salga todo 1 por 1.
	 
	p es la variable que guarda el resultado de la multiplicacion calculada.
	i es el contador de el exponente, para que se multiplique hasta 6 veces.
	j controla el numero actual que se tiene q calcular sus potencias.
	c es el que controla q se multiplique por el mismo numero. (si se saca, todo
da 1).
*/

main()

{
int p=1,i=1,c=1,j=1;	
printf("Este programa mostrara las primeras 6 potencias de los primeros 20 numeros naturales.\n");
printf("\n-----------------------------------------------");
for(j=1;j<=20;j++)
	{
			for(i=1;i<=6;i++)
		{
		
			p=p*c;
			printf("\n%d elevado a la %d es %d.",j,i,p);
		}
		p=1;
		c++;
		printf("\n-----------------------------------------------");
	}

	

getch();
return(1);
}
