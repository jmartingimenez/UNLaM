#include<stdio.h>
#include<conio.h>

int argumento(int n);

int main()

{
int n=0,a;
printf("Ingrese un numero: ");
scanf("%d",&n);
a=argumento(n);
if(a==0)
	{
		printf("El numero es par.");
	}	
else
	{
		printf("El numero es impar.");
	}	
getch();
return 0;	
}

int argumento(int n)

{
	int re=0;
	re=n%2;
	if(re==0)
		{
			return 0;
		}
	else
		{
			return 1;
		}	
}
