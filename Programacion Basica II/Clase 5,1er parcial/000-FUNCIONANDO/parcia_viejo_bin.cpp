/*								ENUNCIADO
Cargar nombre y nota de alumnos. La cantidad de alumnos a ingresar es desconocida.
Terminada la carga permitir cambiar la nota de los alumnos ingresando el nombre y la nueva nota.
Al final los datos deben poder ser listados por pantalla.
Los datos de los alumnos deben almacenarse en archivo y los cambios también.
*/

typedef struct
	{
		char nombre[20];
		float nota;
	}Talumno;

#include<stdio.h>
#include<conio.h>
#include<string.h>

int func_menu();
void func_carga(FILE *arch);
void func_leer(FILE *arch);
void func_cambiar(FILE *arch);

int main()

	{
		int menu;
		FILE *arch;
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
		int menu;
		printf("1-Cargar datos\n2-Leer datos\n3-Cambiar nota\n4-Salir\nSeleccion: ");
		scanf("%d",&menu);
		return menu;
	}	
	
void func_carga(FILE *arch)

	{
		int menu;
		char seguir=1;
		Talumno alumno;
		printf("1-Generar un nuevo listado\n2-Agregar datos\nSeleccion: ");
		scanf("%d",&menu);
		switch(menu)
			{
				case 1:
					arch=fopen("listado.bin","wb");
					break;
				case 2:
					if((arch=fopen("listado.bin","rb"))==NULL)
						{
							printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
							break;
						}
					else
						{
							arch=fopen("listado.bin","ab");
						}								
					break;
			}
		if(menu==1 or menu==2)
			{
				while(seguir==1)
					{
						printf("Ingrese el nombre del alumno: ");
						scanf("%s",&alumno.nombre);
						printf("Ingrese la nota del alumno: ");
						scanf("%f",&alumno.nota);
						fwrite(&alumno,sizeof(alumno),1,arch);
						printf("Para seguir agregando datos pulse 1/otra tecla para salir\nSeleccion: ");
						scanf("%s",&seguir);
					}	
			}
		fclose(arch);		
	}
	
void func_leer(FILE *arch)

	{
		if((arch=fopen("listado.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				arch=fopen("listado.bin","rb");
				Talumno alumno;
				rewind(arch);
				fread(&alumno,sizeof(alumno),1,arch);
				while(!feof(arch))
					{
						printf("%s\t%.2f\n",alumno.nombre,alumno.nota);						
						fread(&alumno,sizeof(alumno),1,arch);
					}
				fclose(arch);
			}
	}
	
void func_cambiar(FILE *arch)

	{
		if((arch=fopen("listado.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				Talumno alumno;
				char aux[20];
				printf("Ingrese el nombre del alumno a modificar su nota: ");
				scanf("%s",&aux);
				arch=fopen("listado.bin","rb+");
				rewind(arch);
				fread(&alumno,sizeof(alumno),1,arch);
				while(!feof(arch))
					{
						if(strcmp(alumno.nombre,aux)==0)
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
						printf("\n\n\t\tERROR!!: no se encontro el nombre\n\n");
					}
				else
					{
						fseek(arch,(-1)*sizeof(alumno),SEEK_CUR);
						printf("Ingrese la nueva nota: ");
						scanf("%f",&alumno.nota);
						fwrite(&alumno,sizeof(alumno),1,arch);
					}	
				fclose(arch);
			}
	}
			
