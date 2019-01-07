#include "file.h"
#include <string.h>
#include <stdlib.h>

/*legge una stringa da file attraverso la getline*/
char* stringReader(FILE *stream) {
	char* s = NULL;
	size_t n = 0;

	getline(&s, &n, stream);
	if(s==NULL){
		free(s);
		return NULL;
	}
	s[strlen(s)-1]= '\0';
	return s;
}

/*ritorna un bucket* inizializzato ai valori letti da file*/
bucket* bucketCreat(FILE* inp) {
	bucket* stud = malloc(sizeof(bucket));
	fscanf(inp, "%ld\n", &(stud->id));
	stud->nome = stringReader(inp);
	if(stud->nome == NULL){
		fprintf(stderr, "Errore lettura Nome: info incomplete (%ld)\n", stud->id);
		exit(1);
	}

	stud->cognome = stringReader(inp);
	if(stud->cognome == NULL){
		fprintf(stderr, "Errore lettura Cognome: info incomplete (%ld)\n", stud->id);
		exit(1);
	}

	return stud;
}
