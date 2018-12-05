#include <time.h>
#include <locale.h>
#include "utils.h"



static clock_t timer;

void timerStart() {
	timer = clock();
}

int timerValue() {
	return (clock() - timer) / CLOCKS_PER_SEC;
}
