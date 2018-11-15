#include "gioca_utils.h"



Coda* creaCarteSeme(seme_t seme) {
	Coda* retn = makeCoda();
	Elemento* newEl;
	
	for(int i=1; i <= N_CARTE_PER_SEME; i+=1) {
		newEl = malloc(sizeof(Elemento));
		newEl->valore = i;
		newEl->seme = seme;
		enqueue(newEl, retn);
	}
	
	return retn;
}

void printElem(Elemento* elem) {
	printf("%d, %c\n", elem->valore, elem->seme);
}

void mixCarte(Coda* mazzo, size_t sz) {
	 /* "ottimizzazione" necessaria: se il resto della funzione fosse
	  * eseguito, potrebbe esserci un U.B. nella fase di randomizzazione */
	if(sz == 0) return;

	 // array di Elemento*
	Elemento** elementi = malloc(sizeof(Elemento*) * sz);
	Elemento* cartaPresa;
	
	// copia tutte le carte all'interno dell'array
	for(int i=0; i<sz; i+=1) {
		cartaPresa = dequeue(mazzo);
		assert(cartaPresa != NULL);
		elementi[i] = cartaPresa;
	}
	
	/* seleziona una carta, e effettua swap con elementi a caso nell'array;
	 * ricrea la coda nel frattempo */
	srand(time(NULL));
	int rnd1 = 0;
	int rnd2 = 0;
	for(int i=0; i<sz; i+=1) {
		rnd1 = rand() % sz;
		rnd2 = rand() % sz;
		cartaPresa = elementi[rnd1];
		elementi[rnd1] = elementi[rnd2];
		elementi[rnd2] = cartaPresa;
	}
	for(int i=0; i<sz; i+=1){
		enqueue(elementi[i], mazzo);
	}
}

