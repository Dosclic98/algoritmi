#include <stdlib.h>
#include <stdio.h>
#include "abr.h"

#define MAX_EL 10000
#define TAB_VISITA ".  "



int* creaArrayRandom(int dim);

/* Scrive sul file dato un array. */
void fprintArray(FILE* f, int* A, int dim);

/* Scrive sul file dato un array, formattando l'output in
 * un dato numero di colonne. */
void fprintfArray(FILE* f, int* A, int dim, int maxLn);

/* Cerca un elemento all'interno dell'array, e restituisce
 * il numero di divisioni effettuate (numero di cicli
 * in "while(start<end)"). */
int ricBin(int* array, int n, int x);

/* Effettua una visita in ordine a partire dalla radice 
 * passata come parametro (stampa l'albero in maniera ordinata). */
void printAlbero(Nodo* r, int numsPerLine);

void swap(int* a, int* b);
int partition(int* A, int begin, int end);
void quicksort(int* A, int begin, int end);

/* Inizializza il cronometro. */
void timerStart();

/* Restituisce il tempo passato, in secondi, dall'ultima
 * chiamata di timerStart(). */
double timerValue();
