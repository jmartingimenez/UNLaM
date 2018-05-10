#include<stdio.h>
#include<conio.h>

int main()

{
int num1=0,num2=0,num3=0;
printf("Ingrese un primer numero: ");
scanf("%d",&num1);
printf("Ingrese un segundo numero: ");
scanf("%d",&num2);
printf("Ingrese un tercer numero: ");	
scanf("%d",&num3);
if((num1==num2)&&(num2==num3))
{
	printf("Los tres numeros son iguales.");
}
else
{
if((num1==num2)&&(num2>num3))	
{
	printf("Los dos primeros numeros son iguales y mayores al tercero.");
}
else
if((num1==num2)&&(num2<num3))
{
	printf("Los dos primeros numeros son iguales y menores al tercero.");
}
else
{
	if((num1==num3)&&(num2>num3))
	{
		printf("El primer numero y el tercero son iguales y menores al segundo.");
	}
	else
	if((num1==num3)&&(num2<num3))
	{
		printf("El primer numero y el tercero son iguales y mayores al segundo. ");
	}
	else
	if((num2==num3)&&(num1>num3))
	{
		printf("El segundo y el tercer numero son iguales y menores al primero.");
	}
	else
	if((num2==num3)&&(num1<num3))
	{
	printf("El segundo y el tercer numero son iguales y mayores al primero.");
	}
	else
	if((num1>num2)&&(num2>num3))
	{
		printf("El primer numero es el mayor y el segundo es mayor al tercero.");
	}
	else
	if((num1>num3)&&(num3>num2))
	{
		printf("El primer numero es el mayor y el segundo es menor al tercero.");
	}
	else
	if((num2>num1)&&(num1>num3))
	{
		printf("El segundo numero es el mayor y el primero es mayor al tercero.");
	}
	else
	if((num2>num3)&&(num3>num1))
	{
		printf("El segundo numero es el mayor y el tercero es mayor al primero.");
	}
	else
	if((num3>num1)&&(num1>num2))
	{
		printf("El tercer numero es el mayor y el primero es mayor al segundo.");
	}
	else
		printf("El tercer numero es el mayor y el segundo es mayor al primero.");
}

}
getch();
return(1);
}
