#ifndef DGR_STR_H
#define DGR_STR_H
#include <stdbool.h>
/*
 *  Ring structure typedef, here I define all the ring
 *  attributes (as variables) and functions, in an
 *  "OOP" way.
 */

typedef struct _ring_node
{
    // variables

    int pos;
    void * elem;
    struct _ring * next;
    struct _ring * previous;

} ring_node_t;

struct _ring
{
    int size;
    ring_note_t * elements;

    // generic functions
    int (*size)(struct _ring *);
    bool (*exist)(struct _ring *, void *);

    // add functions
    void (*push)(struct _ring *, void *);
    void (*push_in)(struct _ring *, int, void *);

    // delete functions
    void (*pop)(struct _ring *);
    void (*pop_in)(struct _ring *);

    // set callbacks
    void (*set_compare)(struct _ring *, bool (*)(void *, void *));
    void (*set_print)(struct _ring *, void (*)(void *));

    // callbacks
    bool (*compare)(void *, void *);
    void (*print)(void *);

    // destruct
    void (*clear)(struct _ring *);
    void (*destruct)(struct _ring *)
}

ring_t * new_ring();

#endif
