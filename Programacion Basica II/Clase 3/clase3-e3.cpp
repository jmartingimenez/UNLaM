/*
Supón que un colegio tiene como máximo 100 alumnos y cada alumno hace siempre 10 asignaturas.
Escribe la declaración de la estructura de datos que se llamará Tcolegio, necesaria para guardar toda la
información del colegio. En concreto, la estructura debe tener:
"	Un entero que será el identificador de colegio.
"	Un entero indicando el número de alumnos.
"	Un vector de elementos de tipo talumno, con la información de cada  alumno.
Declara una variable de tipo Tcolegio y escribe el código necesario para actualizar el campo pasa de todos
los alumnos del colegio (recuerda que el campo 'aprobado' debe ser true si el alumno ha aprobado
más de 6 asignaturas y false en caso contrario).

								HACER MENU Y VALIDACIONES
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<conio.h>


/*============================DECLARACION DE ESTRUCTURAS==================================*/

typedef struct									
			{
				int id;
				float notas[10];						//struct para cada alumno
				bool aprobado;							
			}Talumno;

typedef struct 
			{
				int id_colegio, cant_alumnos;			//struct para el colegio
				Talumno alumno[100];
				
			}Tcolegio;
			
/*============================DECLARACION DE FUNCIONES==================================*/	

void func_limpiar(Tcolegio *p);
int func_menu();
void func_datosColegio(Tcolegio *p);
				int func_IDcolegio();						//subfuncion de func_datosColegio
				int func_CANTalumnos();						//subfuncion de func_datosColegio
void func_datosAlumnos(Tcolegio *p);	
				int func_IDalumno(Tcolegio **pp);			//subfuncion de func_datosAlumnos		
				float func_NOTAalumno(int i);				//subfuncion de func_datosAlumnos
void func_aprobados(Tcolegio *p);				

/*=====================================FUNCIONES========================================*/		

int main()

	{
		Tcolegio escuela,*p=&escuela;				//si entendi bien la consigna es un colegio solo
		int menu;
		func_limpiar(p);
		do
			{
				menu=func_menu();
				switch(menu)
					{
						case 1:
							func_datosColegio(p);
							break;
						case 2:
							func_datosAlumnos(p);
							break;
						case 3:
							func_aprobados(p);
							break;
						case 4:
							break;	
					}
			}while(menu!=4);
		
		getch();
		return 0;
	}

void func_limpiar(Tcolegio *p)

	{			
		p->id_colegio=0;									// campos de la struct
		p->cant_alumnos=0;									//	Tcolegio.
		for(int i=0;i<100;i++)
			{
				p->alumno[i].id=0;							//'i' refiere a cada numero de alumno entre 1-100
				for(int j=0;j<10;j++)
					{	
						p->alumno[i].notas[j]=0;			//'j' refiere a cada nota 1-10 de cada alumno	
					} 	
			}
	}

int func_menu()

	{
		int menu=0;
		printf("=====================================\n");
		printf("1-Cargar datos de un colegio\n2-Cargar datos de un alumno\n3-Consultar ID de alumnos aprobados");
		printf("\n4-Salir\nSeleccion: ");
		scanf("%d",&menu);								//NO ESTABA SEGURO DE QUE COSAS MOSTRAR, ASI QUE
		if(menu<1 or menu>4)							//HICE QUE MUESTRE LAS ID DE LOS APROBADOS
			{
				printf("\n\n\tERROR!!: La opcion seleccionada no existe.\n\n");
				func_menu();
			}
		return menu;
	}
	
void func_datosColegio(Tcolegio *p)
	{
		p->id_colegio=func_IDcolegio();					//En estas funciones, primero compruebo los valores	
		p->cant_alumnos=func_CANTalumnos();				//ingresados antes de agregarlos a los campos
		printf("\n\n");									//La carga de los alumnos esta mas abajo..
	}

