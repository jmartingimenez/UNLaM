#include<stdio.h>
#include<conio.h>

main()
{
	int sum=0,nro=0;
	while(nro!=99)
	{
		sum=sum+nro;
		printf("ingrese un numero: ");
		scanf("%d",&nro);
	}
	printf("suma=%d",sum);
	getch();
	return(1);
}

