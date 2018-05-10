/*=======================================================================================
Ejercicio 1: Escribe la declaración de un tipo de estructura que se llamará Talumno, con la siguiente información:
Identificador de alumno: 	un entero
Sexo: 	un carácter ('M'- 'F'- 'O') (Ingrese todas las opciones conocidas)
Notas: 	un vector de 10 reales que contiene las notas del alumno en las 10 asignaturas.
Aprobado: 	un booleano (cierto o falso) que nos dice si el alumno puede pasar o no de curso

Escribe la declaración de una variable llamada 'alumno' de tipo 'Talumno',
y el código necesario para poner el campo 'aprobado' de esa variable a 'true' si el alumno ha aprobado
más de 6 asignaturas o a false en caso contrario.

								HACER MENU Y VALIDACIONES..
===========================================================================================*/

#include<stdio.h>
#include<conio.h>

typedef struct
				{
					int id;
					char sexo;
					float notas[10];
					bool aprobado;				
				}Talumno;
												 
void func_limpiar(Talumno *p);					
int func_menu();								
void func_datos(Talumno *p);
			int func_cargaID();					//subfuncion de func_datos
			char func_cargaSEXO();				//subfuncion de func_datos
			float func_cargaNOTA(int i);		//subfuncion de func_datos	
void func_aprobar(Talumno *p);				

int main()

	{
		Talumno alumno,*p=&alumno;
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
							func_aprobar(p);
							break;
						case 3:
							break;
					}
			}while(menu!=3);
		getch();	
		return 0;
	}
	
void func_limpiar(Talumno *p)

	{
		for(int i=0;i<10;i++)
			{
				p->notas[i]=0;
			}
	}	
	
int func_menu()

	{
		int menu=0;
		printf("=========================\n");
		printf("1-Cargar datos del alumno\n2-Consultar si el alumno aprobo\n3-Salir\nSeleccion: ");
		scanf("%d",&menu);
		if(menu<1 or menu>3)
			{
				printf("\n\n\tERROR!!: La opcion seleccionada no existe.\n\n");
				func_menu();
			}
		return menu;	
	}	
	
void func_datos(Talumno *p)

	{
		p->id=func_cargaID();						//Dentro de estas funciones primero, compruebo si los							
		p->sexo=func_cargaSEXO();					//valores son correctos antes de asignarlos a 'alumno'
		for(int i=0;i<10;i++)				
			{
				p->notas[i]=func_cargaNOTA(i);		//la 'i' solo la llevo para ver el numero de 
			}										//asignatura a rellenar
	}	
	
/*===============================COMIENZO DE SUBFUNCIONES DE 'func_datos'====================================*/

int func_cargaID()

		{
			int id=0;
			do
				{
					printf("Ingrese la ID del alumno: ");
					scanf("%d",&id);
					if(id<1)
						{
							printf("\n\t\tERROR!!: El numero minimo de ID debe ser 1\n\n");
						}
				}while(id<1);
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
		
void func_aprobar(Talumno *p)

	{
		if(p->notas[0]==0)						//Ya que ninguna nota puede ser 0, aprovecho esto para
			{									//comprobar si los datos del alumno ya fueron ingresados
				printf("\n\n\tERROR!!: El alumno aun no ha sido cargado en el sistema.\n\n");
			}
		else
			{
				int pasa=0;							//contador de notas aprobadas
				for(int i=0;i<10;i++)
					{
						if(p->notas[i]>=7)
							{
								pasa++;
							}
					}
				p->aprobado=pasa>6;			//definiendo el valor de la variable booleana
				if(p->aprobado==1)
					{
						printf("El alumno HA aprobado mas de 6 asignaturas, paso el curso.\n\n");
					}	
				else
					{
						printf("El alumno NO aprobo mas de 6 asignaturas, no paso el curso.\n\n");
					}
			}	
	}
	
