#include <utils.h>
#include <abr.h>



int main(int argc, char** args) {
	int dims[8] = {10,25,50,100,200,500,1000,2000};
	
	for(int i=0;i<1;i++){
		int dimArray = dims[i];
		int* array = creaArrayRandom(dimArray);
		Nodo* radice = NULL;
		radice = creaAlbero(array, dimArray);
		
		quicksort(array,0,dimArray-1);
		fprintArray(stdout,array,dimArray);
		printAlbero(radice);

	}
}
