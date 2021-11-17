#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("fork error\n");
        return -1;
    } else if (pid == 0) { //child process
        if (execl("/home/zning/proj/github/dyr/UNIX-programming/Section08/testinterp",
             "testinterp", "myarg1", "MY ARG2", (char *)NULL) < 0) {
            printf("execl error\n");
            return -1;
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {//wait for parent
        printf("waitpid error\n");
    }

    return 0;
}