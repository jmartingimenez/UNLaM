#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
	{
		char nombre[20];
		int edad;
	}DATO;

int main()

	{
		DATO persona;
		FILE *arch;
		printf("Ingrese el nombre: ");
		gets(persona.nombre);
		printf("Ingrese la edad: ");
		scanf("%d",&persona.edad);
		arch=fopen("datos.txt","w");
		fprintf(arch,"%s\n%d\n",persona.nombre,persona.edad);
		fclose(arch);
		
		arch=fopen("datos.txt","r");
		char aux[20];
		int age;
		fscanf(arch,"%s,%d",aux,age);
		printf("Nombre: %s\t\tEdad: %d",aux,age);
		fclose(arch);
		
		
		getch();
		return 0;
	}
