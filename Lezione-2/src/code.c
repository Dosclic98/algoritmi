#include "code.h"


/* Alloca lo spazio necessario per lo struct della coda,
 * che contiene i due puntatori 'inizio' e 'fine' */
Coda* makeCoda(){
	Coda* c = (Coda*)malloc(sizeof(Coda));
	c->primo = c->ultimo = NULL;
	return c;
}

/* Dealloca ogni elemento contenuto nella coda, ma preserva
 * lo spazio allocato per la coda stessa (Coda*) */
void distruggiCoda(Coda* c) {
	while(c->primo != NULL) {
		c->primo = rimuovi(c->primo);
	}
	c->ultimo = NULL;
}

/* Restituisce un numero diverso da '0' se la coda e' vuota,
 * '0' altrimenti */
int emptyC(Coda* c){
	return emptyL(c->primo);
}

/* Restituisce il primo elemento da prelevare dalla coda, o
 * 'NULL' se la coda e' vuota */
Elemento* first(Coda* c){
	return primo(c->primo);
}

/* Aggiunge un elemento alla fine della coda */
void enqueue(Elemento* el, Coda* c){
	Lista* l;
	l = creaNodo(el);

	if(l != NULL){
		if(emptyC(c)){
			c->primo = l;
			c->ultimo = l;
		}
		else{
			c->ultimo->next = l;
			c->ultimo = l;
		}
	}
}

/* Rimuove un elemento dalla testa della coda, e restituisce
 * una copia dell'elemento rimosso (l'elemento originale viene
 * deallocato) */
Elemento* dequeue(Coda* c){
	Elemento* cpy = malloc(sizeof(Elemento));
	Elemento* el;

	if(!emptyC(c)){
		el = first(c);
		cpy->valore = el->valore;
		cpy->seme = el->seme;
		c->primo = rimuovi(c->primo);
		return cpy;
	}
	return NULL;
}
