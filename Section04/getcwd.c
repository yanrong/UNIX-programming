#include <unistd.h>
#include <stdio.h>
#include "../common/pathalloc.h"

int main(int argc, char *argv[])
{
    char *ptr;
    size_t size;

    if (chdir("/usr/sbin") < 0) {
        printf("chdir failed\n");
        return -1;
    }

    ptr = path_alloc(&size); /* our own function */
    if (getcwd(ptr, size) == NULL) {
        printf("getcwd failed\n");
        return -1;
    }

    printf("cwd = %s\n", ptr);
    return 0;
}
