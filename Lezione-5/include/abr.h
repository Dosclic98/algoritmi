 #ifndef ABR_H
 #define ABR_H

#include <stdlib.h>
#include <stdbool.h>



typedef struct nodo {
	int inf;
	struct nodo* sinistro;
	struct nodo* destro;
} Nodo;

 /* Inserisce nella posizione giusta un nodo con valore 'elem',
  * senza controllare se l'albero contiene gia' un nodo con
  * valore uguale. */
void inserisciNodo(Nodo** radice, Nodo* elem);

 /* Cerca nell'albero binario il nodo con valore 'elem', ritorna
  * il nodo trovato oppure NULL. */
const int * cercaNodo(Nodo* radice, int elem);

 /* Cerca il nodo con valore 'elem', e se esiste lo elimina;
  * ritorna 'true' se e solo se il nodo e' stato trovato. */
bool rimuoviNodo(Nodo* radice, int elem);

 /* Alloca il nodo. */
Nodo* creaNodo(int inf);

 /* Inserisce tutti gli elementi dell'array dato all'interno di
  * un nuovo albero, e ne ritorna la radice. */
Nodo* creaAlbero(int* array, int n);

 /* Dealloca tutti gli elementi dell'albero */
void distruggiAlbero(Nodo* radice);

/* Cerca all'interno dell'albero dato il nodo con campo
 * informativo equivalente a 'elem', e ritorna il numero di
 * passi necessari per trovarlo (nodi visitati). */
int cercaNodoHit(Nodo* radice, int elem);

 #endif
