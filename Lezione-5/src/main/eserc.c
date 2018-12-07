#include <utils.h>
#include <abr.h>
#include <time.h>

#define NUMS_PER_LINE 10



int main(int argc, char** args) {
	//int dims[8] = {10,25,50,100,200,500,1000,2000};
	int dims[8] = {10,25,50,100,200,500,1000,2000};

	FILE* f1 = fopen("ords.csv","wt");
	FILE* f2 = fopen("searchs.csv","wt");
	fprintf(f1,"Dim,TempoAlbero,TempoArray\n");
	fprintf(f2,"Dim,HitsAlbero,HitsArray\n");
	srand(time(NULL));
	for(int i=0;i<8;i++){
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

		fprintf(f1,"%d,%lf,%lf\n", dimArray, t1, t2);

		fprintfArray(stdout, array, dimArray, NUMS_PER_LINE);
		printAlbero(radice);


		// Ricerche
		int hitsArr = 0;
		int hitsABR = 0;
		for(int j=0;j<dimArray;j++){
			int tmp = rand() % MAX_EL;

			hitsArr += ricBin(array,dimArray,tmp);
			hitsABR += cercaNodoHit(radice, tmp);
		}
		hitsArr = hitsArr/dimArray;
		hitsABR = hitsABR/dimArray;
		fprintf(f2,"%d,%d,%d\n", dimArray, hitsABR, hitsArr);


		/*
		printf("%d\n", ricBin(array,dimArray,83));
		printf("%d\n", ricBin(array,dimArray,82));
		*/

		printf("\nTEMPI: %lfs, %lfs\n----------------\n", t1, t2);
		printf("\nHITS: %d, %d\n----------------\n", hitsArr, hitsABR);
		free(array);
		distruggiAlbero(radice);

	}
	fclose(f1);
	fclose(f2);
}
