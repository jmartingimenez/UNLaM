#include<stdio.h>
#include<conio.h>

int menor(int n1,int n2);

int main()

{
	int n1=0,n2=0,m;
	printf("Ingrese un numero: ");
	scanf("%d",&n1);
	printf("Ingrese otro numero: ");
	scanf("%d",&n2);
	m=menor(n1,n2);
	printf("El numero mas bajo es %d",m);
	getch();
	return 0;
}

int menor(int n1,int n2)

{
	if(n1==n2)
		{
			return n1;
		}
	else
		{
			if(n1<n2)
				{
					return n1;
				}
			else
				{
					return n2;
				}	
		}	
}
