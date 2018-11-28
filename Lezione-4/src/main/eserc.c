#include "alberi.h"

int maxOf(int a, int b){
	if(a >= b) return a;
	else return b;
}

int altezza(Nodo* r){
	if(r == NULL) return 0;
	
	return maxOf(altezza(r->sinistro),altezza(r->destro))+1;
}

int numFoglie(Nodo* r){
	if(r == NULL) return 0;
	if((r->sinistro == NULL) && (r->destro == NULL)) return 1;
	
	return numFoglie(r->destro) + numFoglie(r->sinistro);
}

int numFogliePari(Nodo* r){
	
}

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Prendo %s n\n", argv[0]);
		exit(1);
	}
	int n = atoi(argv[1]);
	
	Nodo* root = makeTree(n);
	visitaProf(root);
	puts("");
	visitaAmp(root);
	printf("L'altezza dell'albero è %d\n", altezza(root));
}
