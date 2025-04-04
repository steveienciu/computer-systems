/* Enumerate all of the possible outputs of the program in Practice Problem 8.4 */

#include "csheader/csapp.h"

int main()
{
	int status;
	pid_t pid;

	printf("Start\n");
	pid = Fork();
	printf("%d\n", !pid);
	if (pid == 0) {
		printf("Child\n");
	}
	else if ((waitpid(-1, &status, 0) > 0) && (WIFEXITED(status) != 0)) {
		printf("%d\n", WEXITSTATIS(status));
	}
	printf("Stop\n");
	exit(2);
}

/* the possible outputs for this are
 * 1. Start 0 1 Child Stop 2 Stop
 * 2. Start 1 Child Stop 2 Stop
 * 3. Start 1 0 Child Stop 2 Stop
 */
