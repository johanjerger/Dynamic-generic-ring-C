#include <stdlib.h>
#include <stdbool.h>
#include "include/dynamic_generic_ring.h"
#include "include/dgr_operations.h"
#include "include/dgr_callbacks.h"
#include "include/dgr_push.h"
#include "include/dgr_delete.h"

/*
 * Here I define the interface of the ring_t structure.
 */

ring_t * new_ring()
{
        ring_t * new_ring;

        new_ring = (ring_t *) malloc(sizeof(ring_t));
        new_ring->size = 0;
        new_ring->elements = NULL;

        // Ring functions assignation

        // Generic functions
        new_ring->exist = &dgr_exist;
        new_ring->print = &dgr_print;
        new_ring->size = &dgr_size;

        // Add functions
        new_ring->push = &dgr_push;
        new_ring->push_in = &dgr_push_in;

        // Delete functions
        new_ring->pop = &dgr_pop;
        new_ring->pop_in = &dgr_pop_in;

        // Set callbacks

        new_ring->set_compare = &dgr_set_compare;
        new_ring->set_print = &dgr_set_print;

        // Destroy functions

        new_ring->clear = &dgr_clear;
        new_ring->destruct = &dgr_destruct;

        return new_ring;
}
