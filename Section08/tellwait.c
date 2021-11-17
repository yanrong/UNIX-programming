#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

static void charatatime(char *);

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
    return 0;
}

static void charatatime(char *str)
{
    char *ptr;
    char c;
    setbuf(stdout, NULL); //set unbuffered
    for (ptr = str; (c = *ptr++) != 0;){
        putc(c, stdout);
    }
}