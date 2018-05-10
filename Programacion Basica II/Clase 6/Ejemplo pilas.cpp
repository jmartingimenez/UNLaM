#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
int valor;
struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

/* Funciones con pilas: */
void Push(Pila *l, int v);
int Pop(Pila *l);

int main()
{
Pila pila = NULL;
pNodo p;

Push(&pila, 20);
Push(&pila, 10);
Push(&pila, 40);
Push(&pila, 30);

printf("%d, ", Pop(&pila));
printf("%d, ", Pop(&pila));
printf("%d, ", Pop(&pila));
printf("%d\n", Pop(&pila));

system("PAUSE");
return 0;
}

void Push(Pila *pila, int v)
{
pNodo nuevo;

/* Crear un nodo nuevo */
nuevo = (pNodo)malloc(sizeof(tipoNodo));
nuevo->valor = v;

/* Añadimos la pila a continuación del nuevo nodo */
nuevo->siguiente = *pila;
/* Ahora, el comienzo de nuestra pila es en nuevo nodo */
*pila = nuevo;
}

int Pop(Pila *pila)
{
pNodo nodo; /* variable auxiliar para manipular nodo */
int v; /* variable auxiliar para retorno */

/* Nodo apunta al primer elemento de la pila */
nodo = *pila;
if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
/* Asignamos a pila toda la pila menos el primer elemento */
*pila = nodo->siguiente;
/* Guardamos el valor de retorno */
v = nodo->valor;
/* Borrar el nodo */
free(nodo);
return v;
}
