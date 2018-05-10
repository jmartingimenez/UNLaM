#include<stdio.h>
#include<conio.h>

struct COLA

	{
		int id;
		char nombre[10];
		COLA *siguiente;
	};

typedef COLA empleado;	

void ingreso();
void leercola();

empleado *ultimo=NULL,*primero=NULL;	

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
							ingreso();
							break;
						case 2:
							leercola();
							break;
						case 3:
							break;
						default:
							printf("\nERROR\n");
					}
			}while(opc!=3);	
		getch();
		return 0;
	}

void ingreso()

	{
		empleado *nuevo;
		nuevo=new empleado;
		printf("Ingrese id: ");
		scanf("%d",&nuevo->id);
		fflush(stdin);
		printf("Ingrese nombre: ");
		gets(nuevo->nombre);
		nuevo->siguiente=NULL;			
		if(ultimo==NULL)				
			{
				ultimo=nuevo;			
				primero=nuevo;			
			}
		else							
			{
				ultimo->siguiente=nuevo;
				ultimo=nuevo;			
			}
	}
	
void leercola()

	{
		if(primero==NULL)
			{
				printf("\n\n\t\tERROR: No hay elementos para listar!\n\n");
			}
		else
			{
				empleado *nuevo;		
				nuevo=primero;			
				while(nuevo!=NULL)		
					{
						printf("%d\t%s\n",nuevo->id,nuevo->nombre);
						nuevo=nuevo->siguiente;
					}
			}	
	}
	
