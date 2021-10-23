#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char buf1[] = "adbcdeghij";
char buf2[] = "ABDCEFGHIJ";

int main(int argc, char *argv[])
{
    int fd;

    if ((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        printf("create error\n");
        exit(1);
    }

    if (write(fd, buf1, 10) != 10) {
        printf("buf1 write error\n");
        exit(1);
    }
    /* offset now = 10 */
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        printf("lseek error\n");
        exit(1);
    }
    /* offset now = 16384 */
    if (write(fd, buf2, 10) != 10) {
        printf("buf2 write error\n");
        exit(1);
    }
    /* offset now = 16394 */
    return 0;
}
