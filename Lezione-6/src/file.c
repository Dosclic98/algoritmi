#include "file.h"
 
char* stringReader(FILE *stream) {
	char* s = NULL;
	size_t n = 0;
	
	getline(s, n, stream); 
	if(s==NULL){
		free(s);
		return NULL;
	}
	s[strlen(s)-1]= '\0';
	return s;
}

bucket* bucketCreat(FILE* inp){
	bucket* stud = malloc(sizeof(bucket));
	fscanf(inp,"%ld\n",&(stud->id));
	inp->nome = stringReader(inp);
	if(inp->nome == NULL){
		printf("Errore lettura Nome info incomplete\n");
		
	} 
}
