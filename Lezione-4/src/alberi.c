#include "alberi.h" 

Nodo* makeNodo(int inf){
	Nodo* newNode = malloc(sizeof(Nodo));
	newNode->destro = newNode->sinistro = NULL;
	newNode->inf = inf;
	return newNode;
}

Nodo* makeTree(int n){
	if(n>0){
		int numFigliSX = (n-1)/2;
		int numFigliDX = (n-1) - numFigliSX;
		
		Nodo* newNode = makeNodo(rand() % 100);
		newNode->sinistro = makeTree(numFigliSX);
		newNode->destro = makeTree(numFigliDX);
		return newNode;
	}
	return NULL;
}

void visitaProf(Nodo* corr){
	if(corr == NULL) return;
	
	visita(corr);
	visitaProf(corr->sinistro);
	visitaProf(corr->destro);
}

void visita(Nodo* r){
	printf("%d\n", r->inf);
}
