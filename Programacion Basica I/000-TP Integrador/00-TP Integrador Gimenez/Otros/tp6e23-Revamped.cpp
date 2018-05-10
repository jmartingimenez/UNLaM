#include<stdio.h>
#include<conio.h>
#define FI 30
#define CO 3

int cantidad[30][3];

void func_limpiar(int *ptr);
int func_obra();
int func_material();
void func_cantidad(int obra,int mat);
int func_menu();
void func_mostrar(int *ptr);
void func_contarmat1();
void func_totalmat3();

int main()

{
	int edificio[30],*ptr=edificio,obra=0,mat=0,menu=0;
	func_limpiar(ptr);
	while(obra!=999)
		{
			obra=func_obra();
			if(obra!=999)
				{
					edificio[obra-1]=obra;
					mat=func_material();
					func_cantidad(obra,mat);					
				}
		}
	menu=func_menu();
	switch(menu)
		{
			case 1:
				func_totalmat3();
				break;
			case 2:
				func_contarmat1();
				break;
			case 3:
				func_mostrar(ptr);
				break;
		}
	getch();
	return 0;
}

void func_limpiar(int *ptr)

{
	int i=0,j=0;
	for(i=0;i<FI;i++)
		{
			ptr[i]=0;
			for(j=0;j<CO;j++)
				{
					cantidad[i][j]=0;
				}
		}
}

int func_obra()

{
	int obra=0;
	while((obra<1)||(obra>30)&&(obra!=999))
		{
			printf("Ingrese el edificio seleccionado -entre 1 y 30-: ");
			scanf("%d",&obra);
			if((obra<1)||(obra>30)&&(obra!=999))
				{
					printf("\n\t\tERROR!!: Codigo de edificio incorrecto.\n");
				}	
		}
	return obra;		
}

int func_material()

{
	int mat=0;
	while((mat<1)||(mat>3))
		{
			printf("Seleccione el tipo de material que desea -entre 1 y 3-: ");
			scanf("%d",&mat);
			if((mat<1)||(mat>3))
				{
					printf("\n\t\tERROR!!: Codigo de material incorrecto.\n");					
				}
		}
	return mat;	
}

void func_cantidad(int obra,int mat)

{
	int cant=0;
	printf("Ingrese la cantidad del material %d que desea para el edificio %d: ",mat,obra);
	scanf("%d",&cant);
	cantidad[obra-1][mat-1]+=cant;
}

int func_menu()

{
	int menu=0;
	while((menu<1)||(menu>3))
		{
			printf("\n\nSeleccione que desea\n-----------------------");
			printf("\n1-Mostrar la cantidad total de material 3 que se utiliza en todas las obras.");
			printf("\n2-Mostrar cuantas obras recibieron mas de 300 unidades del material 1");
			printf("\n3-Listar las cantidades de material que recibio cada obra\nSeleccion: ");
			scanf("%d",&menu);
			if((menu<0)||(menu>3))
				{
					printf("\n\t\t\tCodigo erroneo.\n");
				}	
		}
	return menu;
}

void func_totalmat3()

{
	int i=0,j=0,suma=0;
	for(i=0;i<FI;i++)
		{
			suma+=cantidad[i][2];
		}
	printf("\n\nSe uso una cantidad de %d del material 3 en todas las obras.",suma);
}

void func_contarmat1()

{
	int i=0,j=0,suma=0;
	for(i=0;i<FI;i++)
		{
			for(j=0;j<=0;j++)
				{
					if(cantidad[i][j]>300)
						{
							suma++;	
						}
				}
		}
	printf("Un total de %d obras recibieron mas de 300 unidades del material 1.",suma);	
}

void func_mostrar(int *ptr)

{
	int i=0,j=0;
	printf("\n\nEdificio\tMat1\tMat2\tMat3\n------------------------------------\n\n");
	for(i=0;i<FI;i++)
		{
			if(ptr[i]!=0)
				{
					printf("\n%d\t\t",ptr[i]);
					for(j=0;j<CO;j++)
						{
							if(cantidad[i][j]!=0)
								{
									printf("%d",cantidad[i][j]);
								}
							printf("\t");	
						}					
				}
		}
}

