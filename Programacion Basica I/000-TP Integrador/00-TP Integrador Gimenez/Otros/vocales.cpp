/*
Ingresar una palabra y contar cuantas vocales tiene
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void func_palabra(char *ptr);
void func_stats(char *ptr);

int main()

{
	char *ptr=NULL,palabra[20];
	ptr=palabra;
	func_palabra(ptr);
	func_stats(ptr);
	getch();
	return 0;
}

void func_palabra(char *ptr)

{
	printf("Ingrese una palabra: ");
	gets(ptr);
}

void func_stats(char *ptr)

{
	int i=0,vocales[5],tam=strlen(ptr);
	for(i=0;i<5;i++)
		{
			vocales[i]=0;
		}
	strlwr(ptr);
	for(i=0;i<tam;i++)
		{
			switch(ptr[i])
				{
					case 'a':
						vocales[0]++;
						break;
					case 'e':
						vocales[1]++;
						break;
					case 'i':
						vocales[2]++;
						break;
					case 'o':
						vocales[3]++;
						break;
					case 'u':
						vocales[4]++;
						break;																								
				}
		}
	printf("\n\nA\tE\tI\tO\tU\n---------------------------------\n\n");
	for(i=0;i<5;i++)
		{
			if(vocales[i]!=0)
				{
					printf("%d\t",vocales[i]);
				}
			else
				{
					printf("\t");
				}	
			
		}	
}


