#include "liste.h"

Lista* makeLista(){
	return NULL;
}

int emptyL(Lista* l){
	return (l == NULL);
}

Elemento* primo(Lista* l){
	if(l != NULL){
		return (l->inf);
	}
	return NULL;
}

Lista* creaNodo(Elemento* el){
	Lista* l;
	
	l = (Lista*) malloc(sizeof(Lista));
	if(l != NULL){
		l->inf = el;
		l->next = NULL;
	}
	return l;
}

void visualizza_lista(Lista* l){
	Lista* p;
	p = l;
	
	printf("\n lista: \n");
	while(p != NULL){
		printf("\t %d, %c \n", p->inf->valore, p->inf->seme);
		p = p->next;
	}
	printf("NULL\n\n");
}

Lista* inserisci(Elemento* el, Lista* l){
	Lista* l1;
	l1 = creaNodo(el);
	
	if(l1 != NULL){
		l1->next = l;
		l = l1;
	}
	return l;
}

Lista* rimuovi(Lista* lptr){
	if(lptr != NULL){
		Lista* l = lptr;
		lptr = lptr->next;
		free(l->inf);
		free(l);
	}
	
	return lptr;
}

void distruggiLista(Lista** lista){
	while((*lista)!=NULL)
	{
		Lista* tmp = (*lista)->next;
		rimuovi(*lista);
		(*lista) = tmp;
	}
}
