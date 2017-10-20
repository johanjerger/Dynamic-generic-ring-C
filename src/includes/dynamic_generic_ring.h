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

    // generic functions
    int (*size)(struct _ring *);
    bool (*exist)(struct _ring *, void *);
    void (*print)(struct _ring *);

    // add functions
    void (*add_elem)(struct _ring *, void *);
    void (*add)(struct _ring *, void *);
    void (*add_before)(struct _ring *, void *);
    void (*add_next)(struct _ring *, void *);

    // delete functions
    void (*delete)(struct _ring *);
    void (*delete_before)(struct _ring *);
    void (*delete_next)(struct _ring *);
    void (*delete_elem)(struct _ring *, void *);
    void (*delete_all_elem)(struct _ring *, void *);
    void (*delete_next_elem_to)(struct _ring *, void *);
    void (*delete_before_elem_to)(struct _ring *, void *);

    // set callbacks
    void (*set_equals_callback)(struct _ring *, bool (*)(void *, void *));
    void (*set_print_callback)(struct _ring *, void (*)(void *));

    // callbacks
    bool (*equals_callback)(void *, void *);
    void (*print_callback)(void *);

    // destruct
    void (*destruct)(struct _ring *);
} ring_t;

ring_t * new_ring();

#endif
