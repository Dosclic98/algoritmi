#include "sort.h" 
#include "utils.h"
#include <sys/time.h>

#define DIMENS 9

struct timeval T1, T2;

long getTime(timeval T1, timeval T2){
	long seconds = T2.tv_sec - T1.tv_sec;
	long useconds = T2.tv_usec - T1.tv_usec;
	
	long tempoDiEsecuzione = ((seconds) * 1000 + useconds/1000.0) + 0.5:
	return tempoDiEsecuzuone;
}

int main(){
	int numeroRun = 10;
	int dimensioni[DIMENS] = {5, 10, 25, 50, 100, 200, 500, 1000, 2000};
	for(int i=0;i<DIMENS;i++){
		int n = dimensioni[i];
		int timeBubble = timeQuick = timeHeap = 0;
		
		for(int k=1;k<=numeroRun;k++){
			int* testArray = creaArrayRandom(10);
			
			int* arrayDaOrdinare = copyArray(testArray,10);
			gettimeofday(&T1, NULL);
			bubbleSort(arrayDaOrdinare, 10);
			gettimeofday(&T2, NULL);
			timeBubble = timeBubble + getTime(T1,T2);
			free(arrayDaOrdinare);
			
			arrayDaOrdinare = copyArray(testArray,10);
			gettimeofday(&T1, NULL);
			quicksort(arrayDaOrdinare,0,9);
			gettimeofday(&T2, NULL);
			timeQuick = timeQuick + getTime(T1,T2);
			free(arrayDaOrdinare);

			arrayDaOrdinare = copyArray(testArray,10);
			gettimeofday(&T1, NULL);
			heapSort(arrayDaOrdinare, 10);
			gettimeofday(&T2, NULL);
			timeHeap = timeHeap + getTime(T1,T2);
			free(arrayDaOrdinare);
			
			free(testArray);
		}
		printf("timeBubble: %d, timeQuick: %d, timeHeap %d\n", timeBubble/numeroRun, timeQuick/numeroRun, timeHeap/numeroRun);
	}
}
