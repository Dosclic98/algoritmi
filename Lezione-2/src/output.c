#include "output.h"


void fprintLista(FILE* f, Lista* lista) {
	printf("[");
	if(lista != NULL){
		fprintf(f,"%d%c", lista->inf->valore, lista->inf->seme);
		lista = lista->next;
	}
	while(lista != NULL)
	{
		fprintf(f,", %d%c", lista->inf->valore, lista->inf->seme);
		lista = lista->next;
	}
	printf("]\n");
}

void fprintMazzo(FILE* f, Coda* mazzo) {
	fprintf(f,"Carte nel mazzo:\n");
	fprintLista(f,mazzo->primo);
}

void fprintGiocatori(FILE* f, Pila** giocatori, size_t sz){
	for(int i=0;i<sz;i++)
	{
		fprintf(f,"Mano giocatore %d:\n", i+1);
		fprintLista(f,giocatori[i]->cima);
	}
}

void fprintTavolo(FILE* f, Lista* tavolo){
	printf("Carte in tavola:\n");
	fprintLista(f,tavolo);
}
