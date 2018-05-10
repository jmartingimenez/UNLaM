/*	(enunciado)
Escribir numeros e irlos sumando (con 999 terminara el programa y mostrara los resultados)
-Suma de todos los numeros
-Mayor numero
-Menor numero
*/
#include<stdio.h>
#include<conio.h>

int n=0,resu=0,may=NULL,men=NULL,*ptr=NULL;

int suma(int *ptr);
int mayor(int *ptr);
int menor(int *ptr);
void stats(int may,int men,int resu);

int main()

{
	while(n!=999)
		{
			printf("Ingrese un numero: ");
			scanf("%d",&n);
			if(n==999)
				{
					break;
				}
			else
				{
					ptr=&n;
					resu=suma(ptr);
					may=mayor(ptr);
					men=menor(ptr);					
				}	
		}
	stats(may,men,resu);
	getch();
	return 0;
}

int suma(int *ptr)

{
	return resu+*ptr;
}

int mayor(int *ptr)

{
	if(may==NULL)
		{
			return *ptr;
		}
	else
		{
			if(*ptr<=may)
				{
					return may;
				}
			else
				{
					return *ptr;
				}	
		}	
	
}

int menor(int *ptr)

{
	if(men==NULL)
		{
			return *ptr;
		}
	else
		{
			if(*ptr>=men)
				{
					return men;
				}
			else
				{
					return *ptr;
				}	
		}	
	
}

void stats(int may,int men,int resu)

{
	printf("\n\nEl numero mas alto es: %d\n",may);
	printf("El numero mas bajo es: %d\n",men);
	printf("La suma de todos los numeros es: %d",resu);
}
