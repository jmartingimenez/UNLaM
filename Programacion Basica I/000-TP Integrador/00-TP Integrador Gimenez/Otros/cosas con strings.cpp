#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()

{
	char palabra[5]={'h','O','L','a'},copia[5];
	printf("Mostrando la cadena original\n--------\n%s\n\n",palabra);	
	printf("Convirtiendo a mayuscula\n--------\n");
	strupr(palabra);
	printf("%s\n\n",palabra);
	printf("Convirtiendo a minuscula\n--------\n");
	strlwr(palabra);
	printf("%s\n\n",palabra);
	printf("Copiando la cadena y mostrando\n--------\n");
	strcpy(copia,palabra);//Primero donde se va a copiar, segundo, de donde se copia
	printf("%s\n\n",copia);
	printf("Invirtiendo la cadena copia\n----------\n");
	strrev(copia);	
	printf("%s\n\n",copia);		
	printf("Concatenando las 2 cadenas\n----------\n");
	strcat(palabra,copia);//En ese orden, queda primero el contenido de palabra y segundo el de copia
	printf("%s",palabra);
	getch();
	return 0;
}


