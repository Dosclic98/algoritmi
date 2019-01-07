#include "file.h"
#include <stdlib.h>

void printBucket(bucket* tmp){
	printf("[%ld, %s, %s]\n", tmp->id, tmp->nome, tmp->cognome);
}

void test(FILE* inp, FILE* out, int n, int m) {
	bucket** T = malloc(m*sizeof(bucket*));
	id_t* ids = malloc(n*sizeof(id_t));
	double avg = 0;
	for(int j=0; j<m; j++){
		T[j] = NULL;
	}

	// Lettura - Inserimento
	for(int i=0; i<n; i++){
		bucket* tmp = bucketCreat(inp);
		printBucket(tmp);
		ids[i] = tmp->id;
		int ins = hashInsert(T, tmp, m);
		if(ins == -1) {
			destroyBucket(tmp);
			puts("Non inserito\n");
		}
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

	avg = (double)sumHits/(double)n;
	fprintf(out, "%f,%lf\n", (float)n/(float)m, avg);
	printf(" Hit medie: %f\n", avg);

	destroyTable(T, m);
	free(ids);
	free(T);
	rewind(inp);
}

int main(int argc, char** argv) {
	FILE* inp = fopen("studenti.txt", "r");
	FILE* out = fopen("output.csv", "w");
	fprintf(out, "a,hitMedie\n");

	const int n = 80;
	// int m_array[6] = {160, 133, 114, 100, 88, 80};
	int m_array[6] = {400, 200, 133, 100, 80};
	for(int i=0; i<5; i++) {
		test(inp, out, n, m_array[i]);
	}

	fclose(inp);
	fclose(out);
}
