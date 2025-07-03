/*
 * Suppose the disk file foobar.txt consists of the six ASCII characters foobar. Then what is the output of
 * the following program?
 */

#include "csheader/csapp.h"

int main()
{
    int fd1, fd2; 
    char c;

    fd1 = Open("foobar.txt", O_RDONLY, 0);
    fd2 = Open("foobar.txt", O_RDONLY, 0);

    Read(fd1, &c, 1);
    Read(fd2, &c, 1);

    printf("c = %c\n", c);

    exit(0);
}

/*
 * The output of the program will be 'c = f'. The reason is we are only reading 1 byte from the file and
 * this one byte contains f. The value of c will be from the second although both reads will have the 
 * same char since each descriptor has their own file table entry
 */
