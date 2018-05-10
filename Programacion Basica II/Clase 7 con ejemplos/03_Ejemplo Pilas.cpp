#include<stdio.h>
#include<conio.h>

struct PILA													//Estructura Para el manejo de la pila
	{
		char nombre[10];
		int num;											//Variable que guardara numeros ingresados
		struct PILA *anterior;								//Puntero autoreferencial que apuntara al
															//elemento ingresado anteriormente
	};

int main()

	{
		PILA *ultimo=NULL,*actual=NULL;						//Declaracion de 2 punteros de tipo PILA
															//*ultimo guardara el ultimo elemento ingresado
															//*actual actua como auxiliar y funcionara
															//de manera similar a *ultimo
															//A medida que se apilen elementos, actual siempre
															//tendra el ultimo elemento ingresado. Ultimo
															//podra tener el mismo o el anterior y anterior
															//el anterior a ultimo
															//		EJ DE PILA
															//					-Actual/Ultimo
															//					-Anterior
															//Por cada iteracion (un loop en un bucle)
															//Actual ira tomando el valor actual ingresado
															//Anterior tomara el valor de ultimo y este
															//el de actual. Actual actua como auxiliar
															//estilo el tipico 'temp' usado para ordenar
															//vectores
															
		int opcion,apilados=0,desapilados=0;				//opcion es para el do/while, para seguir ingresando
															//apilados es un contador de elemenos apilados
															//desapilados cuenta los desapilados
		
			/*========================AGREGAR NUMEROS A LA PILA========================*/
							
		do
			{
				actual=new struct PILA;						//Se reserva memoria dinamica para actual. Estamos
															//creando un nuevo elemento de la pila. 
															
				printf("Ingrese un numero: ");				//Pedido de numero
				scanf("%d",&actual->num);					//Se guarda en el campo numero de actual
															//Recordemos que actual es una variable de tipo
															//PILA, por lo que tiene este campo y el puntero
															//*anterior
				fflush(stdin);
				printf("Ingrese nombre: ");
				gets(actual->nombre);											
				actual->anterior=ultimo;					//Como escribi arriba, anterior pasa a tener el
															//valor del ultimo ingreso ya que necesitamos
															//guardarlo por que en el proximo loop se
															//perderia por la linea que sigue ahora..
															
				ultimo=actual;								//ultimo toma el valor de la auxilar actual
															//Como son variables iguales de tipo PILA
															//ultimo tambien tiene los 2 campos definidos
															//al principio
															
				printf("\n\n\t\tSi desea finalizar la carga pulse 0. Otro numero para continuar\n\t\tSeleccion: ");
				scanf("%d",&opcion);
				printf("\n\n");
				apilados++;									//Contador de elementos apilados
			}while(opcion!=0);
		printf("\n\n\t\t%d elementos apilados.\n\n",apilados);//Mostrando la cantidad de apilados	
			
		/*========================VISUALIZANDO LOS ELEMENTOS DE LA PILA========================*/
							
		if(ultimo==NULL)									//Arriba definimos *ultimo=NULL
															//Si no se apilo nada, se mantiene igual
															//y se da el msj de error
			{
				printf("\n\n\t\tERROR!!: No hay elementos para listar.\n\n");
			}
		else
			{
				actual=ultimo;								//Actual toma el valor de ultimo. Ahora
															//vendria la operacion inversa ya que ira
															//'retrocediendo'
															//(yendo del ultimo elemento agregado hasta
															//el primero)
															
				while(actual!=NULL)							//Como ultimo se inicializa como NULL
															//Si estamos 'retrocediendo', en algun momento
															//ultimo sera NULL y por ende actual al igualarlo
															//tambien lo sera. Lo que indicara que se llego
															//al primer elemento ingresado.
					{
						printf("%d\t%s\n",actual->num,actual->nombre);			//Se muestra el campo num de actual correspondiente
															//al elemento de la pila analizado
															
						actual=actual->anterior;			//actual pasa a tomar un valor anterior al actual
					}
			}	
			
		/*========================DESAPILANDO LOS ELEMENTOS DE LA PILA========================*/
							
		if(ultimo==NULL)									//Si ultimo se mantuvo como NULL es por que no
															//se apilo nada.
			{
				printf("\n\n\t\tERROR!!: No hay elementos para desapilar.\n\n");
			}					
		else
			{
				while(ultimo!=NULL)							//Como iremos desapilando desde el ultimo
															//elemento hasta el primero, al terminar de
															//desapilar ultimo tomara su valor original
															//al ser declarado que servira para indicar
															//que se termino de desapilar
															//(este es el sentido de que *anterior vuelva
															//a llamar a la misma estructura en la declaracion
															//, para mantener los elementos de la pila 'linkeados'
															//, o al menos yo lo entiendo asi, tomalo con pinzas)
					{
						actual=ultimo;						//actual toma el valor del ultimo. Al liberar
															//actual 2 lineas mas abajo nos estamos deshaciendo
															//del primer elemento en la pila
															
						ultimo=ultimo->anterior;			//ultimo ahora pasara a tomar el valor anterior
															//si existe otra iteracion, tambien sera eliminado
															//este elemento 
															
						delete actual;						//liberamos actual y por ende, nos deshacemos del
															//primer elemento en la lista a eliminar
															//el (actual=ultimo) que esta mas arriba
															
						desapilados++;						//contador de elementos desapilados
					}
			}	
		printf("\n\n\t\t%d elementos desapilados.",desapilados);	//mostrando la cantidad de elemenos 
																	//desapilados	
		getch();
		return 0;
	}
