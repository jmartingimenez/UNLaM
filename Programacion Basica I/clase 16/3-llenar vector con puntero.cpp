//ejercicio rellenar las posiciones desde 20 a 30 inclusive con '1' usando punteros
#include<stdio.h>
#include<conio.h>

main()

{
	int vector[100],i=0;//Se declara el vector y el contador
	int *ptr;//Se declara un puntero
	ptr=&vector[0];//Se obtiene la direccion de memoria de la posicion '0' del vector
	*ptr=22;//Se guarda en 'vector[0]'
	*(ptr+1)=33;//Se guarda en 'vector[1]'
	*(ptr+2)=44;//Se guarda en 'vector[2]'
	printf("pos 0:%d\npos 1:%d\npos 2:%d\n\n",vector[0],vector[1],vector[2]);//Mostrando que se cambiaron
	for(i=20;i<=30;i++)
	{
		*(ptr+i)=1;//A la posicion que apunta -sumada al valor de 'i' se le guarda el numero '1'
		printf("pos %d: %d\n",i,vector[i]);//Se va mostrando que se guardo bien
	}
	getch();
	return(1);
}
