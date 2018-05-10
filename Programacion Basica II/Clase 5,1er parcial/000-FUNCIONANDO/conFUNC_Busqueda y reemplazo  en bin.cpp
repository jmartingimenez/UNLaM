#include<stdio.h>
#include<conio.h>


int func_menu();
void func_crear(FILE *arch);
void func_carga(FILE *arch);
void func_leer(FILE *arch);
void func_buscar(FILE *arch);
void func_reemplazar(FILE *arch);

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
							func_reemplazar(arch);
							break;	
						case 6:
							break;		
					}	
			}while(menu!=6);
		getch();
		return 0;
	}

int func_menu()
	{
		int menu;
		do
			{
				printf("Elija la opcion deseada\n-----------------------\n\n");
				printf("1-Crear el archivo\n2-Agregar datos al archivo\n3-Leer el archivo\n4-Buscar en el archivo\n5-Reemplazar un numero\n6-Salir\nSeleccion: ");	
				scanf("%d",&menu);	
				if(menu<1 or menu>6)
					{
						printf("\n\n\t\tERROR!!: Opcion incorrecta\n\n");
					}		
			}while(menu<1 or menu>6);
		printf("\n\n");	
		return menu;	
	}
	
void func_crear(FILE *arch)

	{
		if((arch=fopen("numeritos.bin","rb"))!=NULL)					
			{
				printf("\n\nERROR!!: El archivo ya existe\n\n");
				fclose(arch);
			}
		else
			{
				arch=fopen("numeritos.bin","wb");
				fclose(arch);
				printf("Archivo creado\n\n");
			}		
	}

void func_carga(FILE *arch)

	{
		if((arch=fopen("numeritos.bin","rb"))==NULL)//Como lectura siempre para probar si existe
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				arch=fopen("numeritos.bin","wb");//No agrege opcion para append, es solo un testeo
				int num;
				printf("\n\nIngrese un numero, con 0 terminara la carga\n");
				scanf("%d",&num);
				while(num!=0)
					{
						fwrite(&num,sizeof(num),1,arch);
						scanf("%d",&num);						
					}
				fclose(arch);
				printf("\n\n");					
			}	
	}	
	
void func_leer(FILE *arch)

	{
		if((arch=fopen("numeritos.bin","rb"))==NULL)//Como lectura siempre para probar si existe
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				int leido;
				arch=fopen("numeritos.bin","rb");
				rewind(arch);
				printf("Lectura del archivo\n===============\n\n");
				fread(&leido,sizeof(leido),1,arch);
				while(!feof(arch))
					{
						printf("%d ",leido);
						fread(&leido,sizeof(leido),1,arch);
					}
				fclose(arch);
				printf("\n\n");
			}
	}
	
void func_buscar(FILE *arch)

	{
		if((arch=fopen("numeritos.bin","rb"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				int linea=1,num,leido;
				/*
				QUE LA PRIMER LINEA SEA 1 (SI PRIMERO INGRESASTE 1, TE VA DECIR Q ESTA EN LA LINEA 1)
				UNA VARIABLE QUE GUARDA EL NUMERO A BUSCAR
				UNA VARIABLE QUE GUARDA EL NUMERO OBTENIDO POR EL FREAD
				*/				
				arch=fopen("numeritos.bin","rb");
				rewind(arch);
				printf("Ingrese el numero a buscar: ");
				scanf("%d",&num);
				fread(&leido,sizeof(leido),1,arch);
				while(!feof(arch) and num!=leido)
					{
						linea++;
						fread(&leido,sizeof(leido),1,arch);
					}
				if(feof(arch))
					{
						printf("No se encontro el numero.\n\n");
					}	
				else
					{
						printf("El numero %d se encontro en la linea %d\n\n",num,linea);
					}	
				fclose(arch);	
			}		
	}		
	
void func_reemplazar(FILE *arch)

	{
		if((arch=fopen("numeritos.bin","rb+"))==NULL)
			{
				printf("\n\n\t\tERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
		else
			{
				int num,leido;				
				printf("\nIngrese el numero a reemplazar: ");
				scanf("%d",&num);
				arch=fopen("numeritos.bin","rb+");
				rewind(arch);
				fread(&leido,sizeof(leido),1,arch);
				while(!feof(arch) and num!=leido)
					{
						fread(&leido,sizeof(leido),1,arch);
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: No se encontro el numero\n\n");
					}	
				else
					{
						printf("\n\nIngrese el nuevo numero: ");
						scanf("%d",&num);
						fseek(arch,(-1)*sizeof(leido),SEEK_CUR);
						fwrite(&num,sizeof(num),1,arch);
					}			
				fclose(arch);
			}
	}
	
