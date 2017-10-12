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
    int size;
    struct _ring * next;
    struct _ring * previous;

    // generic functions

    bool (*exist)(struct _ring *, void *);

    // add functions
    struct _ring * (*add)(struct _ring *, void *);
    struct _ring * (*add_before)(struct _ring *, void *);
    struct _ring * (*add_next)(struct _ring *, void *);

    // delete functions
    struct _ring * (*delete)(struct _ring *);
    struct _ring * (*delete_before)(struct _ring *);
    struct _ring * (*delete_next)(struct _ring *);
    struct _ring * (*delete_item)(struct _ring *, void *);

    // set callbacks
    void (*set_equals_callback)(struct _ring *, bool (*)(void *, void *));

    // callbacks
    bool (*equals_callback)(void *, void *);

    // destruct
    void (*destruct)(struct _ring *);
} ring_t;

ring_t * new_ring();

#endif
