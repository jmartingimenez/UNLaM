/*
	-Ingresar cliente[1-5], termina con 999
	-Articulos[10-14]
	-Cantidad
			
***Mostrar el cuadro

Cliente			Art(10)		Art(11)		Art(12)		Art(13)		Art(14)
1				XX			XX			XX			XX			XX
2				XX			XX			XX			XX			XX
3				XX			XX			XX			XX			XX
4				XX			XX			XX			XX			XX
5				XX			XX			XX			XX			XX

***Decir que cliente llevo mas articulos
*/
#include<stdio.h>
#include<conio.h>
#define FI 5
#define CO 5

int cantidad[FI][CO];

void func_limpiar();
int func_cliente();
int func_articulo();
void func_cantidad(int cliente,int art);
void func_estadisticas(int *ptr);

int main()

{
	int cliente=0,art=0,clientes[5]={1,2,3,4,5},*ptr=clientes;
	func_limpiar();
	while(cliente!=999)//El ingreso para terminar es '999', pero siempre retorno 1 menos de lo ingresado
		{
			cliente=func_cliente();	
			if(cliente!=999)
				{
					art=func_articulo();
					func_cantidad(cliente,art);
				}		

		}
	func_estadisticas(ptr);	
	getch();
	return 0;
}

void func_limpiar()

{
	int i=0,j=0;
	for(i=0;i<FI;i++)
		{
			for(j=0;j<CO;j++)
				{
					cantidad[i][j]=0;
				}
		}
}

int func_cliente()

{
	int cliente=0;
	while((cliente<1)||(cliente>5)&&(cliente!=999))
		{
			printf("Ingrese el numero de cliente: ");
			scanf("%d",&cliente);
			if((cliente<1)||(cliente>5)&&(cliente!=999))
				{
					printf("ERROR!!: Codigo de cliente incorrecto, el rango es entre 1 y 5.\n");
				}
		}
	return cliente;	
}

int func_articulo()

{
	int art=0;
	while((art<10)||(art>14))
		{
			printf("Ingrese el codigo de articulo que desea llevar -Entre 10 y 14-: ");
			scanf("%d",&art);
			if((art<10)||(art>14))
				{
					printf("ERROR!!: Codigo de articulo incorrecto, el rango es entre 10 y 14.\n");
				}
		}
	return art;
}

void func_cantidad(int cliente,int art)

{
	int cant=0;
	printf("Ingrese la cantidad que llevara el cliente %d del articulo %d: ",cliente,art);
	scanf("%d",&cant);
	cantidad[cliente-1][art-10]+=cant;
}

void func_estadisticas(int *ptr)

{
	int i=0,j=0,suma=0,mayorcant=0,clientemax=0;
	/*CALCULANDO CLIENTE QUE MAS GASTO*/
	for(i=0;i<FI;i++)
		{
			for(j=0;j<CO;j++)
				{
					suma+=cantidad[i][j];
				}
			if(suma>mayorcant)
				{
					mayorcant=suma;
					clientemax=i+1;
				}
			suma=0;		
		}
	/*MOSTRANDO TABLA*/
	printf("\nCliente\t\tart10\tart11\tart12\tart13\tart14");
	printf("\n------------------------------------------------------");
	for(i=0;i<FI;i++)
		{
			printf("\n%d\t\t",*(ptr+i));
			for(j=0;j<CO;j++)
				{
					if(cantidad[i][j]==0)
						{
							printf("\t");
						}
					else
						{
							printf("%d\t",cantidad[i][j]);
						}	
				}
		}
	printf("\n\nEl cliente que mas articulos llevo fue el %d con un total de %d articulos.",clientemax,mayorcant);	
}


