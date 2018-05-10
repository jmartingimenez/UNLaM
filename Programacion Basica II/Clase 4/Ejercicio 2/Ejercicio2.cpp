	/*
ENUNCIADO:
			(Crear una estructura cursos)
			
			-nombre curso
			-cant integrante
			-fecha de inicio (validada)
			-codigo (id)		
												
										***abrirlo, poderlo escribir/leer
										
---No especificado, el nombre del archivo, si se tiene q elegir nombre o no. Simplemente
el archivo se llamara 'curso'. 	

	===Este programa crea el archivo 'cursos.txt', permite agregar, modificar, visualizar y eliminarlo===									
*/

#include<stdio.h>
#include<conio.h>

const char *cabecera="ID\t\tNombre\t\tCantidad\tFecha de inicio\n\n";
/*
LA IDEA DE ESTA CONSTANTE ES QUE AL CREAR UN ARCHIVO, APAREZCA ESE TEXTO POR DEFECTO. A TRAVES DE
LA VARIABLE QUE ESTA DEBAJO VOY CONTROLANDO SI AGREGARLA AL ARCHIVO O NO
			(EN EL SUBMENU DE AGREGAR/SOBREESCRIBIR DATOS)
======ME GUSTARIA SABER POR QUE SE PONE EL PUNTERO, ESTA IDEA LA ENCONTRE LEYENDO..
*/
int TITULOS=0;//Variable global para controlar que el texto por default que aparece al crear un archivo
			  //ya esta puesto. Con esto evito que cada vez que agrege datos en modo append la cabecera se
			  //agrege nuevamente
			  			  	
typedef struct
			{
				char nombre[20];
				int id_curso;					//supongo que con codigo(ID), se referia al del curso
				int cant;					
				int dia,mes,anio;				//quizas convenia en otra struct pero me avive cuando
			}Tcurso;							//ya habia terminado


int func_menu();
int func_existe(FILE *arch);
void func_abrir(FILE *arch);
void func_agregar(FILE *arch,Tcurso *p);
				void func_new(FILE *arch,Tcurso *p);			//subfuncion de 'func_agregar'
				void func_add(FILE *arch,Tcurso *p);			//subfuncion de 'func_agregar'
				void func_fecha(FILE *arch,Tcurso *p);			//subfuncion de 'func_agregar'
				int func_bisiesto(int anio);					//subfuncion de 'func_agregar'
void func_leer(FILE *arch,Tcurso *p);
void func_eliminar(FILE *arch);

int main()

	{
		Tcurso curso,*p=&curso;
		int menu;
		FILE *arch;
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							func_abrir(arch);
							break;
						case 2:
							func_agregar(arch,p);
							break;
						case 3:
							func_leer(arch,p);
							break;
						case 4:
							func_eliminar(arch);
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
				printf("1-Crear el archivo cursos.txt\n2-Agregar datos al archivo\n3-Leer el archivo\n");
				printf("4-Eliminar el archivo\n5-Salir\nSeleccion: ");
				scanf("%d",&opcion);
				if(opcion<1 or opcion>5)
					{
						printf("\n\t\tERROR!!: Opcion incorrecta!!\n\n");
					}						
			}while(opcion<1 or opcion>5);
		return opcion;
	}	
	
int func_existe(FILE *arch)

	{
		if((arch=fopen("cursos.txt","r"))!=NULL)					//comprobando si ya esta creado			
			{
				fclose(arch);
				return 0;											
			}
		else
			{
				return -1;										
			}
	}	
	
void func_abrir(FILE *arch)
	
	{
		int existe=func_existe(arch);
		if(existe==0)
			{
				printf("\n\nERROR!!: El archivo ya existe. Para agregar/sobreescribir datos elija la opcion 2\n\n");
			}
		else
			{
				printf("\n\n\t\tEl archivo parece no existir. Se ha creado uno nuevo.");
				arch=fopen("cursos.txt","w");
				fprintf(arch,"%s",cabecera);				//Ponemos titulos al archivo de texto
				TITULOS=1;									//controlando que ya estan creados..
				printf("\n\t\tEl archivo cursos.txt ha sido creado.\n\n");
				fclose(arch);				
			}
	}
	
