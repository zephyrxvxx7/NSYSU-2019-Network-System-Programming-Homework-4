/*
 * is_background.c :  check for & at end
 */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_background(char ** myArgv) {

  	if (*myArgv == NULL)
    	return 0;

  	/* Look for "&" in myArgv, and process it.
  	 *
	 *	- Return TRUE if found.
	 *	- Return FALSE if not found.
	 *
	 * Fill in code.
	 */

    int i = 0;

    while (myArgv[i] != NULL) {
        i++;
    }
    if (strcmp(myArgv[i - 1], "&") == 0) {
        free(myArgv[i]);
        myArgv[i - 1] = NULL;
        return TRUE;
    }

    return FALSE;
}