 #ifndef LISTE_H
 #define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define CUORI   'c'
#define QUADRI  'q'
#define FIORI   'f'
#define PICCHE  'p'

typedef struct elemento{
	int valore;
	char seme;
}Elemento;

typedef struct Nodo_Lista{
	Elemento* inf;
	struct Nodo_Lista* next;
} Lista;

Lista* makeLista();
int emptyL(Lista* l);
Elemento* primo(Lista* l);
Lista* creaNodo(Elemento* el);
Lista* inserisci(Elemento* el, Lista* l);
Lista* rimuovi(Lista* lptr);
void distruggiLista(Lista** lista);

 #endif
