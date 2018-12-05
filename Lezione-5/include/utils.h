#include <stdlib.h>
#include <stdio.h>
#include "abr.h"

#define MAX_EL 100



int* creaArrayRandom(int dim);
void fprintArray(FILE* f, int* A, int dim);

void printAlbero(Nodo* r);
void visita(Nodo* r);

void swap(int* a, int* b);
int partition(int* A, int begin, int end);
void quicksort(int* A, int begin, int end);

void timerStart();
double timerValue();
