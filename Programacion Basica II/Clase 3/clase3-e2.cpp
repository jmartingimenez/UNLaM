/*
===============================================================================================
Ejercicio 2: Escribe la declaración en C de un vector de 50 elementos de tipo 'talumno'. 
Escribe después el código necesario para subir, a todas las chicas,  0,5 puntos en la calificación
de todas las asignaturas.
								HACER MENU Y VALIDACIONES..
=====================================================================================================*/


#include<stdio.h>
#include<conio.h>

/*=====================================DECLARACION DE LA ESTRUCTURA===================================*/

typedef struct
			{
				int id;
				char sexo;
				float notas[10];
			}Talumno;

/*=====================================DECLARACION DE LAS FUNCIONES===================================*/

void func_limpiar(Talumno *p);
int func_menu();
void func_datos(Talumno *p);
			int func_cargaID();							//subfuncion de func_datos
			char func_cargaSEXO();						//subfuncion de func_datos
			float func_cargaNOTA(int i);				//subfuncion de func_datos
void func_notas(Talumno *p);
void func_aumentar(Talumno *p);		

/*==========================================FUNCIONES===================================================*/	

int main()

{
	Talumno alumnos[50],*p=alumnos;
	int menu;
	func_limpiar(p);
	do
		{
			menu=func_menu();
			switch(menu)
				{
					case 1:
						func_datos(p);
						break;
					case 2:
						func_notas(p);
						break;
					case 3:
						func_aumentar(p);
						break;
					case 4:
						break;	
				}
		}while(menu!=4);
	getch();
	return 0;
}


void func_limpiar(Talumno *p)

{
	for(int i=0;i<50;i++)
		{
			p[i].id=0;
			p[i].sexo='-';								//caracter random
			for(int j=0;j<10;j++)
				{
					p[i].notas[j]=0;					//'i' seria la ID
				}										//'j' el numero de asignatura
		}	
}

int func_menu()

{
		int menu=0;
		printf("=========================\n");
		printf("1-Cargar datos de un alumno\n2-Ver notas de chicas\n3-Aumentar notas de chicas\n4-Salir\nSeleccion: ");
		scanf("%d",&menu);
		if(menu<1 or menu>4)
			{
				printf("\n\n\tERROR!!: La opcion seleccionada no existe.\n\n");
				func_menu();
			}
		return menu;	
}

void func_datos(Talumno *p)

{
	int opcion=func_cargaID();							//Primero, pido la ID y el numero que retorna
	p[opcion-1].id=opcion;								//lo uso como posicion del vector.
	p[opcion-1].sexo=func_cargaSEXO();					//El (-1) viene de que los vectores comienzan de 0
	for(int i=0;i<10;i++)								//pero el minimo de ID a ingresar es 1
		{
			p[opcion-1].notas[i]=func_cargaNOTA(i);		//llevo 'i' para mostrar el numero de asignatura
		}												//supongo que deberia haber creado un puntero..
	printf("\n\n");	
}

/*===============================COMIENZO DE SUBFUNCIONES DE 'func_datos'====================================*/

int func_cargaID()
	{
		int id=0;
		do
			{
				printf("Ingrese la ID del alumno: ");
				scanf("%d",&id);
				if(id<1 or id>50)				//supongo que las ID deberian ir desde 1 a 50
					{
						printf("\n\t\tERROR!!: Numero minimo de ID: 1///Numero maximo de ID: 50\n\n");
					}
			}while(id<1 or id>50);
		return id;			
	}
	
char func_cargaSEXO()

{
	char sexo='-';
		while(sexo!='m' or sexo!='f' or sexo!='o')
			{
				fflush(stdin);
				printf("Ingrese el sexo\t(m)asculino\t(f)emenino\t(o)tros\nSeleccion: ");
				scanf("%c",&sexo);
				if(sexo=='m' or sexo=='f' or sexo=='o')
					{
						return sexo;
					}
				else
					{
						printf("\n\tERROR!!: La tecla correspondiente al sexo debe ser 'm', 'f' u 'o'.\n\n");
					}	
			}	
}	

float func_cargaNOTA(int i)

{
	float nota;
	do
		{
			printf("Ingrese la nota correspondiente a la asignatura numero %d: ",i+1);
			scanf("%f",&nota);	
			if(nota<1 or nota>10)
				{
					printf("\n\tERROR!!: La nota debe estar entre 1 y 10.\n\n");
				}				
		}while(nota<1 or nota>10);
	return nota;	
}

/*===================================FIN DE SUBFUNCIONES DE 'func_datos'====================================*/

void func_notas(Talumno *p)

{
	printf("\n\n---------------------------------------------------------------------------\n");
	printf("NOTAS DE LAS CHICAS\t(SI MUESTRO LA NOTA 10, SE ME DESARMA EL CUADRO)\n");
	printf("---------------------------------------------------------------------------\n");	
	printf("ID:\tN1\tN2\tN3\tN4\tN5\tN6\tN7\tN8\tN9\n");	
	printf("---------------------------------------------------------------------------\n\n");	
	for(int i=0;i<50;i++)
		{
			if(p[i].sexo=='f')											//buscando que sean mujeres
				{
					printf("%d:\t",p[i].id);
					for(int j=0;j<9;j++)//SI QUIERO VER LAS 10, EL CUADRO SE ME DESARMA!!!. Prefiero ver la ID			
						{
							printf("%.2f\t",p[i].notas[j]);				//'i' hace referencia  a la 'ID'
						}												//encontrada. 'j' al numero de
																		//asignatura	
				}
		}
	printf("\n\n");	
}

void func_aumentar(Talumno *p)

{
	for(int i=0;i<50;i++)
		{
			if(p[i].sexo=='f')											//buscando que sean mujeres
				{
					for(int j=0;j<10;j++)
						{
							if(p[i].notas[j]<=9.5)						//PARA QUE LA NOTA NO PASE DE 10!!	
								{										//'i' es el numero de ID
									p[i].notas[j]+=0.5;					//'j' es el numero de asignatura
								}
						}												
																			
				}	
		}
	printf("\n\t\t\tNOTAS AUMENTADAS!!!\n\n");		
}
