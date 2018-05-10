#include<stdio.h>

struct PILA
	{
		int num;
		PILA *anterior;
	};
	
typedef PILA dato;	

dato *ultimo=NULL;

int main()

	{
		/*AGREGANDO A LA PILA Y AL ARCHIVO*/
		
		FILE *archivo;
		dato *actual;
		archivo=fopen("test.bin","wb");
		int opc;
		do
			{
				dato auxiliar;				//<------------------ESTO ES LO NUEVO (ESTRUCTURA AUXILIAR)
				actual=new dato;
				scanf("%d",&actual->num);
				auxiliar=*actual;			//<------------------QUIZAS PARA GUARDAR EN EL ARCHIVO NO HAGA FALTA
				fwrite(&auxiliar,sizeof(auxiliar),1,archivo);//<--UN AUXILIAR XQ CON FPRINTF ESCRIBE BIEN
				actual->anterior=ultimo;
				ultimo=actual;
				printf("\n\n\t\tpulse 0 para terminar: ");
				scanf("%d",&opc);
			}while(opc!=0);
		fclose(archivo);
		
		/*ELIMINANDO LA PILA*/
		
		while(ultimo!=NULL)							
			{
				actual=ultimo;
				ultimo=ultimo->anterior;
				delete actual;
			}
		
		/*ABRIENDO EL ARCHIVO PARA LECTURA*/
		
		dato aux;											//<----------ESTRUCTURA AUXILIAR PARA LEER (ESTE SI)
		archivo=fopen("test.bin","rb");						//<----------PARECE SER NECESARIO
		rewind(archivo);
		fread(&aux,sizeof(aux),1,archivo);					//<----------GUARDO EN LA STRUCT AUXILIAR Y MUESTRO
		while(!feof(archivo))
			{
				printf("%d\n",aux.num);
				fread(&aux,sizeof(aux),1,archivo);
			}
		return 0;
	}
