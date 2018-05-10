#include<stdio.h>
#include<conio.h>

struct PILA
	{
		int id;
		char nombre[10];
		PILA *anterior;
	};
	
typedef PILA alumno;

alumno *ingreso(alumno*);
void creararchivo(alumno*);
void mostrarpila(alumno*);
void mostrararchivo();

int main()

	{
		int opc;
		alumno *ultimo=NULL;
		do
			{
				printf("1-Agregar\n2-Leer pila\n3-Leer archivo\n4-Salir\n\nSeleccion: ");
				scanf("%d",&opc);
				switch(opc)
					{
						case 1:
							ultimo=ingreso(ultimo);
							break;
						case 2:
							mostrarpila(ultimo);
							break;
						case 3:
							mostrararchivo();
							break;	
						case 4:
							printf("\nadios\n");
							break;
						default:
							printf("\nERROR\n");
							break;
					}
			}while(opc!=4);
		getch();
		return 0;	
	}
	
alumno *ingreso(alumno *ultimo)			//apila bien

	{
		alumno *actual;							
		actual=new alumno;							
		printf("Ingrese el codigo: ");
		scanf("%d",&actual->id);
		fflush(stdin);
		printf("Ingrese nombre: ");
		gets(actual->nombre);				
		actual->anterior=ultimo;						
		ultimo=actual;									
		creararchivo(ultimo);							
		return ultimo;			
	}
	
void creararchivo(alumno *ultimo)			//al menos con fprintf crea el archivo perfectamente

	{
		FILE *archivo;									
		alumno *actual;							
		actual=ultimo;										
		archivo=fopen("ejemplo.bin","wb");												
		while(actual!=NULL)						
			{											
				fwrite(&actual,sizeof(actual),1,archivo);
				//fprintf(archivo,"%d\t%s\n",actual->id,actual->nombre);			<---ESCRIBE BIEN LA PILA
				actual=actual->anterior;		
			}
		fclose(archivo);						
	}
	
void mostrarpila(alumno *ultimo)					//muestra la pila sin problema

	{
		if(ultimo==NULL)
			{
				printf("\nERROR: No hay elemento para visualizar\n");
			}
		else
			{
				alumno *actual;
				actual=ultimo;							
				while(actual!=NULL)						
					{									
						printf("%d\t%s\n",actual->id,actual->nombre);
						actual=actual->anterior;		
					}
			}				
	}
	
void mostrararchivo()								//aca ya no muestra bien

	{
		FILE *archivo;
		if((archivo=fopen("ejemplo.bin","rb"))==NULL)
			{
				printf("\nERROR DE LECTURA\n");
			}
		else
			{
				archivo=fopen("ejemplo.bin","rb");							
				printf("\n\n\t\tEstoy entrando en el else..\n\n");
				alumno info;
				fread(&info,sizeof(info),1,archivo);
				//printf("%d\t%s\n",info.id,info.nombre);				<-LEE PERO MUESTRA BASURA			
				while(!feof(archivo))			//ENTONCES NO SE SI ES PROBLEMA EN EL FWRITE O EN EL FREAD					
					{
						printf("%d\t%s\n",info.id,info.nombre);			//<-aca ya no entra
						fread(&info,sizeof(info),1,archivo);
					}
				fclose(archivo);				
			}
	}	
				
