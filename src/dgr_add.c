#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring add functions.
 */

void dgr_add_elem(ring_t * act_ring, void * elem)
{
        act_ring->size++;
        act_ring->elem = elem;
}

// The add function add an element on before the actual ring position.
void dgr_add_before(ring_t * act_ring, void * elem)
{
        ring_t * ring = new_ring();

        ring->elem = elem;
        ring->next = act_ring;
        ring->previous = act_ring->previous;
        act_ring->previous->next = ring;
        act_ring->previous = ring;
        act_ring->size++;
}

// The add function add an element on after the actual ring position.
void dgr_add_next(ring_t * act_ring, void * elem)
{
        ring_t * ring = new_ring();

        ring->elem = elem;
        ring->previous = act_ring;
        ring->next = act_ring->next;
        act_ring->next->previous = ring;
        act_ring->next = ring;
        act_ring->size++;
}

// This method is a wrapper of dgr_add_before
void dgr_add(ring_t * act_ring, void * elem)
{
        act_ring->add_before(act_ring, elem);
}
