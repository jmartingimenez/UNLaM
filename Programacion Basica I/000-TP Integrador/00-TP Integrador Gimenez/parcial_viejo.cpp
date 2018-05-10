#include<stdio.h>
#include<conio.h>

int cantidad[10][5];

void limpieza(int *ptr);
int funcion_articulo();
int funcion_deposito();
void funcion_cantidad(int art,int dep);
void estadisticas(int *ptr);

int main()

{
	int art=0,dep=0,cant=0,articulo[10],*ptr;
	ptr=articulo;
	limpieza(ptr);
	while(dep!=999)
		{
			dep=funcion_deposito();		
			if(dep!=999)
				{
					art=funcion_articulo();
					articulo[art-1]=art;
					funcion_cantidad(art,dep);	
				}	
		}
	estadisticas(ptr);
	getch();
	return 0;
}

void limpieza(int *ptr)

{
	int i=0,j=0;
	for(i=0;i<10;i++)
		{
			*(ptr+i)=0;//Limpiando el vector, funciona tambien poner 'ptr[i]=0'
			for(j=0;j<5;j++)
				{
					cantidad[i][j]=0;
				}
		}
}

int funcion_deposito()

{
	int dep=0;
	while((dep<1)||(dep>5)&&(dep!=999))
		{
			printf("Ingrese el codigo de deposito -el rango es entre 1 y 5-: ");
			scanf("%d",&dep);
			if((dep<1)||(dep>5)&&(dep!=999))
				{
					printf("\n\t\t\tERROR!!: Codigo de deposito incorrecto\n");
				}
		}
	return dep;	
}

int funcion_articulo()

{
	int art=0;
	while((art<1)||(art>10))
		{
			printf("Ingrese el codigo de articulo -el rango es entre 1 y 10-: ");
			scanf("%d",&art);
			if((art<1)||(art>10))
				{
					printf("\n\t\t\tERROR!!: Codigo de articulo incorrecto\n");
				}
		}
	return art;	
}

void funcion_cantidad(int art,int dep)

{
	int cant=0;
	printf("Ingrese la cantidad del articulo %d que llevara el deposito %d: ",art,dep);
	scanf("%d",&cant);
	cantidad[art-1][dep-1]+=cant;
}

void estadisticas(int *ptr)

{
	int i=0,j=0,dep_mayor=0,dep_nummayor=0,suma_cant=0;
	for(j=0;j<5;j++)
		{
			for(i=0;i<10;i++)
				{
					suma_cant+=cantidad[i][j];
				}
			if(suma_cant>dep_mayor)
				{
					dep_mayor=suma_cant;
					dep_nummayor=j+1;
				}
			suma_cant=0;				
		}
	printf("\n\nArticulo\tD1\tD2\tD3\tD4\tD5\n");
	printf("----------------------------------------------------------\n");
	for(i=0;i<10;i++)
		{
			if(*(ptr+i)!=0)
				{
					printf("\n%d\t\t",*(ptr+i));
					for(j=0;j<5;j++)
						{
							if(cantidad[i][j]!=0)
								{
									printf("%d",cantidad[i][j]);							
								}
							printf("\t");
						}
				}
		}
	printf("\n\nEl deposito que mas recibio fue el %d con una cantidad de %d.",dep_nummayor,dep_mayor);	
}

