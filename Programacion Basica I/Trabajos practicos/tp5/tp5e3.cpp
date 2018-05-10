#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

Programa: Mostrar una letra elegida una cantidad de veces tambien elegida.

	num guarda la cantidad de repeticiones elegidas.
	c es la variable contador que controla que se repita la cantidad de veces
elegidas. (Si empieza en 0, va mostrar una vez mas de lo necesario). Ej:
con c=0;---> letra f, 1 repeticion (se mostraria f 2 veces, una por c=0
y otra por c=1).
	letra es una variable de caracter para usar la letra ingresada.
	fflush(stdin) <------- Limpia memoria de teclado..
	system("cls") limpia la pantalla (requiere la libreria <stdlib.h>)

	**El while repetira la letra ingresada mientras el contador sea <=num

*/

main()
{
	int num=0,c=1;
	char letra;
	printf("ingrese una letra: ");
	scanf("%c",&letra);
	fflush(stdin);
	printf("ingrese una cantidad de repeticiones: ");
	scanf("%d",&num);
	system("cls");//Clear screen
	while(c<=num)
	{
		printf("\n%c",letra);
		c++;
	}
	
getch();
return 0;	
}
