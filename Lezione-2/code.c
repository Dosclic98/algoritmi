#include "code.h"

Coda* makeCoda(){
	Coda* c = (Coda*)malloc(sizeof(Coda));
	c->primo = c->ultimo = NULL;
	return c;
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
	Elemento* el;
	
	if(!emptyC(c)){
		el = first(c);
		c->primo = rimuovi(c->primo);
		return el;
	}
	return NULL;
}
