#include "output.h"
#include "gioca_utils.h"



Coda* mazzo;

int main(int argn, char** args) {
	mazzo = creaCarteSeme(CUORI);
	mixCarte(mazzo, N_CARTE_PER_SEME);
	fprintMazzo(stdout, mazzo);
	distruggiCoda(mazzo);
	
	exit(EXIT_SUCCESS);
}
