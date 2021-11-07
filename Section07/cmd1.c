#include <stdio.h>
#include <setjmp.h>

#define MAXLINE 4096
#define TOK_ADD 1

void do_line(char *);
void cmd_add(void);
int get_token(void);

jmp_buf jmpbuffer;

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    if (setjmp(jmpbuffer) != 0)
        printf("error\n");

    while (fgets(line, MAXLINE, stdin) != NULL) {
        do_line(line);
    }

    return 0;
}

char *tok_ptr;
void do_line(char *ptr)
{
    int cmd;
    tok_ptr = ptr;
    while ((cmd = get_token()) > 0) {
        switch (cmd)
        {
        case TOK_ADD:
            cmd_add();
            break;
        }
    }
}

void cmd_add(void)
{
    int token;
    token = get_token();
    if (token < 0) /*an error has occurred*/
        longjmp(jmpbuffer, 1);
    /*rest of processing for this command*/
}

int get_token(void)
{
    return -1;
    /*fetch next token from line pointed to by  tok_ptr*/
}