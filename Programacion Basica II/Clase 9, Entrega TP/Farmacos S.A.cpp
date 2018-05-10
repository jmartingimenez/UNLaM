/*
	Alumnos: Pace Ayrton, Jonatan gimenez
	Problema encontrado: Eliminar el archivo usando 'remove' no funciona por alguna razon
*/	


#include<stdio.h>
#include<conio.h>
#include<string.h>

/*DECLARACION DE ESTRUCTURAS*/

struct PILA
	{
		int codigo;
		char droga[25];
		char nombre_comercial[25];
		int cant;
		PILA *anterior;
	};

struct COLA
	{
		int codigo;
		char droga[25];
		char nombre_comercial[25];
		char estado[10];
		COLA *siguiente;									
	};
struct LISTA
	{
		int codigo;
		char nombre[25];
		LISTA *prox;
	};

typedef PILA medicamento;
typedef COLA drogas;	
typedef LISTA farmacos;

/*FUNCIONES PARA DETERMINAR SI SE VA TRABAJAR CON ESTRUCTURAS DINAMICAS O CON ARCHIVO*/

int menu_archivo(char *pnombre);
void crear_archivo(char *pnombre);
int carga_archivo(char *pnombre);

/*SUERTE DE BANNER EN LOS MENUES*/

void titulo_general();
void titulo_medicamento();
void titulo_droga();
void titulo_otros();

/*MENUES GENERALES*/
							
void e_menu_estructuras(char *pnombre);
void a_menu_archivos(char *pnombre);					
														
/*FUNCIONES DE MEDICAMENTO (PILA)*/

void e_menu_medicamento(char *pnombre);
void e_insertar_medicamento(char *pnombre);
void e_extraer_medicamento();
void e_mostrar_medicamento();
void e_eliminar_medicamento(char *pnombre);
void e_guardar_medicamento(char *pnombre);							

void a_menu_medicamento(char *pnombre);
void a_ingresar_medicamento(char *pnombre);
void a_visualizar_medicamento(char *pnombre);
void a_extraer_medicamento(char *pnombre);

/*FUNCIONES DE DROGAS (COLA)*/
							
void e_menu_droga(char *pnombre);							
void e_insertar_droga(char *pnombre);
void e_extraer_droga();
void e_mostrar_droga();
void e_eliminar_droga(char *pnombre);
void e_guardar_droga(char *pnombre);
	
void a_menu_droga(char *pnombre);		
void a_insertar_droga(char *pnombre);
void a_extraer_droga(char *pnombre);
void a_visualizar_droga(char *pnombre);

/*FUNCIONES DE OTROS FARMACOS (LISTAS)*/

void e_menu_otros(char *pnombre);
void e_insertar_farmacos(char *pnombre);
void e_eliminar_farmaco();
void e_eliminar_farmaco_ID();
void e_eliminar_farmaco_Nombre();
void e_mostrar_farmacos();	
void e_modificar_farmaco(char *pnombre);
void e_buscar_farmaco();
void e_buscar_farmaco_ID();
void e_buscar_farmaco_Nombre();
void e_guardar_farmacos(char *pnombre);

int validar_ID();
int validar_Nombre(char *val_Nombre);	

void a_menu_farmacos(char *pnombre);
void a_insertar_farmacos(char *pnombre);
void a_modificar_farmaco(char *pnombre);
void a_visualizar_farmacos(char *pnombre);
void a_buscar_farmaco(char *pnombre);
void a_buscar_farmaco_ID(char *pnombre);
void a_buscar_farmaco_Nombre(char *pnombre);


/*PUNTEROS PARA MANEJAR LAS ESTRUCTURAS DINAMICAS*/							

medicamento *p_ultimo=NULL;
drogas *c_primero=NULL,*c_ultimo=NULL;
farmacos *l_primero=NULL;

	/*==================================================================================================
	============================COMIENZO DE LAS FUNCIONES DEL PROGRAMA==================================
	====================================================================================================*/

int main()
	{
		int modo;
		char nombre_archivo[15],*pnombre=nombre_archivo;
		modo=menu_archivo(pnombre);	
		if(modo!=-1)//(1)-creo nuevo archivo/(2)-Se cargo un archivo existente/(-1)-Error al cargar existente
			{
				switch(modo)
					{
						case 1:
							e_menu_estructuras(pnombre);
							break;
						case 2:
							a_menu_archivos(pnombre);
							break;
					}
			}
		getch();
		return 0;
	}
											/*BANNERS*/

void titulo_general()
	{
		printf("\n\t\t###########################################");
		printf("\n\t\t#####   ===    Farmacos  S.A    ===   #####");
		printf("\n\t\t###########################################");		
	}

void titulo_medicamento()
	{
		printf("\n\t\t###########################################");
		printf("\n\t\t####Farmacos S.A    ===    Medicamentos####");
		printf("\n\t\t###########################################");
	}

