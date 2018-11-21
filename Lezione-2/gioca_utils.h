#include "pile.h"
#include "code.h"

#define CARTE_PER_SEME  10
#define N_GIOCATORI     4

typedef seme_t char;

void creaCarteSeme(Coda* mazzo, seme_t seme);
Elemento* creaElemento(seme_t seme, int val);
void mixCarte(Coda* mazzo); // Lista -> Array; si randomizza O(n); Array -> Lista
void assegnaCarte(Coda* mazzo, Pila** giocatori);
void giocaCarta(Pila* giocatore, Lista* mazzoCentro);

