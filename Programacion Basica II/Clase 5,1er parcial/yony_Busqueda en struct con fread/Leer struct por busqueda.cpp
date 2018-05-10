#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
	{
		char nombre[10];
		int id,edad;
	}FICHA;

void func_datos(FICHA *p);
void func_escritura(FILE *arch,FICHA *p);
void func_lectura(FILE *arch);
void func_buscarID(FILE *arch,FICHA *p);
void func_buscarNOMBRE(FILE *arch,FICHA *p);

int main()

	{
		FILE *arch;
		FICHA persona[3],*p=persona;
		func_datos(p);
		func_escritura(arch,p);
		func_lectura(arch);
		func_buscarID(arch,p);
		func_buscarNOMBRE(arch,p);
		getch();
		return 0;
	}
	
void func_datos(FICHA *p)

	{
		for(int i=0;i<3;i++)
			{
				printf("Ingrese la ID: ");
				scanf("%d",&p[i].id);
				printf("Ingrese el nombre: ");
				scanf("%s",&p[i].nombre);
				printf("Ingrese la edad: ");
				scanf("%d",&p[i].edad);
			}
		printf("\n\n\t\tDATOS INGRESADOS\n");
		printf("ID\tNombre\tEdad\n--------------------\n\n");
		for(int i=0;i<3;i++)
			{
				printf("%d\t%s\t%d\n",p[i].id,p[i].nombre,p[i].edad);
			}
	}
	
void func_escritura(FILE *arch,FICHA *p)

	{
		arch=fopen("persona.txt","w");
		for(int i=0;i<3;i++)
			{
				fprintf(arch,"%d\t%s\t%d\n",p[i].id,p[i].nombre,p[i].edad);
			}
		fclose(arch);
	}
	
void func_lectura(FILE *arch)

	{
		int c,id,edad;
		char nombre[10];
		arch=fopen("persona.txt","r");
		rewind(arch);
		printf("\n\n\t\tDATOS LEIDOS DESDE EL ARCHIVO\n");
		printf("ID\tNombre\tEdad\n--------------------\n\n");		
		while((c=getc(arch))!=EOF)
			{
				putchar(c);
			}
		fclose(arch);			
	}

void func_buscarID(FILE *arch,FICHA *p)

	{
		int opcion,check_error;
		long int readstate;//fread devuelve la cantidad de bytes leidos correctamentes
		arch=fopen("persona.txt","r");
		rewind(arch);
		printf("\n\n\t\tBUSQUEDA EN EL ARCHIVO\nSeleccione la ID para ver sus datos: ");
		scanf("%d",&opcion);
		readstate=fread(p,sizeof(p),0,arch);	//El 0 para que lea desde el primero
		check_error=ferror(arch);				//Devuelve 0 si leyo sin problemas
		if(readstate!=-1 and check_error==0)	//no se que tan infalible es esto pero es lo que me funciona
			{
				for(int i=0;i<3;i++)
					{
						if(opcion==p[i].id)
							{
								printf("ID\tNombre\tEdad\n--------------------\n\n");
								printf("%d\t%s\t%d\n",p[i].id,p[i].nombre,p[i].edad);
							}				
					}
			}
		else
			{
				printf("ERROR DE LECTURA.");
			}		
		fclose(arch);	
	}
	
void func_buscarNOMBRE(FILE *arch,FICHA *p)

	{
		char opcion[10];
		arch=fopen("persona.txt","r");
		rewind(arch);
		printf("\n\n\t\tBUSQUEDA EN EL ARCHIVO\nSeleccione el nombre para ver sus datos: ");
		scanf("%s",&opcion);
		long int readstate=fread(p,sizeof(p),0,arch);
		int check_error=ferror(arch);//ferror devuelve 0 si no hubo algun error en la lectura
		if(readstate!=-1 and check_error==0)
			{
				for(int i=0;i<3;i++)
					{
						if(!strcmp(opcion,p[i].nombre))
							{
								printf("ID\tNombre\tEdad\n--------------------\n\n");
								printf("%d\t%s\t%d\n",p[i].id,p[i].nombre,p[i].edad);
							}				
					}
			}
		else
			{
				printf("\n\n\t\tERROR DE LECTURA.\n\n");
			}				
		/*
		while(!feof(arch))
			{
				for(int i=0;i<3;i++)
					{
						fread(p,sizeof(p),1L,arch);
						if(!strcmp(opcion,p[i].nombre))						
							{
								printf("ID\tNombre\tEdad\n--------------------\n\n");
								printf("%d\t%s\t%d\n",p[i].id,p[i].nombre,p[i].edad);
								//opcion[10]='';//Se me repite 3 veces :/
							}				
					}	
			}
			*/
		fclose(arch);	
	}		

				
