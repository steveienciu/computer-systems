/*
 * Write a program that converts its 16-bit network byte order to a 16-bit hex number and prints
 * the result
 */

#include "csheader/csapp.h"
#include "stdint.h"

#define MAXSIZE 16

int main(int argc, char **argv)
{
    struct in_addr net_addr;
    uint16_t addr;
    unsigned int test_addr;
    char buf[MAXSIZE];
    int result;

    if (argc != 2) {
        fprintf(stderr, "%d command-line arguments entered. Expecting only 2.\n", argc);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%15s", buf);

    result = inet_pton(AF_INET, buf, &net_addr);
    /* returns 0 if buf does not point to valid dotted-decimal string */
    if (result == 0) {
        fprintf(stderr, "Invalid dotted-decimal string.\n");
        exit(EXIT_FAILURE);
    }
    /* any other error returns -1 and sets errno */ 
    else if (result == -1) {
        perror("inet_pton failed.\n");
    }

    if (net_addr.s_addr > UINT16_MAX) {
        fprintf(stderr, "Value does not fit into a 16 bit value. Closing program.\n");
        exit(EXIT_FAILURE);
    }

    printf("0x%x\n", ntohs(net_addr.s_addr));

    exit(0);
}
