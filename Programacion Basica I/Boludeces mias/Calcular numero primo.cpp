/*
	Programa: Decir si un numero es primo (El resto es 0 solo cuando es dividido por si mismo
o por 1) <---'creo'...

	i= variable contadora para el for
	j= variable contadora que va subir cuando el resto de 'n/i' sea '0'. Se supone que si es un
numero primo, solo debe dar 0 en las 2 circunstancias mencionadas antes, por lo que si 'j' vale
2, el numero es primo.
	re= para guardar el resto
	n= guarda el numero ingresado 
*/

#include<stdio.h>
#include<conio.h>

main()

{
int i=0,re=0,j=0,n=0;
printf("Ingrese un numero: ");	
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
		re=n%i;//Calculando el resto de n/i
		if(re==0)//Si el resto es 0...
			{
				j++;//Subir un valor a 'j'
			}
	}		
if(j==2)//Si solo en 2 loops el resto dio 0...
	{
		printf("%d es un numero primo.",n);//Es primo
	}	
else
	{
		printf("%d no es un numero primo.",n);//De lo contrario, no es primo
	}	
getch();
return(1);	
}
