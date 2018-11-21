#include "pile.h"


Pila* makePila() {
	Pila* newP = malloc(sizeof(Pila));
	newP->primo = newP->ultimo = makeLista();
	return newP;
}

int emptyP(Pila* p) {
	return emptyL(p->primo);
}

void push(Elemento* el, Pila* p) {
	p->primo = inserisci(el, p->primo);
}

Elemento* top(Pila* p){
	if(!emptyP(p))
		return (p->primo->inf);
	return NULL;
}

Elemento* pop(Pila** p){
	Elemento* el;
	if(!emptyP(*p)) {
		el = primo((*p)->primo);
		// Dai un occhiata a rimuovi qua sotto
		(*p)->primo = rimuovi((*p)->primo);
		return el;
	}
	return NULL;
}
