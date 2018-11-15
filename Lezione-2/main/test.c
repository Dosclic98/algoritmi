#include "output.h"
#include "gioca_utils.h"



Coda* mazzo;

int main(int argn, char** args) {
	mazzo = creaCarteSeme(CUORI);
	// da aggiustare mix
	mixCarte(mazzo, N_CARTE_PER_SEME);
	fprintMazzo(stdout, mazzo);
	
	exit(EXIT_SUCCESS);
}
