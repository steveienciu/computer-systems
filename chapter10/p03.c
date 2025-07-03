/*
 * As before, suppose the disk file foobar.txt consists of the six ASCII characters foobar. Them what is
 * the output of the following program?
 */

#include "csheader/csapp.h"

int main()
{
    int fd;
    char c;

    fd = Open("foobar.txt", O_RDONLY, 0);
    if (Fork() == 0) {
        Read(fd, &c, 1);
        exit(0);
    }

    Wait(NULL);

    Read(fd, &c, 1);
    printf("c = %c\n", c);

    exit(0);
}

/*
 * Since the child process gets its own duplicate copy of the parent's descriptor table, they will contain
 * the same open file table so the file position will be shared. Therefore, the output will be 'c = o'
