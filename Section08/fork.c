#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int globvar = 6; // external variable in initalized data
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
    int var;
    pid_t pid; //automatic variable on the stack

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        printf("write error\n");
    }
    printf("before fork\n"); //we do not flush stdou

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { //child
        globvar++;
        var++;
    } else {
        sleep(2); //parent
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    return 0;
}