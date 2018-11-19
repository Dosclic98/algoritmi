#include "gioca_utils.h"


/* Alloca lo spazio di 40 elementi (10 per ogni seme) e li
 * inizializza, dopodiche' restituisce la coda creata */
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

/* Mescola le carte, con il seguente algoritmo:
 * 1. si selezionano due indici, rnd1 e rnd2;
 * 2. si scorre ciascuna lista finche' non si trova l'elemento
 *    corrispondente;
 * 3. si scambiano i due elementi. */
void mixCarte(Coda* mazzo, size_t sz) {
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

/* Estrae 4 elementi dalla coda, e li distribuisce uno ad uno
 * alle pile (giocatori), ripetendo il ciclo 3 volte */
void assegnaCarte(Coda* mazzo, Pila** giocatori, size_t sz){
	for(int j=0;j<3;j++){
		for(int i=0; i<sz; i++){
			Elemento* carta = dequeue(mazzo);
			push(carta, giocatori[i]);
		}
	}
}

/* Estrae un elemento dalla pila (giocatore), lo inserisce nella lista
 * (tavolo) e restituisce l'elemento inserito */
Lista* giocaCarta(Pila* giocatore, Lista* mazzoCentro){
	Elemento* carta = pop(giocatore);
	return inserisci(carta, mazzoCentro);
}

/* Estrae 4 elementi dalla coda (mazzo), e li inserisce
 * nella lista (tavolo) */
Lista* initTavolo(Lista* tavolo, Coda* Mazzo){
	for(int i=0; i<4; i+=1)
	{
		Elemento* carta = dequeue(Mazzo);
		tavolo = inserisci(carta, tavolo);
	}
	return tavolo;
}

/* Alloca lo spazio necessario alle pile
 * relative a ciascun giocatore */
void inizializzaGiocatori(Pila** giocatori){
	for(int i=0;i<4;i+=1){
		giocatori[i] = makePila();
	}
}

/* Mette in pausa il processo, finche' non viene dato un input */
void pause(){
	printf("\nPremere Invio per continuare:\n");
	getchar();
}
