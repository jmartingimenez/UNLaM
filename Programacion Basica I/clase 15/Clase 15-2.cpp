/*
	Programa: Decir si un numero es primo (usando funciones)
	
	n= variable que guarda el numero ingresado
	p= variable que llama a la funcion 'primo' y retorna el valor generado en esta.
(Si retorna 1, el numero es primo)
	i= variable contador para el for que hara las divisiones 'n/i' buscando resto 0.
	j= variable que aumentara cada vez que el resto sea 0.
	re= variable que guardara el valor del resto
	
(si un numero es primo, solo puede ser divisible por 1 y por si mismo -solo 2 situaciones-, por
eso si al final del for, solo hubo 2 'resto 0' -2 casos- es un numero primo y 'p' retorna 1.)
	
*/

#include<stdio.h>
#include<conio.h>

int primo(int n);//Declarando funcion (tipo-nombre-(parametro1,parametro2,etc.)*
				//*Supongo que se refiere a que variable del main llevara a la funcion

int main()

{
int n=0,p;//Declaracion de variables
printf("Ingrese un numero: ");//Pedido de numero
scanf("%d",&n);
p=primo(n);//'p' toma el valor que retorna la funcion 'primo'
/*
Lo que hace el programa en la linea 'p=primo(n)' es ir hasta la funcion 'primo', hacer lo que
esta funcion pide y al final retorna con el valor generado para pasar al if que sigue ahora..
*/
if(p==1)//Si 'p' retorno 1... (ver la otra funcion)
	{
		printf("El numero es primo.");
	}	
else//De lo contrario... (ver la otra funcion)
	{
		printf("El numero no es primo.");
	}	
getch();
return 0;	
}

/*
**************************Funcion Primo*********************************************
*/

int primo(int n)

{
int i=0,j=0,re=0;//Declaracion de variables (son locales xq solo sirven en esta funcion)
for(i=1;i<=n;i++)//Se divide 'n' por 1,2,3... hasta llegar al valor de 'n'
	{
		re=n%i;//Se calcula el resto de 'n/i'
		if(re==0)//Si el resto es 0...
			{
				j++;//Sube el contador 'j'. Esta variable contaria la cantidad de divisores
			}
	}	
if(j==2)//Si la cantidad de divisores ('j') es 2, es un numero primo
	{
		return 1;//'p' retorna 1 (vuelve a la funcion main)
	}	
else	
	{
		return 0;//'p' retorna 0 (vuelve a la funcion main)
	}	
}
