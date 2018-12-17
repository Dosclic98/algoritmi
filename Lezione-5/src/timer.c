#include <time.h>
#include <locale.h>
#include "utils.h"



static double timer;

/* Inizializza il cronometro. */
void timerStart() {
	timer = (double) clock();
}

/* Restituisce il tempo passato, in secondi, dall'ultima
 * chiamata di timerStart(). */
double timerValue() {
	return (((double) clock()) - timer) / (double) CLOCKS_PER_SEC;
}
