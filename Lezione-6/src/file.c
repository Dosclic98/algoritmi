#include "file.h"
#include <string.h>
#include <stdlib.h>

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

bucket* bucketCreat(FILE* inp) {
	bucket* stud = malloc(sizeof(bucket));
	fscanf(inp, "%ld\n", &(stud->id));
	stud->nome = stringReader(inp);
	if(stud->nome == NULL){
		printf("Errore lettura Nome: info incomplete (%ld)\n", stud->id);
		exit(1);
	}

	stud->cognome = stringReader(inp);
	if(stud->cognome == NULL){
		printf("Errore lettura Cognome: info incomplete (%ld)\n", stud->id);
		exit(1);
	}

	return stud;
}
