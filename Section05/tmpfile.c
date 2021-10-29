#include <stdio.h>

#define MAXLINE 4096

int main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf("%s\n", tmpnam(NULL)); //first temp name

    tmpnam(name); //second temp name
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL) { //crate temp file
        printf("tmpfile error\n");
    }

    fputs("one line of output\n", fp); //write to tempfile
    rewind(fp); //set the file position to head

    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("fgets error\n");
    }

    fputs(line, stdout); //print the line we wrote
    return 0;
}