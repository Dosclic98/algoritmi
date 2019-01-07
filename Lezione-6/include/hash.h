#include <stdbool.h>
#include <stdlib.h>



typedef struct bucket {
	long int id;
	char* nome;
	char* cognome;
} bucket;

int hashInsert(bucket* T[], bucket* e, int m);
int hashSearch(bucket* T[], long int key, int m, int* hitsReturn);
void destroyBucket(bucket* bucket);
void destroyTable(bucket** table, size_t size);
int h(int key, int i, int mod);

int h1(int k, int m);
