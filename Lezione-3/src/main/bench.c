#include "sort.h" 
#include "utils.h"
#include <time.h>

#define DIMENS 9

int main(int argn, char** argv) {
	int numeroRun = 10;
	int dimensioni[DIMENS] = {5, 10, 25, 50, 100, 200, 500, 1000, 2000};
	clock_t T1, T2;

	for(int i=0; i < DIMENS; i+=1) {
		int n = dimensioni[i];
		double timeBubble = 0;
		double timeQuick = 0;
		double timeHeap = 0;
		
		for(int k=1; k<=numeroRun; k++) {
			int* testArray = creaArrayRandom(n);
			int* arrayDaOrdinare = copyArray(testArray, n);

			// Valutazione del tempo impiegato dal Bubble Sort
			T1 = clock();
			bubbleSort(arrayDaOrdinare, n);
			T2 = clock();
			timeBubble = timeBubble + (double) (T2-T1) / CLOCKS_PER_SEC;
			free(arrayDaOrdinare);

			// Valutazione del tempo impiegato dal Quicksort
			arrayDaOrdinare = copyArray(testArray, n);
			T1 = clock();
			quicksort(arrayDaOrdinare, 0, n-1);
			T2 = clock();
			timeQuick = timeQuick + (double)(T2-T1) / CLOCKS_PER_SEC;
			free(arrayDaOrdinare);

			// Valutazione del tempo impiegato dall'Heap Sort
			arrayDaOrdinare = copyArray(testArray, n);
			T1 = clock();
			heapSort(arrayDaOrdinare, n);
			T2 = clock();
			timeHeap = timeHeap + (double) (T2-T1) / CLOCKS_PER_SEC;
			free(arrayDaOrdinare);
			
			free(testArray);
		}

		/* Formattazione della chiamata su piu' linee deliberata,
		 * da rivedere con calma */
		printf(
			"-----\ntimeBubble: %lf\ntimeQuick: %lf\ntimeHeap: %lf\n-----\n",
			timeBubble/numeroRun,
			timeQuick/numeroRun,
			timeHeap/numeroRun);
	}
}
