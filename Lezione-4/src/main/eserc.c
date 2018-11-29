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
void printFoglieLivPari(Nodo* r, int liv){
	if(r == NULL) return;
	if(((r->sinistro == NULL) && (r->destro == NULL)) && (liv % 2 == 0)) printf("%d\n", r->inf);
	
	printFoglieLivPari(r->sinistro,liv+1);	
	printFoglieLivPari(r->destro,liv+1);
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

int lessThan(Nodo* r, int x){
	int cond = 0;
	if(r==NULL) return 0;
	if(r->inf <= x) cond++;
	
	return lessThan(r->sinistro, x) + lessThan(r->destro, x) + cond;
	
}

bool isBelanced(Nodo* root){
	if(root==NULL) return true;
	
	int hs = altezza(root->sinistro);
	int hd = altezza(root->destro);
	
	if((hs-hs<=1 || hd-hs<=1) && isBelanced(root->sinistro) && isBelanced(root->destro)) return true;
	else return false;
}

bool pariDis(Nodo* r){
	bool cond;
	if(r->sinistro!=NULL && r->destro!=NULL){
		cond = (((r->sinistro->inf % 2) != 0) && ((r->destro->inf % 2) == 0));
		puts("Cond 1");
		return (pariDis(r->sinistro) && pariDis(r->destro) && cond);
	}
	else if(r->sinistro==NULL && r->destro!=NULL){
		cond = (((r->destro->inf % 2) == 0));
		puts("Cond 2");
		return (pariDis(r->destro) && cond);
	}
	else if(r->sinistro!=NULL && r->destro==NULL){
		cond = (((r->sinistro->inf % 2) != 0));
		puts("Cond 3");
		return (pariDis(r->sinistro) && cond);
	}
	else if(r->sinistro==NULL && r->destro==NULL){
		puts("Cond 4");
		return true;
	}

}

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Prendo %s n\n", argv[0]);
		exit(1);
	}
	int n = atoi(argv[1]);
	
	Nodo* root = makeTree(n);

	puts("Stampo albero profondità");
	visitaProf(root);
	puts("Stampo albero ampiezza");
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
	printFoglieLivPari(root,1);
	printf("Ci sono %d numeri minori o uguali di %d\n", lessThan(root,83),83);
	
	if(isBelanced(root)) puts("Albero bilanciato");
	else puts("Albero non bilanciato");
	
	if(pariDis(root)) puts("Rispetta consizione pari dispari");
	else puts("Non rispetta consizione pari dispari");
}
