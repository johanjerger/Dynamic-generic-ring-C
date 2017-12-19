#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring push functions.
 */

// The push function add an element on before the actual ring position (at the end).
void dgr_push(ring_t * act_ring, void * elem)
{
        printf("push\n");
        ring_t * ring_node = (ring_node_t *) malloc(sizeof(ring_node_t));
        ring_node->elem = elem;
        ring_node->next = act_ring->first();
        ring_node->previous = act_ring->first()->previous;
        act_ring->previous->next = ring_node;
        act_ring->previous = ring_node;
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
}

// This method is a wrapper of dgr_add_before
void dgr_add(ring_t * act_ring, void * elem)
{
        act_ring->add_before(act_ring, elem);
}
