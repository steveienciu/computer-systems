#include <stdio.h>
#include <stdlib.h>

#include "mm.h"
#include "memlib.h"

int main()
{
    char *bp = mm_malloc(sizeof(char));
    printf("Address of start: %p\n", (void *)heap_listp);
    bp[0] = 'a';
    printf("Second address: %p\n", next_fitp);

    char *bp1 = mm_malloc(sizeof(char));
    bp1[0] = 'b';
    printf("Third address: %p\n", next_fitp);

    mm_free(bp); mm_free(bp1);

    return 0;
}
