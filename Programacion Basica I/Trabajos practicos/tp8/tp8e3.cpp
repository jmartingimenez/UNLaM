/*	(enunciado)
Ingresar 2 variables del tipo numericas, realizar la declaracion de 2 punteros, para con ellos realizar la suma
por referencia e informar
*/
#include<stdio.h>
#include<conio.h>

main()

{
	int n1=0,n2=0,suma=0,*ptr1,*ptr2;//Declaracion de varialbes y punteros
	printf("Ingrese un numero: ");//Pedido del primer numero
	scanf("%d",&n1);
	printf("Ingrese otro numero: ");//Pedido del segundo numero
	scanf("%d",&n2);
	ptr1=&n1;//Haciendo que el puntero vaya a la direccion de memoria donde se guarda 'n1'
	ptr2=&n2;//Haciendo que el puntero vaya a la direccion de memoria donde se guarda 'n2'
	suma=(*ptr1)+(*ptr2);//Sumando lo que contienen las 2 direcciones de memoria
	printf("\n\nLa suma da: %d",suma);	
	getch();
	return(1);
}
