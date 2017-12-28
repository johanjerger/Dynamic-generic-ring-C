#include <stdlib.h>
#include <stdbool.h>
#include "include/dynamic_generic_ring.h"
#include "include/dgr_operations.h"
#include "include/dgr_callbacks.h"
#include "include/dgr_push.h"
#include "include/dgr_delete.h"

/*
 *      Ring creation definition
 *     ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */

/*
 *    'new_ring' defines the creation of the ring_t structure,
 *    after allocing memory for this, the set up of all the
 *    function pointers is done.
 *
 *    By default, the ring is initialice as an empty structure,
 *    to maintain compatibility with another data structures
 *    philosophies.
 *
 */

ring_t * new_ring()
{
        ring_t * new_ring;

        // Default initialization (empty ring_t)

        new_ring = (ring_t *) malloc(sizeof(ring_t));
        new_ring->size = 0;
        new_ring->elements = NULL;

        // Ring functions assignation

        // Generic functions
        new_ring->exist = dgr_exist;
        new_ring->print = dgr_print;

        // Add functions
        new_ring->push = dgr_push;
        new_ring->push_in = dgr_push_in;

        // Delete functions
        new_ring->pop = dgr_pop;
        new_ring->pop_in = dgr_pop_in;

        // Set callbacks

        new_ring->compare = NULL;
        new_ring->print_element = NULL;

        // Destroy functions

        new_ring->clear = dgr_clear;
        new_ring->destruct = dgr_destruct;

        return new_ring;
}
