#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BSIZE 1024

int main()
{
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    switch (fork()) {

    case -1:
        perror("fork");
        exit(1);
        break;

    /* child */
    case 0:
        /* Close read side, won't use it */
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);

        execlp("ls", "ls", "-lh", NULL);
        perror("exec ls failed");
        exit(EXIT_FAILURE);

    /* parent */
    default:
        break;
    }

    int len;
    char buffer[BSIZE];

    /* Close write side, won't use it */
    close(pipefd[0]);

    /* print output from CGI */
    while ((len = read(pipefd[1], buffer, BSIZE)) > 0) {
        buffer[len] = '\0';
        printf("%s\n", buffer);
    }

    if (waitpid(-1, (int*)NULL, 0) == -1) {
        perror("waitpid");
        exit(1);
    }

    return EXIT_SUCCESS;
}