#include "apue.h"

static int	pfd1[2], pfd2[2];

void
TELL_WAIT(void)
{
	if (pipe(pfd1) < 0 || pipe(pfd2) < 0)
		printf("pipe error");
}

void
TELL_PARENT(pid_t pid)
{
	if (write(pfd2[1], "c", 1) != 1)
		printf("write error");
}

void
WAIT_PARENT(void)
{
	char	c;

	if (read(pfd1[0], &c, 1) != 1)
		printf("read error");

	if (c != 'p')
		printf("WAIT_PARENT: incorrect data");
}

void
TELL_CHILD(pid_t pid)
{
	if (write(pfd1[1], "p", 1) != 1)
		printf("write error");
}

void
WAIT_CHILD(void)
{
	char	c;

	if (read(pfd2[0], &c, 1) != 1)
		printf("read error");

	if (c != 'c')
		printf("WAIT_CHILD: incorrect data");
}

void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef	WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else
				"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}
