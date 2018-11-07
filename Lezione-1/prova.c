#include <stdio.h>

int somma(int a, int b);

int main()
{
	int a, b, c;
	a = 1;
	b= 2;
	c = somma(a,b);
	
	printf("La somma di %d e %d e: %d\n", a, b, c);
	return 0; 
}

int somma (int a, int b){
	b = a+b;
	return b;
}
