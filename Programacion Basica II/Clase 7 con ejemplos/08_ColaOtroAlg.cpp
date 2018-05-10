#include<stdio.h>
#include<conio.h>

struct COLA
	{
		int id;
		char nombre[10];
		COLA *siguiente;
	};

typedef COLA alumno;

alumno *primero=NULL,*ultimo=NULL;

void ingreso_cola();
void leer_cola();

int main()

	{
		int opc;
		do
			{
				printf("1-Ingresar\n2-Leer\n3-Salir\n\nSeleccion: ");
				scanf("%d",&opc);
				switch(opc)
					{
						case 1:
							ingreso_cola();
							break;
						case 2:
							leer_cola();
							break;
						case 3:
							break;
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta\n\n");
					}
			}while(opc!=3);	
		getch();
		return 0;		
	}
	
void ingreso_cola()

	{
		alumno *nuevo;					//puntero 'auxiliar'
		nuevo=new alumno;				//Asignando memoria del tamaño de alumno
		printf("Ingrese la id: ");
		scanf("%d",&nuevo->id);
		fflush(stdin);
		printf("Ingrese nombre: ");
		gets(nuevo->nombre);
		nuevo->siguiente=NULL;			//ya que es el nuevo, es el ultimo (no hay nadie detras)
		if(ultimo==NULL)				//si el ultimo ya es null es xq hay 1 solo elemento
			{
				ultimo=nuevo;			//entonces unico elemento (nuevo), es el ultimo...
				primero=nuevo;			//y el primero...
			}
		else							//si ya habia un elemento ingresado..
			{
				ultimo->siguiente=nuevo;//el nuevo queda detras del ultimo
				ultimo=nuevo;			//el ultimo toma la posicion del nuevo
			}	
	}

void leer_cola()

	{
		if(primero==NULL)
			{
				printf("\n\n\t\tERROR: No hay elementos para listar!\n\n");
			}
		else
			{
				alumno *nuevo;			//puntero auxiliar
				nuevo=primero;			//este puntero toma el valor del primero
				while(nuevo!=NULL)		//mientras existan elementos..
					{
						printf("%d\t%s\n",nuevo->id,nuevo->nombre);
						nuevo=nuevo->siguiente;//nuevo toma el valor del siguiente en la cola
					}
			}	
	}


