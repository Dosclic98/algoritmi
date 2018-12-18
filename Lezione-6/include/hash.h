#include <stdbool.h>



typedef long int id_t;

typedef struct bucket {
	id_t id;
	char nome[40];
	char cognome[40];
} bucket;

int hashInsert(bucket* T[], bucket* e, int m);
int hashSearch(bucket* T[], bucket* e, int m);
int h(int k, int i, int m);
int h1(int k, int m);
int h2(int k, int m);
