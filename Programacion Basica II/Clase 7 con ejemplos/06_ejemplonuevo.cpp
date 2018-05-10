#include<stdio.h>
#include<conio.h>
#include<string.h>
struct pila{
	int num;
	char nombre[10];
	struct pila *ant;
};

typedef pila DATO;

void ingreso(FILE *archivo);
void mostrar(FILE *archivo,alumno*);

int main()
{
	int sel;
	FILE *archivo;
	do{
		printf("1) Cargar dato \n2) Mostrar dato\n3) Salir\nSeleccion: ");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				ingreso(archivo);
				break;
			case 2:
				mostrar(archivo,alumno);
				break;
		}
	}while(sel!=3);
}

void ingreso(FILE *archivo)
{
	int opc;
	DATO *ultimo=NULL,*actual;
	actual= new DATO;
	archivo=fopen("tamosenelhorno.bin","wb");
	do
		{
			printf("Ingrese numero");
			scanf("%d",&actual->num);
			fflush(stdin);
			printf("Ingrese nombre");
			gets(actual->nombre);	
			//fprintf(archivo,"%d\t",actual->num);
			//fprintf(archivo,"%s\n",actual->nombre);
			fwrite(&actual,sizeof(actual),1,archivo);
			printf("Pulse 0 para finalizar/Otra tecla continuar: ");
			scanf("%d",&opc);		
		}while(opc!=0);
	fclose(archivo);	
}

void mostrar(FILE *archivo)

{
	if((archivo=fopen("tamosenelhorno.bin","rb"))!=NULL)
		{
	archivo=fopen("tamosenelhorno.bin","rb");
	DATO leido;
	fseek(archivo,0,SEEK_END);
	printf("\n\n\t\t%ld\n\n",ftell(archivo));
	rewind(archivo);
	fread(&leido,sizeof(leido),1,archivo);
	printf("%s\t%.2f\n",&leido.num,&leido.nombre);							
	while(!feof(archivo))
		{
			printf("%s\t%.2f\n",&leido.num,&leido.nombre);						
			fread(&leido,sizeof(leido),1,archivo);
		}
	fclose(archivo);			
		}
	else
		printf("asdas");	
	
}
