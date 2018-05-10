#include<stdio.h>
#include<conio.h>

/*

Programa: Mostrar desde el numero entero seleccionado hasta 0
(si se elije 3, mostrara 3,2,1)

	num guarda el numero ingresado.
	El while mostrara el valor de num (por bucle bajara un valor con el
num-- hasta llegar a 1 -por eso es >num y no >=num- 

	Los if creo que no eran necesarios, son solo condiciones para que el
bucle actue de distinta manera. Si el numero ingresado es negativo
en vez de num-- sera num++ (ej: ingresado -3 ---> mostrara -3,-2-,1)
	La otra condicion es si el numero es igual a 0, da un mensaje diciendo
que el numero es igual al limite original.

*/

main()

{
	int num=0;
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	if(num>0)
		{
			while(num>0)
					{
						printf("\n%d",num);
						num--;
					}

		}
	else
	{
		if(num<0)
		{
				while(num<0)
					{
						printf("\n%d",num);
						num++;
					}
		}
		else
printf("El numero ingresado es igual al limite: 0.");
	}
	
getch();
return 0;
}