void titulo_droga()
	{
		printf("\n\t\t###########################################");
		printf("\n\t\t####Farmacos S.A       ===       Drogas####");
		printf("\n\t\t###########################################");
	}
	
void titulo_otros()
	{
		printf("\n\t\t###########################################");
		printf("\n\t\t####Farmacos S.A   ===   Otros Farmacos####");
		printf("\n\t\t###########################################");
	}	
	
								/*MENU INICIAL PARA MODO DE TRABAJO*/

int menu_archivo(char *pnombre)
	{
		int modo;
		do
			{
				printf("1-Crear un nuevo listado\n2-Cargar un listado existente\n\nSeleccion: ");
				scanf("%d",&modo);			
				if(modo<1 or modo>2)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(modo<1 or modo>2);
		fflush(stdin);
		if(modo==1)
			{
				crear_archivo(pnombre);
			}
		else
			{
				modo=carga_archivo(pnombre);//si el archivo existe devuelve 2, de lo contrario -1
			}	
		return modo;	
	}	
	
int carga_archivo(char *pnombre)
	{
		FILE *archivo;
		printf("Ingrese el nombre del archivo sin extension: ");
		gets(pnombre);
		strcat(pnombre,".data");
		if((archivo=fopen(pnombre,"rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
				return -1;
			}
		else
			{
				return 2;
			}	
	}

void crear_archivo(char *pnombre)
	{
		FILE *archivo;
		printf("Ingrese el nombre del nuevo listado: ");
		gets(pnombre);		
		strcat(pnombre,".data");		
		archivo=fopen(pnombre,"wb");
		fclose(archivo);
	}

							/*MENUES GENERALES*/
	
void e_menu_estructuras(char *pnombre)
	{
		int menu;
		do
			{
				titulo_general();
				printf("\n\n1-Medicamentos de venta libre\n2-Drogas Ilegales\n3-Otros farmacos\n4-Salir");
				printf("\n\t\t\tListado actual: %s\n\nSeleccion: ",pnombre);
				scanf("%d",&menu);
				if(menu<1 or menu>4)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(menu<1 or menu>4);
		switch(menu)
			{
				case 1:
					e_menu_medicamento(pnombre);
					break;
				case 2:
					e_menu_droga(pnombre);
					break;
				case 3:
					e_menu_otros(pnombre);
					break;
			}
	}	

void a_menu_archivos(char *pnombre)
	{
		int menu;
		do
			{
				titulo_general();
				printf("\n\n1)Medicamentos\n2)Drogas\n3)Otros farmacos\n4)Salir");				
				printf("\n\t\t\tListado actual: %s\n\nSeleccion: ",pnombre);
				scanf("%d",&menu);
				if(menu<1 or menu>4)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(menu<1 or menu>4);
		switch(menu)
			{
				case 1:
					a_menu_medicamento(pnombre);
					break;
				case 2:
					a_menu_droga(pnombre);
					break;
				case 3:
					a_menu_farmacos(pnombre);
					break;
			}		
	}	

								/*FUNCIONES DE MEDICAMENTOS (PILA)*/
	
void e_menu_medicamento(char *pnombre)								
	{
		int menu;
		do
			{
				titulo_medicamento();
				printf("\n\n1-Insertar medicamento\n2-Extraer medicamento\n3-Ver listado de medicamentos");
				printf("\n4-Eliminar listado de medicamentos\n5-Salir");
				printf("\n\t\t\tListado actual: %s\n\nSeleccion: ",pnombre);
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							e_insertar_medicamento(pnombre);
							break;
						case 2:
							e_extraer_medicamento();
							break;
						case 3:
							e_mostrar_medicamento();
							break;
						case 4:
							e_eliminar_medicamento(pnombre);
							break;
						case 5:
							break;	
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
							break;	
					}				
			}while(menu!=5);
	}	

void e_insertar_medicamento(char *pnombre)
	{
		medicamento *nuevo;							
		nuevo=new medicamento;							
		printf("Ingrese el codigo: ");
		scanf("%d",&nuevo->codigo);
		fflush(stdin);
		printf("Ingrese el nombre de la droga: ");
		gets(nuevo->droga);
		fflush(stdin);
		printf("Ingrese el nombre comercial: ");
		gets(nuevo->nombre_comercial);
		printf("Ingrese la cantidad de comprimidos: ");
		scanf("%d",&nuevo->cant);			
		nuevo->anterior=p_ultimo;					
		p_ultimo=nuevo;
		e_guardar_medicamento(pnombre);							
	}
	
void e_extraer_medicamento()
	{
		if(p_ultimo==NULL)									
			{
				printf("\nERROR: No hay elementos para visualizar\n");
			}
		else
			{
				int codigo;									
				printf("Ingrese el codigo a buscar: ");
				scanf("%d",&codigo);
				medicamento *nuevo;								
				nuevo=p_ultimo;								
				printf("\n\nCodigo\tDroga\tNombre Comercial\tCant Comprimidos\n");
				printf("--------------------------------------------------------\n\n");
				while(nuevo!=NULL)											
					{									
						if(codigo==nuevo->codigo)				
							{								
								printf("%d\t%s",nuevo->codigo,nuevo->droga);
								printf("\t\t%s\t\t\t%d\n",nuevo->nombre_comercial,nuevo->cant);
								break;							
							}								
						nuevo=nuevo->anterior;		
					}
				if(nuevo==NULL)								
					{									
						printf("\nNO SE ENCONTRO EL CODIGO.\n");
					}					
			}		
	}	
	
void e_mostrar_medicamento()
	{
		if(p_ultimo==NULL)									
			{
				printf("\nERROR: No hay elementos para visualizar\n");
			}
		else
			{
				medicamento *nuevo;								
				nuevo=p_ultimo;								
				printf("\n\nCodigo\tDroga\tNombre Comercial\tCant Comprimidos\n");
				printf("--------------------------------------------------------\n\n");
				while(nuevo!=NULL)											
					{									
						printf("%d\t%s",nuevo->codigo,nuevo->droga);
						printf("\t\t%s\t\t\t%d\n",nuevo->nombre_comercial,nuevo->cant);
						nuevo=nuevo->anterior;				
					}						
			}			
	}	
	
void e_eliminar_medicamento(char *pnombre)
	{
		if(p_ultimo==NULL)										
			{
				printf("\nERROR: No hay medicamentos ingresados en el sistema.\n");
			}
		else
			{
				medicamento *nuevo;									
				while(p_ultimo!=NULL)							
					{
						nuevo=p_ultimo;								
						p_ultimo=p_ultimo->anterior;				
						delete nuevo;													
					}
			}	
	}	

void e_guardar_medicamento(char *pnombre)
	{
		FILE *archivo;									
		medicamento *nuevo,auxiliar;							
		nuevo=p_ultimo;										
		archivo=fopen(pnombre,"wb");												
		while(nuevo!=NULL)						
			{											
				auxiliar=*nuevo;
				fwrite(&auxiliar,sizeof(auxiliar),1,archivo);
				nuevo=nuevo->anterior;		
			}
		fclose(archivo);		
	}

							/*FUNCIONES DE MEDICAMENTOS (ARCHIVO)*/

void a_menu_medicamento(char *pnombre)	
{
	int sel;
	do
		{
			titulo_medicamento();
			printf("\n1)Ingresar medicamento\n2)Extraer medicamento\n3)Ver listado medicamentos\n4)Borrar medicamento\n5)Salir\n\tSeleccion: ");
			scanf("%d",&sel);
			if(sel<1 or sel>5)
				{
					printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
				}	
			switch(sel)
				{
					case 1:
						a_ingresar_medicamento(pnombre);
						break;
					case 2:
						a_extraer_medicamento(pnombre);
						break;
					case 3:
						a_visualizar_medicamento(pnombre);
						break;
					case 4:
						remove(pnombre);					//ACA HAY UN PROBLEMA, NO SE BORRA :/
						break;
				}						
		}while(sel!=5);
	}

void a_ingresar_medicamento(char *pnombre)
	{
		FILE *arch;
		medicamento auxiliar;
		arch=fopen(pnombre,"ab");
		printf("Ingrese el codigo del medicamento: ");
		scanf("%d",&auxiliar.codigo);
		printf("\nIngrese el nombre comercial del medicamento: ");
		scanf("%s",&auxiliar.nombre_comercial);
		printf("\nIngrese el nombre del medicamento: ");
		scanf("%s",&auxiliar.droga);
		printf("Ingrese la cantidad de medicamentos: ");
		scanf("%d",&auxiliar.cant);
		fwrite(&auxiliar,sizeof(auxiliar),1,arch);
		fclose(arch);
	}
		
void a_extraer_medicamento(char *pnombre)
	{
		int auxiliar;
		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay medicamentos ingresados en el sistema.\n");
			}
		else
			{
				arch=fopen(pnombre,"rb");
				printf("Ingrese el codigo del medicamento que desea visualizar: ");
				scanf("%d",&auxiliar);
				rewind(arch);						
				medicamento info;
				fread(&info,sizeof(info),1,arch);	
				while(!feof(arch))					
					{
						if(auxiliar==info.codigo)
							{
								printf("\n\nCodigo\tDroga\tNombre Comercial\tCant Comprimidos\n");
								printf("--------------------------------------------------------\n\n");
								printf("%d\t%s\t\t%s\t\t\t%d\n",info.codigo,info.nombre_comercial,info.droga,info.cant);	
								break;
							}
						fread(&info,sizeof(info),1,arch);
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: No se encontro el medicamento\n\n");
					}
				fclose(arch);							
			}	
	}
	
void a_visualizar_medicamento(char *pnombre)
	{
		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay medicamentos ingresados en el sistema.\n");
			}
		else
			{
				arch=fopen(pnombre,"rb");
				rewind(arch);						
				medicamento info;
				printf("\n\nCodigo\tDroga\tNombre Comercial\tCant Comprimidos\n");
				printf("--------------------------------------------------------\n\n");
				fread(&info,sizeof(info),1,arch);	
				while(!feof(arch))					
					{
						printf("%d\t%s\t\t%s\t\t\t%d\n",info.codigo,info.nombre_comercial,info.droga,info.cant);	
						fread(&info,sizeof(info),1,arch);
					}
				fclose(arch);						
			}	
	}

							/*FUNCIONES DE DROGAS (COLA)*/

void e_menu_droga(char *pnombre)								
	{
		int menu;
		do
			{
				titulo_droga();
				printf("\n\n1-Insertar droga\n2-Extraer droga\n3-Ver listado de drogas");
				printf("\n4-Eliminar listado de drogas\n5-Salir");
				printf("\n\t\t\tListado actual: %s\n\nSeleccion: ",pnombre);
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							e_insertar_droga(pnombre);
							break;
						case 2:
							e_extraer_droga();
							break;
						case 3:
							e_mostrar_droga();
							break;
						case 4:
							e_eliminar_droga(pnombre);
							break;
						case 5:
							break;
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
							break;	
					}									
			}while(menu!=5);	
	}	

void e_insertar_droga(char *pnombre)
	{
		drogas *nuevo;
		int opc;
		nuevo=new drogas;									
		printf("Ingrese el codigo: ");
		scanf("%d",&nuevo->codigo);
		fflush(stdin);
		printf("Ingrese el nombre de la droga: ");
		gets(nuevo->droga);
		fflush(stdin);
		printf("Ingrese el nombre comercial: ");
		gets(nuevo->nombre_comercial);
		do
			{
				printf("Ingrese el estado\n1-Liquido\n2-Solido\n3-Gaseoso\n\nSeleccion: ");
				scanf("%d",&opc);
				switch(opc)
					{
						case 1:
							strcpy(nuevo->estado,"Liquido");
							break;
						case 2:
							strcpy(nuevo->estado,"Solido");
							break;
						case 3:
							strcpy(nuevo->estado,"Gaseoso");
							break;
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(opc<1 or opc>3);
		nuevo->siguiente=NULL;								
		if(c_ultimo==NULL)											
			{
				c_ultimo=nuevo;								
				c_primero=nuevo;								
			}
		else													
			{
				c_ultimo->siguiente=nuevo;				
				c_ultimo=nuevo;							
			}
		e_guardar_droga(pnombre);			
	}
	
void e_extraer_droga()
	{
		if(c_primero==NULL)									
			{
				printf("\n\n\t\tERROR: No hay elementos para visualizar.\n\n");
			}
		else											
			{
				drogas *nuevo;
				int aux;								
				printf("Ingrese el codigo a buscar: ");
				scanf("%d",&aux);											
				nuevo=c_primero;							
				printf("\n\nCodigo\tDroga\tNombre Comercial\tEstado\n");
				printf("--------------------------------------------------------\n\n");				
				while(nuevo!=NULL)							
					{
						if(aux==nuevo->codigo)				
							{
								printf("%d\t%s",nuevo->codigo,nuevo->droga);
								printf("\t\t%s\t\t%s\n",nuevo->nombre_comercial,nuevo->estado);
								break;
							}
						nuevo=nuevo->siguiente;			
					}
				if(nuevo==NULL)							
					{
						printf("\nERROR!!: El producto no pudo ser encontrado.\n");
					}	
			}			
	}
	
void e_mostrar_droga()
	{
		if(c_primero==NULL)								
			{
				printf("\n\n\t\tERROR: No hay elementos para listar!\n\n");
			}
		else										
			{
				drogas *nuevo;												
				nuevo=c_primero;	
				printf("\n\nCodigo\tDroga\tNombre Comercial\tEstado\n");
				printf("--------------------------------------------------------\n\n");											
				while(nuevo!=NULL)									
					{
						printf("%d\t%s",nuevo->codigo,nuevo->droga);
						printf("\t\t%s\t\t%s\n",nuevo->nombre_comercial,nuevo->estado);		
						nuevo=nuevo->siguiente;			
					}
			}			
	}			
	
void e_eliminar_droga(char *pnombre)
	{
		if(c_ultimo==NULL)							
													
			{
				printf("\n\n\t\tERROR: No hay elementos para eliminar!\n\n");
			}
		else											
			{
				while(c_ultimo!=NULL)
					{
						drogas *nuevo;											
						nuevo=c_primero;
						c_primero=c_primero->siguiente;
						delete nuevo;
						if(c_primero==NULL)
							{
								c_ultimo=c_primero;
							}						
					}
			}
	}	
				
void e_guardar_droga(char *pnombre)
	{
		FILE *archivo;
		drogas *nuevo,auxiliar;												
		nuevo=c_primero;
		archivo=fopen(pnombre,"wb");	
		while(nuevo!=NULL)									
			{
				auxiliar=*nuevo;
				fwrite(&auxiliar,sizeof(auxiliar),1,archivo);
				nuevo=nuevo->siguiente;			
			}
		fclose(archivo);	
	}

									/*FUNCIONES DE DROGAS (ARCHIVO)*/

void a_menu_droga(char *pnombre)
	{
		int sel;
		do
			{
				titulo_droga();
				printf("\n1)Ingresar droga\n2)Extraer droga\n3)Ver listado de drogas\n4)Borrar drogas\n5)Salir\n\tSeleccion: ");
				scanf("%d",&sel);
				if(sel<1 or sel>5)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}	
				switch(sel)
					{
						case 1:
							a_insertar_droga(pnombre);
							break;
						case 2:
							a_extraer_droga(pnombre);
							break;
						case 3:
							a_visualizar_droga(pnombre);
							break;
						case 4:
							remove(pnombre);					//ACA HAY UN PROBLEMA, NO SE BORRA :/
							break;
					}						
			}while(sel!=5);
	}

void a_insertar_droga(char *pnombre)
	{
		int sel;
		FILE *arch;
		drogas auxiliar;
		arch=fopen(pnombre,"ab");
		printf("Ingrese el codigo de la droga: ");
		scanf("%d",&auxiliar.codigo);
		fflush(stdin);
		printf("\nIngrese el nombre comercial de la droga: ");
		scanf("%s",&auxiliar.nombre_comercial);
		fflush(stdin);
		printf("\nIngrese el nombre de la droga: ");
		scanf("%s",&auxiliar.droga);
		do
			{
				printf("Ingrese el estado\n1-Liquido\n2-Solido\n3-Gaseoso\n\nSeleccion: ");
				scanf("%d",&sel);
				switch(sel)
					{
						case 1:
							strcpy(auxiliar.estado,"Liquido");
							break;
						case 2:
							strcpy(auxiliar.estado,"Solido");
							break;
						case 3:
							strcpy(auxiliar.estado,"Gaseoso");
							break;
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(sel<1 or sel>3);
		fwrite(&auxiliar,sizeof(auxiliar),1,arch);
		fclose(arch);
	}

void a_extraer_droga(char *pnombre)
	{
		int auxiliar;
		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay medicamentos ingresados en el sistema.\n");
			}
		else
			{
				arch=fopen(pnombre,"rb");
				printf("Ingrese el codigo de la droga que desea visualizar: ");
				scanf("%d",&auxiliar);
				rewind(arch);						
				drogas info;
				fread(&info,sizeof(info),1,arch);	
				while(!feof(arch))					
					{
						if(auxiliar==info.codigo)
							{
								printf("\n\nCodigo\tDroga\tNombre Comercial\tEstado\n");
								printf("--------------------------------------------------------\n\n");
								printf("%d\t%s\t\t%s\t\t%s\n",info.codigo,info.nombre_comercial,info.droga,info.estado);	
								break;
							}
						fread(&info,sizeof(info),1,arch);
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: No se encontro la droga\n\n");
					}
				fclose(arch);							
			}	
	}

void a_visualizar_droga(char *pnombre)
	{
		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay medicamentos ingresados en el sistema.\n");
			}
		else
			{
				arch=fopen(pnombre,"rb");
				rewind(arch);						
				drogas info;
				fread(&info,sizeof(info),1,arch);
				printf("\n\nCodigo\tDroga\tNombre Comercial\tEstado\n");
				printf("--------------------------------------------------------\n\n");					
				while(!feof(arch))					
					{
						printf("%d\t%s\t\t%s\t\t%s\n",info.codigo,info.nombre_comercial,info.droga,info.estado);	
						fread(&info,sizeof(info),1,arch);
					}
				fclose(arch);	
			}					
	}	

						/*FUNCIONES DE OTROS FARMACOS (LISTA)*/

void e_menu_otros(char *pnombre)									
	{
		int menu;
		do
			{
				titulo_otros();
				printf("\n\n1-Insertar farmaco\n2-Eliminar farmaco de la lista\n3-Visualizar farmacos\n4-Modificar farmaco\n5-Buscar\n6-Salir");
				printf("\n\t\t\tListado actual: %s\n\nSeleccion: ",pnombre);
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							e_insertar_farmacos(pnombre);
							break;
						case 2:
							e_eliminar_farmaco();
							break;
						case 3: 
							e_mostrar_farmacos();
							break;
						case 4:
							e_modificar_farmaco(pnombre);
							break;	
						case 5:
							e_buscar_farmaco(); 
							break;
						case 6:
							break;	
						default:
							printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
							break;	
					}									
			}while(menu!=6);		
	}

void e_insertar_farmacos(char *pnombre)
	{
		int id,nombre;
		char auxNombre[25],*val_Nombre=auxNombre;
		farmacos *p,*w,*aux;
		p=w=l_primero;
		aux=new farmacos;
		do
			{
				id=validar_ID();
				if(id<1)
					{
						printf("\n\n\t\tERROR!!: El codigo lleva un valor negativo o existente.\n\n");
					}
			}while(id<1);
		aux->codigo=id;	
		do
			{
				fflush(stdin);
				printf("\nIngrese nombre del farmaco: ");
				gets(val_Nombre);				
				nombre=validar_Nombre(val_Nombre);	
			}while(nombre==0);
		strcpy(aux->nombre,val_Nombre);	
		while(w!=NULL)
		{
			if(aux->codigo < w->codigo)
				{
					break;
				}
			p=w;
			w=p->prox;
		}
		if(w==l_primero)
			{
				aux->prox=w;
				l_primero=aux;
			}
		else
			{
				aux->prox=w;
				p->prox=aux;
			}
		e_guardar_farmacos(pnombre);	
	}

int validar_ID()
	{
		farmacos *p;
		p=l_primero;
		int id;
		printf("Ingrese el codigo del farmaco: ");
		scanf("%d",&id);
		while(p!=NULL)												
		{
			if(id==p->codigo)
				{
					return -1;
				}		
			p=p->prox;										
		}		
		return id;		
	}

int validar_Nombre(char *val_Nombre)
	{
		farmacos *p;
		p=l_primero;
		while(p!=NULL)
			{
				if(strcmp(val_Nombre,p->nombre)==0)
					{
						printf("\n\n\t\tERROR!!: El nombre ya existe!.\n\n");
						return 0;
					}
				p=p->prox;
			}
		return 1;	
	}

void e_eliminar_farmaco()
	{
		if(l_primero==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay elementos para eliminar\n\n");
			}
		else
			{
				int opc;
				do
					{
						printf("\n1-Eliminar por codigo\n2-Eliminar por nombre\n\nSeleccion: ");
						scanf("%d",&opc);
						if(opc<1 or opc>2)
							{
								printf("\n\n\t\tERROR!!: Opcion Incorrecta.\n\n");
							}	
					}while(opc<1 or opc>2);
				switch(opc)
					{
						case 1:
							e_eliminar_farmaco_ID();
							break;
						case 2:
							e_eliminar_farmaco_Nombre();
							break;
					}				
			}	
	
	}

void e_eliminar_farmaco_ID()
	{
		farmacos *p,*w;									
		p=w=l_primero;								
		int aux;									
		printf("Ingrese el codigo: ");
		scanf("%d",&aux);
		while(w!=NULL)								
			{										
				if(w->codigo==aux)						
					{
						break;						
					}
				p=w;								
				w=p->prox;							
			}									
		if(w==NULL)									
			{										
				printf("\n\n\t\tERROR!!: No se encontro el nombre.\n\n");
			}
		else									
			{
				if(w==l_primero)					
					{							
						l_primero=w->prox;				 
					}								
				else										
					{								
						p->prox=w->prox;		
					}
				delete w;							
			}			
	}
	
void e_eliminar_farmaco_Nombre()
	{
		farmacos *p,*w;									
		p=w=l_primero;								
		char aux[25];									
		fflush(stdin);
		printf("Ingrese el nombre: ");
		gets(aux);
		while(w!=NULL)								
			{										
				if(strcmp(w->nombre,aux)==0)
					{
						break;						
					}
				p=w;								
				w=p->prox;							
			}									
		if(w==NULL)									
			{										
				printf("\n\n\t\tERROR!!: No se encontro el nombre.\n\n");
			}
		else									
			{
				if(w==l_primero)					
					{							
						l_primero=w->prox;				 
					}								
				else										
					{								
						p->prox=w->prox;		
					}
				delete w;							
			}			
	}	

void e_mostrar_farmacos()
	{
		farmacos *p;
		p=l_primero;
		if(p==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay elementos para listar\n\n");
			}
		else
			{
				printf("\n\nCodigo\tNombre\n--------------\n\n");
				while(p!=NULL)
					{
						printf("%d\t%s\n",p->codigo,p->nombre);
						p=p->prox;
					}					
			}	
	}

void e_modificar_farmaco(char *pnombre)

/*
NOTA: SI BIEN, LA FUNCION DE REEMPLAZO PUEDE SER MAS SIMPLE, SI SIMPLEMENTE REEMPLAZO EL DATO, LA LISTA
NO SE ME REORDENA. ADEMAS DE QUEDAR DESORDENADA, EL NUEVO CODIGO INGRESADO PUEDE AFECTAR EL ORDENAMIENTO
DE LOS PROXIMOS INGRESOS. LA UNICA SOLUCION QUE ENCONTRAMOS (YA QUE NO DIMOS CON UN ALGORITMO CORTO DE 
MODIFICACION Y REORDENAMIENTO) FUE QUE AL ENCONTRAR COINCIDENCIA, BORRAR EL NODO Y LLAMAR A LA FUNCION DE
INGRESO QUE ADEMAS DE REORDENAR LA LISTA TIENE LAS VALIDACIONES CORRESPONDIENTES.
*/	

	{
		if(l_primero==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay elementos ingresados.\n\n");
			}
		else
			{
				int busqueda;						
				farmacos *p,*w;									
				p=w=l_primero;								
				printf("Ingrese el codigo para modificar: ");
				scanf("%d",&busqueda);
				while(w!=NULL)											
					{										
						if(w->codigo==busqueda)									
							{
								break;									
							}
						p=w;											
						w=p->prox;								
					}
				if(w==NULL)										
					{										
						printf("\n\n\t\tERROR!!: No se encontro la ID.\n\n");
					}
				else															
					{
						if(w==l_primero)					
							{							
								l_primero=w->prox;				 
							}							
						else							
							{								
								p->prox=w->prox;	
							}
						delete w;					
						e_insertar_farmacos(pnombre);					
					}					
			}	
	}

void e_buscar_farmaco()
	{
		if(l_primero==NULL)
			{
				printf("\n\n\t\tERROR!!: No hay elementos para buscar.\n\n");
			}
		else
			{
				int opc;
				do
					{
						printf("1-Buscar por codigo\n2-Buscar por nombre\n\nSeleccion: ");
						scanf("%d",&opc);
						if(opc<1 or opc>2)
							{
								printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
							}
					}while(opc<1 or opc>2);	
					switch(opc)
						{
							case 1:
								e_buscar_farmaco_ID();
								break;
							case 2:
								e_buscar_farmaco_Nombre();
								break;
						}					
			}	
	}

void e_buscar_farmaco_ID()
	{
		farmacos *p;
		p=l_primero;
		int busqueda;
		printf("Ingrese el codigo a buscar: ");
		scanf("%d",&busqueda);
		printf("\n\nCodigo\tNombre\n--------------\n\n");
		while(p!=NULL)
			{
				if(p->codigo==busqueda)
					{
						printf("%d\t%s\n",p->codigo,p->nombre);
						break;
					}
				p=p->prox;
			}
		if(p==NULL)
			{
				printf("\n\n\t\tERROR!! No se encontro la ID\n\n");
			}			
	}
	
void e_buscar_farmaco_Nombre()
	{
		farmacos *p;
		p=l_primero;
		char aux[25];
		fflush(stdin);
		printf("Ingrese el nombre a buscar: ");
		gets(aux);
		printf("\n\nCodigo\tNombre\n--------------\n\n");
		while(p!=NULL)
			{
				if(strcmp(aux,p->nombre)==0)
					{
						printf("%d\t%s\n",p->codigo,p->nombre);
						break;
					}
				p=p->prox;
			}
		if(p==NULL)
			{
				printf("\n\n\t\tERROR!! No se encontro el nombre\n\n");
			}	
	}	

void e_guardar_farmacos(char *pnombre)
	{
		FILE *archivo;
		archivo=fopen(pnombre,"wb");																					
		farmacos *p,aux;
		p=l_primero;
		while(p!=NULL)
		{
			aux=*p;
			fwrite(&aux,sizeof(aux),1,archivo);
			p=p->prox;
		}										
		fclose(archivo);
	}

								/*FUNCIONES DE OTROS FARMACOS (ARCHIVO)*/

void a_menu_farmacos(char *pnombre)
	{
		int sel;
		do
			{
				titulo_otros();
				printf("\n1)Ingresar otro farmaco\n2)Eliminar listado de farmacos\n3)Modificar farmaco\n4)Ver listado de farmacos\n5)Buscar farmaco\n6)Salir\n\tSeleccion: ");
				scanf("%d",&sel);
				if(sel<1 or sel>6)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}	
				switch(sel)
					{
						case 1:
							a_insertar_farmacos(pnombre);
							break;
						case 2:
							remove(pnombre);					//ACA HAY UN PROBLEMA, NO SE BORRA :/
							break;
						case 3:
							a_modificar_farmaco(pnombre);
							break;
						case 4:
							a_visualizar_farmacos(pnombre);
							break;
						case 5:
							a_buscar_farmaco(pnombre);
							break;
						case 6:
							break;	
					}						
			}while(sel!=6);
	}

