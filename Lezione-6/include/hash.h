#include <stdbool.h>

typedef struct{
	long int id;
	char* nome;
	char* cognome;
}bucket;

int hashInsert(bucket* T[], bucket* e, int m);
int hashSearch(bucket* T[], bucket* e, int m);
int h(int k, int i, int m);
int h1(int k, int m);
int h2(int k, int m);