void func_agregar(FILE *arch,Tcurso *p)

	{
		int menu,existe=func_existe(arch);
		if(existe==0)
			{
				printf("\n\nSeleccione la opcion deseada.");
				printf("\n----------------------------\n");
				printf("\n1-Agregar un curso\n2-Sobreescribir el archivo.");
				printf("\n\nSeleccion: ");
				scanf("%d",&menu);
				switch(menu)
					{
						case 1:
							func_add(arch,p);
							break;
						case 2:
							func_new(arch,p);
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

void func_leer(FILE *arch,Tcurso *p)

	{
		int c,existe=func_existe(arch);
		if(existe==0)
			{
				arch=fopen("cursos.TXT","r");									
				rewind(arch);													
				printf("Lectura del archivo.\n\n");
				while((c=getc(arch))!=EOF)			//Tuve muchos problemas para mostrar el texto con
					{								//las funciones que estan en el word de archivo en miel
						putchar(c);					//asi que termine usando este while que encontre leyendo
					}								//en internet. Debe haber una forma mas eficiente que estar
				fclose(arch);						//mostrando caracter por caracter pero es lo unico que me
				printf("\n\n");						//funciono. Necesitaria algun ejemplo
			}		
		else
			{
				printf("\n\nERROR!!: El archivo no puede encontrarse. Existe?\n\n");
			}
	}	

void func_eliminar(FILE *arch)

	{
		int existe=func_existe(arch);
		if(existe==0)
			{
				int del=remove("cursos.txt");
				if(del==0)
					{
						printf("\n\n\t\tEl archivo ha sido eliminado correctamente.\n\n");
						TITULOS=0;
					}
				else
					{
						printf("\n\n\t\tERROR!!: No se puede eliminar el archivo.\n");
					}								
			}
		else
			{
				printf("\n\nERROR!!: El archivo no puede encontrarse. Existe?\n\n");							
			}		
	}	
	
/*-------------------------------------SUBFUNCIONES DE 'func_agregar'-----------------------------------------*/

void func_add(FILE *arch,Tcurso *p)

	{
		int existe=func_existe(arch);
		if(existe==0)
			{
				TITULOS=1;			//avisamos que la cabecera esta creada. La razon de este if es que
			}						//se puede acceder a esta opcion si abris el programa y el txt ya existe	
		arch=fopen("cursos.txt","a");
		printf("Ingrese la ID del curso: ");
		scanf("%d",&p->id_curso);
		printf("Ingrese el nombre del curso: ");
		scanf("%s",&p->nombre);
		printf("Ingrese la cantidad de alumnos en el curso: ");
		scanf("%d",&p->cant);
		func_fecha(arch,p);
		fprintf(arch,"%d\t\t",p->id_curso);
		fprintf(arch,"%s\t\t",p->nombre);
		fprintf(arch,"%d\t\t",p->cant);
		fprintf(arch,"%d/%d/%d\n",p->dia,p->mes,p->anio);
		fclose(arch);
	}	

void func_new(FILE *arch,Tcurso *p)

	{

		arch=fopen("cursos.txt","w");							//es practicamente igual a func_add
		fprintf(arch,"%s",cabecera);							//solo cambiando el modo
		printf("Ingrese la ID del curso: ");					
		scanf("%d",&p->id_curso);
		printf("Ingrese el nombre del curso: ");
		scanf("%s",&p->nombre);
		printf("Ingrese la cantidad de alumnos en el curso: ");
		scanf("%d",&p->cant);
		func_fecha(arch,p);
		fprintf(arch,"%d\t\t",p->id_curso);
		fprintf(arch,"%s\t\t",p->nombre);
		fprintf(arch,"%d\n",p->cant);
		fprintf(arch,"%d/%d/%d\n",p->dia,p->mes,p->anio);
		fclose(arch);
	}		

void func_fecha(FILE *arch,Tcurso *p)

	{
		int anio,mes,dia,diaMAX=31;
		do	
			{
				printf("Ingrese el anio de inicio del curso: ");				//basicamente, primero
				scanf("%d",&anio);												//reviso la validez de los
				if(anio<0)														//datos antes de agregarlos
					{															//a la estructura
						printf("\n\n\t\tERROR!!: Anio negativo.\n\n");
					}
			}while(anio<0);
		p->anio=anio;//Guardando el anio	
		do
			{
				printf("Ingrese el mes de inicio del curso: ");
				scanf("%d",&mes);
				switch(mes)
					{
						case 4:
						case 6:
						case 9:
						case 11:
							diaMAX-=1;												//30 dias
							break;	
						case 2:
							diaMAX=func_bisiesto(anio);	
							break;	
						default:
							if(mes<1 or mes>12)
								{
									printf("\n\n\t\tERROR!!: Codigo de mes incorrecto\n\n");
								}
							break;	
					}						
			}while(mes<1 or mes>12);
		p->mes=mes;//Guardando el mes	
		do
			{
				printf("Ingrese el dia de inicio del curso: ");
				scanf("%d",&dia);
				if(dia<1 or dia>diaMAX)
					{
						printf("\n\n\t\tERROR!!: Codigo de dia incorrecto\n\n");
					}						
			}while(dia<1 or dia>diaMAX);
		p->dia=dia;//Guardando el dia	
	}

int func_bisiesto(int anio)

	{
		if((anio%4==0 and anio%100!=0)or(anio%400==0))
			{
				return 29;
			}
		else
			{
				return 28;
			}	
	}
