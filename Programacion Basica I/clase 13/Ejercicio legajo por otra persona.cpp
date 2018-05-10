#include <stdio.h>
#include <conio.h>

main ()
{
	int nota[10], i=0,j=0,auxnota=0, auxleg=0,legajen[10];
	
	for (i=0;i<=9;i++)
		{
			nota[i]=0;
			legajen[i]=0;		
		}
	
	for (i=0;i<=9;i++)
		{
			printf("Ingrese n° de legajo: ");
			scanf("%d",&legajen[i]);
			printf("Ingrese promedio : ");
			scanf("%d",&nota[i]);			
		}
	for(i=0;i<=9;i++)
		{
			j=i;
				while(nota[j]>nota[j+1])
					{
					  auxnota=nota[j];
					  nota[j]=nota[j+1];
					  nota[j+1]=auxnota;
					  auxleg=legajen[j];
					  legajen[j]=legajen[j+1];
					  legajen[j+1]=auxleg;
					  if(j>0)
						{
							j=j-1;
						}
					}
		}
	printf("\nEl ordenamiento de Legajo es el siguiente :\n");
	
	for	(i=0;i<=9;i++)
		{
			printf("\nEl legajo numero %d - Promedio: %d",legajen[i],nota[i]);
		}
		
	getch();	
	
	
}
