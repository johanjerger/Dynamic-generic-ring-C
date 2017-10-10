#include <stdlib.h>
#include "includes/dynamic_generic_ring.h"
#include "includes/dgr_operations.h"

/*
 * Here I define the interface of the ring_t structure.
 */

ring_t * new_ring()
{
        ring_t * new_ring;

        new_ring = (ring_t *) malloc(sizeof(ring_t));
        new_ring->elem = NULL;
        new_ring->next = new_ring;
        new_ring->previous = new_ring;

        // Ring functions assignation

        new_ring->size = &dgr_size;
        new_ring->add = &dgr_add;

        return new_ring;
}
