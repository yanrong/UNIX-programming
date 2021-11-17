#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { //first child process
        if ((pid = fork()) < 0) {
            printf("fork subprocess error\n");
        } else if (pid > 0) { //pid == 0 is child, other wise is parent
            exit(0); //parent from second fork == first child, exit in first process
        }
        /*
        * We're the second child, out parent becomes init as soon
        * as our real parent call exit() in the statement above.
        * Here's where we'd continue executing, knowing that when
        * we're done, init will reap our status
        */
        sleep(5);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid) { //wait for first child
        printf("waitpid error\n");
    }

    /*
    * We're the parent (the original process); we continue executing,
    * knowing that we;re not the parent of the second child
    */
    return 0;
}