#include "output.h"
#include "gioca_utils.h"

static void inizializzaGiocatori(Pila** giocatori){
	for(int i=0;i<4;i+=1){
		giocatori[i] = makePila();
	}
}

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
	
	tavolo = initTavolo(tavolo, mazzo);
	fprintTavolo(stdout, tavolo);
	
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
