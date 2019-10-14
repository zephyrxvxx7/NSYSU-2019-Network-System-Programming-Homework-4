/*
 *  pipe_present.c :  check for |
 */

#include "shell.h"
#include <stdio.h>
#include <string.h>

/*
 * Return index offset into argv of where "|" is,
 * -1 if in an illegal position (first or last index in the array),
 * or 0 if not present.
 */
int pipe_present(char ** myCurrentArgv) {
	int index = 0;

  	/* Search through myCurrentArgv for a match on "|". */

    while (myCurrentArgv[index] != NULL) {
        if(strcmp(myCurrentArgv[index], "|") == 0)
            break;
        index++;
    }
    

    	

  	if (myCurrentArgv[index] == NULL) {
    	return 0;
        
  	} else if (myCurrentArgv[index + 1] == NULL || index == 0) {
        return -1;  

  	} else {
    	/* In the middle. */
    	return index;
  	}
}
