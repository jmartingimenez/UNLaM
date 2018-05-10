#include <stdio.h>
#include <conio.h>
#define TOPE 999
#define FIL 10
#define COL 5

void mostrar (int mat[][COL]);
void fila (int mat[][COL]);
void mayor (int mat[][COL]);

main ()
{
    int i=0, j=0, art=0, depo=0, cant=0, mat[FIL][COL];
	
    printf ("\nIngrese el numero de deposito o teclee (999) para terminar ");
    scanf ("%d", &depo);

    for(i=0; i<FIL; i++)
    {
		for(j=0; j<COL; j++)
       	{
			mat[i][j]=0;
		}
	}
    while (depo!=999)
    {
        printf ("\nIngrese el codigo de articulo: ");
        scanf ("%d", &art);

        if (depo>0 && depo<=5 && art>0 && art<=10)
        {
            printf ("Ingrese la cantidad que quiera depositar: ");
            scanf ("%d", &cant);

            mat[art][depo]+=cant;
        }

    printf ("\nSi desea continuar, ingrese otro numero de deposito, sino teclee (999) ");
    scanf ("%d", &depo);
    }

    mostrar (mat);
    fila (mat);
    mayor (mat);

}

void mostrar (int mat[][COL])
{
    int i=0, j=0;

    for (i=0;i<=FIL;i++)
    {
        for (j=0;j<=COL;j++)
        {
            printf ("%d ", mat[i][j]);
        }
        printf ("\n");
    }
}

void fila (int mat[][COL])
{
    int j=0, fila=0;

    printf ("\nElija el numero de fila que quiera ver: ");
    scanf ("%d", &fila);

    for (j=0;j<=COL;j++)
        printf ("%d ", mat[fila][COL]);
}

void mayor (int mat[][COL])
{
    int i=0, j=0, mayor=0, fila=0, columna=0;

    for (i=1;i<=FIL;i++)
        for (j=1;j<=COL;j++)
        {
            if (mat[i][j]>mayor)
            {
                mayor=mat[i][j];
                fila=i;
                columna=j;
            }
        }
    printf ("\nEl articulo de mayor cantidad es el numero %d del deposito %d con %d cantidades", fila, columna, mayor);
}
