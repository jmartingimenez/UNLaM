#include<stdio.h>
#include<conio.h>

int main()
{
	int ord=0,articulo=0,cantidad=0,precio=0,articulomenorcantidad=0,total=0,totalindividual=0,
	    mayorimporte=0,mayortotal,menorcantidad=0,segundomenorimporte=0,menorimporte=0,
		menorarticulo=0,segundomenorarticulo=0;
    float totalconiva=0, ingresobruto=0,totalapagar=0;
    printf("Cod\t Articulo\tPrecio\t\n");
    printf("1 \t Zapallos\t20$\t\n");
    printf("2 \t Batatas\t15$\t\n");
    printf("3 \t Naranjas\t30$\t\n");
    printf("4 \t Manzanas\t25$\t\n");
    printf("5 \t Bananas\t20$\t\n");
    
	printf("\nIngrese un articulo\t");
	scanf("%i",&articulo);

	while(articulo!=986)
	{
	printf("\nIngrese una cantidad\t");
	scanf("%i",&cantidad);
		switch(articulo)
		{
			case 1: printf("\nZapallos\t  20$\n");
			precio=20*cantidad;
			totalindividual=precio;
			printf("\nEl precio total individual es %d\n",totalindividual);
			total=total+precio;
			break;
			case 2: printf("\nBatatas\t 15$\n");
			precio=15*cantidad;
			totalindividual=precio;
			printf("\nEl precio total individual es %d \n",totalindividual);
			total=total+precio;
			break;
			case 3: printf("\nNaranjas\t 30$\n");
			precio=30*cantidad;
			totalindividual=precio;
			printf("\nEl precio total individual es %d \n",totalindividual);
			total=total+precio;
			break;
			case 4: printf("\nManzanas\t 25$\n");
			precio=25*cantidad;
			totalindividual=precio;
			printf("\nEl precio total individual es %d \n",totalindividual);
			total=total+precio;
			break;
			case 5: printf("\nBananas\t 20$\n");
			precio=20*cantidad;
			totalindividual=precio;
			printf("\nEl precio total individual es %d \n",totalindividual);
			total=total+precio;
			break;		
			default: printf("\n El articulo seleccionado no existe. ERROR 404 NOT FOUND\n");
			break;
		}
			ord++;
	        if(ord==1) /* aca esta el articulo de mayor importe*/
			   {mayorimporte=articulo;
		        mayortotal=totalindividual;
				menorimporte=totalindividual;
			 	menorarticulo=articulo;}
				else {if(totalindividual>mayortotal) 
			            {mayorimporte=articulo;
			  	         mayortotal=totalindividual; }}
			 if(ord==1)
			    { /* aca esta el articulo de menor cantidad*/
			     articulomenorcantidad=articulo;
			     menorcantidad=cantidad;}
				 else
				  {
			 	if(cantidad<menorcantidad)
				 {
			 articulomenorcantidad=articulo;
			 menorcantidad=cantidad;
			 	}
			 }
			 if(ord==2) /* aca esta el segundo menor en importe*/
			   {if(totalindividual<menorimporte)
        		   {segundomenorimporte=menorimporte;
		  	  	    segundomenorarticulo=menorarticulo;
                	menorimporte=totalindividual;
			    	menorarticulo=articulo;}
			    	else 
                      {segundomenorimporte=totalindividual;
			    	   segundomenorarticulo=articulo;}}
			   else  	   
			        {if(totalindividual<menorimporte)
        		      {segundomenorimporte=menorimporte;
		  	  	       segundomenorarticulo=menorarticulo;
                       menorimporte=totalindividual;
			           menorarticulo=articulo;}
			    	else 
			           if(totalindividual<segundomenorimporte)
                        {segundomenorimporte=totalindividual;
			    	     segundomenorarticulo=articulo;}}
			  	
        		   
	           printf("\nIngrese un articulo\t");
               scanf("%i",&articulo);}
	printf("\nEl total es %d\n",total);
	totalconiva=total+total*0.1086;
	printf("\nEl total con iva es %.2f\n",totalconiva);
	ingresobruto=total+total*0.06;
	printf("\nEl total con ingreso bruto es %.2f\n",ingresobruto);
	totalapagar=total+total*0.06+total*0.1086;
	printf("\nEl total a pagar es %.2f\n",totalapagar);
	printf("\n El producto de mayor importe fue del articulo %d que costo %d\n ",mayorimporte,mayortotal);
	printf("\n El producto menos comprado fue del articulo %d comprado %d veces\n ",articulomenorcantidad,menorcantidad);
	printf("\n El segundo menor importe fue %d del articulo %d",segundomenorimporte,segundomenorarticulo);
}
