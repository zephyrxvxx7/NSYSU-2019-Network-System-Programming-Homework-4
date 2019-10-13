#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

int main(){
    struct utsname uts;
    int hostid;

    if (uname(&uts) == -1){
        perror("uname");
        exit(1);
    }
    printf("hostname: %s\n", uts.nodename);
    printf("%s\n", uts.release);

    hostid = gethostid();

    printf("hostid: %d\n", hostid);
}