 #ifndef CODE_H
 #define CODE_H

#include "alberi.h"

typedef Nodo elem_t;

typedef struct nc {
	elem_t* elem;
	NodoCoda* next;
} NodoCoda;

typedef struct coda {
	NodoCoda* primo;  // primo da prelevare
	NodoCoda* ultimo; // ultimo inserito
} Coda;

void enqueue(Coda* coda, elem_t* elemento);
elem_t* dequeue(Coda* coda);
elem_t* primoCoda(Coda* coda);
bool codaVuota(Coda* coda);

 #endif
