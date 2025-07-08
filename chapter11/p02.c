/*
 * Write a program that converts its 16-bit hex argument to a 16-bit network byte order and prints
 * the result
 */

#include "csheader/csapp.h"
#include <stdint.h>

#define MAXSIZE 16 /* IPv4 address contains at most 16 chars including the null terminator */

int main(int argc, char **argv)
{
    struct in_addr net_addr;
    uint16_t addr;
    unsigned int test_addr;
    char buf[MAXSIZE];

    if (argc != 2) {
        fprintf(stderr, "%d command-line arguments entered. Expecting only 2.\n", argc);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%x", &test_addr);
    /* check for overflow */
    if (test_addr > UINT16_MAX) {
        fprintf(stderr, "Overflow detected. Closing program.\n");
        exit(EXIT_FAILURE);
    }
    addr = (uint16_t)test_addr;
    net_addr.s_addr = htons(addr);

    /* if inet_ntop fails, it returns NULL and sets errno  */
    if (inet_ntop(AF_INET, &net_addr, buf, MAXBUF) == NULL) {
        perror("inet_ntop failed\n");
    }

    printf("%s\n", buf);

    exit(0);
}
