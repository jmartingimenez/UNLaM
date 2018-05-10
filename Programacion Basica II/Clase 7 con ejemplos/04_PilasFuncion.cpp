#include<stdio.h>
#include<conio.h>
#include<string.h>
struct PILA										//Declaracion de la estructura dinamica
	{
		int codigo;
		char nombre[25];
		PILA *anterior;							//Puntero autoreferencial
	};

typedef PILA medicamento;						//sin esto, cada vez que declarase los punteros
												//ultimo, actual, o funciones tendria q poner struct PILA
												//se hace mas corto...
												//ej..  struct PILA *insertar(struct PILA insertar*);

int func_menu();
medicamento *insertar(medicamento*);
medicamento *extraer(medicamento*);
void visualizar(medicamento*);
medicamento *destruir(medicamento*);
void crear_archivo(medicamento*);
void buscar_archivo();
/*
Las funciones de tipo PILA (insertar, extraer, destruir) actuan como punteros ya que utlizan el valor
de 'ultimo'.
medicamento* es un equivalente a poner 'struct PILA *medicamento' o 'medicamento *medicamento'
*/
	
int main()

	{
		int menu;
		medicamento *ultimo=NULL;						//la principal para tener las cosas apiladas
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							ultimo=insertar(ultimo);	//devuelve el nuevo valor de ultimo que resulte de aca
							break;
						case 2:
							ultimo=extraer(ultimo);		//devuelve el nuevo valor de ultimo que resulte de aca
							break;
						case 3:
							visualizar(ultimo);
							break;
						case 4:
							ultimo=destruir(ultimo);	//devuelve el nuevo valor de ultimo que resulte de aca
							break;						//que es NULL ya que desapila todo
						case 5:
							buscar_archivo();
							break;	
					}
			}while(menu!=6);
		getch();
		return 0;
	}	

int func_menu()

	{
		int menu;
		printf("\n1-Insertar\n2-Extraer\n3-Visualizar\n4-Destruir\n5-Buscar en archivo\n6-Salir\n\nSeleccion: ");
		scanf("%d",&menu);
		return menu;
	}	
	
medicamento *insertar(medicamento *ultimo)

	{
		medicamento *actual;							//ya que actual es auxiliar no necesito mantener
														//esta funcion 'viva' como con 'ultimo'
		actual=new medicamento;							//creando un elemento de la pila. Tampoco es
														//necesario igualarla a NULL
		printf("Ingrese el codigo: ");
		scanf("%d",&actual->codigo);
		fflush(stdin);
		printf("Ingrese nombre: ");
		gets(actual->nombre);				
		actual->anterior=ultimo;						//algoritmo 'push'. Estas 2 lineas son las que
		ultimo=actual;									//van apilando los elementos, uno 'sobre' otro
		crear_archivo(ultimo);							//funcion para crear un archivo
		return ultimo;									//devuelvo la nueva posicion a donde apunta 'ultimo'
	}
	
medicamento *extraer(medicamento *ultimo)

	{
		medicamento *actual;
		if(ultimo==NULL)								//si es NULL, no se apilo nada
			{
				printf("\nERROR: No hay elementos para desapilar.\n");
			}
		else
			{
				
				actual=ultimo;							//algoritmo 'pop'. Estas 2 lineas hacen que 'ultimo'
				ultimo=ultimo->anterior;				//tome el valor anterior
				delete actual;							//evitando memory leaks
				printf("\nElemento desapilado\n");
			}	
		crear_archivo(ultimo);							//funcion para crear un archivo
		return ultimo;									//devuelvo la nueva posicion a donde apunta 'ultimo'
	}
	
void visualizar(medicamento *ultimo)

	{
		medicamento *actual;
		if(ultimo==NULL)
			{
				printf("\nERROR: No hay elemento para visualizar\n");
			}
		else
			{
				actual=ultimo;							//'actual' toma el valor de 'ultimo' para comenzar a
														//recorrer la pila	
				while(actual!=NULL)						
					{									//mientras 'actual' no sea NULL, que muestre el elemento
						printf("%d\t%s\n",actual->codigo,actual->nombre);
						actual=actual->anterior;		//'actual' toma la posicion anterior
					}
			}	
	}		
	
medicamento *destruir(medicamento *ultimo)

	{
		medicamento *actual;
		if(ultimo==NULL)
			{
				printf("\nERROR: No hay elementos para desapilar.\n");
			}
		else
			{
				while(ultimo!=NULL)						//mientras ultimo no sea NULL
					{
						actual=ultimo;					//que se repita el algoritmo 'pop'
						ultimo=ultimo->anterior;		//hasta que no queden elementos por desapilar
						delete actual;					//evitando memory leaks			
					}
			}
		return ultimo;									//devuelvo la nueva posicion a donde apunta 'ultimo'
	}	
	
void crear_archivo(medicamento *ultimo)

	{
		FILE *archivo;									//con esto generamos un nuevo archivo cada vez que
		medicamento *actual;							//insertamos o extraemos. Como el nuevo reemplaza
		actual=ultimo;									//al viejo no hay q preocuparse por abrir en append	
		archivo=fopen("ejemplo04.data","wb");			//o usar rewind. La pila gestiona todo :D									
		while(actual!=NULL)						
			{											//esta funcion es igual a la de visualizacion, solo
				fwrite(&actual,sizeof(actual),1,archivo);//que agregamos esta linea :)
				actual=actual->anterior;		
			}
		fclose(archivo);						
	}	
	
void buscar_archivo()

	{
		FILE *archivo;
		medicamento *actual,*ultimo=NULL;
		actual=new medicamento;
		archivo=fopen("ejemplo04.data","rb");
		int codigo;
		printf("Ingrese el codigo a buscar: ");
		scanf("%d",&codigo);
		fread(&actual,sizeof(actual),1,archivo);	
		actual->anterior=ultimo;						
		ultimo=actual;				
		while(!feof(archivo))
			{
				fread(&actual,sizeof(actual),1,archivo);
				actual->anterior=ultimo;						
				ultimo=actual;									
			}
		fclose(archivo);
	}	
