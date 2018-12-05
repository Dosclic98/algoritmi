#include <time.h>
#include <locale.h>
#include "utils.h"



static double timer;

void timerStart() {
	timer = (double) clock();
}

double timerValue() {
	return (((double) clock()) - timer) / (double) CLOCKS_PER_SEC;
}
