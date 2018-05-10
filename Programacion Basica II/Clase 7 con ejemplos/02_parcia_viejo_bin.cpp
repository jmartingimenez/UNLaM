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

/*
Declaracion de una estructura llamada 'Talumno' con 2 campos, un char y un float
Si nosotros creamos una variable de tipo Talumno llamada 'alumno', esta variable actuara
como un registro, este registro 'alumno' contara con los dos campos. Encontes...
¿Cual seria el tamaño de esta variable 'alumno' de tipo Talumno?
Recordemos que un char ocupa 1 byte mientras que un float ocupa 4 bytes
La situacion nos dice que tenemos una cadena de 20 caracteres, por lo que...

				1*21		=		21 bytes
	(1 byte extra por que las cadenas tiene el caracter '0/' para indicar el final)
				
Sumado a la variable float..

		21 bytes + 4 bytes	=		25 bytes
				
Por ende... 	

			Cuando hablamos de sizeof(alumno) o sizeof(Talumno) estamos hablando de 25 bytes..	
				
					
************************Comprobacion de existencia del archivo

		if((arch=fopen("listado.bin","rb"))==NULL)				
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				//Lo que quieras hacer con el archivo
			}
				

-Cuando nosotros abrimos un archivo			arch=fopen(.....)
					La funcion fopen devuelve un valor, si el archivo no puede leerse devuelve NULL
						
			Lo que aca comprobamos es que el archivo devuelva NULL. Si lo hace es que el archivo no
			pudo ser leido, entonces damos el mensaje de error. De lo contrario, ahi ya hacemos lo que
			sea que necesitamos hacer...					
			

************************Explicacion del strcmp							

		if(strcmp(alumno.nombre,aux)==0)	
			{
				break;						
			}
		else
			{
				fread(&alumno,sizeof(alumno),1,arch);	
			}

strcmp(alumno.nombre,aux)				=			Estamos comparando 2 cadenas. Esto devuelve un valor, el
													que nos interesa es cero, que es el valor que devuelve 
													cuando las cadenas son exactamente iguales.
													Entonces si la coincidencia existe rompemos para salir
													del bucle completamente por que al encontrar coincidencia
													no necesitamos seguir leyendo.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int func_menu();										//Declaracion de funciones
void func_carga(FILE *arch);							//Como las variables, incluyendo la variable
void func_leer(FILE *arch);								//'alumno' actua practicamente como auxilar
void func_cambiar(FILE *arch);							//no necesito pasarla como paramentro, solo el
														//puntero el archivo basta

int main()

	{
		int menu;
		FILE *arch;
		do
			{
				menu=func_menu();						//Menu...
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
	
int func_menu()							//Menu, retorna un valor que sera usado en el switch de arriba
	
	{
		int menu;
		printf("1-Cargar datos\n2-Leer datos\n3-Cambiar nota\n4-Salir\nSeleccion: ");
		scanf("%d",&menu);
		return menu;
	}	
	
void func_carga(FILE *arch)

	{
		int menu;								//Varible para este submenu
		char seguir=1;							//Opcion para decidir si seguir agregando datos
		Talumno alumno;							//Variable de tipo Talumno llamada 'alumno'
		printf("1-Generar un nuevo listado\n2-Agregar datos\nSeleccion: ");
		scanf("%d",&menu);
		switch(menu)
			{
				case 1:
					arch=fopen("listado.bin","wb");				//Se abre el archivo en modo escritura-binaria
					break;
				case 2:
					if((arch=fopen("listado.bin","rb"))==NULL)
						{
							printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
							break;
						}
					else
						{
							arch=fopen("listado.bin","ab");		//Se abre el archivo en modo append-binario
						}								
					break;
			}
		if(menu==1 or menu==2)									//Para que solo salga si se eligio alguna de
																//las 2 opciones
			{
				while(seguir==1)								//auxiliar para decidir si seguir..
					{
						printf("Ingrese el nombre del alumno: ");
						scanf("%s",&alumno.nombre);				//Se guarda un campo
						printf("Ingrese la nota del alumno: ");
						scanf("%f",&alumno.nota);				//Se guarda el otro campo
						fwrite(&alumno,sizeof(alumno),1,arch);	//Se escribe un registro
						printf("Para seguir agregando datos pulse 1/otra tecla para salir\nSeleccion: ");
						scanf("%s",&seguir);
					}	
			}
		fclose(arch);											//Se cierra el archivo		
	}
	
void func_leer(FILE *arch)

	{
		if((arch=fopen("listado.bin","rb"))==NULL)				//EXPLICADO ARRIBA
			{
				printf("\n\n\t\tERROR!!: El archivo no puede leerse. Existe?\n\n");
			}
		else
			{
				arch=fopen("listado.bin","rb");
				Talumno alumno;									//Se vuelve a crear la variable para guardar
																//los campos leidos desde el archivo
				rewind(arch);
				fread(&alumno,sizeof(alumno),1,arch);			//Se lee el primer registro		
				while(!feof(arch))
					{
						printf("%s\t%.2f\n",alumno.nombre,alumno.nota);	//Se muestran los campos que ahora
																		//tienen los datos leidos desde el
																		//archivo					
						fread(&alumno,sizeof(alumno),1,arch);	//Se lee el registro siguiente
					}
				fclose(arch);									//Se cierra el archivo
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
				char aux[20];									//Vamos a reemplazar buscando por nombre
																//Esta variable guarda el nombre a buscar
																//Fijate que el tamaño es el mismo (20)
				printf("Ingrese el nombre del alumno a modificar su nota: ");
				scanf("%s",&aux);
				arch=fopen("listado.bin","rb+");				
				rewind(arch);
				fread(&alumno,sizeof(alumno),1,arch);			//Se lee el primer registro
				while(!feof(arch))
					{
						if(strcmp(alumno.nombre,aux)==0)		//Si hay coincidencia entre el campo leido
																//desde el archivo y la nueva cadena
																//ingresada que es la que se busca
																//(EXPLICADO MAS ARRIBA)
							{
								break;							//salir del while
							}
						else
							{
								fread(&alumno,sizeof(alumno),1,arch);	//Que lea un nuevo registro
							}	
							
					}
				if(feof(arch))
					{
						printf("\n\n\t\tERROR!!: no se encontro el nombre\n\n");	//No se encontro
					}
				else
					{
						fseek(arch,(-1)*sizeof(alumno),SEEK_CUR);			//Nos posicionamos al comienzo
																			//del registro
						printf("Ingrese la nueva nota: ");
						scanf("%f",&alumno.nota);
						fwrite(&alumno,sizeof(alumno),1,arch);				//Escribimos el registro modificado
																			//(VER NOTA ABAJO)
					}	
				fclose(arch);							//Se cierra el archivo
			}
	}


/*
fwrite(&alumno,sizeof(alumno),1,arch);

Recordemos como pusimos arriba, 'alumno' ocupa 25 bytes. En este ultimo fwrite de reemplazo, nosotros cambiamos
solo la nota... 
				
			¿Como es que el nombre se mantiene igual si estamos escribiendo un nuevo registro?
				
Recordemos que creamos nuevamente en esta funcion la variable 'alumno' q obviamente no tiene datos cargados.
Cuando vamos leyendo un registro, se almacena en cada campo los datos leidos desde el archivo.
Si el primer registro leido contenia la cadena 'pepe' (recordemos que esto ocupa 21 bytes
ya que las posiciones de la cadena sin llenar quedaron reservados) y el float tiene la nota (8.5))
Ahora los campos quedaran asi..

		alumno.nombre="pepe"
		alumno.nota="8.5"
		
En el else de reemplazo cambiamos el valor de alumno.nota (supongamos por 6.7) ahora tendremos esto..

		alumno.nombre="pepe"
		alumno.nota="6.7"
		
Con el fwrite escribimos un registro que sobreescribe el anterior pero como se ve arriba, el nombre "pepe"
esta guardado por lo que quedara intacto		:)		
*/			
