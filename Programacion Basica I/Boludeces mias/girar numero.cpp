#include<stdio.h>
#include<conio.h>

main()

{
int i=0,inv=0,cifra=0,num=0;
printf("Ingrese un numero: ");
scanf("%d",&num);
printf("El numero %d girado es ",num);
while(num>0)
	{
		cifra=num%10;
		inv=inv*10+cifra;
		num/=10;
	}
printf("%d ",inv);	
getch();
return(1);	
}
