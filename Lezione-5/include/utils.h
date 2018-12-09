#include <stdlib.h>
#include <stdio.h>
#include "abr.h"

#define MAX_EL 10000



int* creaArrayRandom(int dim);

/* Scrive sul file dato un array. */
void fprintArray(FILE* f, int* A, int dim);

/* Scrive sul file dato un array, formattando l'output in
 * un dato numero di colonne. */
void fprintfArray(FILE* f, int* A, int dim, int maxLn);

/* Cerca un elemento all'interno dell'array, e restituisce
 * il numero di divisioni effettuate (che e' asintotico al
 * tempo di esecuzione della funzione stessa). */
int ricBin(int* array, int n, int x);

void printAlbero(Nodo* r);
void visita(Nodo* r);

void swap(int* a, int* b);
int partition(int* A, int begin, int end);
void quicksort(int* A, int begin, int end);

/* Inizializza il cronometro. */
void timerStart();

/* Restituisce il tempo passato, in secondi, dall'ultima
 * chiamata di timerStart(). */
double timerValue();
