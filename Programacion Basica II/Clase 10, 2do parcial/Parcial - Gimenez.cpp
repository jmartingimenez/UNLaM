/*
Apellido: Gimenez
Nombre: Jonatan
Tema: Pila
*/

#include<stdio.h>

struct PILA
	{
		int codigo;
		char producto[15];
		float precio;
		PILA *anterior;
	};

int seleccion_estructura();
PILA *menu_pila(PILA *ultimo);
PILA *ingreso(PILA *ultimo);
void visualizar(PILA *ultimo);
void extraer(PILA *ultimo);
PILA *eliminar(PILA *ultimo);
void crear_archivo(PILA *ultimo);

int main()

	{
		int menu_estructura;
		PILA *ultimo=NULL;
		do
			{
				menu_estructura=seleccion_estructura();
				switch(menu_estructura)
					{
						case 1:
							ultimo=menu_pila(ultimo);
							break;
						case 4:
							break;	
						default:
							printf("\n\nERRROR!!: La opcion seleccionada no se encuentra disponible!!\n\n");
					}
			}while(menu_estructura!=4);
		crear_archivo(ultimo);	
		return 0;
	}

int seleccion_estructura()

	{
		int opc;
		printf("1-Pila\n2-Cola\n3-Lista\n4-Salir\n\nSeleccion: ");
		scanf("%d",&opc);
		return opc;
	}

PILA *menu_pila(PILA *ultimo)
	
	{
		int menu;
		do
			{
				printf("\n\n1-Insertar producto\n2-Visualizar\n3-Extraer producto\n4-Eliminar listado de productos\n5-Volver\n\nSeleccion: ");
				scanf("%d",&menu);
				if(menu<1 or menu>5)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta!!\n\n");;
					}
				switch(menu)
					{
						case 1:
							ultimo=ingreso(ultimo);
							break;
						case 2:
							visualizar(ultimo);
							break;	
						case 3:
							extraer(ultimo);
							break;
						case 4:
							ultimo=eliminar(ultimo);
							break;
						case 5:
							break;	
					}					
			}while(menu!=5);
		return ultimo;		
	}

PILA *ingreso(PILA *ultimo)

	{
		PILA *actual;
		actual=new PILA;
		printf("Ingrese el codigo del producto: ");
		scanf("%d",&actual->codigo);
		fflush(stdin);
		printf("Ingrese el nombre del producto: ");
		gets(actual->producto);
		printf("Ingrese el precio del producto: ");
		scanf("%f",&actual->precio);
		actual->anterior=ultimo;
		ultimo=actual;
		return ultimo;
	}	

void visualizar(PILA *ultimo)

	{
		if(ultimo==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay productos en la lista!!\n\n");
			}
		else
			{
				PILA *actual;
				actual=ultimo;
				printf("\n\nCodigo\tNombre de producto\tPrecio\n--------------------------------------\n\n");
				while(actual!=NULL)
					{
						printf("\n%d\t\t%s\t\t$%.2f",actual->codigo,actual->producto,actual->precio);
						actual=actual->anterior;
					}				
			}	
	}
	
void extraer(PILA *ultimo)

	{
		
		if(ultimo==NULL)
		{
				printf("\n\n\t\tERROR!!: No hay productos en la lista!!\n\n");
		}
		else
			{
				int aux;
				printf("Ingrese el codigo del producto que desea visualizar: ");
				scanf("%d",&aux);
				PILA *actual;
				actual=ultimo;
				while(actual!=NULL)
					{
						if(aux==actual->codigo)
							{
								break;
							}
						actual=actual->anterior;	
					}
				if(actual==NULL)
					{
						printf("\n\n\t\tERROR!!: No se encontro el codigo\n\n");
						return;
					}
				else
					{
						printf("\n\nCodigo\tNombre de producto\tPrecio\n--------------------------------------\n\n");
						printf("\n%d\t\t%s\t\t$%.2f",actual->codigo,actual->producto,actual->precio);	
					}				
			}			
	}
	
PILA *eliminar(PILA *ultimo)

	{
		
		if(ultimo==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay productos en la lista!!\n\n");
			}
		else
			{
				PILA *actual;
				actual=ultimo;
				while(actual!=NULL)
					{
						ultimo=ultimo->anterior;
						delete actual;
						actual=ultimo;
					}
				printf("\n\n\t\tListado de precios eliminados!!\n\n");	
				return ultimo;				
			}			
	}	
	
void crear_archivo(PILA *ultimo)

	{
		if(ultimo!=NULL)
			{
			
				FILE *arch;
				PILA *actual;
				actual=ultimo;
				arch=fopen("ListadoDeProductos.txt","w");
				fprintf(arch,"Codigo\tNombre de producto\tPrecio\n--------------------------------------\n\n");					
				while(actual!=NULL)
					{
						fprintf(arch,"\n%d\t\t%s\t\t$%.2f",actual->codigo,actual->producto,actual->precio);
						actual=actual->anterior;
					}
				fclose(arch);
			
			}
	}					
