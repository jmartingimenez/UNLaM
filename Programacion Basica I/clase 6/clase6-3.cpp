#include<stdio.h>
#include<conio.h>

/*

Programa: Mostrar factorial desde 25 hasta 5 en forma descendente.

***Importante: solo calcula bien hasta 13! (Es un problema con la cantidad 
de bits segun san google)

El unsigned long esta para que calcule mejor mas factoriales pero no vi diferencia.
i es la variable contador madre: regula que pase de ejercicio..
	una vez q se calcula el factorial de 25, pasa a 24, 23, etc
	(es la que marca que llege hasta 5)
n marca el numero de inicio de las multiplicaciones
	 (coincide con i, por eso se iguala), ira haciendo *25,*24,*23;etc.
	 Para que sea en forma descendiente las multiplicaciones.
f va guardando los resultados provisorios
	(f=f*n) ------> (f=1*25, ya que f=1), ese resultado	despues *24,*23, etc.
	Al finalizar el bucle madre debe volver a 1 para reiniciar el calculo del
	bucle interno correctamente.
c es la variable contador hija, ordena desde donde arrancan las multiplicaciones.
	si se la quita, todos los factoriales darian igual
	(el teorico 25! que es un resultado incorrecto x lo marcado al principio) 	

*/
main()

{

unsigned long int i=0,n=25,c=25;
float f=1;
printf("Este programa mostrara los factoriales comprendidos entre 25 y 5 en forma descendente.");	
for(i=n;i>=5;i--)//aca el limite hasta 5 para calcular
	{
			for(n=c;n>=1;n--)
		{
			f=f*n;
		}
		c--;
		printf("\n%d! = %.0f.",i,f);
		f=1;

	}

getch();
return(1);	
}
