/*
 * What is the output of the following program?
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;

    fd1 = open("foo.txt", O_RDONLY, 0);
    if (fd1 == -1) {
        printf("Unable to open file foo.txt\n");
        exit(EXIT_FAILURE);
    }
    if (close(fd1) == -1) {
        printf("Unable to close file foo.txt\n");
        exit(EXIT_FAILURE);
    }

    fd2 = open("baz.txt", O_RDONLY, 0);
    if (fd2 == -1) {
        printf("Unable to open file baz.txt\n");
        exit(EXIT_FAILURE);
    }
    printf("fd2 = %d\n", fd2);

    exit(0);
}

/*
 * The output of the program is 3
 */
