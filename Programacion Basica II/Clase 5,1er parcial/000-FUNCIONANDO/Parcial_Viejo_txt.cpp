/*								ENUNCIADO
Cargar nombre y nota de alumnos. La cantidad de alumnos a ingresar es desconocida.
Terminada la carga permitir cambiar la nota de los alumnos ingresando el nombre y la nueva nota.
Al final los datos deben poder ser listados por pantalla.
Los datos de los alumnos deben almacenarse en archivo y los cambios también.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
		{
			char nombre[10];
			float nota;
		}Talumno;

int func_menu();
void func_carga(FILE *arch);
void func_leer(FILE *arch);
void func_cambiar(FILE *arch);

int main()

	{
		FILE *arch;
		int menu;
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							func_carga(arch);
							break;
						case 2:
							func_leer(arch);
							break;
						case 3:
							func_cambiar(arch);
							break;
						case 4:
							break;		
					}
			}while(menu!=4);
		getch();
		return 0;
	}
	
int func_menu()

	{
		printf("\n\n");	
		int menu;
		do
			{
				printf("1-Cargar datos\n2-Leer los datos\n3-Cambiar una nota\n4-Salir\nSeleccion: ");
				scanf("%d",&menu);
				if(menu<1 or menu>4)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta.\n\n");
					}
			}while(menu<1 or menu>4);
		return menu;	
	}
	
void func_carga(FILE *arch)

	{
		int opcion,abierto=0;
		printf("\n\n1-Generar un nuevo archivo\n2-Agregar datos\nSeleccion: ");
		scanf("%d",&opcion);
		switch(opcion)
			{
				case 1:
					arch=fopen("listado.txt","w");
					abierto++;
					break;
				case 2:
					if((arch=fopen("listado.txt","r"))==NULL)
						{
							printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
						}
					else
						{
							arch=fopen("listado.txt","a");
							abierto++;
						}	
					break;
				default:
					printf("ERROR!!: Opcion incorrecta");
					break;
			}
		if(abierto==1)
			{
				Talumno alumno;
				float nota;
				fflush(stdin);
				printf("Ingrese el nombre del alumno: ");
				gets(alumno.nombre);
				printf("Ingrese la nota del alumno: ");
				scanf("%f",&alumno.nota);
        		fwrite(&alumno,sizeof(alumno),1,arch);
				fclose(arch);	
			}		
	}
	
void func_leer(FILE *arch)

	{
		if((arch=fopen("listado.txt","r"))==NULL)
			{
				printf("\n\n\t\tERROR!!: No puede leerse el archivo. Existe?\n\n");
			}
		else
			{
				Talumno alumno;
				arch=fopen("listado.txt","r");
				rewind(arch);
				fread(&alumno,sizeof(alumno),1,arch);
				while(!feof(arch))
					{
						printf("\n%s\t\t%.2f",alumno.nombre,alumno.nota);
						fread(&alumno,sizeof(alumno),1,arch);
					}
				fclose(arch);
			}	
	}	

void func_cambiar(FILE *arch)

	{
		if((arch=fopen("listado.txt","r"))==NULL)
			{
				printf("\n\n\t\tERROR!!: No puede leerse el archivo. Existe?\n\n");
			}
		else
			{
				Talumno alumno;
				char nombre[20];
				arch=fopen("listado.txt","r+");
				rewind(arch);
				fflush(stdin);
				printf("Ingrese el nombre: ");
				scanf("%s",nombre);
				fread(&alumno,sizeof(alumno),1,arch);				
				while(!feof(arch))
					{
						if(strcmp(alumno.nombre,nombre)==0)
							{
								break;
							}
						else
							{
								fread(&alumno,sizeof(alumno),1,arch);
							}	
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: No se encontro el nombre.\n\n");
					}
				else
					{
						fseek(arch,(-1)*sizeof(alumno),SEEK_CUR);
						printf("Ingrese una nueva nota: ");
						scanf("%f",&alumno.nota);
						fwrite(&alumno,sizeof(alumno),1,arch);						
					}		
				fclose(arch);
			}
	}		
