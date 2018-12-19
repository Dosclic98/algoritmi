#include <stdbool.h>



typedef int (*hash_func)(int);

typedef struct bucket {
	long int id;
	char* nome;
	char* cognome;
} bucket;

int hashInsert(bucket* T[], bucket* e, int m, hash_func hash1, hash_func hash2);
int hashSearch(bucket* T[], long int key, int m, hash_func hash1, hash_func hash2);
int h(int key, int i, hash_func hash1, hash_func hash2);

int h2(int k);
int h1(int k);
int xorshift(int k);
