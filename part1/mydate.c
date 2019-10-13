#include <stdio.h>
#include <time.h>

int main(){
    time_t t;
    struct tm* info;
    char buffer[80];

    time(&t);
    info = localtime(&t);
    strftime(buffer, 80, "%b %d(%a), %Y %I:%M %p", info);
    printf("%s\n", buffer);
}