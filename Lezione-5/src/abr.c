#include "abr.h"



/* Alloca un nodo, inizializza i suoi campi e ne ritorna
 * il puntatore. */
Nodo* creaNodo(int inf) {
	Nodo* newNode = malloc(sizeof(Nodo));
	newNode->destro = newNode->sinistro = NULL;
	newNode->inf = inf;
	return newNode;
}

/* Costruisce un albero di ricerca binario, inserendo
 * ogni elemento presente nell'array (mantenendo
 * multipli elementi con lo stesso valore). */
Nodo* creaAlbero(int* array, int dim) {
	Nodo* radice = NULL;

	for(int i=0; i < dim; i+=1) {
		inserisciNodo(&radice, creaNodo(array[i]));
	}

	return radice;
}

/* Inserisce all'interno del nodo padre, nella corretta
 * posizione, l'elemento dato. */
void inserisciNodo(Nodo** padre, Nodo* elem) {
	if(*padre == NULL) {
		*padre = elem;
		return;
	}

	if(elem->inf <= (*padre)->inf) {
		inserisciNodo(&((*padre)->sinistro), elem);
	} else {
		inserisciNodo(&((*padre)->destro), elem);
	}
}

/* Dealloca ogni elemento all'interno del nodo dato,
 * e tutti gli elementi sottostanti. */
void distruggiAlbero(Nodo* radice) {
	if(radice == NULL)
		return;

	distruggiAlbero(radice->sinistro);
	distruggiAlbero(radice->destro);

	free(radice);
}

/* Cerca un nodo dato il valore del suo campo informativo;
 * restituisce un puntatore al nodo se e' trovato, 'NULL'
 * altrimenti. */
const int * cercaNodo(Nodo* radice, int elem) {
	if(radice == NULL)
		return NULL;

	if(elem == radice->inf) {
		return &(radice->inf);
	}
	else if(elem < radice->inf) {
		return cercaNodo(radice->sinistro, elem);
	}
	else /* maggiore */ {
		return cercaNodo(radice->destro, elem);
	}
}

/* Funzione ricorsiva d'appoggio per cercaNodoHit(Nodo*, int). */
void cercaNodoHit_ric(Nodo* radice, int elem, int* hitPreced) {
	*hitPreced += 1;

	if((radice == NULL) || (elem == radice->inf))
		return;

	if(elem < radice->inf) {
		cercaNodoHit_ric(radice->sinistro, elem, hitPreced);
	}
	else /* maggiore */ {
		cercaNodoHit_ric(radice->destro, elem, hitPreced);
	}
}

/* Cerca all'interno dell'albero dato il nodo con campo
 * informativo equivalente a 'elem', e ritorna il numero di
 * passi necessari per trovarlo (che e' un numero asintotico
 * al tempo di esecuzione della funzione stessa). */
int cercaNodoHit(Nodo* radice, int elem) {
	int hits = 0;
	cercaNodoHit_ric(radice, elem, &hits);
	return hits;
}
