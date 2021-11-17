#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *env_init[] = {"USER=unkown", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid ;

    if ((pid = fork()) < 0) {
        printf("fork error\n");
        return -1;
    } else if (pid == 0) { //specify pathname, specify environment
        if (execle("/home/zning/bin/echoall", "echoall", "myarg1", "MY ARG2", (char *)NULL, env_init) < 0){
            printf("execle error\n");
            exit(-1);
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        printf("wait error\n");
        exit(-1);
    }

    if ((pid = fork()) < 0) {
        printf("error fork 2\n");
        exit(-1);
    } else if (pid == 0) { //specify pathname, specify environment
        if (execlp("echoall", "echoall", "only 1 arg", (char *)NULL) < 0) {
            printf("execlp error\n");
            exit(-1);
        }
    }
    return 0;
}