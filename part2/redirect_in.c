/*
 * redirect_in.c  :  check for <
 */

#include "shell.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define STD_OUTPUT 1
#define STD_INPUT  0

/*
 * Look for "<" in myArgv, then redirect input to the file.
 * Returns 0 on success, sets errno and returns -1 on error.
 */
int redirect_in(char ** myArgv) {
  	int i = 0;
  	int fd;

  	/* search forward for <
  	 *
	 * Fill in code. */

    while (myArgv[i] != NULL){
        if(strcmp(myArgv[i], "<") == 0)
            break;
        i++;
    }

  	if (myArgv[i]) {	/* found "<" in vector. */
    	/* 1) Open file.
     	 * 2) Redirect stdin to use file for input.
   		 * 3) Cleanup / close unneeded file descriptors.
   		 * 4) Remove the "<" and the filename from myArgv.
		 *
   		 * Fill in code. */

        if(freopen(myArgv[i + 1], "r", stdin) == NULL){
            errno = ENOENT;
            return -1;
        }

        myArgv[i] = NULL;
        myArgv[i + 1] = NULL;
        free(myArgv[i + 1]);

  	}
  	return 0;
}
