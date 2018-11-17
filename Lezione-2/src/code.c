#include "code.h"

Coda* makeCoda(){
	Coda* c = (Coda*)malloc(sizeof(Coda));
	c->primo = c->ultimo = NULL;
	return c;
}

void distruggiCoda(Coda* c) {
	while(c->primo != NULL) {
		c->primo = rimuovi(c->primo);
	}
	c->ultimo = NULL;
}

int emptyC(Coda* c){
	return emptyL(c->primo);
}

Elemento* first(Coda* c){
	return primo(c->primo);
}

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
