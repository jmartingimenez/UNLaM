#include<stdio.h>
#include<conio.h>

main()

{
	int num,mayor;
	while(num!=99)
	{
		printf("\nIngrese un numero: ");
		scanf("%d",&num);
		if((num>mayor)&&(num!=99))
			{
				mayor=num;
			}
	}
printf("\nEl mayor numero es: %d",mayor);
getch();
return(1);
}

