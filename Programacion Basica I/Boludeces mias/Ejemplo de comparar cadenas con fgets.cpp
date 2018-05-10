#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//para usar el system("cls")/fflush(stdin)..
#include<string.h>//para usar el strcmp, gets..

/*

***Programa de Ejemplo para comparar cadenas con fgets.

	El gets() aparentemente puede dar muchos problemas si se escribe mas
caracteres de lo permitido.

	Explicacion: fgets(cad1,100,stdin) <---Lee cadena hasta un \n
		1-cad1 es la variable donde se guarda.
		2-100 es para el limite de caracteres, esta vez se fija.
		3-es para indicar del buffer de donde se leen los datos.


*/

main()

{
	int c;
	printf("Programa para comparar cadenas.");
	while(c!=0)
		{
			fflush(stdin);
			char cad1[50],cad2[50];
			printf("\nIngrese una palabra o frase: ");
			fgets(cad1,100,stdin);
			system("cls");
			printf("Ingrese una segunda palabra o frase: ");
			fgets(cad2,100,stdin);
			c=strcmp(cad1,cad2);//el compare da un valor numerico(0 son iguales)
			if(c!=0)
				{
					system("cls");
					printf("Las frases son diferentes. Vuelve a intentarlo!!");
				}
		}
	
	printf("\nLas frases son iguales.");

getch();
return(1);
}
