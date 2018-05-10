#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
	{
		char nombre[20];
		float nota;
		double DNI;
		
	}DATO;

int func_menu();
void func_cargar(FILE *arch);
void func_leer(FILE *arch);
void func_cambiar(FILE *arch);
void func_ordenar(FILE *arch);

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
							func_cargar(arch);
							break;
						case 2:
							func_leer(arch);
							break;
						case 3:
							func_cambiar(arch);
							break;
						case 4:
							func_ordenar(arch);
							break;
						case 5:
							break;	
					}
				
			}while(menu!=4);
		getch();
		return 0;
	}

int func_menu()

	{
		int menu;
		printf("1-Agregar datos\n2-Leer datos\n3-Modificar una nota\n4-Ordenar por nombre\n5-Salir\nSeleccion: ");
		scanf("%d",&menu);
		return menu;
	}

void func_cargar(FILE *arch)

	{
		int menu,abierto=0;
		printf("1-Generar un nuevo archivo\n2-Agregar datos\nSeleccion: ");
		scanf("%d",&menu);
		switch(menu)
			{
				case 1:
					arch=fopen("database.bin","wb");
					abierto++;
					break;
				case 2:
					if((arch=fopen("database.bin","rb"))==NULL)
						{
							printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
						}
					else
						{
							arch=fopen("database.bin","ab");
							abierto++;
						}	
					break;
				default:
					printf("\n\nERROR!!: Opcion incorrecta.\n\n");
					break;
			}
		if(abierto==1)
			{
				DATO persona;
				char rta='1';
				while(rta=='1')
					{	
						printf("Ingrese nombre: ");
						scanf("%s",&persona.nombre);
						printf("Ingrese nota: ");
						scanf("%f",&persona.nota);
						printf("Ingrese D.N.I: ");
						scanf("%lf",&persona.DNI);
						fwrite(&persona,sizeof(persona),1,arch);
						printf("Si desea seguir agregando pulse 1/Otra tecla para finalizar la carga\nSeleccion: ");
						scanf("%s",&rta);
					}
				fclose(arch);	
			}	
	}	

void func_leer(FILE *arch)

	{
		if((arch=fopen("database.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				arch=fopen("database.bin","rb");
				rewind(arch);
				DATO persona;
				fread(&persona,sizeof(persona),1,arch);
				while(!feof(arch))
					{
						printf("%s\t%.2f\t%lf\n",persona.nombre,persona.nota,persona.DNI);
						fread(&persona,sizeof(persona),1,arch);
						
					}
				fclose(arch);	
			}	
	}	
	
void func_cambiar(FILE *arch)

	{
		if((arch=fopen("database.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				char aux[20];
				DATO persona;
				arch=fopen("database.bin","rb+");
				rewind(arch);
				printf("Ingrese el nombre del alumno que desea modificar: ");
				scanf("%s",&aux);
				fread(&persona,sizeof(persona),1,arch);
				while(!feof(arch))
					{
						if((strcmp(persona.nombre,aux))==0)
							{
								break;
							}
						else
							{
								fread(&persona,sizeof(persona),1,arch);
							}	
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: No se encontro el alumno.\n\n");
					}	
				else
					{
						fseek(arch,(-1)*sizeof(persona),SEEK_CUR);
						printf("Ingrese la nueva nota: ");
						scanf("%f",&persona.nota);
						fwrite(&persona,sizeof(persona),1,arch);
					}	
				fclose(arch);
			}	
	}	
	
void func_ordenar(FILE arch)

	{
		if((arch=fopen("database.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				arch=fopen("database.bin","rb+");
				rewind(arch);
				DATO persona,aux;
				fread(&persona,sizeof(persona),1,arch);
				while(!feof(arch))
					{
						aux=persona;
						if(strcmp(persona.nombre>aux.nombre))
							{
								
							}
						fread(&persona,sizeof(persona),1,arch);	
					}
				
				fclose(arch);
			}
	}
