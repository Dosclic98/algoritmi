#include "pile.h"


/* Alloca lo spazio necessario per gli struct della pila,
 * che contiene i due puntatori 'inizio' e 'fine' */
Pila* makePila() {
	Pila* newP = malloc(sizeof(Pila));
	newP->cima = makeLista();
	return newP;
}

/* Restituisce un numero diverso da '0' se la pila e' vuota,
 * '0' altrimenti */
int emptyP(Pila* p) {
	return emptyL(p->cima);
}

/* Aggiunge un elemento sulla cima della pila */
void push(Elemento* el, Pila* p) {
	p->cima = inserisci(el, p->cima);
}

/* Restituisce il primo elemento da prelevare dalla pila, o
 * 'NULL' se la pila e' vuota */
Elemento* top(Pila* p){
	if(!emptyP(p))
		return (p->cima->inf);
	return NULL;
}

/* Rimuove un elemento dalla cima della pila, e restituisce
 * una copia dell'elemento rimosso (l'elemento originale viene
 * deallocato) */
Elemento* pop(Pila* p){
	Elemento* cpy = malloc(sizeof(Elemento));
	Elemento* el;

	if(!emptyP(p)){
		el = top(p);
		cpy->valore = el->valore;
		cpy->seme = el->seme;
		p->cima = rimuovi(p->cima);
		return cpy;
	}
	return NULL;

}

/* Dealloca ogni elemento contenuto nella pila (ma non il puntatore a Pila)*/
void distruggiPila(Pila* p)
{
	while(p->cima != NULL) {
		p->cima = rimuovi(p->cima);
	}
	free(p);
}
