#include <stdio.h>
#include <conio.h>
#define MILANESA 25.0
#define VINO_ENTRERIOS -3.0
#define DULCEDELECHE 3.0
#define DDL_CHIMICHURRI_LIMON 2.0
#define VINO_GASEOSA 5.0
#define VODKA_CANIA 25.0
#define ASADO 26.0
#define CHIMICHURRI 2.0
#define CANIA 20.0
#define VINO_LT 8.0
#define DDL_CHIMICHURRI_DDN -5.0
#define DESCUENTO 0.12
#define RECARGO 0.15
main()
{
    int menu=0, sub_menu1=0, sub_menu2=0, mesa=0, mesa_mayor_consumicion=0, cantidad_descuentos=0, cantidad_recargos=0;
    float total=0.0, total_descuento=0, total_recargo=0, total_facturado=0, mayor_consumicion=0;
    
    printf("Seleccione numero de mesa: ");
    scanf("%i",&mesa);
    while(mesa !=999)
         {printf("\tMesa %i\n",mesa);
          printf("Menu 1: Milanesa con papas fritas y vino ($25) Presione 1\n");
          printf("Menu 2: Asado con papas fritas y vino ($26) Presione otro numero\n");
          scanf("%i",&menu);
          if(menu==1)
            {printf("Menu 1:\n");
             printf("Elija una sola opcion:\n");
             printf("Cambiar por vino de Entre Rios. (3$ menos). Opcion 1\n");
             printf("Agregar dulce de leche. (3$ mas). Opcion 2\n");
             printf("Agregar dulce de leche, chimichurri y limnon. (2$ mas). Opcion 3\n");
             printf("Cambiar vino por gaseosa de 750cc. (5$ mas). Opcion 4\n");
             printf("Agregado de un vaso de vodka y de un vaso de cania. (25$ mas). Opcion 5\n");
             scanf("%i",&sub_menu1);
             switch(sub_menu1)
                   {case 1:total=MILANESA+VINO_ENTRERIOS;
                           break;
                    case 2:total=MILANESA+DULCEDELECHE;
                           break;
                    case 3:total=MILANESA+DDL_CHIMICHURRI_LIMON;
                           break;
                    case 4:total=MILANESA+VINO_GASEOSA;
                           break;
                    case 5:total=MILANESA+VODKA_CANIA;
                           break;}
            }
          else
            {printf("Menu 2:\n");
             printf("Elija una sola opcion:\n");
             printf("Agregar chimichurri. (2$ mas). Opcion 1\n");
             printf("Agregar una copa de cania. (20$ mas). Opcion 2\n");
             printf("Agregar un lt de vino. (8$ mas). Opcion 3\n");
             printf("Agregar dulce de leche, chimichurri y dulce de naranja. (5$ menos). Opcion 4\n");
             scanf("%i",&sub_menu2);
             switch(sub_menu2)
                   {case 1:total=ASADO+CHIMICHURRI;
                           break;
                    case 2:total=ASADO+CANIA;
                           break;
                    case 3:total=ASADO+VINO_LT;
                           break;
                    case 4:total=ASADO+DDL_CHIMICHURRI_DDN;
                           break;}
            }
          printf("Su total es: %.2f\n",total);
          if(total>=30)
            {total_descuento=total-(total*DESCUENTO);
             printf("\nTotal con descuento: %.2f\n\n",total_descuento);
             cantidad_descuentos++;}
          else
            {total_recargo=(total*RECARGO)+total;
             printf("\nTotal con recargo: %.2f\n\n",total_recargo);
             cantidad_recargos++;}
          
          if(total_descuento>mayor_consumicion)
            {mayor_consumicion=total_descuento;
             mesa_mayor_consumicion=mesa;}
          if(total_recargo>mayor_consumicion)
            {mayor_consumicion=total_recargo;
             mesa_mayor_consumicion=mesa;}
          
          total_facturado=total_facturado+total_descuento+total_recargo;
          total_descuento=0;
          total_recargo=0;
          printf("Seleccione numero de mesa: ");
          scanf("%i",&mesa);
         }
         printf("El total facturado es: %.2f\n",total_facturado);
         printf("La mesa que mas consumio es la %i con una facturacion de %.2f\n",mesa_mayor_consumicion,mayor_consumicion);
         printf("La cantidade de descuentos fue: %i\n",cantidad_descuentos);
         printf("La cantidad de recargos fue: %i\n",cantidad_recargos);
         getch(); 
}
