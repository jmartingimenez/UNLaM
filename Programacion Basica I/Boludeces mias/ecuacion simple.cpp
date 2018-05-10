//Ecuacion tipo aX+b=c

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Solo para usar el 'system("cls)'

int main()

{
	float a=0,b=0,c=0,x=0;
	while((a<=0)||(b<=0)||(c<=0))
		{
			printf("Ecuacion del tipo aX+b=c\nPOR AHORA SOLO INGRESAR NUMEROS POSITIVOS\n");
			printf("-----------------------------------------\n\n");
			printf("Ingrese el valor de a: ");
			scanf("%f",&a);
			printf("Ingrese el valor de b: ");
			scanf("%f",&b);
			printf("Ingrese el valor de c: ");
			scanf("%f",&c);
			if((a<=0)||(b<=0)||(c<=0))		
				{
					system("cls");//Limpia la pantalla
					printf("ERROR!!: Solo ingresar numeros mayores a 0\n\n\n");
				}	
		}
	system("cls");
	printf("-----------------------------------\n\n");
	printf("Tu ecuacion es \t\t%.2fX+%.2f=%.2f",a,b,c);	
	printf("\n1er paso:\t\t%.2fX=%.2f-%.2f",a,c,b);
	c=c-b;
	printf("\n2do paso:\t\tX=%.2f/%.2f",c,a);
	c=c/a;
	printf("\n\nResultado=\t\tX=%.2f",c);	
	getch();
	return 0;	
}
