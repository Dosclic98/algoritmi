#include <utils.h>
#include <abr.h>
#include <time.h>

#define NUMS_PER_LINE 10



int main(int argc, char** args) {
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

		printf("Array:\n");
		fprintfArray(stdout, array, dimArray, NUMS_PER_LINE);
		printf("\nAlbero:\n");
		printAlbero(radice, NUMS_PER_LINE);
		

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

		printf(
				"\n"
				"TEMPI di esecuzione delle funzioni di ordinamento per dimensione %d:\n"
				"\t%1.6lfs (ordinamento di array);\n"
				"\t%1.6lfs (creazione dell'albero di ricerca)\n"
				"\n", dimArray, t2, t1);
		printf(
				"HIT medi delle funzioni di ricerca:\n"
				"\t%-2d (ricerca binaria);\n"
				"\t%-2d (ricerca nell'albero)\n", hitsArr, hitsABR);
				
		printf("-----------------------------\n");
		free(array);
		distruggiAlbero(radice);

	}
	fclose(f1);
	fclose(f2);
}
