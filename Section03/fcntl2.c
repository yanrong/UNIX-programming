#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("fcntl F_GETFL error\n");
        exit(1);
    }

    val != flags; /*turn on flags*/

    if (fcntl(fd, F_SETFL, val) < 0) {
        printf("fcntl F_SETFL error\n");
        exit(1);
    }
}