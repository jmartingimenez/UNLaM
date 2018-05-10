/* Ejemplo escritura en un fichero texto.

Este programa lee números del teclado y los introduce en un archivo llamado "NUMEROS.TXT" (Será texto). Terminamos cuando introduzcamos un cero.
*/

# include <stdio.h>

void main(void)
{
   FILE *fich;   /* puntero del fichero */
   int n;           /* número a escribir */

 /* abrimos el archivo para escritura */
   fich = fopen("E:\NUMEROS.TXT","wt");

   printf("Introduzca los números del archivo: \n");
   
   scanf("%d",&n);
   while (n)
   {
      fprintf(fich,"%d\n",n);  /* escribo en el fichero */
      scanf("%d",&n);
   }
   fclose(fich);
}

