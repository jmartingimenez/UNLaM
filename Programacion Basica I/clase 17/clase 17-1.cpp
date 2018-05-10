#include<stdio.h>
#include<conio.h>
#include<string.h>

void vocales(char *ptr);

int main()

{
	char *ptr=NULL;
	char palabra[20];
	printf("Ingrese una palabra: ");
	gets(palabra);
	ptr=palabra;
	vocales(ptr);
	getch();
	return 0;
}

void vocales(char *ptr)

{
	int i=0,vocal[5];
	for(i=0;i<5;i++)
		{
			vocal[i]=0;
		}
	for(i=0;i<20;i++)
		{
			switch(*(ptr+i))
				{
					case 'a':
						vocal[0]++;
						break;
					case 'e':
						vocal[1]++;
						break;
					case 'i':
						vocal[2]++;
						break;
					case 'o':
						vocal[3]++;
						break;
					case 'u':
						vocal[4]++;
						break;
				}
		}
	printf("\nCantidad de 'A': %d",vocal[0]);	
	printf("\nCantidad de 'E': %d",vocal[1]);
	printf("\nCantidad de 'I': %d",vocal[2]);
	printf("\nCantidad de 'O': %d",vocal[3]);
	printf("\nCantidad de 'U': %d",vocal[4]);				
}


