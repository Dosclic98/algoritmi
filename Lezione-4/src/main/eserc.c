#include "alberi.h"
#include "code.h"
int maxOf(int a, int b){
	if(a >= b) return a;
	else return b;
}

int minOf(int a, int b){
	if(a <= b) return a;
	else return b;
}

int altezza(Nodo* r){
	if(r == NULL) return 0;
	
	return maxOf(altezza(r->sinistro),altezza(r->destro))+1;
}

int altezzaMin(Nodo* r){
	if(r == NULL) return 0;
	
	return minOf(altezzaMin(r->sinistro),altezzaMin(r->destro))+1;
}


int numFoglie(Nodo* r){
	if(r == NULL) return 0;
	if((r->sinistro == NULL) && (r->destro == NULL)) return 1;
	
	return numFoglie(r->destro) + numFoglie(r->sinistro);
}

int numFogliePari(Nodo* r){
	if(r == NULL) return 0;
	if(((r->sinistro == NULL) && (r->destro == NULL)) && (r->inf % 2 == 0)) return 1;
	
	return numFogliePari(r->destro) + numFogliePari(r->sinistro);	
}
// Non va
void printFoglieLivPari(Nodo* r){
	static int i = 0;
	i++;
	// printf("%d\n", i);
	if(r == NULL) return;
	if(((r->sinistro == NULL) && (r->destro == NULL)) && (i % 2 == 0)) printf("%d\n", r->inf);
	
	printFoglieLivPari(r->sinistro);
	i--;	
	printFoglieLivPari(r->destro);
	i--;
}

int numNodi(Nodo* r){
	if(r == NULL) return 0;
	if((r->sinistro == NULL) && (r->destro == NULL)) return 1;
	
	return numNodi(r->sinistro) + numNodi(r->destro) + 1;
}

bool cerca(Nodo* r, int x){
	if(r==NULL) return false;
	if(r->inf == x) return true;
	
	if(cerca(r->sinistro,x)) return true;
	if(cerca(r->destro,x)) return true;
	return false;
}

int sommaRic(Nodo* r){
	if(r==NULL) return 0;
	return sommaRic(r->sinistro) + sommaRic(r->destro) + r->inf;
}


int sommaIter(Nodo* r){
	Coda* p = nuovaCoda();
	
	Nodo* tmp = NULL;
	int somma = 0;
	if(r!=NULL){
		enqueue(p,r);
		while(!codaVuota(p)){
			tmp = dequeue(p);
			if(tmp!=NULL){
				somma+=tmp->inf;
				enqueue(p,tmp->sinistro);
				enqueue(p,tmp->destro);
			}
		}
	}
	return somma;
}

int bigger(Nodo* r){
	if(r==NULL) return -1;
	return maxOf(maxOf(bigger(r->sinistro),bigger(r->destro)),r->inf);
}

bool isBigger(Nodo* r){
	if(r->inf >= bigger(r)) return true;
	else return false;
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
	printf("L'altezza massima dell'albero è %d\n", altezza(root));
	printf("L'altezza minima dell'albero è %d\n", altezzaMin(root));
	printf("L'albero ha %d foglie\n", numFoglie(root));
	printf("L'albero ha %d foglie pari\n", numFogliePari(root));
	printf("L'albero ha %d nodi\n", numNodi(root));
	
	if(cerca(root,15))printf("Trovato\n");
	else printf("Non trovato\n");
	
	printf("La somma ricorsiva dei nodi e': %d\n", sommaRic(root));
	printf("La somma iterativa dei nodi e': %d\n", sommaIter(root));

	if(isBigger(root))printf("Elemento più grande nella radice\n");
	else printf("Non in radice\n");
	
	printf("L'elemento più grande dell'albero e': %d\n", bigger(root));
	printf("Stampo foglie pari\n");
	printFoglieLivPari(root);
}
