/*
	Programa: Sumar dos numeros dados e indicar cual es el mayor (usando funciones)
				
	a,b= variables que guardan los numeros ingresados
	s= variable que llama a la funcion 'suma' y toma el valor retornado por esta (la suma)
				
***Diferencia entre el 'int' y el 'void'
	-la funcion 'suma' es tipo entera (retorna un valor entero, en este caso, la suma de a y b)
	-la funcion 'mayor' es tipo 'void' (vacia), debido a que no retorna ningun valor
			
(Las comparaciones y los prints se hacen dentro de la funcion 'mayor', no retorna ningun valor
que pueda ser utilizando en el main)
 			
*/

#include<stdio.h>
#include<conio.h>

int suma(int a,int b);//Declaracion de funcion tipo entera (retornara a+b)
void mayor(int a,int b);//Declaracion de funcion tipo void (no retorna ningun valor)

int main()

{
	int a=0,b=0,s;//Declaracion de variables
	printf("Ingrese un numero: ");//Pedido del primer numero
	scanf("%d",&a);
	printf("Ingrese otro numero: ");//Pedido del segundo numero
	scanf("%d",&b);
	s=suma(a,b);//'s' llama a la funcion 'suma' y toma el valor retornado por esta
	printf("La suma da como resultado %d\n",s);//Se muestra 's' (que es la suma)
	mayor(a,b);	//Se llama a la funcion mayor y no retorna nada
/*Si retornara algun valor, como en 'suma', se necesitaria una variable, ej. 'm' para 
almacenar el mismo, como no es el caso, ya que las comparaciones y los mensajes se realizan
completamente en la funcion 'mayor' se escribe simplemente asi*/	
	getch();//Despues de finalizar la funcion 'mayor' vuelve aca
	return 0;
}

//************funcion suma*****************

int suma(int a,int b)

{
	return a+b;//Directamente retornamos la suma, no es necesario crear variables para esto
				//ya que es una operacion simple	
}

//***************funcion mayor*****************

void mayor(int a,int b)

{
	if(a==b)//Comparaciones..
		{
			printf("Los numeros son iguales.");
		}
	else
		{
			if(a>b)
				{
					printf("El numero %d es el mayor.",a);
				}
			else
				{
					printf("El numero %d es el mayor.",b);
				}	
		}	
}
