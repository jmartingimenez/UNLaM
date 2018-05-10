/*	(enunciado)
Escribe un programa que muestre y realice el siguiente menu de opciones:
	1-Carga de datos
	2-Ingresar notas
	3-Lista de alumnos aprobados
	4-Fin
Cargar datos: Matricula, especialidad (de 1 a 100)
Ingresar notas: Dada la matricula se colocaran 3 notas. Emitir un mensaje de error si no se encontro la
matricula
Listar todos los datos de los alumnos cuyas 3 notas sean superiores a 4	
---------------------------------
***Nota: No especifica un limite de matriculas, esto me jode xq no se como relacionar entre si los
vectores y la matriz. Incluso, sin saber un limite, no se como guardaria las matriculas -necesito un vector
minimo-. Por eso puse que el numero de matricula este al igual que la especialidad entre 1 y 100.
(Asi los 2 vectores y la matriz tienen 100 filas y es mas facil relacionar todo)
***Nota2: Quizas en vez de 2 vectores y una matriz se podia hacer todo en 1 matriz de 2(para alumno
y especialidad), otra matriz como hice aca para las notas, o todo en una sola matriz (es cosa de probar)..
*/
#include<stdio.h>
#include<conio.h>
#define TAM 100
#define CANT 3

main()

{
int i=0,j=0,menu=0,numero_alumno=0,numero_especialidad=0,especialidad[TAM],alumno[TAM];
float notas[TAM][CANT];
for(i=0;i<TAM;i++)//Limpiando vectores
	{
		especialidad[i]=0;
		alumno[i]=0;
	}
for(i=0;i<TAM;i++)//Limpiando array
	{
		for(j=0;j<CANT;j++)
			{
				notas[i][j]=0;
			}
	}
		
while(menu!=4)
	{
		printf("\nSeleccione la opcion deseada\n------------------------\n\n");
		printf("1-Carga de los datos\n2-Ingresar notas\n3-Listar materias aprobadas\n4-Fin\n");
		printf("\nSeleccion: ");
		scanf("%d",&menu);
		switch(menu)
			{
				case 1:
					do
						{
							printf("Ingrese numero de matricula -Entre 1 y 100-: ");//Ver nota
							scanf("%d",&numero_alumno);									
						}while((numero_alumno<1)||(numero_alumno>100));
					alumno[numero_alumno-1]=numero_alumno;
					printf("Ingrese la especialidad -de 1 a 100-: ");
					scanf("%d",&numero_especialidad);
					if((numero_especialidad>=1)&&(numero_especialidad<=100))
						{
							especialidad[numero_alumno-1]=numero_especialidad;
						}
					else
						{
							printf("La especialidad solo puede estar entre 1 y 100.");
						}	
					break;
				case 2:
					printf("Seleccione el numero de matricula al cual se le ingresaran las notas: ");
					scanf("%d",&numero_alumno);
					if(alumno[numero_alumno-1]<1)
						{
							printf("ERROR!!: No se encontro la matricula");
						}
					else
						{
							for(i=0;i<CANT;i++)
								{
									printf("Ingrese la nota numero %d: ",i+1);
									scanf("%f",&notas[numero_alumno-1][i]);
								}
						}	
					break;
				case 3:
					printf("Se muestran solo las notas de los alumnos que obtuvieron las 3 notas >4\n");
					printf("Num Matricula\tEspecialidad\tNota 1\tNota 2\tNota3\n");
					printf("------------------------------------------------------\n\n");
					for(i=0;i<TAM;i++)
						{
							for(j=0;j<CANT;j++)
								{
									if((notas[i][j]>4)&&(notas[i][j+1]>4)&&(notas[i][j+2]>4))
										{
											printf("\n\t%d\t\t%d\t%.2f\t%.2f\t%.2f",alumno[i],especialidad[i],notas[i][j],notas[i][j+1],notas[i][j+2]);
										}
								}
						}
					break;
				default:
					break;		
			}
	}	
getch();
return(1);	
}
