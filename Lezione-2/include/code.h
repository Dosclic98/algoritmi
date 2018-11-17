 #ifndef CODE_H
 #define CODE_H

#include "liste.h"

typedef struct coda{
	Lista* primo;
	Lista* ultimo;
} Coda;

Coda* makeCoda();
void distruggiCoda(Coda* c);
int emptyC(Coda* p);
void enqueue(Elemento* el, Coda *c);
Elemento* first(Coda* c);
Elemento* dequeue(Coda* c);

 #endif
