// Ingresar caracteres y sumarlas (termina cuando aparece "?") 



#include <stdio.h>
#include <conio.h>

int main(){
	char letra;
	int letraa=0,letrae=0,letrai=0,letrao=0,letrau=0,consonante=0;
	printf("Ingrese un caracter: ");
	scanf("%c",&letra);
	
	while(letra !='?')
	{
		fflush(stdin);
		
		switch(letra){
			case 'a':letraa=letraa+1;
			break;
			case 'e':letrae=letrae+1;
			break;
			case 'i':letrai=letrai+1;
			break;
			case 'o':letrao=letrao+1;
			break;
			case 'u':letrau=letrau+1;
			break;
			default:consonante=consonante+1;
		}
		printf("Ingrese un caracter: ");
		scanf("%c",&letra);
	}
	printf("Usted ingreso el caracter %c\n", letra);
	printf("ingreso %d veces la letra a\n", letraa);
	printf("Ingreso %d veces la letra e\n", letrae);
	printf("Ingreso %d veces la letra i\n", letrai);
	printf("Ingreso %d veces la letra o\n", letrao);
	printf("Ingreso %d veces la letra u\n", letrau);
	printf("Ingreso %d consonantes", consonante);
	
	getch();
	return(1);
}
