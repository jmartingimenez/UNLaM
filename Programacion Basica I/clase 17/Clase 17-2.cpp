/*


Nota: OJO A ESTO!!.. 		*(ptr+i)	=/= 	*ptr+i
***El primero apunta 'i' direcciones mas adelante. El segundo apunta al mismo lugar pero le cambia
el valor..
ej... (palabra 'hola')
Si *ptr originalmente apunta  a una 'h', suponiendo que 'i' vale 1, con los parentesis, el puntero
apuntaria a la 'o'. Sin los parentesis, el puntero apuntaria al mismo lugar pero no seria 'h', sino 'i'
(el caracter que le sigue en el codigo ASCII)
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>


void palindromo(char *ptr,char *ptr2,int tam_real);
//Un puntero va al inicio de la palabra,otro al final(que se calcula con tam_real)
int main()

{
	int tam_real=0;//Para saber a donde va apuntar el segundo puntero
	char cadena[50],*ptr=NULL,*ptr2=NULL;
	printf("Ingrese una palabra: ");
	gets(cadena);
	tam_real=(strlen(cadena))-1;//el '-1-' es por que los vectores comienzan de 0 y no de 1
	ptr=cadena;//Apunta a la posicion 0
	ptr2=&cadena[tam_real];//Apunta a la posicion correspondiente al ultimo caracter ingresado
	palindromo(ptr,ptr2,tam_real);//Se llama a la funcion, llevando los punteros y el tamaño
	getch();
	return 0;
}

void palindromo(char *ptr,char *ptr2,int tam_real)

{
	int i=0,pal=0;//pal es un contador de 'no coincidencias'
	printf("\n\n");
	for(i=0;i<=tam_real;i++)
		{
			printf("%c\t%c\n",*(ptr+i),*(ptr2-i));//Mostrando las letras que son comparadas			
			if(*(ptr+i)!=*(ptr2-i))
				{
					pal++;//Si no hay coincidencia, aumenta el contador
				}
		}
	if(pal==0)//Si pal no aumento...
		{
			printf("\n\nLa palabra es un palindromo.");
		}
	else//de lo contrario...
		{
			printf("\n\nLa palabra no es un palindromo.");			
		}	
	
}
