#include "sort.h"
#include "utils.h"

void bubbleSort (int* A, int n){
	int ultimoScambiato = n-1;
	int scambiati = 1;
	int tmp = 0;
	int ultimoScambiatoTemp = 0;
	
	while(scambiati > 0){
		scambiati = 0;
		for(int i=0; i<ultimoScambiato; i++){
			if(A[i] > A[i+1]){
				tmp = A[i];
				A[i] = a[i+1];
				A[i+1] = tmp;
				
				ultimoScambiatoTemp = i;
				scambiati = 1;
			}
		}
		ultimoscambiato = ultimoScambiatoTemp;
	}
} 

int partition(int* A, int begin, int end){
	int pivot, l, r, random;
	
	pivot = A[begin];
	l = begin + 1;
	r = end;
	while(l<=r){
		while(A[r] > pivot) r=r-1;
		while((A[l]<=pivot) && (l<=r)) l=l+1;
		if(l<r){
			
		}
	}
}

void quicksort(int* A, int begin, int end){
	int q;
	
	if(begin<end){
		q = partition(A,begin,end);
		quicksort(A,begin,q-1);
		quicksort(A,q+1,end);
	}
}
