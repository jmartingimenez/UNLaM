#include <stdio.h>
#include <conio.h>

main()
{
	int mat[5][5],cliente=0,i=0,j=0,cantidad=0;
	
	for(i=0;i<5;i++)
	{
		for (j=0;j<5;j++)
		{
			mat[i][j]=0;
	    }
	}
	
	printf("Ingrese cliente: ");
	scanf("%d",&cliente);
	
	while(cliente!=999)
	{
		if(cliente<=5)
		{
			cantidad=0;
				for (j=0;j<5;j++)
				{
					printf("\n¿Que cantidad del articulo %d desea llevar? ... ",j+10);
					scanf("%d",&cantidad);
					mat[cliente-1][j]=mat[cliente-1][j]+cantidad;
				}
		}
		else
		{
			//cls;
			printf("\n\nSolo ingresar Clientes 1 - 2 - 3 - 4 - 5 - NO OTRO NUMERO :D");
			printf("\nIntente ingesar de nuevo los datos ...\n\n");
		}
		
		printf("\n\nIngrese cliente:");
	    scanf("%d",&cliente);
	}
	i=0;
	j=0; 
	printf("\t\t\tArt 10 \tArt 11 \tArt 12 \tArt 13 \tArt 14 ");
	for(i=0;i<5;i++)
	{
		
		printf("\n================================================================\n ");
		printf("Cliente Nro %d  \t",i+1);
		for(j=0;j<5;j++)
		{
			printf("%d \t",mat[i][j]);
		}
	}
	getch();
}
