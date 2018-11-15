#include "liste.h"

#define CARTE_PER_SEME 10

typedef seme_t char;

void creaCarteSeme(Coda* mazzo, seme_t seme);
Elemento* creaElemento(seme_t seme, int val);
void mixCarte(Coda* mazzo);

