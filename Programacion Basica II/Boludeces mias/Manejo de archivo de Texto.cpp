#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
	{
		char nombre[10];
		int edad;
	}DATO;
	
int main()

	{
		FILE *archivo;
		DATO alumno;
		int opc;
		
		/*CREANDO EL ARCHIVO*/
		
		printf("Creando el archivo de texto.\n");
		archivo=fopen("algoentexto.txt","w");
		fclose(archivo);
		printf("Archivo de texto creado.\n");
		
		/*ESCRIBIENDO EN EL ARCHIVO*/
		
		printf("Escribiendo en el archivo\n");
		archivo=fopen("algoentexto.txt","w");
		do														
			{
				fflush(stdin);												
				printf("Ingrese nombre: ");
				gets(alumno.nombre);
				printf("Ingrese edad: ");
				scanf("%d",&alumno.edad);
				fprintf(archivo,"%s\t%d\n",alumno.nombre,alumno.edad);		//Escribimos los datos guardados
																			//con el formato que se me canta
				printf("\n\n\t\tPulse 0 para finalizar, otro numero para continuar\n\t\tSeleccion: ");
				scanf("%d",&opc);				
			}while(opc!=0);
		fclose(archivo);
		
		/*LEYENDO DATOS DESDE EL ARCHIVO*/
		
		printf("leyendo el archivo\n");
		char aux[80];									//Vamos a leer linea por linea y guardar su contenido
														//en este array (vector) auxiliar
														//El tamaño maximo de caracteres que salen por pantalla
														//horizontalmente es 80
														
		archivo=fopen("algoentexto.txt","r");
		rewind(archivo);								//nos paramos al inicio del archivo
		fgets(aux,80,archivo);							//Guardamos en nuestro array auxiliar 80 caracteres
														//leidos desde la posicion actual del puntero del
														//archivo (seguro q con fseek se debe poder jugar con
														//esto para realizar modificaciones pero es un
														//quilombito)
		while(!feof(archivo))							//Mientras no se llege al final del archivo...
			{
				printf("%s",aux);						//Que imprima la cadena (osea, toda la linea)
				fgets(aux,80,archivo);					//Volvemos a 'scanear' la linea siguiente
			}
		fclose(archivo);
		
		/*BUSCANDO UN DATO EN EL ARCHIVO*/
		
		archivo=fopen("algoentexto.txt","r");
		rewind(archivo);
		char busqueda[2];								//Vamos a guardar la edad a buscar, puse solo de 2
														//elementos por que asumo que no escribiras alguien con
														//mas de 100 años, pero haciendo mas largo el array no
														//deberia dar problemas
		fflush(stdin);
		printf("Ingrese la edad para ver una persona que la tenga: ");
		gets(busqueda);
		fgets(aux,80,archivo);							
		while(!feof(archivo))
			{
				if(strstr(aux,busqueda)!=NULL)			//'strstr' lo que hace basicamente es buscar una cadena
														//dentro de otra. En ese if le estamos diciendo que
														//recorra la cadena 'aux' y busque coincidencia con
														//lo ingresado en 'busqueda'. Si no se encontro
														//coincidencia devuelve NULL. Entonces la idea del if
														//es que si no devuelve NULL (existe coincidencia)
														//se muestre la linea leida actualmente guardada en
														//'aux' y depaso que rompa el ciclo y salga del while
					{
						printf("%s",aux);				//mostramos la linea actual que es la que tiene la
														//coincidencia
						break;
					}
				fgets(aux,80,archivo);					//sino, seguimos leyendo..
			}
		if(feof(archivo))								//si se pudo llegar al final es por que no se encontro
			{											//nada
				printf("No se encontro ninguna persona con la edad ingresada.");
			}	
		fclose(archivo);
		getch();
		return 0;
	}	
	
	
/*
NOTA:
	-No estoy seguro si hay que poner fflush antes de un fgets(estamos leyendo una cadena dsp de todo)
	-Si queres separar esto en funciones, simplemente pasas como parametro el puntero al archivo
		o simplemente lo volves a declarar en cada funcion :)
*/	
