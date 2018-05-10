/*
3)	Decir si las siguientes expresiones son equivalentes. Realizar las declaraciones necesarias
para que las mismas se cumplan

*ip = &v[0] 				ip = v[ ]
x = ip; 					x = v[0]; 
&(v + 1) 					*v[1] 
*v + I 						&v[i]
*/

#include<stdio.h>
#include<conio.h>
#define MAX 5

int main()

{
	int i=0,x=0,v[MAX]={2,4,6,8,10},*ip=&v[0];
	printf("Primera Expresion\tSegunda Expresion\n------------------------------------------\n\n");

/*PRIMERA EXPRESION		*ip = &v[0] 				ip = v[ ]				*/	
	printf("%d",&v[0]);					//La expresion ip=v[] ni siquiera permite compilar
	ip=v;								//Para la equivalencia se puede usar ip=v
	printf("\t\t\t%d\n",ip);			//en la segunda expresion
	


/*SEGUNDA EXPRESION		x = ip; 					x = v[0]; 				*/	
	x=*ip;								//La expresion x=ip no deja compilar por que 'ip' no es una variable
	printf("\n%d",x);					//Para igualar la primera expresion a la segunda, que si esta bien hecha,
	x=v[0];								//hay que hacer 			x=*ip;
	printf("\t\t\t%d\n",x);
	
	
/*TERCERA EXPRESION		&(v + 1) 					*v[1]					*/	
	printf("\n%d",&v[1]);				//La expresion &(v + 1) no deja compilar, para mostrar la direccion
										// de la segunda posicion del vector se puede usar &v[1]
										
	//Entendiendo yo que se quiere igualar la segunda expresion a la primera y utilizando yo '&v[1]'	
									
	printf("\t\t\t%d\n",&(ip[1]));		//*v[1]	es otro error de sintaxis, si se quiere mostrar el valor
										//de la posicion 1, se podria usar *(ip+1) o ip[1] o v[1]
										//Para que la segunda expresion muestre la misma direccion que la
										//primera se puede utilizar &(ip[1])
	
	
/*CUARTA EXPRESION		*v + I 						&v[i]					*/	
	for(i=0;i<MAX;i++)
		{
			printf("\n%d",ip+i);		//La primera expresion suma el valor de 'i' al valor de la primera 
			printf("\t\t\t%d",&v[i]);	//posicion del vector. La segunda muestra las direcciones de memoria
										//donde se alojan los valores de cada posicion del vector
										//Para que ambas muestren las direcciones de memoria, la primera
										//puede dejarse como 'ip+i'
		}

	//FIN
 	getch();
	return 0;
}

