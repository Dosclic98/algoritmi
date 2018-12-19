#include <stdbool.h>



typedef struct bucket {
	long int id;
	char* nome;
	char* cognome;
} bucket;

int hashInsert(bucket* T[], bucket* e, int m);
int hashSearch(bucket* T[], long int key, int m, int* hitsReturn);
int h(int key, int i, int mod);

int h1(int k, int m);
int h2(int k, int m);
int xorshift(int k);
int findPrime(int upperBound);