/*=========================COMIENZO DE SUBFUNCIONES DE 'func_datosColegio'==============================*/

	
int func_IDcolegio()
	{
		int id;
		do
			{
				printf("\nIngrese la ID del colegio: ");
				scanf("%d",&id);
				if(id<1)
					{
						printf("\n\n\t\t\tERROR!!: El numero minimo de ID debe ser 1.\n\n");
					}
			}while(id<1);
		return id;	
	}	

int func_CANTalumnos()

	{
		int cant;
		do
			{
				printf("Ingrese la cantidad de alumnos: ");
				scanf("%d",&cant);
				if(cant<1 or cant>100)
					{
						printf("\n\n\t\tERROR!!: Cantidad minima debe ser 1, la maxima 100.\n\n");
					}
			}while(cant<1 or cant>100);
		return cant;
	}	
	
/*=========================FIN DE SUBFUNCIONES DE 'func_datosColegio'==============================*/

void func_datosAlumnos(Tcolegio *p)
	
	{
		if(p->id_colegio==0)					
			{
				printf("\n\n\t\tERROR!!: El colegio aun no ha sido cargado en el sistema.\n\n");
			}
		else
			{
				Tcolegio **pp=&p;				//No se si es la forma mas practica, pero fue lo que se
				int id=func_IDalumno(pp);		//me ocurrio para poder separar en funciones mas chicas..
				p->alumno[id-1].id=id;			//Primero verifico que la ID sea valida antes de guardarla
				for(int i=0;i<10;i++)								//Ya teniendo la ID, simplemente completo
					{													//los campos. El (-1) es por que la ID
						p->alumno[id-1].notas[i]=func_NOTAalumno(i);	//comienza desde 1, pero el vector 
																		//desde 0	
					}
				printf("\n\n");	
			}
	}
	
/*=========================COMIENZO DE SUBFUNCIONES DE 'func_datosAlumnos'==============================*/

int func_IDalumno(Tcolegio **pp)

	{
		int id;
		do
			{
				printf("Ingrese la ID del alumno que desea agregar: ");
				scanf("%d",&id);
				if(id<1 or id>(**pp).cant_alumnos)
					{
						printf("\n\n\t\tERROR!!: La id debe estar por debajo de la cantidad de alumnos.\n\n");
					}
			}while(id<1 or id>(**pp).cant_alumnos);				//NO ENTIENDO BIEN POR QUE SE USA
		printf("\n\n");											//EL PUNTO EN LUGAR DE LA FLECHA
		return id;												
	}	
	
float func_NOTAalumno(int i)		//Traigo 'i' solo para mostrar el numero de asignatura a agregar

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
	
/*=========================FIN DE SUBFUNCIONES DE 'func_datosAlumnos'==============================*/

void func_aprobados(Tcolegio *p)

	{
		int ingresos=0,materias_aprobadas=0;							//2 contadores	
		for(int i=0;i<p->cant_alumnos;i++)
			{
				if(p->alumno[i].id!=0)									//Busco si hay alguna ID ingresada
					{													//para dar un mensaje de error
						ingresos++;
					}
			}
		if(ingresos==0)						
			{
				printf("\n\n\t\tERROR!!:Ningun alumno ha sido cargado en el sistema.\n\n");
			}
		else	/*---------SI HAY ID, AHORA BUSCO CUANTOS APROBARON MAS DE 6 ASIGNATURAS----------*/
			{
				for(int i=0;i<p->cant_alumnos;i++)
					{
						materias_aprobadas=0;							//Para que reinicie el contador
						for(int j=0;j<10;j++)							//por cada alumno
							{
								if(p->alumno[i].notas[j]>=7)			//Por cada alumno, cuento cuantas
									{									//materias aprobo
										materias_aprobadas++;
									}
									
							}
						p->alumno[i].aprobado=materias_aprobadas>6;		//Definicion de la variable booleana							
					}
			printf("\n\nID de alumnos que aprobaron\n---------------------------\n\n");	
			for(int i=0;i<p->cant_alumnos;i++)							
				{
					if(p->alumno[i].aprobado==1)						//Mostrando las ID de los que aprobaron
						{
							printf("%d ",p->alumno[i].id);
						}
				}	
			}
		printf("\n\n");				
	}

