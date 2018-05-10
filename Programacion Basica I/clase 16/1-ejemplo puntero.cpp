/*
	Programa: Ejemplo de como funcionan los punteros
*/
#include<stdio.h>
#include<conio.h>


main()

{
	int x=0;//Se declara la variable 'x' con un valor inicial de 0
	int *p1,*p2;//Se declaran 2 punteros (no estan apuntando a nada -basura probablemente-)
	p1=&x;//Se obtiene la direccion de memoria
	printf("p1: %d\n",p1);//Se muestra la direccion de memoria (no en hexadecimal)
	printf("p1: %p\n",p1);//Se muestra la direccion de memoria (en hexadecimal)
	p2=p1;//p2 toma el mismo valor que p1
	printf("p2:\t%d\t%p\t%d\n",p2,p2,*p2);//Se muestra que es exactamente igual a p1
	*p1=33;//Se apunta a la direccion que apunta p1 (&x) y se le guarda el valor de 33
	printf("%d\t%d\n",p1,*p1);//El primero muestra la direccion, el segundo el contenido
	printf("Valor de x actual: %d\n",x);//Se observa que 'x' tomo el valor que apunta *p1
	x=*p1+7;//Se suma 7 al lugar donde apunta *p1 y se guarda en 'x'
	printf("Nuevo valor de x: %d\n",x);
	*p1=*p2+4;//Se le suma 4 a los 40
	printf("Ahora vale: %d\n",*p1);
	printf("%p\t%d",x,x);//Se muestra la direccion final y el valor final de x
	getch();
	return(1);
}
