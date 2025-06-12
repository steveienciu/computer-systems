/*
 * Implement a find_fit function for the simple allocator described in Section 9.9.12.
 * static void *find_fit(size_t asize)
 * Your solution should perform a first-fit search of the implicit free list.
 */

staitc void *find_fit(size_t asize)
{
    void *bp;

    for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
        if (GET_SIZE(HDRP(bp)) <= asize && !GET_ALLOC(HDRP(bp))) {
            return bp;
        }
    }

    return NULL;
}
