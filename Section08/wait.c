#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination , exit status = %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abornal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status) ? "(core file generated)" : "");
#else
        "");
#endif
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) {
        exit(7); // child exit
    }
    if (wait(&status) != pid) //wait for child
        printf("wait exit error");
    pr_exit(status); //and print its status

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { // child process
        abort(); //generate SIGABRT
    }
    if (wait(&status) != pid) //wait for child
        printf("wait abort error");
    pr_exit(status); //and print its status

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { //child
        status /= 0; //divide by 0 generates SIGFPE
    }
    if (wait(&status) != pid) //wait for child
        printf("wait error");
    pr_exit(status); // and print its status

    return 0;
}