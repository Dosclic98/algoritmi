#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nodo{
	int inf;
	struct nodo *sinistro, *destro;
}Nodo;

Nodo* makeNodo(int inf);
Nodo* makeTree(int n);
void visita(Nodo* r);
void visitaProf(Nodo* corr);
void visitaAmp(Nodo* corr); 
