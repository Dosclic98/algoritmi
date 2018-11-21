#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


int* creaArrayRandom(int dim) {
	// ALLOC
	int* arr = malloc(dim * sizeof(int));
	for(int i=0; i < dim; i+=1)
		arr[i] = rand();
	return arr;
}

int* copyArray(int* A, int dim) {
	int* arr = malloc(dim * sizeof(int));
	memcpy(arr, A, dim * sizeof(int));
	return arr;
}

void fprintArray(FILE* f, int* A, int dim) {
	printf("[");
	if(dim > 0)
		fprintf(f,"%d", A[0]);
	
	// attenzione, si inizia da 1 perche' il primo elemento
	// (se esistente) e' gia' stato stampato
	for(int i=1; i < dim; i+=1)
		fprintf(f,", %d", A[i]);
		
	printf("]\n");
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

