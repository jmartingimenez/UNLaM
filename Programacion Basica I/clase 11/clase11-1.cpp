#include<stdio.h>
#include<conio.h>
#define MESES 12

main()
{
int i=0,mes=0;
float impt[MESES];	
for(i=0;i<MESES;i++)
	{
		impt[i]=0;
	}	
for(i=0;i<MESES;i++)
	{
		printf("\nIngrese un importe: ");
		scanf("%f",&impt[i]);
	}
while(mes!=99)
	{
		printf("\nIngrese el numero de mes: ");
		scanf("%d",&mes);
		if((mes>=1)&&(mes<=3))
			{
				impt[MESES-1]=impt[MESES-1]+impt[i];
			}
	}
for(i=0;i<MESES;i++)
	{
		printf("\nimporte del mes %d: %.2f",i+1,impt[i]);
	}
	
getch();
return(1);	
}

