#include "abr.h"



Nodo* creaNodo(int inf) {
	Nodo* newNode = malloc(sizeof(Nodo));
	newNode->destro = newNode->sinistro = NULL;
	newNode->inf = inf;
	return newNode;
}

Nodo* creaAlbero(int* array, int dim) {
	Nodo* radice = NULL;

	for(int i=0; i < dim; i+=1) {
		inserisciNodo(&radice, creaNodo(array[i]));
	}

	return radice;
}

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

void distruggiAlbero(Nodo* radice) {
	if(radice == NULL)
		return;

	distruggiAlbero(radice->sinistro);
	distruggiAlbero(radice->destro);

	free(radice);
}

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

int cercaNodoHit(Nodo* radice, int elem) {
	int hits = 0;
	cercaNodoHit_ric(radice, elem, &hits);
	return hits;
}
