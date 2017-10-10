#include <stdlib.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring functions.
 */

int dgr_size(ring_t * act_ring)
{
        int size = 1;
        ring_t * head = act_ring;

        // while you don't walk in circles...
        while(head->next != act_ring) {
                size++;
                head = head->next;
        }

        return size;
}


ring_t * dgr_add(ring_t * act_ring, void * elem)
{
        if (act_ring->elem == NULL) {
                return (act_ring->elem = elem);
        }

        ring_t * ring = new_ring();

        ring->elem = elem;
        act_ring->previous->next = ring;
        act_ring->previous = ring;

        return act_ring;
}
