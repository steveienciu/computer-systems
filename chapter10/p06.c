/* 
 * What is the output of the following program?
 */

#include "csheader/csapp.h"

int main()
{
    int fd1, fd2;

    fd1 = Open("foo.txt", O_RDONLY, 0);
    fd2 = Open("bar.txt", O_RDONLY, 0);

    Close(fd2);

    fd2 = Open("baz.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);

    exit(0);
}

/*
 * The first three descriptor indexes are stdin, stdout, and stderr. The next descriptor, 3, will be 
 * foo.txt then index number 4 will be bar.txt. Since we close bar.txt, when we open baz.txt it will
 * grab index 4. Therefore, the output of the program will be 'fd2 = 4'
 */
