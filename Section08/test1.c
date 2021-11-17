#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) { //parent
        printf("fork error\n");
    } else if (pid != 0) {
        sleep(2);
        exit(2); //terminate with exit status 2
    }

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid != 0) { //first child
        sleep(4);
        abort(); // terminate with core dump
    }

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid != 0) { //second child
        execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", (char *)NULL);
        exit(7); //shouldn't get here
    }

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { //third child
        sleep(8);
        exit(0); //normal exit
    }

    sleep(6); //four child
    kill(getpid(), SIGKILL); //terminate w/signal, no core dump
    exit(6);
}