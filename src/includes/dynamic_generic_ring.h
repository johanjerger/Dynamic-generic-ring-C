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

    int (*size)(struct _ring *);
} ring_t;

ring_t * new_ring();

#endif
