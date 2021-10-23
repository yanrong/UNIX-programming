#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXLINE 512

int main(int argc, char const *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    printf("%% "); /*print prompt (printf requires %% to print %)*/
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) -1] = 0; /*replace newline with null*/
        }

        if((pid = fork()) < 0){
            printf("fork error\n");
            exit(-1);
        }else if(pid == 0){ /*child*/
            execlp(buf, buf, (char *)0);
            printf("couldn't execute %s\n", buf);
            exit(127);
        }

        /*parent */
        if((pid == waitpid(pid, &status, 0)) < 0){
            printf("waitpid error\n");
        }
        printf("%% ");
    }
    return 0;
}
