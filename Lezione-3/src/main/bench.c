#include "sort.h" 
#include "utils.h"
#include <time.h>
#include <locale.h>

#define SCL 1
#define NUMERORUN 10
clock_t T1, T2;

void bench(int begin, int end, int step,  FILE* f){
	for(int i=begin; i <= end; i+=step) {
		int n = i*SCL;
		double timeBubble = 0;
		double timeQuick = 0;
		double timeHeap = 0;
		
		for(int k=1; k<=NUMERORUN; k++) {
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
			timeBubble/NUMERORUN,
			timeQuick/NUMERORUN,
			timeHeap/NUMERORUN);
		fprintf(f,"%d,%lf,%lf,%lf\n", n, timeBubble/NUMERORUN, timeQuick/NUMERORUN, timeHeap/NUMERORUN);
	}
	
}

int main(int argn, char** argv) {
	FILE* f1 = fopen("table1.csv","w+");
	if(f1==NULL){
		printf("Errore apertura file\n");
		exit(1);
	}

	FILE* f2 = fopen("table2.csv","w+");
	if(f2==NULL){
		printf("Errore apertura file\n");
		exit(1);
	}

	fprintf(f1,"Dimensione,timeBubble,timeQuick,timeHeap\n");
	fprintf(f2,"Dimensione,timeBubble,timeQuick,timeHeap\n");
	
	bench(5,25,1,f1);
	bench(50,2000,250,f2);
	
	fclose(f1);
	fclose(f2);
}

