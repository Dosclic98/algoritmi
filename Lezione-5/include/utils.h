#include <stdlib.h>
#include <stdio.h>
#include "abr.h"

#define MAX_EL 10000



int* creaArrayRandom(int dim);
void fprintArray(FILE* f, int* A, int dim);
void fprintfArray(FILE* f, int* A, int dim, int maxLn);
int ricBin(int* array, int n, int x);

void printAlbero(Nodo* r);
void visita(Nodo* r);

void swap(int* a, int* b);
int partition(int* A, int begin, int end);
void quicksort(int* A, int begin, int end);

void timerStart();
double timerValue();
