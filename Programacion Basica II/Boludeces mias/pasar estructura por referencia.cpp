#include<stdio.h>

struct HOLA
	{
		int id;
		int nota;
	};
	
typedef HOLA dato;

void comprobando(dato *ptr);

int main()

	{
		dato nuevo,*ptr=&nuevo;
		nuevo.id=5;
		nuevo.nota=10;
		printf("%d - %d\n\n",ptr->id,ptr->nota);
		comprobando(ptr);
		printf("%d - %d\n\n",ptr->id,ptr->nota);
		return 0;
	}
	
void comprobando(dato *ptr)

	{
		ptr->id=-3;
		ptr->nota=-8;
	}	
