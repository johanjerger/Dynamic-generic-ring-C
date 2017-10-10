#ifndef DGR_STR_H
#define DGR_STR_H

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

    struct _ring (*new_ring)();
    struct _ring (*add)(struct _ring *, void *);
} ring_t;

#endif
