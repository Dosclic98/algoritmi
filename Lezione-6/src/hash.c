#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define PRIME 73

/*inserisce un nuovo elemento nella tabella*/
int hashInsert(bucket* T[], bucket* e, int m){
	int i=0;
	do{
		int j = h(e->id,i,m);
		if(T[j]==NULL){
			T[j] = e;
			return j;
		}
		else i++;
	}while(i<m);
	return -1;
}
/*cerca un elemento nella tabella e ritorna le hit efettuate*/
int hashSearch(bucket* T[], long int key, int m, int* hits) {
	int i=0;
	int j=0;
	*hits = 0;
	do{
		*hits += 1;
		j = h(key,i,m);
		if(T[j]->id == key) return j;
		else i++;
	} while( (T[j]!=NULL) && i<m);
	return -1;
}

/*dealloca un bucket**/
void destroyBucket(bucket* elem) {
	printf("distrutto %ld, %s, %s\n", elem->id, elem->nome, elem->cognome);
	free(elem->nome);
	free(elem->cognome);
	free(elem);
}

/*dealloca lo spazio usato dalla tabella*/
void destroyTable(bucket** table, size_t size) {
	for(size_t i=0; i < size; i+=1) {
		if(table[i] != NULL){
			destroyBucket(table[i]);
		}
	}
}

int h(int k, int i, int m){
	return (h1(k,m) + i) % m;
}

int h1(int k, int m){
	return (k % m);
}
