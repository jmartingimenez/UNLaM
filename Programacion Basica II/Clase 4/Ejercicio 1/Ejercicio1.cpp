/*ESTE PROGRAMA CREA UN ARCHIVO LLAMADO 'numeros.txt', PERMITE MODIFICUARLO, VISUALIZARLO Y ELIMINARLO*/
#include<stdio.h>
#include<conio.h>

int func_menu();
int func_existe(FILE *p_arch);
void func_abrir(FILE *p_arch);
void func_agregar(FILE *p_arch);
				void func_add(FILE *p_arch);				//subfuncion de func_agregar
				void func_new(FILE *p_arch);				//subfuncion de func_agregar
void func_leer(FILE *p_arch);
void func_eliminar(FILE *p_arch);

int main()

	{
		int menu;
		FILE *p_arch;
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							func_abrir(p_arch);
							break;
						case 2:
							func_agregar(p_arch);
							break;
						case 3:
							func_leer(p_arch);
							break;
						case 4:
							func_eliminar(p_arch);
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
		int opcion=0;
		do
			{
				printf("==============================\n");
				printf("1-Crear el archivo numeros.txt\n2-Agregar datos al archivo\n3-Leer el archivo\n");
				printf("4-Eliminar el archivo\n5-Salir\nSeleccion: ");
				scanf("%d",&opcion);
				if(opcion<1 or opcion>5)
					{
						printf("\n\t\tERROR!!: Opcion incorrecta!!\n\n");
					}						
			}while(opcion<1 or opcion>5);
		return opcion;
	}

int func_existe(FILE *p_arch)

	{
		if((p_arch=fopen("numeros.txt","r"))!=NULL)					//Comprobando si puede leerse
			{
				fclose(p_arch);
				return 0;											//se puede, existe
			}
		else
			{
				return -1;											//No se puede, en teoria no existe
			}
	}

void func_abrir(FILE *p_arch)
	
	{
		int existe=func_existe(p_arch);
		if(existe==0)
			{
				printf("\n\nERROR!!: El archivo ya existe. Para agregar/sobreescribir datos elija la opcion 2\n\n");
			}
		else
			{
				printf("\n\n\t\tEl archivo parece no existir. Se ha creado uno nuevo.");
				p_arch=fopen("numeros.txt","w");
				printf("\n\t\tEl archivo numeros.txt ha sido creado.\n\n");
				fclose(p_arch);				
			}
	}	
	
void func_agregar(FILE *p_arch)

	{
		int menu,existe=func_existe(p_arch);
		if(existe==0)
			{
				printf("\n\nSeleccione la opcion deseada.");
				printf("\n----------------------------\n");
				printf("\n1-Agregar datos\n2-Sobreescribir el archivo.");
				printf("\n\nSeleccion: ");
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							func_add(p_arch);
							break;
						case 2:
							func_new(p_arch);
							break;
						default:
							printf("ERROR!!: Opcion incorrecta!!");
							break;
					}
				printf("\n\n");	
			}
		else
			{
				printf("\n\nERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
	}

void func_leer(FILE *p_arch)

	{
		int num,existe=func_existe(p_arch);
		if(existe==0)
			{
				p_arch=fopen("numeros.TXT","r");					//abriendolo para lectura				
				rewind(p_arch);										//principio del archivo					
				int num;											
				printf("Lectura del archivo.\n\n");	
				fscanf(p_arch,"%d",&num);										
			    while(!feof(p_arch))												
			    	{		
			    		printf("%d ",num);
			    		fscanf(p_arch,"%d",&num);
					}	
				fclose(p_arch);	
				printf("\n\n");
			}		
		else
			{
				printf("\n\nERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
	}	

void func_eliminar(FILE *p_arch)

	{
		int existe=func_existe(p_arch);
		if(existe==0)
			{
				//ya existe, borrar
				int del=remove("numeros.txt");
				if(del==0)
					{
						printf("\n\n\t\tEl archivo ha sido eliminado correctamente.\n\n");
					}
				else
					{
						printf("\n\n\t\tERROR!!: No se puede eliminar el archivo.\n");
					}								
			}
		else
			{
				//no existe	
				printf("\n\nERROR!!: El archivo no puede encontrarse. Existe?\n\n");							
			}		
	}

/*-------------------------------------SUBFUNCIONES DE 'func_agregar'-----------------------------------------*/

void func_new(FILE *p_arch)

	{
		
		p_arch=fopen("numeros.txt","w");									//Abriendolo para escritura
		int num;
		printf("\n\nIngrese numeros y seran almacenados en el archivo. Con 0 terminara la carga.\n");
		scanf("%d",&num);
		while(num)
			{
				fprintf(p_arch,"%d\n",num);
				scanf("%d",&num);	
			}
		fclose(p_arch);	
	}
	
void func_add(FILE *p_arch)

	{
		p_arch=fopen("numeros.txt","a");									//'a', al final
		int num;
		printf("\n\nIngrese numeros y seran almacenados en el archivo. Con 0 terminara la carga.\n");
		scanf("%d",&num);
		while(num)
			{
				fprintf(p_arch,"%d\n",num);
				scanf("%d",&num);
			}
		fclose(p_arch);	
	}	