void a_insertar_farmacos(char *pnombre)
	{
		int id,nombre;
		char auxnombre[25],*val_Nombre=auxnombre;
		farmacos aux;
		do
			{
				id=validar_ID();
				if(id<1)
					{
						printf("\n\n\t\tERROR!!: El codigo lleva un valor negativo o existente.\n\n");
					}
			}while(id<1);
		aux.codigo=id;	
		do
			{
				fflush(stdin);
				printf("\nIngrese nombre del farmaco: ");
				gets(val_Nombre);				
				nombre=validar_Nombre(val_Nombre);	
			}while(nombre==0);
		strcpy(aux.nombre,val_Nombre);			
		FILE *arch;
		arch=fopen(pnombre,"ab");
		fwrite(&aux,sizeof(aux),1,arch);
		fclose(arch);
	}

void a_modificar_farmaco(char *pnombre)
	{

		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				farmacos info;
				int aux;								
				printf("Ingrese el codigo a modificar: ");
				scanf("%d",&aux);
				arch=fopen(pnombre,"rb+");				
				rewind(arch);
				fread(&info,sizeof(info),1,arch);			
				while(!feof(arch))
					{
						if(info.codigo==aux)	
							{
								break;							
							}
						fread(&info,sizeof(info),1,arch);	
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: no se encontro el codigo.\n\n");	
					}
				else
					{
						fseek(arch,(-1)*sizeof(info),SEEK_CUR);			
						printf("Ingrese el nuevo codigo: ");
						scanf("%d",&info.codigo);
						fflush(stdin);
						printf("Ingrese el nombre: ");
						gets(info.nombre);
						fwrite(&info,sizeof(info),1,arch);				
					}	
				fclose(arch);							
			}
	}

