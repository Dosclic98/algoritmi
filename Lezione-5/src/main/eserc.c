#include <utils.h>
#include <abr.h>



int main(int argc, char** args) {
	//int dims[8] = {10,25,50,100,200,500,1000,2000};
	int dims[8] = {10,25,50,100,200,500,1000,2000};

	for(int i=0;i<1;i++){
		int dimArray = dims[i];
		double t1, t2;
		int* array = creaArrayRandom(dimArray);
		Nodo* radice = NULL;

		timerStart();
		radice = creaAlbero(array, dimArray);
		t1 = (double) timerValue();

		timerStart();
		quicksort(array,0,dimArray-1);
		t2 = (double) timerValue();

		fprintArray(stdout,array,dimArray);
		printAlbero(radice);

		printf("\nTEMPI: %lfs, %lfs\n----------------\n", t1, t2);
	}
}
