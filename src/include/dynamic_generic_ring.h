#ifndef DGR_STR_H
#define DGR_STR_H
#include <stdbool.h>
/*
 *  Ring structure typedef, here I define all the ring
 *  variables and functions..
 */

typedef struct _ring_node
{
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
    bool (*exist)(struct _ring *, void *);
    int (*count)(struct _ring *, void *);

    // add functions
    void (*push_back)(struct _ring *, void *);
    void (*push_in)(struct _ring *, int, void *);

    // delete functions
    void (*pop_back)(struct _ring *);
    void (*pop_in)(struct _ring *);

    // callbacks
    bool (*compare)(void *, void *);
    void (*print_element)(void *);

    // destruct
    void (*clear)(struct _ring *);
    void (*destruct)(struct _ring *)
}

ring_t * new_ring();

#endif