void a_visualizar_farmacos(char *pnombre)
	{
		FILE *arch;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay farmacos ingresados en el sistema.\n");
			}
		else
			{
				arch=fopen(pnombre,"rb");				
				rewind(arch);						
				farmacos info;
				fread(&info,sizeof(info),1,arch);	
				printf("\n\nCodigo\tNombre\n--------------\n\n");
				while(!feof(arch))					
					{
						printf("%d\t%s\n",info.codigo,info.nombre);	
						fread(&info,sizeof(info),1,arch);
					}
				fclose(arch);							
			}		
	}
	
void a_buscar_farmaco(char *pnombre)
	{
		FILE *arch;
		int opc;
		if((arch=fopen(pnombre,"rb"))==NULL)										
			{
				printf("\nERROR: No hay farmacos ingresados en el sistema.\n");
			}
		else
			{
				do
					{
						printf("1-Buscar por codigo\n2-Buscar por nombre\n\nSeleccion: ");
						scanf("%d",&opc);
						if(opc<1 or opc>2)
							{
								printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
							}
					}while(opc<1 or opc>2);	
					switch(opc)
						{
							case 1:
								a_buscar_farmaco_ID(pnombre);
								break;
							case 2:
								a_buscar_farmaco_Nombre(pnombre);
								break;
						}
			}		
	}

