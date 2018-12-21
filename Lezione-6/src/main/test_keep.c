#include "file.h"
#include <stdlib.h>

void printBucket(bucket* tmp){
	printf("[%ld, %s, %s]\n", tmp->id, tmp->nome, tmp->cognome);
}

void test(const int m, FILE* out, FILE* inp){
	const int n = 80;
	bucket** T = malloc(m*sizeof(bucket*));
	id_t* ids= malloc(n*sizeof(id_t));
	double avg = 0;
	for(int j=0;j<m;j++){
		T[j] = NULL;
	}
	for(int i=0;i<n;i++){
		bucket* tmp = bucketCreat(inp);
		printBucket(tmp);
		ids[i] = tmp->id;
		int ins = hashInsert(T,tmp,m);
		if(ins == -1) puts("Non inserito\n");
	}
	
	// Ricerca
	int hits = 0;
	int sumHits = 0;
	for(int i=0;i<n;i++){
		if(hashSearch(T,ids[i],m, &hits) != -1) printf("Trovato %d ", i+1);
		else printf("Non Trovato ");
		sumHits+=hits;
		printf("Hits %d\n", hits);
	}
	avg = (double) sumHits/n;
	fprintf(out,"%f,%lf\n", (float)n/(float)m, avg);
	rewind(inp);
}

int main(int argc, char* argv[]){
	FILE* out = fopen("output.txt","w");
	FILE* inp = fopen("studenti.txt","r");
	fprintf(out,"a,hitMedie\n");
	int A[6] = {1000, 700, 500, 200, 100, 80};
	for(int i=0;i<6;i++){
		test(A[i],out,inp);
	}
	
	fclose(out);
}
