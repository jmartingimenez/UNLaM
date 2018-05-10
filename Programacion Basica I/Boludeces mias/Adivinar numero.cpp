#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()

{
	
int seguir=1;
char vida=3;
do
	{
		system("cls");
		int vidas=10,i=0,n=0;
		while((i<1)||(i>999))
			{
				printf("Ingrese un numero secreto entre 1 y 999: ");
				scanf("%d",&i);
				system("cls");			
			}
		while(vidas>0)
			{
				printf("\t\t\tVidas: %c%d\n",vida,vidas);
				printf("Intenta adivinar el numero: ");
				scanf("%d",&n);
				if(n==i)
					{
						system("cls");
						printf("\n\n\n\t\t\tAdivinaste!!");
						vidas=0;
					}
				else
					{
						system("cls");
						if(n>i)
							{
								printf("\n\n\nEl numero secreto es mas bajo!!");
							}
						else
							{
								printf("\n\n\nEl numero secreto es mas alto!!");
							
							}
						vidas--;
					}	
			}	
		if(n!=i)
			{
				system("cls");
				printf("\n\n\n\t\t\tGAME OVER!!");			
			}
		printf("\n\n\n\nDesea continuar?\nSi=1\nNo=Cualquier otra tecla\n\n\t\t\tSeleccion: ");
		scanf("%d",&seguir);
	}while(seguir==1);			
getch();
return(1);	
}