void a_buscar_farmaco_ID(char *pnombre)
	{
		FILE *arch;
		int id;	
		printf("Ingrese el codigo a buscar: ");
		scanf("%d",&id);
		arch=fopen(pnombre,"rb");				
		rewind(arch);						
		farmacos info;
		fread(&info,sizeof(info),1,arch);	
		printf("\n\nCodigo\tNombre\n--------------\n\n");
		while(!feof(arch))					
			{
				if(id==info.codigo)
					{
						printf("%d\t%s\n",info.codigo,info.nombre);	
						break;	
					}
				fread(&info,sizeof(info),1,arch);
			}
		if(feof(arch))
			{
				printf("\n\n\t\tERROR!!: No se encontro la ID\n\n");
			}	
		fclose(arch);			
	}

void a_buscar_farmaco_Nombre(char *pnombre)
	{
		FILE *arch;
		char aux[25];	
		fflush(stdin);
		printf("Ingrese el nombre a buscar: ");
		gets(aux);
		arch=fopen(pnombre,"rb");				
		rewind(arch);						
		farmacos info;
		fread(&info,sizeof(info),1,arch);	
		printf("\n\nCodigo\tNombre\n--------------\n\n");
		while(!feof(arch))					
			{
				if(strcmp(info.nombre,aux)==0)
					{
						printf("%d\t%s\n",info.codigo,info.nombre);	
						break;	
					}
				fread(&info,sizeof(info),1,arch);
			}
		if(feof(arch))
			{
				printf("\n\n\t\tERROR!!: No se encontro el nombre.\n\n");
			}	
		fclose(arch);			
	}
