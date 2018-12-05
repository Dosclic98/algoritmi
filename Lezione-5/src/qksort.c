void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int* A, int begin, int end) {
	int pivot, l, r, random;

	pivot = A[begin];
	l = begin + 1;
	r = end;
	while(l<=r){
		while(A[r] > pivot) r=r-1;
		while((A[l]<=pivot) && (l<=r)) l=l+1;
		if(l<r){
			swap(&A[l], &A[r]);
			l++;
			r--;
		}
	}
	swap(&A[begin],&A[r]);
	return r;
}

void quicksort(int* A, int begin, int end) {
	int q;

	if(begin<end) {
		q = partition(A,begin,end);
		quicksort(A,begin,q-1);
		quicksort(A,q+1,end);
	}
}
