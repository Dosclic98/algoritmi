#include "utils.h"

int* creaArrayRandom(int dim) {
	// ALLOC
	int* arr = malloc(dim * sizeof(int));
	if(arr==NULL){
		printf("Errore allocazione array creazione\n");
		exit(1);
	}

	for(int i=0; i < dim; i+=1){
		arr[i] = rand() % MAX_EL;
	}
	return arr;
}

int ricBin(int* array, int n, int x){
	int hits=0;
	int start = 0;
	int middle;
	int end = n;

	while(end>start){
		hits++;
		middle = (start+end)/2;
		if(array[middle]==x) return hits;
		if(array[middle] > x){
			start = middle+1;
		}
		else{
			end = middle;
		}
	}
	return hits;
}

void fprintArray(FILE* f, int* A, int dim) {
	printf("[");
	if(dim > 0){
		fprintf(f,"%d", A[0]);
	}
	// attenzione, si inizia da 1 perche' il primo elemento
	// (se esiste) e' gia' stato stampato
	for(int i=1; i < dim; i+=1){
		fprintf(f,", %d", A[i]);
	}
	printf("]\n");
}

void fprintfArray(FILE* file, int* array, int dim, int maxLn) {
	if(dim <= 0) {
		fprintf(file, "[]");
		return;
	}

	fprintf(file, "[%-5d", array[0]);

	int i = 1;
	char sep;

	dim -= 1; // per farlo finire 1 elemento prima

	while(i < dim) {
		if((i % maxLn) == 0)
			sep = '\n';
		else
			sep = ' ';
		fprintf(file, "%c %-5d", sep, array[i]);
		i += 1;
	}

	if((i % maxLn) == 0)
		sep = '\n';
	else
		sep = ' ';
	fprintf(file, "%c %d]", sep, array[i]);

	if((i % maxLn) != 0)
		fprintf(file, "\n");
}

void visita(Nodo* r){
	printf("%d\n", r->inf);
}

void printAlbero(Nodo* r){
	if(r==NULL) return;

	printAlbero(r->sinistro);
	visita(r);
	printAlbero(r->destro);
}
