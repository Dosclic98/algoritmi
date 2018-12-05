#include "abr.h"
#include "code.h"



Nodo* creaNodo(int inf) {
	Nodo* newNode = malloc(sizeof(Nodo));
	newNode->destro = newNode->sinistro = NULL;
	newNode->inf = inf;
	return newNode;
}

Nodo* creaAlbero(int n) {
	return creaNodo();
}

Nodo* creaAlbero(int[] array) {
	Nodo* radice = <nuovo_albero>;

	for(int i=0; i < array.length; i+=1) {
		inserisciNodo(radice, creaNodo(array[i]));
	}
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
