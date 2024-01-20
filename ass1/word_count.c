#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define BUFFER_SIZE 2048
#define WORD_SIZE 64

void cleanStr(char * str){
	int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int main(int argc, char** argv){

    char buffer[BUFFER_SIZE];
	char *fname;
	char *word;
	
    // store the file name as the first cmd-line arg
    if (argc > 1) {
		fname = argv[1];
    } else {
		fname = "hello.txt";
	}
	if (argc > 2) {
		word = argv[2];
	} else {
		word = "hello";
	}
    FILE* file = fopen(fname, "r");
	int count = 0;
	char* tok;
	while(fgets(buffer, sizeof(buffer), file)!=NULL){
		//fclose(file);
		//count occurances
		tok = strtok(buffer, " ,.-!?;:\"'\n\t");
		while (tok != NULL){
			cleanStr(tok);
			printf(">%s\n", tok);
			if (strcmp(tok, word)==0){
				count++;
			}
			tok = strtok(NULL, " ,.-!?;:\"'\n\t");
		}
	}
	printf("%s count: %d\n\n", word, count);
	fclose(file);
    return (intptr_t) &main;
}
