#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct elemento{
	int campo1;
	char campo2[20];
}Elemento;

typedef struct Nodo_Lista{
	Elemento inf;
	struct Nodo_Lista;
} Lista;

Lista* makeLista();
int emptyL(Lista* l);
Elemento primo(Lista* l);
Lista* creaNodo(Elemento el);
void visualizza_lista(Lista* l);
Lista* inserisci(Elemento el, Lista* l);
Lista* rimuovi(Lista* lptr);

