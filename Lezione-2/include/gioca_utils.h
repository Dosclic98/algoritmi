#include "pile.h"
#include "code.h"

#define N_CARTE_PER_SEME  10
#define N_GIOCATORI     4

#define CUORI   'c'
#define QUADRI  'q'
#define FIORI   'f'
#define PICCHE  'p'

typedef char seme_t;

Coda* creaCarteMazzo();
void mixCarte(Coda* mazzo, size_t sz);
void assegnaCarte(Coda* mazzo, Pila** giocatori, size_t sz);
Lista* giocaCarta(Pila* giocatore, Lista* mazzoCentro);
Lista* initTavolo(Lista* tavolo, Coda* Mazzo);
void inizializzaGiocatori(Pila** giocatori);
void pause();
