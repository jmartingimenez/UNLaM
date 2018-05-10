/* Este programa pide un numero al usuario y los busca dentro del archivo
   NUMEROS.TXT.

   Escribe por pantalla si esta o no, y en caso de que este‚ muestra la linea en
   la que esta. */

#include <stdio.h>
#include <string.h>

#define LONGITUD 11  /* longitud de la cadena + '\0' */

void lee_cadena_fichero(char *cadena,int max_longitud,FILE *fichero);

void main(void)
{
   char a_buscar[LONGITUD];  /* cadena a buscar en el fichero */
   char cadena[LONGITUD];    /* cadena le¡da del fichero      */
   int n=1;                  /* n£mero de l¡nea del archivo   */
   FILE *fichero;

   /* comprobamos si existe el fichero */

   if ((fichero=fopen("NUMEROS.TXT","rt"))==NULL)
   {
      printf("Error al abrir el fichero NUMEROS.TXT\n");
      getch();
   }

   /* pedimos al usuario la cadena a buscar en el archivo */

   printf("Cadena a buscar: ");
   gets(a_buscar);

   /* buscamos en el archivo */

   lee_cadena_fichero(cadena,LONGITUD,fichero); /* sustituimos por fgets */
   while (!feof(fichero) && strcmp(a_buscar,cadena)!=0)
   {
      /* comprobamos si hemos le¡do el final del archivo o si lo que
         hemos le¡do es el valor que estamos buscando. */

      n++ ;  /* una lanea mas, si estamos aqui es porque el ultimo
                registro leido no es el que buscamos */
      lee_cadena_fichero(cadena,LONGITUD,fichero);
   }

   /* ahora comprobamos si hemos salido del bucle porque hemos encontrado
      lo que busc bamos o porque se ha terminado el archivo */

   if (feof(fichero))
      printf("Valor no encontrado.\n");
   else
      printf("El valor buscado est  en la linea %d.\n",n);

   /* terminamos */

   fclose(fichero);
}

/* la siguiente funcion opera de forma parecida a fgets, pero a diferencia
   de fgets que mete el carecter \n al final de la cadena, esta funcion no
   lo hace (como lo haria fscanf). */

void lee_cadena_fichero(char *cadena,int max_longitud,FILE *fichero)
{
   int longitud_cadena;

   /* leemos la cadena */

   fgets(cadena,max_longitud,fichero);

   /* quitamos el '\n' del final de la cadena */

   longitud_cadena = strlen(cadena);
   cadena[longitud_cadena - 1] = '\0'; /* finalizador de cadena */
}

