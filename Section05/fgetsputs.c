#include <stdio.h>
#define MAXLINE 4096
int main(int argc, char* argv[])
{
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            printf("output error\n");
        }
    }
    //if the error bit is set, return non-zero value
    if (ferror(stdin)) {
        printf("input error\n");
    }
    return 0;
}