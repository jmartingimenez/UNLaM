#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*

	Programa: Mostrar numero mas alto y su orden de ingreso(vectores)
	
	i: en el vector guardara el valor ingresado en el orden correspondiente.
(por eso el i++), el primer numero seria 'vector[0],vector[1]... etc..
***Ademas sirve como contador en el for.
***el for controlara que posicion del vector almacenara los numeros	
	
	max: guarda el numero mas alto
	pos: guarda la posicion del numero mas alto
	vector[30]: array que almacenara todos los numeros ingresados. 30 es
el limite

	-El primer for es para asegurarse que todos los valores del vector
(desde 0 -arranca de 0- hasta 30 -29 creo yo- valgan 0)
	-El segundo ya es el contador que pedira 30 veces ingresar numero
(se iran almacenando en 'vector[i]'. El valor de i depende de cuantas veces
el bucle reinicio. Si es el primer numero sera vector[0]. Si es el decimo,
sera vector[9].

	-El if controla si el numero ingresado es mayor al anterior. Si esta
condicion se cumpla el maximo (max) valdra ese ultimo valor ingresado. Ademas
se guardara la posicion (pos) que es simplemente el valor actual de 'i'

***Nota: Como el vector arranca en 0, si se llama al primer valor usando un
"%d" con un print, en vez de mostrar uno (por ser el primer valor), obviamente
mostrara un 0. Es por eso que al final del print, en vez de poner 'i' como
se hace normalmente, se le agrega un '+1' para que valor mostrado sea uno mas.
De esa manera se ve correctamente (Si esto no se hace al iniciar el programa
diria 'Ingrese un numero en la posicion 0: '


*/

main()

{
int i=0,max=0,pos=0,vector[30];
for(i=0;i<30;i++)
	{
		vector[i]=0;
	}
i=0;		
for(i=0;i<30;i++)	
	{
		system("cls");//Limpiar pantalla en cada bucle
		printf("Ingrese un numero en la posicion %d: ",i+1);//Leer ***nota
		scanf("%d",&vector[i]);//Se guarda en la posicion actual del vector
		if(vector[i]>max)//Compara la posicion actual 
		{
			max=vector[i];//Se setea como maximo el numero del valor actual de i
			pos=i;//Se setea la posicion=valor de i(en el bucle) en ese momento
		}
		
	}	
system("cls");
printf("En la posicion %d se encuentra el numero mas alto que es: %d.",pos,max);	
getch();
return(1);	
}
