/*	(enunciado)
Una empresa constructora tiene 30 edificios en construccion. Para ello envia a cada obra 3 materiales distintos,
los mismos para todas las obras. Cuando envia un material a una obra registra: el numero de obra (de 1 a 30),
el tipo de material (de 1 a 3), y la cantidad. Se pide:
	a.	La cantidad total de material 3 que se utiliza en las obras.
	b.	Cuantas obras recibieron mas de 300 unidades del material 1.
	c.	Listar las cantidades de cada material que recibio cada obra.
-----------------------------------------------------
*/
#include<stdio.h>
#include<conio.h>

main()

{
	int i=0,j=0,opcion=1,edificio=0,edificios[30],material[30][3],cant_mat3=0,cant_obras=0;
	for(i=0;i<30;i++)
		{
			edificios[i]=0;
		}
	for(i=0;i<30;i++)
		{
			for(j=0;j<3;j++)
				{
					material[i][j]=0;
				}
		}	
	while((opcion>0)&&(opcion<5))
		{
			printf("Seleccione el codigo correspondiente a la opcion deseada\n-----\n\n");
			printf("1- Enviar material a una obra determinada\n");
			printf("2- Ver cantidad del material 3 utilizado en todas las obras\n");
			printf("3- Ver cantidad de obras que recibieron mas de 300 unidades del material 1\n");
			printf("4- Ver lista de materiales completa\n5-Fin\n\nSeleccion: ");
			scanf("%d",&opcion);
			switch(opcion)
				{
					case 1:
						edificio=0;//Si no hago esto, al entrar por segunda vez no va salir nada.
						while((edificio<1)||(edificio>30))//Para que el edificio este entre 1 y 30
						{
								printf("Seleccione el edificio al cual desea enviar material: ");
								scanf("%d",&edificio);
								if((edificio<1)||(edificio>30))
									{
										printf("ERROR!!: No existe ese numero de edificio en el sistema.");
									}	
								else
									{
										edificios[edificio-1]=edificio;
										j=0;//por las dudas
										for(i=0;i<3;i++)
											{
												printf("Ingrese la cantidad a enviar del material %d: ",i+1);
												scanf("%d",&material[edificio-1][j+i]);
												cant_mat3+=material[edificio-1][2];//cantidad del material 3	
											}							
									}
							}
						break;
					case 2:
						printf("La cantidad del material 3 utilizado en todas las obras es: %d",cant_mat3);
						break;
					case 3:
						printf("Cantidad de obras que recibieron mas de 300 unidades del material 1\n");
						printf("Edificio\tCantidad\n-----------------------------\n\n");
						j=0;//por las dudas
						cant_obras=0;//para que siempre haga el conteo en el for
						for(i=0;i<30;i++)
							{
								if(material[i][j]>300)
									{
										printf("%d\t\t%d\n",edificios[i],material[i][j]);
										cant_obras++;
									}
							}
						printf("\nUn total de %d obra/s recibieron mas de 300 unidades del material 1\n\n",cant_obras);	
						break;
					case 4:
						printf("Listado de cantidad de materiales que recibio cada obra\n");
						printf("LAS OBRAS NO LISTADAS NO HAN RECIBIDO NADA\n");
						printf("Edificio\tmat. 1\tmat. 2\tmat. 3\n");
						printf("----------------------------------------------------------\n\n");
						for(i=0;i<30;i++)
							{
								if(edificios[i]>0)
									{
										printf("%d\t\t%d\t%d\t%d\n",edificios[i],material[i][j],material[i][j+1],material[i][j+2]);
									}
							}
						break;
					default:
						break;
				}			
		}
	getch();
	return(1);
}
