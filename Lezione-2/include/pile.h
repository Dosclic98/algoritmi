 #ifndef PILE_H
 #define PILE_H

#include "liste.h"

typedef struct pila {
	Lista* cima;
} Pila;

Pila* makePila();
void distruggiPila(Pila* p);
int emptyP(Pila* p);
void push(Elemento* el, Pila *p);
Elemento* top(Pila* p);
Elemento* pop(Pila* p);

 #endif
