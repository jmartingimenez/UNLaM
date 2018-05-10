/*

	Programa: Mostrar el valor absoluto de un numero
		(hecho de 2 maneras)
			
	-Utilizando un if para ver si el numero es negativo y multiplicarlo por (-1)
	-Utilizando 'abs' (requiere stdlib.h)	
	
	n= variable que guarda el numero ingresado.

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Requerido para el abs

main()

{

int n=0;
printf("\nCalculando el valor absoluto sin abs, ver .cpp\n--------\n");
printf("Ingrese un numero: ");
scanf("%d",&n);
if(n>=0)//El valor absoluto es el mismo numero ingresado
	{
		printf("\nEl valor absoluto de %d es %d",n,n);
	}
else//Si es negativo, se lo multiplica por (-1)
	{
		printf("\nEl valor absoluto de %d es %d",n,n*(-1));
	}

/*

	Utilizando 'abs'
		
***Nota: Para calcular el valor absoluto de 'n', se debe escribir 'abs(n)' 
		(en un printf, o para guardarlo en una variable)

*/

printf("\n\n\n-------------------------------\n\n\n");
printf("Calculando el valor absoluto usando abs, ver .cpp\n--------\n");
printf("Ingrese un numero: ");
scanf("%d",&n);
printf("\nEl valor absoluto de %d es %d",n,abs(n));	
getch();
return(1);	
}
