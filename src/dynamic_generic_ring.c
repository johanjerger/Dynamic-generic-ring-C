#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"
#include "includes/dgr_operations.h"
#include "includes/dgr_callbacks.h"
#include "includes/dgr_add.h"

/*
 * Here I define the interface of the ring_t structure.
 */

ring_t * new_ring()
{
        ring_t * new_ring;

        new_ring = (ring_t *) malloc(sizeof(ring_t));
        new_ring->elem = NULL;
        new_ring->size = 0;
        new_ring->next = new_ring;
        new_ring->previous = new_ring;

        // Ring functions assignation

        new_ring->add = &dgr_add;
        new_ring->add_before = &dgr_add_before;
        new_ring->add_next = &dgr_add_next;
        new_ring->exist = &dgr_exist;

        // Callbacks

        new_ring->set_equals_callback = &dgr_set_equals_callback;

        return new_ring;
}
