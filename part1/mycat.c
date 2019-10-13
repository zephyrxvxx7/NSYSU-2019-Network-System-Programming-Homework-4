#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define LONGLINE 255

int main(int argc, char **argv){
    if(argc != 2){
        errno = E2BIG;
        perror("Usage: mycat filename");
        exit(1);
    }

    FILE *source_file;
    source_file = fopen(argv[1], "rb");

    if(source_file == NULL){
        errno = ENOENT;
        perror("error");
        exit(1);
    }

    char buffer[LONGLINE];
    size_t bytes;

    while (!feof(source_file)) {
        bytes = fread(buffer, 1, LONGLINE, source_file);
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    }

    fclose(source_file);
}
