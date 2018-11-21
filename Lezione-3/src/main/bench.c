#include "sort.h" 
#include "utils.h"
#include <sys/time.h>

#define DIMENS 9

struct timeval T1, T2;

int main(){
	int numeroRun = 10;
	int dimensioni[DIMENS] = {5, 10, 25, 50, 100, 200, 500, 1000, 2000};
	for(int i=0;i<DIMENS;i++){
		int n = dimensioni[i];
		int timeBubble = timeQuick = timeHeap = 0;
		
		for(int k=1;k<=numeroRun;k++){
			int* testArray = creaArrayRandom(10);
			
			int* arrayDaOrdinare = copyArray(testArray,10);
			
		}
	}
}
