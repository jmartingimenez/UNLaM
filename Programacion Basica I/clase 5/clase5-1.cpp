#include<stdio.h>
#include<conio.h>
main()
{
	int i=0,ciclos=0;
	printf("Cantidad de ciclos: ");
	scanf("%i",&ciclos);
	float n,s;
	for(i=1;i<=ciclos;i++)
	{
		printf("en el ciclo %i ingrese el nro:",i);
		scanf("%f",&n);
		s=s+n;
	}
	printf("el total fue:%.2f",s);
	 
	getch();
	
}
