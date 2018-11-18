#include "gioca_utils.h"



Coda* creaCarteMazzo() {
	Coda* retn = makeCoda();
	Elemento* newEl;
	seme_t semi[4] = {CUORI, QUADRI, FIORI, PICCHE};
	for(int j=0;j<4;j+=1)
	{
		for(int i=1; i <= N_CARTE_PER_SEME; i+=1) {
			newEl = malloc(sizeof(Elemento));
			newEl->valore = i;
			newEl->seme = semi[j];
			enqueue(newEl, retn);
		}
	}
	return retn;
}

void mixCarte(Coda* mazzo, size_t sz) {
	 /* "ottimizzazione" necessaria: se il resto della funzione fosse
	  * eseguito, potrebbe esserci un U.B. nella fase di randomizzazione */
	if(sz == 0) return;
	
	srand(time(NULL));
	int rnd1 = 0;
	int rnd2 = 0;
	
	Lista* tmp1 = NULL;
	Lista* tmp2 = NULL;
	
	Elemento* tmp = NULL;
	for(int i=0; i<sz; i+=1){
		tmp1 = mazzo->primo;
		tmp2 = mazzo->primo;
		
		rnd1 = rand() % sz;
		rnd2 = rand() % sz;
		
		for(int j=0; j<rnd1; j+=1){
			tmp1 = tmp1->next;
		}
		for(int k=0; k<rnd2; k+=1){
			tmp2 = tmp2->next;
		}
		tmp = tmp1->inf;
		tmp1->inf = tmp2->inf;
		tmp2->inf = tmp;
	}
}

void assegnaCarte(Coda* mazzo, Pila** giocatori, size_t sz){
	for(int j=0;j<3;j++){
		for(int i=0; i<sz; i++){
			Elemento* carta = dequeue(mazzo);
			push(carta, giocatori[i]);
		}
	}
}

Lista* giocaCarta(Pila* giocatore, Lista* mazzoCentro){
	Elemento* carta = pop(giocatore);
	return inserisci(carta, mazzoCentro);
}

Lista* initTavolo(Lista* tavolo, Coda* Mazzo){
	for(int i=0; i<4; i+=1)
	{
		Elemento* carta = dequeue(Mazzo);
		tavolo = inserisci(carta, tavolo);
	}
	return tavolo;
}

void pause(){
	printf("\nPremere Invio per continuare:\n");
	getchar();
}
