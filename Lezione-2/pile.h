#include "liste.h"

typedef struct pila {
	Lista* primo;
	Lista* ultimo;
} Pila;

Pila* makePila();
int emptyP(Pila* p);
void push(Elemento el, Pila *p);
Elemento top(Pila* p);
Elemento pop(Pila** p);

