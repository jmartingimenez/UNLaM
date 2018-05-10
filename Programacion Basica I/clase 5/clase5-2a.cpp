#include<stdio.h>
#include<conio.h>

/*
Programa: Calcular el factorial de un numero.

i es la variable contador.
f controla q valor de cual multiplicacion lleva, va aumentando desde 1 hasta &num.
num guarda el numero a calcular.

Solo se calcula bien si f=1. Si f=0 dentro del for arrancaria con un 0=0*i
	(que daria 0). Las multiplicaciones van desde 1 hasta num
***No se me ocurrio otra forma mas simple de poner un solo getch/return..
***explicacion de for..
	for(i=1;i<=num;i++)
	1- El contador comienza en 1(en cada bucle sube uno).

	2- El limite del contador es num. El <= (en vez de solo <)
es importante, de lo contrario no multiplica su propio numero. Ejemplo...
con <= es... 5!=5*4*3*2*1 (bien) //El programa hace esto: 1*2*3*4*5
con < es...	 5!=4*3*2*1 (mal) //El programa hace esto: 1*2*3*4
	
	3- El ++ sube un valor al contador.

*/

main()

{//inicio
	
int i=0,num=0,f=1;
printf("Ingrese un numero: ");
scanf("%d",&num);
if(num==0)
	{
		printf("\nEl factorial de 0 es 1.");//no me pregunten el xq :D	
getch();
return(1);
	}
else
{

	if(num>0)
	{
		for(i=1;i<=num;i++)
		{
		f=f*i;
		}
	}
	else
	{
		printf("\nEl factorial de un numero negativo no esta definido.");
getch();
return(1);

			
	}
	

}	
printf("\nEl factorial de %d es %d.",num,f);
getch();
return(1);	
}//inicio
