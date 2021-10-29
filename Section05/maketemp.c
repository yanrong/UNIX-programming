#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void make_temp(char *template);

int main(void)
{
    char goold_template[] = "/tmp/dirXXXXXX";//right way
    char *bad_template = "/tmp/dirXXXXXX"; //wrong way\

    printf("trying to create first temp file...\n");
    make_temp(goold_template);
    printf("trying to crate second temp file...\n");
    make_temp(bad_template);

    return 0;
}

void make_temp(char *template)
{
    int fd;
    struct stat sbuf;

    if ((fd = mkstemp(template)) < 0) {
        printf("can't create temp file\n");
    }

    printf("temp name = %s\n", template);
    close(fd);
    if (stat(template, &sbuf) < 0) {
        if (errno == ENOENT)
            printf("file dosen't exist\n");
        else
            printf("stat failed\n");
    } else {
        printf("file exists\n");
        unlink(template);
    }

}