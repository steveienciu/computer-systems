/* fix the bug in the code */

#include "csheader/csapp.h"

volatile sig_atomic_t counter = 0;

void handler(int sig) 
{
	counter++;
//	sleep(1);
	return;
}

int main()
{
	int i;
	
	Signal(SIGUSR2, handler);

	if (Fork() == 0) {
		for (i = 0; i < 5; ++i) {
			Kill(getppid(), SIGUSR2);
			printf("sent SIGUSR2 to parent\n");
			usleep(50000);
		}
		exit(0);
	}

	Wait(NULL);
	printf("counter=%d\n", counter);
	exit(0);
}

/*
 * the bug was that counter would only print out the value 2. what is done here to print out the 
 * proper error is a hacky way of doing it but it works 
 * the reason it would only print the value of 2 is because signals that get sent are not queued.
 * if there is already a signal of the same type being processed the process will drop it and 
 * continue working on the signal already in progress 
 */
