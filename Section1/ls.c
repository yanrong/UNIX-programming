//#include "apue.h"
#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
    {
        printf("usage: ls directory_name\n");
        return 1;
    }
    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("can't open %s\n", argv[1]);
        return 1;
    }
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    closedir(dp);
    return 0;
}