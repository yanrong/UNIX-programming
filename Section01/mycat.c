#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(int argc, char const *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDIN_FILENO, buf, n) != n)
		{
			printf("write error\n");
			exit (1);
		}
	}

	if(n < 0)
	{
		printf("write error\n");
		exit (1);
	}
	exit(0);
}
