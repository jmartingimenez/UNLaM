/*ESTE PROGRAMA CREA/ABRE UN ARCHIVO, GUARDA NUMEROS Y LUEGO LOS VISUALIZA*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()

	{
		FILE *p_arch;													//Puntero al archivo
		int num;														//Numero a escribir
		char nombre[20],extension[5]=".txt";
		
/*ELIJIENDO NOMBRE DE ARCHIVO*/
		printf("Elija un nombre para el archivo: ");
		gets(nombre);
		strcat(nombre,extension);
												
/*ABRIENDO o CREANDO EL ARCHIVO*/
		
		/*
		if((p_arch=fopen("EJERCICIO1.txt","w+"))==NULL)			//Verificando si no podemos leer/escribir
			{
				printf("Parece ser que el archivo no existe. Uno nuevo se ha creado.\n");
			}
		else
			{
				printf("El archivo ya existe.\n");
			}
		*/					//<----	ESTE IF ES PARA SI QUERES DARLE UN NOMBRE ESPECIFICO (linea 22)
		
		p_arch=(fopen(nombre,"w"));
			
/*AGREGANDO DATOS AL ARCHIVO*/
			
		printf("\n\nIngrese numeros y estos seran guardados en el archivo.\nPulse 0 para terminar:\n");
		scanf("%d",&num);
		while(num)
			{
				fprintf(p_arch,"%d\n",num);
				scanf("%d",&num);									//Escribiendo datos en el archivo
			}
			
/*CERRANDO EL ARCHIVO*/	
		
		//fclose(p_arch);						//<---Si no me interesara ver algun error
		int fclose(FILE *p_arch);									//PARA VER QUE VALOR DEVUELVE Y DAR UN MSJ
		if(fclose(p_arch)==-1)
			{
				printf("\n\nERROR!!: El archivo no pudo cerrarse.\n");
			}
		else
			{
				printf("\n\nEl archivo se cerro exitosamente.\n");
			}
			
/*ABRIENDO NUEVAMENTE EL ARCHIVO PARA SU LECTURA*/	

		printf("Lectura del archivo.\n\n");	
		p_arch=fopen(nombre,"rb");							//Abriendo el archivo nuevamente
		fscanf(p_arch,"%d",&num);										//Leyendo los datos del archivo
	    while(!feof(p_arch))											//VER ESTO, XQ SE GUARDA	
	    	{		//SI YO ESCRIBO 7 NUMEROS Y DESPUES SOBREESCRIBO Y PASO ESTA CIFRA, SOLO VE HASTA EL 7
	    		printf("%d ",num);
	    		fscanf(p_arch,"%d",&num);
			}
		fclose(p_arch);
		getch();
		return 0;	
	}
