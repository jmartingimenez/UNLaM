/*
Pendiente: Hacer que se elimine uno solo por nombre o por id, avisar si existe mas de 1 con mismo nombre
*/

#include<stdio.h>
#include<string.h>

struct LISTA
	{
		int id;
		char nombre[10];
		LISTA *prox;
	};

typedef LISTA DATO;

void v2_ingreso();
int v2_validarID();
void v2_lectura();
void v2_eliminar_uno();
void v2_eliminar_todo();
void v2_modificar();
void v2_buscar();


DATO *inicio=NULL;

int main()

	{
		int menu;
		do
			{
				printf("1-Ingresar\n2-Leer\n3-Eliminar uno\n4-Eliminar todo");
				printf("\n5-Modificar\n6-Buscar\n7-Eliminar repetidos\n8-Salir\n\nSeleccion: ");
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							v2_ingreso();
							break;
						case 2:
							v2_lectura();
							break;
						case 3:
							v2_eliminar_uno();
							break;	
						case 4:
							v2_eliminar_todo();
							break;
						case 5:
							v2_modificar();
							break;
						case 6:
							v2_buscar();
							break;
						case 7:
							//v2_eliminar_repetidos();
							break;
						case 8:
							break;			
						default:
							printf("\nerror\n");
					}
			}while(menu!=8);
		return 0;
	}

	
void v2_ingreso()								

	{
		int id;
		DATO *p,*w,*aux;													
		p=w=inicio;											
		aux=new DATO;		
		do
			{
				id=v2_validarID();	
			}while(id<1);
		aux->id=id;
		fflush(stdin);
		printf("Ingrese nombre: ");
		gets(aux->nombre);
		while(w!=NULL)										
			{								
				if(aux->id< w->id)							
					{
						break;								
					}
				p=w;										
				w=p->prox;										
			}		
		if(w==inicio)					
			{
				aux->prox=w;								
				inicio=aux;										
			}
		else								
			{								
				aux->prox=w;								
				p->prox=aux;								
			}
	}														


int v2_validarID()								//Es igual a la funcion de lectura, solo cambiando el
												//printf por este if
	{
		DATO *p;
		p=inicio;
		int id;
		printf("Ingrese la ID: ");
		scanf("%d",&id);
		while(p!=NULL)												
		{
			if(id==p->id)
				{
					printf("\n\n\t\tERROR!!: La ID ya existe o no puede llevar un valor menor a 1.\n\n");
					return -1;
				}		
			p=p->prox;										
		}		
		return id;
	}
															
void v2_lectura()

	{
		DATO *p;																		
		p=inicio;												
		while(p!=NULL)												
		{
			printf("\n%d-%s\n",p->id,p->nombre);		
			p=p->prox;										
		}
	}	

void v2_eliminar_uno()

	{
		DATO *p,*w;									
		p=w=inicio;								
		int aux;									
		printf("Ingrese el codigo: ");
		scanf("%d",&aux);
		while(w!=NULL)								
			{										
				if(w->id==aux)						
					{
						break;						
					}
				p=w;								
				w=p->prox;							
			}									
		if(w==NULL)									
			{										
				printf("\nNO SE ENCONTRO LA ID\n");
			}
		else									
			{
				if(w==inicio)					
					{							
						inicio=w->prox;				 
					}								
				else										
					{								
						p->prox=w->prox;		
													
					}
				delete w;							
			}		
	}

void v2_eliminar_todo()

	{
		DATO *actual;
		while(inicio!=NULL)
			{
				actual=inicio->prox;
				delete inicio;
				inicio=actual;
			}
	}

void v2_modificar()								//Esta basado en la funcion de eliminar uno

	{

		int busqueda;							//Variable para guardar lo que vamos a buscar
		DATO *p,*w;								//Punteros auxiliares	
		p=w=inicio;								
		printf("Ingrese el codigo para modificar: ");
		scanf("%d",&busqueda);
		while(w!=NULL)							//Vamos a recorrer la lista buscando coincidencia				
			{										
				if(w->id==busqueda)				//Si la id que queremos borrar existe...					
					{
						break;					//Salimos del while, sino...				
					}
				p=w;							//Que p y w tomen los varoles siguientes..				
				w=p->prox;						//Para seguir recorriendo la lista		
			}
		if(w==NULL)								//Si w es NULL, no encontro la Id		
			{										
				printf("\nNO SE ENCONTRO LA ID\n");
			}
		else									//De lo contrario...						
			{
				if(w==inicio)					//Si la ID es la primera
					{							
						inicio=w->prox;			//Hacemos que la primera sea la siguiente..	 
					}							//(SI, ESTAMOS BORRANDOLA...)
												//Basicamete, lo unico q hice fue eliminar el nodo	
				else							//coincidente y llamar a la funcion de ingreso para
												//ingresar la nueva ID			
					{								
						p->prox=w->prox;		//Reorganizando..
													
					}
				delete w;						//Finalmente liberamos memoria dinamica
				v2_ingreso();					//Y ahora nomas llamamos a la funcion de ingreso
			}									//Ahi se piden los datos y se ordena solo :)
	}
	
void v2_buscar()

	{
		int opc;
		char aux[25];
		DATO *p,busqueda;																		
		p=inicio;		
		do
			{
				printf("1-Buscar por ID\n2-Buscar por Droga\n\nSeleccion: ");
				scanf("%d",&opc);				
				if(opc<1 or opc>2)
					{
						printf("\nerror\n");
					}
			}while(opc<1 or opc>2);
		switch(opc)
			{
				case 1:
				printf("Ingrese la ID que quiere visualizar: ");
				scanf("%d",&busqueda.id);
				while(p!=NULL)												
				{
					if(p->id==busqueda.id)
						{
							printf("\n%d-%s\n",p->id,p->nombre);
						}
					p=p->prox;										
				}							
					break;
				case 2:
					fflush(stdin);
					printf("Ingrese el nombre que quiere ver: ");
					gets(busqueda.nombre);
					while(p!=NULL)												
						{
							if(strcmp(p->nombre,busqueda.nombre)==0)
								{
									printf("\n%d-%s\n",p->id,p->nombre);
								}
							p=p->prox;										
						}	
					break;
			}
	}



