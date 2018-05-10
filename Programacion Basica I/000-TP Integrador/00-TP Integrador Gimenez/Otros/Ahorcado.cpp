#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void funcion_palabra(char *ptr);
int funcion_adivinar(char *ptr,char *ptr2,int tam,int x);
int funcion_tam(char *ptr);
void funcion_guiones(char *ptr2,int tam);
void funcion_mostrar(char *ptr,char *ptr2,int tam);

int main()

{
	int tam=0,x=0;
	char palabra[10],*ptr=NULL,*ptr2=NULL;
	ptr=palabra;
	funcion_palabra(ptr);
	tam=funcion_tam(ptr);
	char guiones[tam];
	ptr2=guiones;
	funcion_guiones(ptr2,tam);
	system("cls");//Para ocultar la palabra escrita
	printf("Seleccione la cantidad de vidas: ");
	scanf("%d",&x);
	while(x>0)
		{
			fflush(stdin);
			system("cls");
			x=funcion_adivinar(ptr,ptr2,tam,x);
		}
	funcion_mostrar(ptr,ptr2,tam);	
	getch();
	return 0;
}

void funcion_palabra(char *ptr)

{
	printf("Ingrese una palabra: ");
	gets(ptr);
}

int funcion_tam(char *ptr)

{
	return strlen(ptr);
}

void funcion_guiones(char *ptr2,int tam)

{
	int i=0;
	for(i=0;i<tam;i++)
		{
			ptr2[i]='_';//La segunda cadena se compone de los guiones
		}				//A medida que se va adivinando, se reemplaza el guion por la letra encontrada
}

int funcion_adivinar(char *ptr,char *ptr2,int tam,int x)

{
	int i=0,incognitas=0;
	char letra;
	for(i=0;i<tam;i++)
		{
			printf("%c ",ptr2[i]);//Mostrando los guiones con las letras adivinadas hasta el momento..
		}
	printf("\n\nVidas: %d\nIngrese una letra: ",x);//Mostrando vidas y pidiendo una letra
	scanf("%c",&letra);	
	for(i=0;i<tam;i++)
		{
			if(ptr[i]==letra)//Si la letra esta en el vector original donde se ingreso la palabra
				{
					ptr2[i]=letra;//Igualar el guion correspondiente a la letra
				}
			if(ptr2[i]=='_')//Si hay letras por descubrir...
				{
					incognitas++;//contar los guiones..
				}	
		}
	if(incognitas>0)//Si siguen habiendo letras por descubrir
		{
			return x-1;//Descontar una vida		
		}
	else
		{
			return 0;//Quitar todas las vidas para mostrar el resultado final
		}	
	
}

void funcion_mostrar(char *ptr,char *ptr2,int tam)

{
	system("cls");
	int i=0,errores=0;
	for(i=0;i<tam;i++)
		{
			if(ptr[i]!=ptr2[i])
				{
					errores++;//Viendo si cuando se terminaron las vidas, las 2 cadenas son iguales
				}
		}
	if(errores==0)
		{
			printf("Ganaste!!, La palabra es %s",ptr);
		}
	else
		{
			printf("Perdiste!!, La palabra es %s",ptr);
		}	
	
	
}

