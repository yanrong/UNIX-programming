#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
    //Clear the mode
    umask(0);
    if (creat("foo", RWRWRW) < 0) {
        printf("create error for foo\n");
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0) {
        printf("crate error for bar\n");
    }
    return 0;
}
