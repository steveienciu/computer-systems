/* How many “Example” output lines does this program print? */

#include "csheader/csapp.h"

void try()
{
	if (Fork() != 0) {
		Fork();
		printf("Example\n");
		exit(0);
	}
}

int main()
{
	try();
	Fork();
	printf("Example\n");
	exit(0);
}

/*
 * this will output example 4 times 
 * try will get called and create child process in the declaration of the if statement. That
 * first child statment will not hit the inside of the if statement. In the if statement 
 * another child process will get created and both the parent and one of the child processes 
 * will print example which will then end those two processes
 * after try finished, we still have one child process left when then gets forked to print
 * example two more times 
 */
