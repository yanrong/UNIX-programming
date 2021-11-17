#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int globvar = 6; // external variable in initalized data

int main(void)
{
    int var;
    pid_t pid; //automatic variable on the stack

    var = 88;
    printf("before fork\n"); //we don't flush stdio
    if ((pid = vfork()) < 0) {
        printf("vfork error\n");
    } else if (pid == 0) { //child
        globvar++; //modify parent's variables
        var++;
        _exit(0); //child terminate
    }

    //parent continues here
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    return 0;
}