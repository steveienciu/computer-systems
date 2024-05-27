/*
Write a function good_echo that reads a line from standard input and writes it to
standard output.
*/

#include <stdio.h>

#define BUFF 10

void good_echo();

int main()
{
	good_echo();

	return 0;
}

void good_echo()
{
	char str[BUFF];

	if (fgets(str, sizeof(str), stdin) != NULL) {
		printf("%s\n", str);
	}
	else {
		printf("\nError was spotted.\n");
	}
}
