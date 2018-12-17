#include "hash.h"

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

int hashSearch(bucket* T[], bucket* e, int m){
	int i=0;
	do{
		int j = h(e->key,i,m);
		if(T[j] == e->key) return j;
		else i++;
	}while( (T[j]!=NULL) && i<m);
	return -1;
}
