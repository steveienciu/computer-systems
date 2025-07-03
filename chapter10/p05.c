/*
 * Assuming that the disk file foobar.txt xonsists of the six ASCII characters foobar, what is the output
 * of the following program?
 */

#include "csheader/csapp.h"

int main()
{
    int fd1, fd2;
    char c;

    fd1 = Open("foobar.txt", O_RDONLY, 0);
    fd2 = Open("foobar.txt", O_RDONLY, 0);

    Read(fd2, &c, 1);
    Dup2(fd2, fd1);
    Read(fd1, &c, 1);

    printf("c = %c\n", c);

    exit(0);
}

/*
 * The output of the program would be 'c = o' since when we call Dup2, it copies the file descriptor 
 * table into fd1 which inherits everything from fd2. This means that the file position attribute 
 * will be seen in fd1 so it would show the second character
 */
