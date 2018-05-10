#include<stdio.h>
#include<conio.h>



void incrementar_var(int *var);//Usa la referencia como argumento

main()

{
	int x=1;//Se declara 'x'
	incrementar_var(&x);//Se lleva la direccion de memoria donde se encuentra 'x' a la funcion
	printf("%d",x);//Se muestra el nuevo valor de 'x'
	getch();
	return 0;
}
void incrementar_var(int *var)//El puntero utiliza como referencia el '&x'
{
	(*var)++;//Se le aumenta en 1 el contenido de la direccion referenciada
}
