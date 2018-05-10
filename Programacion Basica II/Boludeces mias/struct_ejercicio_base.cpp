#include<stdio.h>
#include<conio.h>
#include<string.h>

struct alumno//Declaramos una estructura llamada alumno
	{
		char alumno[40];			//Las variables que contiene la estructura
		int edad;
		float nota;
	};

int main()

{
	struct alumno a1;//Creamos una variable 'a1' para la estructura alumno
	
	/*TE PERMITE USAR a1.alumno, a1.edad, a1.nota*/
	
	char alumno_aux[40];//Hay que usar un auxiliar para el nombre, no se bien xq todavia
	printf("Ingrese el nombre del alumno: ");
	gets(alumno_aux);
	strcpy(a1.alumno,alumno_aux);//pasando el nombre del auxiliar a la variable de la estructura
	printf("Ingrese la edad de %s: ",a1.alumno);//Pidiendo la edad
	scanf("%d",&a1.edad);
	printf("Ingrese la nota de %s: ",a1.alumno);//Pidiendo la nota
	scanf("%f",&a1.nota);
	printf("\n\nAlumno: %s\nEdad: %d\nNota: %.2f",a1.alumno,a1.edad,a1.nota);//Mostrando	
 	getch();
	return 0;
}

