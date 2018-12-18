#include "hash.h"
#define PRIME 73

int hashInsert(bucket* T[], bucket* e, int m){
	int i=0;
	do{
		int j = h(e->key,i,m);
		if(T[j]==NULL){
			T[j] = e;
			return j;
		}
		else i++;
	}while(i<m);
	return -1;
}

int hashSearch(bucket* T[], long int key, int m){
	int i=0;
	do{
		int j = h(key,i,m);
		if(T[j] == key) return j;
		else i++;
	}while( (T[j]!=NULL) && i<m);
	return -1;
}

int h(int k, int i, int m){
	return (h1(k,m) + i*h2(k,m)) % m;
}

int h1(int k, int m){
	return (key % m);
}

int h2(int k, int m){
	return PRIME - (key % PRIME);
}
