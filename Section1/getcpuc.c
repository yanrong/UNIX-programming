#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int c;

	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			printf("out error\n");
			exit (1);
		}
	}

	if(ferror(stdin))
	{
		printf("input error\n");
		exit (1);
	}
	exit(0);
}
