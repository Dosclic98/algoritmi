#include "file.h"
#include <stdlib.h>

void printBucket(bucket* tmp){
	printf("[%ld, %s, %s]\n", tmp->id, tmp->nome, tmp->cognome);
}

int main(int argc, char* argv[]){
	const int n = 79;
	const int m = 79;
	bucket** T = malloc(m*sizeof(bucket*));
	id_t* ids= malloc(n*sizeof(id_t));
	FILE* inp = fopen("studenti.txt","r");

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
	sumHits = sumHits/n;
	printf("hits medie: %d\n", sumHits);
}

