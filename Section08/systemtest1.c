#include <sys/wait.h>
#include "../common/apue.h"

int main(int argc, char *argv[])
{
    int status;

    if ((status = system("date")) < 0) {
        printf("system() error\n");
    }
    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0) {
        printf("system() error\n");
    }
    pr_exit(status);

    if ((status = system("who; exit 44")) < 0) {
        printf("system() error\n");
    }
    pr_exit(status);

    return 0;
}