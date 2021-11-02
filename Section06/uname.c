#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char*argv)
{
    struct utsname hostname;
    uname(&hostname);

    printf("host info:\n");
    printf("sysname = %s\n", hostname.sysname);
    printf("nodename = %s\n", hostname.nodename);
    printf("release = %s\n", hostname.release);
    printf("version = %s\n", hostname.version);
    printf("machine = %s\n", hostname.machine);

    return 0;
}