/*
 * Given an input file hello.txt that consists of the string Hello, world!\n, write a C program that uses mmap
 * to change the contents of hello.txt to Jello, world!\n
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_NAME "hello.txt"

void *change_file(FILE *fp, size_t size);

int main()
{
    /* open up the file */
    int fd = open(FILE_NAME, O_RDWR);
    if (fd == -1) {
        printf("Could not open %s. Terminating\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    /* number of chars in file */
    size_t count = 15;

    /* map file to new part of memory */
    char *new_fd = mmap(NULL, count, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (new_fd == MAP_FAILED) {
        printf("Mapping to new address space failed. Terminating\n");
        exit(EXIT_FAILURE);
    }

    /* print inital contents of file */
    for (int i = 0; i < count; ++i) {
        printf("%c", new_fd[i]);
    }

    /* manipulate and print contents of file */
    new_fd[0] = 'J';
    for (int i = 0; i < count; ++i) {
        printf("%c", new_fd[i]);
    }

    /* ensure that remove allocated memory */
    if (munmap(new_fd, count) == -1) {
        printf("Unable to deallocate memory. Terminating");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        printf("Closing file %s failed. Terminating\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    return 0;
}
