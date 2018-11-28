#include "code.h"
#include "stdlib.h"

Coda* nuovaCoda() {
	Coda* retn = malloc(sizeof(Coda));
	retn->primo = retn->ultimo = NULL;
	return retn;
}

void distruggiCoda(Coda* coda) {
	free(coda);
}

void enqueue(Coda* coda, elem_t* elem) {
	NodoCoda* nodo = malloc(sizeof(NodoCoda));
	nodo->elem = elem;
	nodo->next = NULL;

	if(coda->primo == NULL) {
		coda->primo = nodo;
	} else {
		coda->ultimo->next = nodo;
	}
	coda->ultimo = nodo;
}

elem_t* dequeue(Coda* coda) {
	NodoCoda* nodo = coda->primo;
	elem_t* retn = nodo->elem;

	if((coda->primo = nodo->next) == NULL)
		coda->ultimo = NULL;

	free(nodo);

	return retn;
}

bool codaVuota(Coda* coda) {
	return coda->primo == NULL;
}
