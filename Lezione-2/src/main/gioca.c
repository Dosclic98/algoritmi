#include "output.h"
#include "gioca_utils.h"

int main(int argn, char** args) {
	Coda* mazzo = creaCarteMazzo();

	Pila* giocatori[4];
	inizializzaGiocatori(giocatori);

	Lista* tavolo = makeLista();

	fprintMazzo(stdout, mazzo);
	fprintGiocatori(stdout,giocatori,4);
	fprintTavolo(stdout, tavolo);

	printf("Si mischia\n");
	mixCarte(mazzo, 4*N_CARTE_PER_SEME);
	fprintMazzo(stdout, mazzo);

	printf("Disposizione delle 4 carte sul tavolo\n");
	tavolo = initTavolo(tavolo, mazzo);
	fprintTavolo(stdout, tavolo);

	pause();

	for(int i = 0; i<3; i+=1){
		assegnaCarte(mazzo,giocatori,4);
		for(int j = 0; j<3; j+=1)
		{
			printf("--- Mano %d ---\n", j+1+(i*3));
			for(int k = 0; k<4; k+=1){
				Elemento* tavoloInsert = pop(giocatori[k]);
				tavolo = inserisci(tavoloInsert,tavolo);
				fprintf(stdout,"Carta giocata da giocatore %d: %d%c\n", k+1, tavoloInsert->valore, tavoloInsert->seme);
			}
			fprintMazzo(stdout, mazzo);
			fprintGiocatori(stdout,giocatori,4);
			fprintTavolo(stdout, tavolo);
			// Ferma sempre il gioco tranne all ultima giocata dell'ultima mano
			if(i!=2 || j!=2) pause();
		}
	}

	distruggiLista(&tavolo);
	free(tavolo);

	distruggiPila(giocatori[0]);
	distruggiPila(giocatori[1]);
	distruggiPila(giocatori[2]);
	distruggiPila(giocatori[3]);

	distruggiCoda(mazzo);
	free(mazzo);

	exit(EXIT_SUCCESS);
}
