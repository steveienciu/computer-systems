/*
 * Implement a place function for the example allocator.
 * static void place(void *bp, size_t asize)
 * Your solution should place the requested block at the beginning of the free block, splitting only if the 
 * size of the remainder would equal or exceed the minimum block size
 */

static void place(void *bp, size_t asize)
{
    size_t bsize = GET_SIZE(HDRP(bp));

    if ((bsize - asize) >= 2 * DSIZE) {
        PUT(HDRP(bp), PACK(asize, 1));
        PUT(FTRP(bp), PACK(asize, 1));
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(csize - asize, 0));
        PUT(FTRP(bp), PACK(csize - asize, 0));
    }
    else {
        PUT(HDRP(bp), PACK(bsize, 0));
        PUT(FTRP(bp), PACK(bsize, 0));
    }
}
