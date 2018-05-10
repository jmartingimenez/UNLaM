#include<stdio.h>
#include<conio.h>

int suma(int a,int b);
int mayor(int a,int b);

int main()

{
	int a=0,b=0,s,m;
	printf("Ingrese un numero: ");
	scanf("%d",&a);
	printf("Ingrese otro numero: ");
	scanf("%d",&b);
	s=suma(a,b);
	printf("La suma da %d",s);//printf("da %d",suma(a,b));
	m=mayor(a,b);//siendo 0 validar
	printf("El mayor es %d",m);
	getch();
	return 0;
}

int suma(int a,int b)

{
	int sum=0;
	sum=a+b;
	return(sum);//return(a+b);
}

int mayor(int a,int b)
{
	if(a==b)
		{
			return 0;
		}
	else
		{
			if(a>b)
				{
					return a;
				}
			else
				{
					return b;
				}	
		}	
}
