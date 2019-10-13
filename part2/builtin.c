/*
 * builtin.c : check for shell built-in commands
 * structure of file is
 * 1. definition of builtin functions
 * 2. lookup-table
 * 3. definition of is_builtin and do_builtin
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/utsname.h>
#include "shell.h"

/****************************************************************************/
/* builtin function definitions                                             */
/****************************************************************************/
static void bi_builtin(char ** argv);	/* "builtin" command tells whether a command is builtin or not. */
static void bi_cd(char **argv) ;		/* "cd" command. */
static void bi_echo(char **argv);		/* "echo" command.  Does not print final <CR> if "-n" encountered. */
static void bi_hostname(char ** argv);	/* "hostname" command. */
static void bi_id(char ** argv);		/* "id" command shows user and group of this process. */
static void bi_pwd(char ** argv);		/* "pwd" command. */
static void bi_quit(char **argv);		/* quit/exit/logout/bye command. */




/****************************************************************************/
/* lookup table                                                             */
/****************************************************************************/

static struct cmd {
  	char * keyword;					/* When this field is argv[0] ... */
  	void (* do_it)(char **);		/* ... this function is executed. */
} inbuilts[] = {
  	{ "builtin",    bi_builtin },   /* List of (argv[0], function) pairs. */

    /* Fill in code. */
    { "echo",       bi_echo },
    { "quit",       bi_quit },
    { "exit",       bi_quit },
    { "bye",        bi_quit },
    { "logout",     bi_quit },
    { "cd",         bi_cd },
    { "pwd",        bi_pwd },
    { "id",         bi_id },
    { "hostname",   bi_hostname },
    {  NULL,        NULL }          /* NULL terminated. */
};


static void bi_builtin(char ** argv) {
	/* Fill in code. */
    if (argv[1] == NULL) {
        printf("\n");
        return;
    }

    printf("%s %s builtin feature\n", argv[1], (is_builtin(argv[1]) ? "is a" : "is NOT a"));
}

static void bi_cd(char **argv) {
	/* Fill in code. */
    if (argv[1] == NULL) {
        printf("\n");
        return;
    }
    chdir(argv[1]);
}

static void bi_echo(char **argv) {
	/* Fill in code. */
    if (argv[1] == NULL) {
        printf("\n");
        return;
    }
    
    if (strcmp(argv[1], "-n") != 0) {
        int count = 1;
        while (argv[count] != NULL) {
            printf("%s ", argv[count]);
            count++;
        }
        printf("\n");
    }
    else {
        if (argv[2] == NULL)
            printf("\n");
        else if (atoi(argv[2]) == 0)
            printf("\n");
        else {
            printf("%s\n", argv[2 + atoi(argv[2])]);
        }
    }
}

static void bi_hostname(char ** argv) {
	/* Fill in code. */
    struct utsname uts;

    if (uname(&uts) == -1) {
        perror("uname");
        return;
    }
    printf("hostname: %s\n", uts.nodename);
}

static void bi_id(char ** argv) {
 	/* Fill in code. */
    struct passwd *pw;
    pw = getpwuid(getuid());

    struct group *grp;
    grp = getgrgid(getgid());

    printf("UserID = %d(%s), GroupID = %d(%s)\n", pw->pw_uid, pw->pw_name, grp->gr_gid, grp->gr_name);
}

static void bi_pwd(char ** argv) {
	/* Fill in code. */
    char* dir;
    long pathmaxlen = pathconf(".", _PC_PATH_MAX);

    dir = getcwd((char*)NULL, pathmaxlen + 1);

    if (dir == NULL) {
        perror("getcwd");
        return;
    }

    printf("%s\n", dir);
    free(dir);
}

static void bi_quit(char **argv) {
	exit(0);
}


/****************************************************************************/
/* is_builtin and do_builtin                                                */
/****************************************************************************/

static struct cmd * this; /* close coupling between is_builtin & do_builtin */

/* Check to see if command is in the inbuilts table above.
Hold handle to it if it is. */
int is_builtin(char *cmd) {
	struct cmd *tableCommand;

  	for (tableCommand = inbuilts ; tableCommand->keyword != NULL; tableCommand++)
    	if (strcmp(tableCommand->keyword,cmd) == 0) {
      		this = tableCommand;
      		return 1;
    	}
  return 0;
}


/* Execute the function corresponding to the builtin cmd found by is_builtin. */
int do_builtin(char **argv) {
	this->do_it(argv);
}
