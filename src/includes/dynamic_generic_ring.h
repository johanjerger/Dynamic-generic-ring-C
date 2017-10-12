#ifndef DGR_STR_H
#define DGR_STR_H
#include <stdbool.h>
/*
 *  Ring structure typedef, here I define all the ring
 *  attributes (as variables) and functions, in an
 *  "OOP" way.
 */

typedef struct _ring
{
    // variables

    void * elem;
    struct _ring * next;
    struct _ring * previous;

    // functions

    int (*size)(struct _ring *);
    struct _ring * (*add)(struct _ring *, void *);
    bool (*exist)(struct _ring *, void *);

    // callbacks
    bool (*exist_callback)(void *, void *);
} ring_t;

ring_t * new_ring();

#endif
