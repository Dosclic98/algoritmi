#include "sort.h"
#include "utils.h"


int left_i(int i) {
	return (2*i)+1;
}
int right_i(int i) {
	return (2*i)+2;
}
int parent_i(int i) {
	return (i-1)/2;
}


void fixHeap(int* A, int i, int size) {
	int l = left_i(i);
	int r = right_i(i);
	int largest_i;
	
	if((l < size) && (A[l] > A[i])) {
		largest_i = l;
	} else {
		largest_i = i;
	}
	
	if(r < size && (A[r] > A[largest_i])) {
		largest_i = r;
	}
	
	if(largest_i != i) {
		swap(A+i, A+largest_i);
		fixHeap(A, largest_i, size);
	}
}

void heapify(int* A, int n) {
	for(int i = (n/2); i >= 0; i-=1)
		fixHeap(A, i, n);
}

void heapSort(int* A, int n) {
	int hpSize = n;
	
	heapify(A, n);
	for(int i = n-1; i >= 1; i-=1) {
		swap(A, A+i);
		hpSize -= 1;
		fixHeap(A, 0, hpSize);
	}
}

