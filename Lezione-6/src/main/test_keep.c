// #include "hash.h"
#include "file.h"
#include <stdlib.h>

void printBucket(bucket* tmp){
	printf("[%ld, %s, %s]\n", tmp->id, tmp->nome, tmp->cognome);
}

int main(int argc, char* argv[]){
	const int n = 80;
	const int m = 86;
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
		hashInsert(T,tmp,m);
	}
	
	// Ricerca
	int hits = 0;
	for(int i=0;i<n;i++){
		hits += hashSearch(T,ids[i],m);
	}
}

