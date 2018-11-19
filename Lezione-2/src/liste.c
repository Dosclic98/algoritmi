#include "liste.h"


/* --- */
Lista* makeLista(){
	return NULL;
}

/* --- */
int emptyL(Lista* l){
	return (l == NULL);
}

/* Restituisce il campo informativo (puntatore ad elemento) 
 * del primo nodo della lista (NULL se la lista è vuota)*/
Elemento* primo(Lista* l){
	if(l != NULL){
		return (l->inf);
	}
	return NULL;
}

/* Alloca ed inizializza un nuovo elemento */
Lista* creaNodo(Elemento* el){
	Lista* l;

	l = (Lista*) malloc(sizeof(Lista));
	if(l != NULL){
		l->inf = el;
		l->next = NULL;
	}
	return l;
}

/* Aggiunge un elemento ad una lista, e ne restituisce la testa */
Lista* inserisci(Elemento* el, Lista* l){
	Lista* l1;
	l1 = creaNodo(el);

	if(l1 != NULL){
		l1->next = l;
		l = l1;
	}
	return l;
}

/* Rimuove e dealloca la testa della lista, e restituisce la nuova
 * testa */
Lista* rimuovi(Lista* lptr){
	if(lptr != NULL){
		Lista* l = lptr;
		lptr = lptr->next;
		free(l->inf);
		free(l);
	}

	return lptr;
}

/* Dealloca ogni elemento della lista */
void distruggiLista(Lista** lista){
	while((*lista)!=NULL)
	{
		Lista* tmp = (*lista)->next;
		rimuovi(*lista);
		(*lista) = tmp;
	}
}
