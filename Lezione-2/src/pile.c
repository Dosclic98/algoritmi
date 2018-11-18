#include "pile.h"


/* Alloca lo spazio necessario per gli struct della pila,
 * che contiene i due puntatori 'inizio' e 'fine' */
Pila* makePila() {
	Pila* newP = malloc(sizeof(Pila));
	newP->primo = newP->ultimo = makeLista();
	return newP;
}

/* Restituisce un numero diverso da '0' se la pila e' vuota,
 * '0' altrimenti */
int emptyP(Pila* p) {
	return emptyL(p->primo);
}

/* Aggiunge un elemento alla testa della pila */
void push(Elemento* el, Pila* p) {
	p->primo = inserisci(el, p->primo);
}

/* Restituisce il primo elemento da prelevare dalla pila, o
 * 'NULL' se la pila e' vuota */
Elemento* top(Pila* p){
	if(!emptyP(p))
		return (p->primo->inf);
	return NULL;
}

/* Rimuove un elemento dalla testa della coda, e restituisce
 * una copia dell'elemento rimosso (l'elemento originale viene
 * deallocato) */
Elemento* pop(Pila* p){
	Elemento* cpy = malloc(sizeof(Elemento));
	Elemento* el;

	if(!emptyP(p)){
		el = top(p);
		cpy->valore = el->valore;
		cpy->seme = el->seme;
		p->primo = rimuovi(p->primo);
		return cpy;
	}
	return NULL;

}

/* Dealloca ogni elemento contenuto nella pila, ma preserva
 * lo spazio allocato per la coda stessa */
void distruggiPila(Pila* p)
{
	while(p->primo != NULL) {
		p->primo = rimuovi(p->primo);
	}
	p->ultimo = NULL;
	free(p);
}
