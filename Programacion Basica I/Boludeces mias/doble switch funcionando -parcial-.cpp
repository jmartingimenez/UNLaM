#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{

int n=1,menu=0,submenu=0,codigo=0;
do
{
if(n!=0)
	{//if
		printf("\nIngrese un numero de mesa.\nCon 0 finaliza el programa\n\nSeleccion: ");
		scanf("%d",&n);	
	}//if
	if(n!=0)
		{//2nd if
			printf("\nElija\nOpcion (1)\nOpcion (2)\nCero para finalizar.");
			printf("\n\nSeleccion: ");
			scanf("%d",&menu);
			switch(menu)
				{//switch menu
				case 1:
					printf("\nMenu 1 seleccionado\nOpcion (1)\nOpcion(2)\nCero para finalizar");
					printf("\nSeleccion: ");
					scanf("%d",&submenu);
					switch(submenu)
						{//switch submenu del menu 1

							case 1:
								codigo=11;
								break;
							case 2:
								codigo=12;
								break;
							default:
								codigo=10;
								break;
						}//switch submenu del menu 1	
					break;//Este era el problema. (faltaba un break)						     	
				case 2:
					printf("\nMenu 2 seleccionado\nOpcion (1)\nOpcion(2)\nCero para finalizar");					
					printf("\nSeleccion: ");
					scanf("%d",&submenu);
					switch(submenu)
						{//switch submenu del menu 2
							case 1:
								codigo=21;
								break;
							case 2:
								codigo=22;
								break;
							default:
								codigo=20;
								break;
						}//switch submenu del menu 2
				break;//Este era el problema (faltaba un break)							
				default:
					break;
				}//switch menu					
		}//2nd if
}while(n!=0);
system("cls");
printf("\nExplicacion del Codigo");
printf("\nXX donde el primer valor indica el menu elegido y el segundo el submenu elegido");
printf("\nUn 0 signifca un default en el while/switch");
printf("\n\n\n\n\t\tCodigo:%d",codigo);
getch();
return(1);
}












