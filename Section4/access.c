#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: a.out <pathname>\n");
        exit(-1);
    }

    if (access(argv[1], R_OK) < 0) {
        printf("access read error for %s\n", argv[1]);
        exit(-1);
    } else {
        printf("read access OK\n");
    }

    if (open(argv[1], O_RDONLY) < 0) {
        printf("open error for %s\n", argv[1]);
        exit(-1);
    } else {
        printf("open for reading OK\n");
    }

    return 0;
}