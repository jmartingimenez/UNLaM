#include<stdio.h>
#include<conio.h>
#include<string.h>

struct COLA
	{
		int id;
		char nombre[10];
		COLA *siguiente;
	};

typedef COLA dato;	

int main()

	{
		dato *primero=NULL,*ultimo=NULL,*nuevo=NULL;
		int opc;
		printf("INGRESO\n\n");
		do
			{
				nuevo=new dato;
				printf("Ingrese id: ");
				scanf("%d",nuevo->id);
				fflush(stdin);
				printf("Ingrese nombre: ");
				gets(nuevo->nombre);
				nuevo->siguiente=NULL;
				ultimo->siguiente=nuevo;
				ultimo=nuevo;
				if(primero==NULL)
					{
						primero=nuevo;
					}
				printf("Presione 0 para terminar la carga: ");
				scanf("%d",&opc);	
			}while(opc!=0);
		printf("\n\nLISTADO\n\n");	
		if(primero==NULL)
			{
				printf("No hay elementos para listar");
			}
		else
			{
				nuevo=primero;
				while(nuevo->siguiente!=NULL)
					{
						printf("%d\t%s\n",nuevo->id,nuevo->nombre);
						nuevo=nuevo->siguiente;
					}
			}	
		getch();
		return 0;
	}
