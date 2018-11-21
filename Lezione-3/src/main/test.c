#include "sort.h" 
#include "utils.h"

int main(int argc, char* argv[]){
	int* A = creaArrayRandom(10);
	int* B = creaArrayRandom(10);
	int* C = creaArrayRandom(10);
	
	quicksort(A, 0, 9);
	bubbleSort(B, 10);
	heapSort(C, 10);
	
	fprintArray(stdout, A, 10);
	fprintArray(stdout, B, 10);
	fprintArray(stdout, C, 10);
}

