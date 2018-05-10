#include<stdio.h>
#include<conio.h>
int func_menu();
void func_cargar(int *p);
void func_mostrar(int *p);
void func_ordenar(int *p);
int main()

{
	int vector[5]={0,0,0,0,0},menu=0,*p=vector;
	do
	{
		menu=func_menu();
		switch(menu)
			{
				case 1:
					func_cargar(p);
					break;
				case 2:
					func_mostrar(p);
					break;
				case 3:
					func_ordenar(p);
					break;
				case 4:
					printf("ADIOS!!");
					break;
				default:
					printf("ERROR!!: Codigo incorrecto");
					break;
			}
	}while(menu!=4);
}

int func_menu()

{
	int menu=0;
	printf("\n\n1 - Cargar Vector\n2 - Ver Vector\n3 - Ordenar\n4 - Salir\nSeleccion: ");
	scanf("%d",&menu);
	return menu;
}

void func_cargar(int *p)

{
	int opcion=0;
	for(int i=0;i<5;i++)
		{
			printf("Asigne un valor para la posicion %d:\t",i);
			scanf("%d",&p[i]);			
			printf("\t\t\tDesea seguir agregando valores?\n\t\t\t1- Si\n\t\t\tCualquier otra opcion para salir\n\t\t\tSeleccion: ");
			scanf("%d",&opcion);
			if(opcion!=1)
				{
					break;
				}
		}
}

void func_mostrar(int *p)
	{
		for(int i=0;i<5;i++)
			{
				printf("pos%d:\t%d\n",&p[i],p[i]);
			}
	}
	
void func_ordenar(int *p)
	{
		int temp=0;
		for(int i=0;i<5;i++)
			{
				for(int j=0;j<4;j++)
					{
						if(p[j]>p[j+1])
							{
								temp=p[j];
								p[j]=p[j+1];
								p[j+1]=temp;
							}
					}
			}
		printf("Ordenado!!");	
	}	
