#include<stdio.h>
#include<conio.h>

int func_menu();
void func_crear(FILE *arch);
void func_carga(FILE *arch);
void func_leer(FILE *arch);
void func_buscar(FILE *arch);

int main()

	{
		FILE *arch;
		int menu;
		printf("Programa de ejemplo de carga y busqueda de archivos");
		printf("\nNOTA: No agrege opcion append, es solo para probar");
		printf("\n===================================================\n\n");
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							func_crear(arch);
							break;
						case 2:
							func_carga(arch);
							break;
						case 3:
							func_leer(arch);
							break;
						case 4:
							func_buscar(arch);
							break;	
						case 5:
							break;		
					}	
			}while(menu!=5);
		getch();
		return 0;
	}

int func_menu()
	{
		int menu;
		do
			{
				printf("Elija la opcion deseada\n-----------------------\n\n");
				printf("1-Crear el archivo\n2-Agregar datos al archivo\n3-Leer el archivo\n4-Buscar en el archivo\n5-Salir\nSeleccion: ");	
				scanf("%d",&menu);	
				if(menu<1 or menu>5)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta\n\n");
					}		
			}while(menu<1 or menu>5);
		printf("\n\n");	
		return menu;	
	}
	
void func_crear(FILE *arch)

	{
		if((arch=fopen("numeritos.txt","r"))!=NULL)					
			{
				printf("\n\nERROR!!: El archivo ya existe\n\n");
				fclose(arch);
			}
		else
			{
				arch=fopen("numeritos.txt","w");
				fclose(arch);
				printf("Archivo creado\n\n");
			}		
	}

void func_carga(FILE *arch)

	{
		if((arch=fopen("numeritos.txt","r"))==NULL)//Como lectura siempre para probar si existe
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				arch=fopen("numeritos.txt","w");//No agrege opcion para append, es solo un testeo
				int num;
				printf("\n\nIngrese un numero, con 0 terminara la carga\n");
				scanf("%d",&num);
				while(num!=0)
					{
						fprintf(arch,"%d\n",num);
						scanf("%d",&num);
					}
				fclose(arch);
				printf("\n\n");					
			}	
	}	
	
void func_leer(FILE *arch)

	{
		if((arch=fopen("numeritos.txt","r"))==NULL)//Como lectura siempre para probar si existe
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				int num;
				arch=fopen("numeritos.txt","r");
				rewind(arch);
				printf("Lectura del archivo\n===============\n\n");
				fscanf(arch,"%d",&num);
				while(!feof(arch))
					{
						printf("%d ",num);
						fscanf(arch,"%d",&num);
					}
				fclose(arch);
				printf("\n\n");
			}
	}
	
void func_buscar(FILE *arch)

	{
		if((arch=fopen("numeritos.txt","r"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				int linea=1,busqueda,resultado;
				/*
				QUE LA PRIMER LINEA SEA 1 (SI PRIMERO INGRESASTE 1, TE VA DECIR Q ESTA EN LA LINEA 1)
				UNA VARIABLE QUE GUARDA EL NUMERO A BUSCAR
				UNA VARIABLE QUE GUARDA EL NUMERO OBTENIDO POR EL FSCANF
				*/				
				arch=fopen("numeritos.txt","r");
				printf("Ingrese el numero a buscar: ");
				scanf("%d",&busqueda);
				fscanf(arch,"%d",&resultado);
				while(!feof(arch) and busqueda!=resultado)
					{
						linea++;
						fscanf(arch,"%d",&resultado);
					}
				if(feof(arch))
					{
						printf("No se encontro el numero.\n\n");
					}	
				else
					{
						printf("El numero %d se encontro en la linea %d\n\n",busqueda,linea);
					}	
				fclose(arch);	
			}		
	}		
