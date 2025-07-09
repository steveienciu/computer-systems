/*
 * The getaddrinfo and getnameinfo functions subsume the functionality of inet_pton and 
 * inet_ntop, respectively, and they provide a higher-level of abstraction that is 
 * independent of any particular address format. To convince yourself how handy this is, 
 * write a version of hostinfo (Figure 11.17) that uses inet_ntop instead of getnameinfo 
 * to convert each socket address to a dotted-decimal address string
 */

#include "csheader/csapp.h"

int main(int argc, char **argv)
{
    struct addrinfo *p, *listp, hints;
    struct sockaddr_in *pointer;
    char buf[MAXLINE];
    int rc, flags;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* get list of addrinfo records */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IPv4 only */
    hints.ai_socktype = SOCK_STREAM; /* connections only */
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    /* walk the list and display each IP */
    for (p = listp; p; p = p->ai_next) {
        pointer = (struct sockaddr_in *)p->ai_addr;
        Inet_ntop(AF_INET, &(pointer->sin_addr), buf, MAXLINE);
        printf("%s\n", buf);
    }

    /* clean up */
    Freeaddrinfo(listp);

    exit(0);
}

/*
 * not fun at all to do it this way. need to do a lot of pointer casting to get the pointer
 * in use with the right format then need to get the address of the resulting pointer to
 * allow it to print the ip
 */
