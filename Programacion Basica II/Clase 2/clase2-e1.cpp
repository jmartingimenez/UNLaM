#include<stdio.h>
#include<conio.h>
void func_mostrar(int *p);
int main()
{
	int n=10,*p=&n;
	func_mostrar(p);
	getch();
	return 0;
}

void func_mostrar(int *p)
	{
		printf("Direccion: %d\nContenido: %d",&p,*p);
	}
