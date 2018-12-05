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
	else if(elem < radice) {
		return cercaNodo(radice->sinistro, elem);
	}
	else /* maggiore */ {
		return cercaNodo(radice->destro, elem);
	}
}
