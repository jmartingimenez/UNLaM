#include<stdio.h>
#include<conio.h>

void suma(int a,int b);
void mayor(int a,int b);

int main()

{
	int a=0,int b=0;
	printf("ingrese numero");
	scanf("%i",&a);
	printf("ingrese otro numero");
	scanf("%i",&b);
	suma(a,b);
	mayor(a,b);
	getch();
	return(1);
}
void suma(int a,int b);
{
	int sum=0;
	sum=a+b;
	printf("la suma da %d",sum);
	
}
void mayor(int a,int b);
{
	if(a==b)
	printf("son iguales");
	else
	{
		if(a>b)
		printf("a es mayor %d",a);
		else
		printf("b es mayor %d",b);
	}
}
