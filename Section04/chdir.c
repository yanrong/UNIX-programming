#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (chdir("/tmp") < 0) {
        printf("chdir failed\n");
        return -1;
    }
    printf("chdir to /tmp succeeded\n");
    return 0;
}
