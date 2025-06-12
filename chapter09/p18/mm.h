/* mm.h */

/* Added to header file for testing purposes */
extern char *next_fitp;
extern char *heap_listp;

extern int mm_init(void);
extern void *mm_malloc (size_t size);
extern void mm_free (void *ptr);
