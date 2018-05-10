/*
	Programa: Decir si un numero es perfecto

(Un numero es perfecto si la suma de sus divisores es igual al mismo. Ej.: 6 es un numero
perfecto por que sus divisores son 1,2 y 3 (1+2+3=6))

		
	n= variable que guarda el numero ingresado
	i= variable contador para el for
	divisores= variable que cuando el resto sea '0'. Acumulara el valor de 'i', al final
del for, si esta variable es igual al numero ingresado, se trata de un numero perfecto
	re= guarda el resto de 'n/i'
*/

#include<stdio.h>
#include<conio.h>

main()

{
int n=0,i=0,divisores=0,re=0;	
printf("Ingrese un numero: ");
scanf("%d",&n);
for(i=1;i<=n/2;i++)
	{
		re=n%i;
		if(re==0)
			{
				divisores+=i;
			}
	}	
if(divisores==n)
	{
		printf("%d es un numero perfecto.",n);
	}	
else
	{
		printf("%d no es un numero perfecto.",n);
	}	
getch();
return(1);	
}
