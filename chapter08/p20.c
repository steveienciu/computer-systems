/* Use execve to write a program called myls whose behavior is identical to the
/bin/ls program. Your program should accept the same command-line argu-
ments, interpret the identical environment variables, and produce the identical
output */

#include "csheader/csapp.h"

int main(int argc, char *argv[], char *env[])
{
	int status;
	pid_t pid;

	if ((pid = Fork()) == 0) {
		if ((execve("/bin/ls", argv, env) == -1)) {
			printf("errror");
			exit(0);
		}
	}

	if ((pid = waitpid(-1, &status, 0)) > 0) {
		if (WIFEXITED(status)) {
			printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
		}
		else {
			printf("child %d terminated abnormally\n", pid);
		}
	}

	exit(0);
}
