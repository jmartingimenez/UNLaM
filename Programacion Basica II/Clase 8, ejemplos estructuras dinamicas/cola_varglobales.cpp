#include<stdio.h>
#include<conio.h>

struct COLA
	{
		int num;											//dato a pedir
		COLA *siguiente;									//Puntero autoreferencial (el q mantiene 'linkeada' la cola)
	};

typedef COLA dato;											//Achicando la definicion

dato *primero=NULL,*ultimo=NULL;							//VARIABLES GLOBALES QUE NECESITAMOS SEGUIR
															//A DIFERENCIA DE LA PILA, ACA SON 2, ENTONCES
															//COMO NO PUEDO RETORNAR 2 COSAS (AL MENOS DE
															//MANERA QUE YO SEPA), HACEMOS ESTO...

void cola_ingreso();										//Declaracion de funciones
void cola_mostrar();
void cola_buscar();
void cola_eliminar();//NO FUNCIONA BIEN, SI ELIMINO LA COLA NO ME DEJA VOLVER A AGREGAR :(

int main()

	{
		int opc;											//Para el menu..
		do
			{
				printf("1-Ingresar\n2-Leer\n3-Buscar\n4-Eliminar cola\n5-Salir\n\nSeleccion: ");	
				scanf("%d",&opc);
				switch(opc)
					{
						case 1:
							cola_ingreso();
							break;
						case 2:
							cola_mostrar();
							break;
						case 3:
							cola_buscar();
							break;
						case 4:
							cola_eliminar();
							break;
						case 5:
							break;	
						default:
							printf("\nERROR!!\n");
					}
			}while(opc!=5);
		getch();
		return 0;
	}
	
void cola_ingreso()

	{
		dato *nuevo;									//Puntero auxiliar
		nuevo=new dato;									//Asignando memoria dinamica para nuevo sizeof(dato)
		printf("Ingrese un numero: ");					//Pedido de numero
		scanf("%d",&nuevo->num);
		nuevo->siguiente=NULL;							//Ya que es el nuevo, es el ultimo (no hay nadie detras)	
		if(ultimo==NULL)								//Si el ultimo es NULL es xq hay 1 solo elemento			
			{
				ultimo=nuevo;							//Entonces el unico elemento (nuevo), es el ultimo...	
				primero=nuevo;							//y tambien el primero...	
			}
		else											//Si ya habia un elemento ingresado..		
			{
				ultimo->siguiente=nuevo;				//El nuevo queda detras del ultimo
				ultimo=nuevo;							//El ultimo de la cola ahora es el nuevo ingreso
			}
	}
	
void cola_mostrar()

	{
		if(primero==NULL)								//Si no existe primero en la cola, no hay nadie..
														//Usar ultimo, se supone que da el mismo efecto	
			{
				printf("\n\n\t\tERROR: No hay elementos para listar!\n\n");
			}
		else											//Si hay cola para observar..
			{
				dato *nuevo;							//Puntero auxiliar						
				nuevo=primero;							//Nuevo toma el valor de 'primero'
														//(En pila se recorria desde el ultimo al primero)
														//(Aca es desde el primero hasta el ultimo)			
				while(nuevo!=NULL)						//Mientras nuevo no sea NULL (no termine de recorrer)			
					{
						printf("%d\n",nuevo->num);		//Mostrar el dato actual del recorrido
						nuevo=nuevo->siguiente;			//'nuevo' toma el valor del siguiente en la cola
														//para continuar el recorrido.
					}
			}			
	}	
	
void cola_buscar()

	{
		if(primero==NULL)								//Esta funcion es IDENTICA a la de arriba	
														//Solo cambia el while para buscar coincidencia													
			{
				printf("\n\n\t\tERROR: No hay elementos para buscar!\n\n");
			}
		else											
			{
				dato *nuevo;
				int aux;								//Variable auxiliar para guardar el numero a buscar
				printf("Ingrese el numero a buscar: ");
				scanf("%d",&aux);											
				nuevo=primero;							
				while(nuevo!=NULL)							
					{
						if(aux==nuevo->num)				//Si existe coincidencia
							{
								printf("\nEncontrado el numero %d\n",nuevo->num);
								break;
							}
						nuevo=nuevo->siguiente;			
					}
				if(nuevo==NULL)							//Si recorrio todo es por que no hubo coincidencia
														//y jamas toco el 'break'
					{
						printf("\nNO SE ENCONTRO EL NUMERO.\n");
					}	
			}				
	}	
	
void cola_eliminar()								//SI ELIMINO LA COLA NO ME DEJA VOLVER A AGREGAR

	{
		if(ultimo==NULL)							
													
			{
				printf("\n\n\t\tERROR: No hay elementos para eliminar!\n\n");
			}
		else											
			{
				while(ultimo!=NULL)
					{
						dato *nuevo;											
						nuevo=primero;
						primero=primero->siguiente;
						delete nuevo;
						if(primero==NULL)
							{
								ultimo=primero;
							}						
					}
			}				
	}		
