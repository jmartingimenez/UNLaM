#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

Programa: Ingresar numeros y mostrar cual fue el mayor, el menor y el orden en
que estos 2 fueron ingresados. El resultado final se muestra escribiendo 99.
	
	num= guarda el numero ingresado.
	may= va almacenando el numero mayor.
	men= va almacenando el numero menor.
	ord= va controlando el orden de todos los numeros ingresados.
	ordm= guarda el orden del numero mas alto ingresado.
	ordmen= guarda el orden del numero mas bajo ingresado.

*/
main()

{
	int num=0,may=0,men=0,ord=0,ordm=0,ordmen=0;
	printf("Ingrese numeros y el programa seleccionara mayor, menor y orden en que fueron ingresados.");
	printf("\n\n\tESCRIBA 99 PARA VER EL LAS ESTADISTICAS FINALES");
	printf("\n------------------------------------------");	
	while(num!=99)
	{
		ord++;
		printf("\n%d - Ingrese un numero: ",ord);
		scanf("%d",&num);
		if(ord==1)
			{	  	
				//Este if es el que me permitio solucionar lo del menor.
				//Daba 0 por que no era declarado antes.
				may=num;
				ordm=num;
				men=num;
				ordmen=num;
			}
		if((num==may)&&(num!=99))
			{
				may=num;
				ordm=ord;
			}
		if((num>may)&&(num!=99))
			{
				may=num;
				ordm=ord;
			}
		if((num<men)&&(num!=99))
			{
				men=num;
				ordmen=ord;
			}
	}


system("cls");
printf("\nNumero mayor: %d.\nOrden de ingreso del numero mayor: %d.",may,ordm);
printf("\n------------------------------------------");
printf("\nNumero menor: %d.\nOrden de ingreso del numero menor: %d.",men,ordmen);
getch();
return(1);

}
