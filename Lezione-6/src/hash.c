#include <stdlib.h>
#include "hash.h"

#define PRIME 73

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

int h(int k, int i, int m){
	return (h1(k,m) + i*h2(k,m)) % m;
}

int h1(int k, int m){
	return (k % m);
}

int h2(int k, int m){
	return 1 + (k % (m-1));
}

 /*XORSHIFT con modulo
int h2(int k, int mod) {
	k ^= k << 13;
	k ^= k >> 14;
	k ^= k << 7;
	k ^= k >> 10;
	k ^= k << 3;
	if(k < 0) k = -k;
	return k % mod;
}
*/

static
bool prime(int n) {
	if(n == 2) return true;

	int half = (n/2)+1;
	for(int i=3; i < half; i+=1) {
		if((n % i) == 0)
			return false;
	}
	return true;
}

int findPrime(int n) {
	for(int i=(n-1); i >= 0; i-=1) {
		if(prime(i))
			return i;
	}
	return 2;
}
