#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

	Programa: Clasificar numeros ingresados entre pares e impares y mostrar
el numero mayor.

	El 99 muestra las estadisticas y finaliza el while. Esta excluido en
todos los if para que este numero no se agrege a las estadisticas.
	cpar=contador de numeros pares ingresados.
	cimpar=contador de numeros impares ingresados.
	num= variable tipo entera que almacena en numero ingresado.
	mayor=variable que guarda el mayor numero ingresado.
	resto= calcula el resto de la division de num por 2
(Es una variable de tipo entero ya que guarda el resultado)
si el resto es 0, el numero es par. Si el resto es 1, el numero es impar.	
	

*/

main()

{
	int cpar=0,cimpar=0,num=0,resto=0,mayor=0;
	printf("Ingrese numeros y el programa los separara en pares e impares.");
	printf("\nTambien mostrara el numero mas alto ingresado.");
	printf("\n\n\tESCRIBA 99 PARA VER EL LAS ESTADISTICAS FINALES");
	printf("\n------------------------------------------\n");		
	while(num!=99)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&num);
		resto=num%2;
		if((resto==0)&&(num!=99))//Sin esto, el 99 se agrega al contador de pares. 
			{
				cpar++;//el numero es par,aumenta el contador de pares
			}
		else
			{
				if(num!=99)//Sin esto, el 99 se agrega al contador de impares.
				{
					cimpar++;//el numero es impar,aumenta el contador de impares.
				}
			
			}
	if((num>mayor)&&(num!=99))//Sin esto, el 99 podria pasaria a ser numero mayor.
		{
			mayor=num;//se define el numero mayor.
		}
	}

system("cls");//limpiar pantalla
printf("Cantidad de numeros pares: %d",cpar);
printf("\nCantidad de numeros impares: %d",cimpar);
printf("\nEl numero mayor es %d.",mayor);
getch();
return(1);
}
