#include <stdlib.h>
#include "hash.h"

#define PRIME 7

int hashInsert(bucket* T[], bucket* e, int m, hash_func hash1, hash_func hash2){
	int i=0;
	do{
		int j = h(e->id, i, hash1, hash2) % m;
		if(T[j]==NULL){
			T[j] = e;
			return j;
		}
		else i++;
	}while(i<m);
	return -1;
}

int hashSearch(bucket* T[], long int key, int m, hash_func hash1, hash_func hash2){
	int i=0;
	int j=0;
	do{
		j = h(key, i, hash1, hash2) % m;
		if(T[j]->id == key) return j;
		else i++;
	} while( (T[j]!=NULL) && i<m);
	return -1;
}

int h(int k, int i, hash_func hash1, hash_func hash2){
	return hash1(k) + i*hash2(k);
}

int h1(int k){
	return k;
}

int h2(int k){
	return PRIME - (k % PRIME);
}

int xorshift(int k) {
	k ^= k << 13;
	k ^= k >> 14;
	k ^= k << 7;
	k ^= k >> 10;
	k ^= k << 3;
	if(k <= 0) k = 1-k;
	return k;
}
