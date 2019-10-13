/*
 * redirect_out.c   :   check for >
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
 * Look for ">" in myArgv, then redirect output to the file.
 * Returns 0 on success, sets errno and returns -1 on error.
 */
int redirect_out(char ** myArgv) {
	int i = 0;
  	int fd;

  	/* search forward for >
  	 * Fill in code. */
    
    while (myArgv[i] != NULL){
        if(strcmp(myArgv[i], ">") == 0)
            break;
        i++;
    }

    i++;
  	if (myArgv[i]) {	/* found ">" in vector. */
    
    	/* 1) Open file.
    	 * 2) Redirect to use it for output.
    	 * 3) Cleanup / close unneeded file descriptors.
    	 * 4) Remove the ">" and the filename from myArgv.
		 *
    	 * Fill in code. */
        

        int out = open(myArgv[i], O_RDWR|O_CREAT, 0600);
        if (-1 == out) {
            errno = ENOENT;
            return -1; 
        }

        int save_out = dup(STDOUT_FILENO);

        if (-1 == dup2(out, STDOUT_FILENO)) {
            perror("cannot redirect stdout");
            return -1;
        }

        puts("doing an ls or something now");

        fflush(stdout);
        close(out);
        dup2(save_out, STDOUT_FILENO);
        close(save_out);

  	}
    else {
        return -1;
    }

  	return 0;
}
