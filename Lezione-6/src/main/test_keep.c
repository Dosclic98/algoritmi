#include "file.h"
#include <stdlib.h>

void printBucket(bucket* tmp){
	printf("[%ld, %s, %s]\n", tmp->id, tmp->nome, tmp->cognome);
}

void test(FILE* inp, FILE* out, int n, int m) {
	bucket** T = malloc(m*sizeof(bucket*));
	id_t* ids= malloc(n*sizeof(id_t));
	double avg = 0;
	for(int j=0; j<m; j++){
		T[j] = NULL;
	}

	// Lettura - Inserzione
	for(int i=0; i<n; i++){
		bucket* tmp = bucketCreat(inp);
		printBucket(tmp);
		ids[i] = tmp->id;
		int ins = hashInsert(T, tmp, m);
		if(ins == -1)
			puts("Non inserito\n");
	}

	// Ricerca
	int hits = 0;
	int sumHits = 0;
	for(int i=0; i<n; i++){
		if(hashSearch(T, ids[i], m, &hits) != -1)
			printf("Trovato %d ", i+1);
		else
			printf("Non Trovato ");
		sumHits += hits;
		printf("Hits %d\n", hits);
	}
	avg = (double) sumHits/n;
	fprintf(out, "%f,%lf\n", (float)n/(float)m, avg);
	rewind(inp);
}

int main(int argc, char** argv) {
	FILE* inp = fopen("studenti.txt", "r");
	FILE* out = fopen("output.txt", "w");
	fprintf(out, "a,hitMedie\n");

	const int n = 80;
	int m_array[6] = {880, 720, 560, 400, 240, 80};
	for(int i=0; i<6; i++) {
		test(inp, out, n, m_array[i]);
	}

	fclose(out);
}
