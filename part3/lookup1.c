/*
 * lookup1 : straight linear search through a local file
 * 	         of fixed length records. The file name is passed
 *	         as resource.
 */
#include <string.h>
#include <stdlib.h>
#include "dict.h"

int lookup(Dictrec * sought, const char * resource) {
	Dictrec dr;
	static FILE * in;
	static int first_time = 1;

	if (first_time) { 
		first_time = 0;
		/* open up the file
		 *
		 * Fill in code. */
        if ((in = fopen(resource, "r")) == NULL){DIE(resource);}
	}
    // strcat(sought->word, "\n");

	/* read from top of file, looking for match
	 *
	 * Fill in code. */

    strcpy(sought->text, "");
    rewind(in);
	while(!feof(in)) {
		/* Fill in code. */
        
        if(fgets(dr.word, WORD, in) == NULL)
            break;
        
        dr.word[strlen(dr.word) - 1] = '\0';
        
        if (strcmp(sought->word, dr.word) == 0){
            fseek(in, WORD - strlen(dr.word) - 1, SEEK_CUR);

            while(fgets(dr.word, TEXT, in) && strcmp(dr.word, "") != 0)
                strcat(sought->text, dr.word);
            sought->text[strlen(sought->text) - 1] = '\0';

		    return FOUND;
        }
        fseek(in, 511 - strlen(dr.word), SEEK_CUR);
	}

	return NOTFOUND;
}
