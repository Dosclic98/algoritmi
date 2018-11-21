#include <stdio.h> 
#include <stdlib.h>

void bubbleSort (int* A, int n);

void quicksort(int* A, int begin, int end);
int partition(int* A, int begin, int end);

void fixHeap(int* A, int i, int HeapSize);
void heapify(int* A, int n);
void heapSort(int* A, int n);
