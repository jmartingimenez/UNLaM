/*
EJEMPLO DE MANEJO DE PILA USANDO EL PUNTERO DE SEGUIMIENTO (*ultimo) COMO GLOBAL.
DECLARAR COMO GLOBAL ALGO QUE SE PUEDE EVITAR ,SEGUN DICEN, NO ES LO IDEAL.
EN LO QUE RESPECTA AL MANEJO DE COLA HAY QUE HACER EL SEGUIMIENTO DE 2 PUNTEROS (*primero) Y (*ultimo), COMO
LAS FUNCIONES PUEDEN RETORNAR SOLO UNA COSA A LA VEZ, NO SE BIEN COMO ESTAR AL TANTO DE A DONDE APUNTAN
AMBOS. ES POR ESTO QUE TOME LA DECISION DE QUE LOS PUNTEROS QUE SE USAN EN LAS ESTRUCTURAS DINAMICAS
DECLARARLOS COMO GLOBALES
	-DA MENOS TRABAJO
	-HACE MAS SIMPLE Y ENTENDIBLE EL CODIGO
				
VI MUY POR ARRIBA LISTA Y PARECE Q USA 4 PUNTEROS, ASI Q MAS JODIDO AUN DE SEGUIR TODOS LOS PUNTEROS, ASI
QUE SI ESTAS DE ACUERDO CON DEJAR LOS PUNTEROS COMO GLOBALES LE DAMOS PARA ADELANTE DE ESTA MANERA.		
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct PILA
	{
		int id;										//Datos a pedir
		char nombre[10];							//Datos a pedir
		PILA *anterior;								//Puntero autoreferencial (el q mantiene 'linkeada' la pila)
	};
	
typedef PILA dato;									//Con esto puedo hacer 'dato *ultimo=NULL'
													//Sin esto tendria q poner 'struct PILA ultimo=NULL'

dato *ultimo=NULL;									//DECLARANDO EL PUNTERO QUE NOS INTERESA SEGUIR SU VALOR
													//COMO GLOBAL, COMO YA NO LO VAMOS A PASAR POR REFERENCIA
													//NI  RETORNAR NADA, LAS FUNCIONES QUEDAN EN VOID Y NO
													//NECESITAN ACTUAR COMO PUNTEROS

void ingreso_pila();								//Declaracion de funciones
void leer_pila();
void buscar_pila();
void desapilar_pila();
	
int main()

	{
		int opc;									//Para el menu
		do
			{
				printf("1-Ingresar\n2-Leer\n3-Buscar\n4-Desapilar\n5-Salir\n\nSeleccion: ");
				scanf("%d",&opc);
				switch(opc)
					{
						case 1:
							ingreso_pila();
							break;
						case 2:
							leer_pila();
							break;
						case 3:
							buscar_pila();
							break;
						case 4:
							desapilar_pila();
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
	
void ingreso_pila()

	{
		dato *nuevo;										//Puntero auxiliar
		nuevo=new dato;										//Asignando memoria dinamica sizeof(dato)
		printf("Ingrese el codigo: ");
		scanf("%d",&nuevo->id);
		fflush(stdin);										//Antes de manejar caracteres
		printf("Ingrese el nombre: ");
		gets(nuevo->nombre);
		nuevo->anterior=ultimo;								//El puntero autoreferencial de la variable
															//'nuevo' (es de tipo 'dato' asi que tiene los
															//mismos campos que la estructura) toma el
															//valor del ingreso anterior a 'ultimo' que 
															//pasara a ser el anterior en reemplazo del nuevo
															//dato ingresado				
		ultimo=nuevo;										//el ultimo (cima de la pila) toma el valor
															//del ultimo ingreso	
	}	
	
void leer_pila()

	{
		if(ultimo==NULL)									//Si 'ultimo' no vario de NULL, no se ingreso nada
			{
				printf("\nERROR: No hay elemento para visualizar\n");
			}
		else
			{
				dato *nuevo;								//Puntero auxiliar
				nuevo=ultimo;								//'nuevo' toma el valor del ultimo dato ingresado					
				while(nuevo!=NULL)							//mientras 'nuevo' no llege a NULL
															//(Recorre desde el ultimo dato hasta el primero)
					{									
						printf("%d\t%s\n",nuevo->id,nuevo->nombre);//Mostrar los valores de 'nuevo'
						nuevo=nuevo->anterior;				//Nuevo toma el valor alojado en la posicion
					}										//anterior a la actual (para que siga recorriendo)
			}			
	}	
	
void buscar_pila()

	{
		if(ultimo==NULL)									//Si 'ultimo' no vario de NULL, no se ingreso nada
			{
				printf("\nERROR: No hay elemento para visualizar\n");
			}
		else
			{
				int codigo;									//Variable auxiliar para buscar
				printf("Ingrese el codigo a buscar: ");
				scanf("%d",&codigo);
				dato *nuevo;								//Puntero auxiliar
				nuevo=ultimo;								//Toma el dato del ultimo ingreso
				while(nuevo!=NULL)							//Esto funciona igual que la funcion de leer..				
					{									
						if(codigo==nuevo->id)				//Solo que imprime cuando hay coincidencia..
							{								
								printf("%d\t%s\n\n",nuevo->id,nuevo->nombre);
								break;						//Para salir del while y evitar que llege a NULL	
							}								//(De lo contrario nos daria el error de abajo)
						nuevo=nuevo->anterior;		
					}
				if(nuevo==NULL)								//Es por que nunca encontro coincidencia y termino
					{										//de recorrer la pila.
						printf("\nNO SE ENCONTRO EL CODIGO.\n");
					}					
			}
	}	
	
void desapilar_pila()

	{
		if(ultimo==NULL)										//Si ultimo es NULL, no se apilo nada
			{
				printf("\nERROR: No hay elementos para desapilar.\n");
			}
		else
			{
				dato *nuevo;									//Puntero auxiliar
				while(ultimo!=NULL)								//Mientras no sea NULL...
					{
						nuevo=ultimo;							//'nuevo' toma el valor de 'ultimo'			
						ultimo=ultimo->anterior;				//'ultimo' toma el valor del elemento que
																//le sigue en la pila. Como estamos eliminando
																//desde el primer elemento al final. Si no 
																//hacemos esto, se pierde la 'conexion' entre
																//los elementos
						delete nuevo;							//Liberamos la memoria del elemento borrado						
					}
			}		
	}	
