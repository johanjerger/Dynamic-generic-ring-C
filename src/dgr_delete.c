#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring add functions.
 */

// The delete function delete an element on before the actual ring position.
ring_t * dgr_delete_before(ring_t * act_ring)
{
        if (act_ring->size == 0) {
                return act_ring;
        }
        if (act_ring->size == 1) {
                act_ring->size--;
                return act_ring->elem = NULL;
        }

        act_ring->size--;

        ring_t * new_previous = act_ring->previous->previous;
        new_previous->next = act_ring;
        free(act_ring->previous);
        act_ring->previous = new_previous;

        return act_ring;
}

// The delete function delete an element on after the actual ring position.
ring_t * dgr_delete_next(ring_t * act_ring)
{
        return act_ring;
}


ring_t * dgr_delete_elem(ring_t * act_ring, void * elem)
{
        return act_ring;
}


// This method is a wrapper of dgr_delete_before
ring_t * dgr_delete(ring_t * act_ring)
{
        return act_ring->delete_before(act_ring);
}
