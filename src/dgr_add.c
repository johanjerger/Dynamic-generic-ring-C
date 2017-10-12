#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring add functions.
 */

// The add function add an element on before the actual ring position.
ring_t * dgr_add(ring_t * act_ring, void * elem)
{
        if (act_ring->elem == NULL) {
                return (act_ring->elem = elem);
        }

        ring_t * ring = new_ring();

        ring->elem = elem;
        ring->next = act_ring;
        ring->previous = act_ring->previous;
        act_ring->previous->next = ring;
        act_ring->previous = ring;

        return act_ring;
}
