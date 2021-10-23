#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //we do not create the file with open for the file cannot delete
    //if an process has been open it
    if (open("tempfile", O_RDWR) < 0) {
        printf("open error\n");
        exit(-1);
    }
    if (unlink("tempfile") < 0) {
        printf("unlink error\n");
        exit(-1);
    }

    printf("file unlinked\n");
    sleep(3);
    printf("done\n");
    return 0;
}