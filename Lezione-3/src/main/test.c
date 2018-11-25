#include "sort.h" 
#include "utils.h"
#include <stdbool.h>

// Controlla se l'array è ordinato
bool isSorted(int* A, int n){
	for(int i=0; i<n-1; i+=1){
		if(A[i] > A[i+1]) return false;
	}
	return true;
}

int main(int argc, char* argv[]){
	int* A = creaArrayRandom(10);
	int* B = creaArrayRandom(10);
	int* C = creaArrayRandom(10);

	fprintArray(stdout, A, 10);
	fprintArray(stdout, B, 10);
	fprintArray(stdout, C, 10);
	
	if(!isSorted(A,10)) printf("false\n");
	else printf("true\n");

	if(!isSorted(B,10)) printf("false\n");
	else printf("true\n");

	if(!isSorted(C,10)) printf("false\n");
	else printf("true\n");
	
	printf("...SORTING...\n");
	// SORT
	quicksort(A, 0, 9);
	bubbleSort(B, 10);
	heapSort(C, 10);
	
	fprintArray(stdout, A, 10);
	fprintArray(stdout, B, 10);
	fprintArray(stdout, C, 10);
	
	if(!isSorted(A,10)) printf("false\n");
	else printf("true\n");

	if(!isSorted(B,10)) printf("false\n");
	else printf("true\n");

	if(!isSorted(C,10)) printf("false\n");
	else printf("true\n");

}

