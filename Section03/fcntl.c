#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int val;

    if (argc != 2) {
        printf("usage: a.out <descriptor#>\n");
        exit(1);
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        printf("fcntl error for fd %d\n", atoi(argv[1]));
        exit(1);
    }

    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        printf("unkown access mode\n");
        exit(1);
    }

    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", noblocking");
    if (val & O_SYNC)
        printf(", synchronous wirtes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes")
#endif
    putchar('\n');
    exit(0);
}
